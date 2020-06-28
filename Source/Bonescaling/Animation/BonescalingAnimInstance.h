// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AnimNodes/AnimeNode_ScaleBones.h"
#include "BonescalingAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class BONESCALING_API UBonescalingAnimInstance : public UAnimInstance
{
	GENERATED_BODY()


public:
	
	virtual void NativeBeginPlay() override;

protected:

	UFUNCTION(BlueprintCallable, Category = "Animation Params")
	void UpdateBonescalingData(TMap<FName, int32> AccumulatedHits);

	UPROPERTY(BlueprintReadOnly, Category = "References")
	class UDefensiveComponent* OwnerDefensiveComponent = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Animation Params")
	FScaleData BonescalingData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation Params", meta = (ClampMin = "0.0", UIMin = "0.0"))
	float ScalePerHit = 0.1;
};
