// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DefensiveComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDamageRecievedResult, int32, Health, FHitResult, Hit);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDeathResult, FHitResult, Hit);

UCLASS( Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BONESCALING_API UDefensiveComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UDefensiveComponent(const FObjectInitializer& objectInitializer);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Settings", meta = (ClampMin = "0", UIMin = "0"))
	int32 Health = 100;

	UPROPERTY(BlueprintAssignable, Category = "Defensive")
	FDamageRecievedResult OnDamageRecieved;

	UPROPERTY(BlueprintAssignable, Category = "Defensive")
	FDeathResult OnDied;

	UPROPERTY(BlueprintReadOnly, Category = "Defensive")
	TMap<FName, int32> AccumulatedHits;
	
	UPROPERTY(BlueprintReadOnly, Category = "Defensive")
	bool bIsDead = false;

protected:
	
	UFUNCTION(BlueprintCallable, Category = "Damage")
	void DealDamage(int32 DamageValue, FHitResult Hit, AActor* DamageInstigator, bool &bSuccess);
		
};
