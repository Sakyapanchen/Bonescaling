// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class BONESCALING_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	

	AProjectile(const FObjectInitializer& objectInitializer);

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Projectile", meta = (AllowPrivateAccess = "true"))
	class USphereComponent* ProjectileBounds = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Projectile", meta = (AllowPrivateAccess = "true"))
	class UProjectileMovementComponent* ProjectileMovement = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Projectile", meta = (ClampMin = "0.0", UIMin = "0.0"))
	int32 ProjectileDamage = 0;
};
