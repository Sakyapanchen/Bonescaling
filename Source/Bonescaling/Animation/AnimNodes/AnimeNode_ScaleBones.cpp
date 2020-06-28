// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimeNode_ScaleBones.h"
#include "AnimationRuntime.h"
#include "Animation/AnimInstanceProxy.h"

/////////////////////////////////////////////////////
// FAnimNode_ScaleBones

FAnimNode_ScaleBones::FAnimNode_ScaleBones()
	: ScaleMode(BSM_Additive)
	, ScaleSpace(BCS_ComponentSpace)
{
	ScaleData.BoneList.Empty();
}

void FAnimNode_ScaleBones::EvaluateSkeletalControl_AnyThread(FComponentSpacePoseContext& Output, TArray<FBoneTransform>& OutBoneTransforms)
{
	DECLARE_SCOPE_HIERARCHICAL_COUNTER_ANIMNODE(EvaluateSkeletalControl_AnyThread)
	check(OutBoneTransforms.Num() == 0);
	
	const FBoneContainer& BoneContainer = Output.Pose.GetPose().GetBoneContainer();
	const FReferenceSkeleton ReferenceSkeleton = BoneContainer.GetReferenceSkeleton();
	TMap<FName, FVector> BoneList = ScaleData.BoneList;
	
	for(const TPair<FName, FVector> Elem : BoneList)
	{
		FName BoneName = Elem.Key;
		int32 BoneIndex = -1;
		BoneIndex = ReferenceSkeleton.FindBoneIndex(BoneName);
		
		if(BoneIndex >= 0)
		{
			FCompactPoseBoneIndex CompactPoseBoneToModify = BoneContainer.GetCompactPoseIndexFromSkeletonIndex(BoneIndex);
			FTransform NewBoneTM = Output.Pose.GetComponentSpaceTransform(CompactPoseBoneToModify);
			FTransform ComponentTransform = Output.AnimInstanceProxy->GetComponentTransform();
			FVector Scale = Elem.Value;
			
			if (ScaleMode != BSM_Ignore)
			{
				FAnimationRuntime::ConvertCSTransformToBoneSpace(ComponentTransform, Output.Pose, NewBoneTM, CompactPoseBoneToModify, ScaleSpace);

				if (ScaleMode == BSM_Additive)
				{
					NewBoneTM.SetScale3D(NewBoneTM.GetScale3D() * Scale);
				}
				else
				{
					NewBoneTM.SetScale3D(Scale);
				}
				FAnimationRuntime::ConvertBoneSpaceTransformToCS(ComponentTransform, Output.Pose, NewBoneTM, CompactPoseBoneToModify, ScaleSpace);
			}

			OutBoneTransforms.Add(FBoneTransform(CompactPoseBoneToModify, NewBoneTM));
		}
	}
}

bool FAnimNode_ScaleBones::IsValidToEvaluate(const USkeleton* Skeleton, const FBoneContainer& RequiredBones)
{
	if(!IsValid(Skeleton) || !RequiredBones.IsValid())
		return false;
	if(RequiredBones.GetNumBones() == 0)
		return false;
	return true;
}
