// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BoneControllers/AnimNode_SkeletalControlBase.h"
#include "UObject/NoExportTypes.h"
#include "AnimeNode_ScaleBones.generated.h"

/**
 * 
 */
class USkeletalMeshComponent;

UENUM(BlueprintType)
enum EBonesScaleMode
{
	/** The modifier ignores this channel (keeps the existing bone translation scale). */
	BSM_Ignore UMETA(DisplayName = "Ignore"),

	/** The modifier replaces the existing translationscale. */
	BSM_Replace UMETA(DisplayName = "Replace Existing"),

	/** The modifier adds to the existing scale. */
	BSM_Additive UMETA(DisplayName = "Add to Existing")
};

USTRUCT(BlueprintType)
struct BONESCALING_API FScaleData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	TMap<FName, FVector> BoneList;
};

/**
 *	Simple controller that replaces or adds to the translation/rotation of a single bone.
 */
USTRUCT(BlueprintInternalUseOnly)
struct BONESCALING_API FAnimNode_ScaleBones : public FAnimNode_SkeletalControlBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Scale, meta = (AlwaysAsPin))
	FScaleData ScaleData;

	/** Whether and how to modify the translation of this bone. */
	UPROPERTY(EditAnywhere, Category = Scale)
	TEnumAsByte<EBonesScaleMode> ScaleMode;

	/** Reference frame to apply Scale in. */
	UPROPERTY(EditAnywhere, Category = Scale)
	TEnumAsByte<enum EBoneControlSpace> ScaleSpace;

	FAnimNode_ScaleBones();

	// FAnimNode_SkeletalControlBase interface
	virtual void EvaluateSkeletalControl_AnyThread(FComponentSpacePoseContext& Output, TArray<FBoneTransform>& OutBoneTransforms) override;
	virtual bool IsValidToEvaluate(const USkeleton* Skeleton, const FBoneContainer& RequiredBones) override;
	// End of FAnimNode_SkeletalControlBase interface

};
