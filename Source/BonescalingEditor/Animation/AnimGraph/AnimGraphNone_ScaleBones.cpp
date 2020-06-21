// Copyright Epic Games, Inc. All Rights Reserved.

#include "AnimGraphNone_ScaleBones.h"
#include "UnrealWidget.h"
#include "AnimNodeEditModes.h"
#include "Kismet2/CompilerResultsLog.h"

/////////////////////////////////////////////////////
// UAnimGraphNode_ScaleBones

#define LOCTEXT_NAMESPACE "A3Nodes"

UAnimGraphNode_ScaleBones::UAnimGraphNode_ScaleBones(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	CurWidgetMode = (int32)FWidget::WM_Scale;
}

void UAnimGraphNode_ScaleBones::ValidateAnimNodeDuringCompilation(USkeleton* ForSkeleton, FCompilerResultsLog& MessageLog)
{
	if (Node.ScaleMode == BSM_Ignore)
	{
		MessageLog.Warning(*LOCTEXT("NothingToScalw", "@@ - No components to modify selected.  Either Scale should be set to something other than Ignore").ToString(), this);
	}

	Super::ValidateAnimNodeDuringCompilation(ForSkeleton, MessageLog);
}

FText UAnimGraphNode_ScaleBones::GetControllerDescription() const
{
	return LOCTEXT("ScaleBones", "Scale Bones");
}

FText UAnimGraphNode_ScaleBones::GetTooltipText() const
{
	return LOCTEXT("AnimGraphNode_ScaleBones_Tooltip", "The Transform Bone node alters the transform - i.e. Scale - of the bone");
}

FString UAnimGraphNode_ScaleBones::GetNodeCategory() const
{
	return TEXT("Scale Bones");
}

FText UAnimGraphNode_ScaleBones::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	if ((TitleType == ENodeTitleType::ListView || TitleType == ENodeTitleType::MenuTitle) && (Node.ScaleData.BoneList.Num() == 0))
	{
		return GetControllerDescription();
	}
	return LOCTEXT("Scale Bones", "Scale Bones");;
}

void UAnimGraphNode_ScaleBones::CopyNodeDataToPreviewNode(FAnimNode_Base* InPreviewNode)
{
	FAnimNode_ScaleBones* ScaleBones = static_cast<FAnimNode_ScaleBones*>(InPreviewNode);

	ScaleBones->ScaleData = Node.ScaleData;

	ScaleBones->ScaleMode = Node.ScaleMode;

	ScaleBones->ScaleSpace = Node.ScaleSpace;
}

#undef LOCTEXT_NAMESPACE
