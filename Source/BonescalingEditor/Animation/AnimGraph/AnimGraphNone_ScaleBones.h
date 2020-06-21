// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AnimGraph/Classes/AnimGraphNode_SkeletalControlBase.h"
#include "Bonescaling/Animation/AnimNodes/AnimeNode_ScaleBones.h"
#include "EdGraph/EdGraphNodeUtils.h"
#include "AnimGraphNone_ScaleBones.generated.h"


class FCompilerResultsLog;

UCLASS(meta = (Keywords = "Scale Bones"))
class BONESCALINGEDITOR_API UAnimGraphNode_ScaleBones : public UAnimGraphNode_SkeletalControlBase
{
	GENERATED_UCLASS_BODY()

public:

	// UEdGraphNode interface
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual FText GetTooltipText() const override;
	// End of UEdGraphNode interface

	// Begin UAnimGraphNode_Base Interface
	virtual FString GetNodeCategory() const override;
	// End UAnimGraphNode_Base Interface

	UPROPERTY(EditAnywhere, Category = Settings)
	FAnimNode_ScaleBones Node;

protected:
	// UAnimGraphNode_Base interface
	virtual void ValidateAnimNodeDuringCompilation(USkeleton* ForSkeleton, FCompilerResultsLog& MessageLog) override;
	//virtual FEditorModeID GetEditorMode() const override;
	virtual void CopyNodeDataToPreviewNode(FAnimNode_Base* InPreviewNode) override;
	// End of UAnimGraphNode_Base interface

	// UAnimGraphNode_SkeletalControlBase interface
	virtual FText GetControllerDescription() const override;
	virtual const FAnimNode_SkeletalControlBase* GetNode() const override { return &Node; }
	// End of UAnimGraphNode_SkeletalControlBase interface

private:
	/** Constructing FText strings can be costly, so we cache the node's title */
	FNodeTitleTextTable CachedNodeTitles;

	// storing current widget mode 
	int32 CurWidgetMode;
};
