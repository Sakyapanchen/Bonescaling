// Fill out your copyright notice in the Description page of Project Settings.


#include "BonescalingAIController.h"

void ABonescalingAIController::GoToAIState(EAIState NewState)
{
	CurrentAIState = NewState;
	OnAIStateChange.Broadcast(CurrentAIState);
}