// Fill out your copyright notice in the Description page of Project Settings.


#include "DefensiveComponent.h"

UDefensiveComponent::UDefensiveComponent(const FObjectInitializer& objectInitializer) : Super(objectInitializer)
{

}

void UDefensiveComponent::DealDamage(int32 DamageValue, FHitResult Hit, AActor* DamageInstigator, bool &bSuccess)
{
	bSuccess = false;
	if (bIsDead)
		return;

	if(Hit.BoneName != NAME_None)
	{
		if (AccumulatedHits.Contains(Hit.BoneName))
		{
			int32 HitsCount = *AccumulatedHits.Find(Hit.BoneName);
			HitsCount++;
			AccumulatedHits.Emplace(Hit.BoneName, HitsCount);
		}
		else
		{
			AccumulatedHits.Add(Hit.BoneName, 1);
		}
	}
	
	bSuccess = true;
	Health = FMath::Max(0, Health - DamageValue);
	
	if (Health == 0)
	{
		bIsDead = true;
		OnDied.Broadcast(Hit);
	}
	else
		OnDamageRecieved.Broadcast(DamageInstigator, Health, Hit);
}
