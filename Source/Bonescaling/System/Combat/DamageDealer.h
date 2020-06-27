// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DamageDealer.generated.h"

UINTERFACE(Blueprintable, MinimalAPI)
class UDamageDealer : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};


class BONESCALING_API IDamageDealer
{
	GENERATED_IINTERFACE_BODY()


public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Damage")
	void MakeDamage(int32 DamageValue, FHitResult Hit, AActor* DamageInstigator, bool &bSuccess);



};
