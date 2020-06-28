// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BonescalingAIController.generated.h"

UENUM(BlueprintType)
enum class EAIState : uint8
{
	E_Idle			UMETA(DisplayName = "Idle"),
	E_Escape		UMETA(DisplayName = "Escape"),
	E_Died			UMETA(DisplayName = "Died"),
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAIStateChangeResult, EAIState, NewAIState);

UCLASS()
class BONESCALING_API ABonescalingAIController : public AAIController
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Go To AI State"))
	void GoToAIState(EAIState NewState);

	UPROPERTY(BlueprintReadOnly, Category = "AI", meta = (DisplayName = "Current AI State"))
	EAIState CurrentAIState = EAIState::E_Idle;

	UPROPERTY(BlueprintAssignable, Category = "AI", meta = (DisplayName = "On AI State Change"))
	FAIStateChangeResult OnAIStateChange;

	
};
