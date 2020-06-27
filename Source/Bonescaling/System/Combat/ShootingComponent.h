// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ShootingComponent.generated.h"


UCLASS( Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BONESCALING_API UShootingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UShootingComponent(const FObjectInitializer& objectInitializer);

	UFUNCTION(BlueprintCallable, Category = "Shooting")
	void Fire(class USceneComponent* FireSource,  bool &bSuccess);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Shooting")
	bool Hitscan(FHitResult &Hit);

	UFUNCTION(BlueprintPure, BlueprintNativeEvent, Category = "Shooting")
	FVector GetHitscanDirection();

	UFUNCTION(BlueprintPure, BlueprintNativeEvent, Category = "Shooting")
	FVector GetHitscanSourceLocation();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Settings")
	TSubclassOf<class AProjectile> ShootingProjectileClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Settings", meta = (ClampMin = "0", UIMin = "0"))
	int32 AffectionValue = 10;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Settings", meta = (ClampMin = "0.0", UIMin = "0.0"))
	float FireDistance = 1000.f;
	
protected:

	virtual void NativeGetReferences();

public:	

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
