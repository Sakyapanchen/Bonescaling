// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootingComponent.h"
#include "GameFramework/Character.h"
#include "Engine/EngineTypes.h"
#include "Kismet/GameplayStatics.h"
#include "Math/Quat.h"
#include "Projectile.h"


UShootingComponent::UShootingComponent(const FObjectInitializer& objectInitializer) : Super(objectInitializer)
{
	PrimaryComponentTick.bCanEverTick = true;
	ShootingProjectileClass = AProjectile::StaticClass();
}

void UShootingComponent::Fire(USceneComponent* FireSource, bool &bSuccess)
{
	bSuccess = false;
	if (!IsValid(FireSource) || !IsValid(ShootingProjectileClass) || !IsValid(GetWorld()) )
		return;
	FHitResult Hit;
	
	FVector ShootingTarget;
	bSuccess = Hitscan(Hit);
	bSuccess ? ShootingTarget = Hit.ImpactPoint : ShootingTarget = Hit.TraceEnd;

	FQuat SpawnQuat = FQuat(FRotationMatrix::MakeFromX(ShootingTarget - FireSource->GetComponentLocation()).Rotator());
	FVector SpawnLocation = FireSource->GetComponentLocation();
	FTransform SpawnTransform;
	SpawnTransform.SetRotation(SpawnQuat);
	SpawnTransform.SetLocation(SpawnLocation);
	
	AProjectile* Projectile = GetWorld()->SpawnActorDeferred<AProjectile>(ShootingProjectileClass, SpawnTransform, GetOwner(), nullptr, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
	
	if (Projectile)
	{
		bSuccess = true;
		Projectile->ProjectileDamage = AffectionValue;
		UGameplayStatics::FinishSpawningActor(Projectile, SpawnTransform);
	}

}

bool UShootingComponent::Hitscan_Implementation(FHitResult& Hit)
{
	return false;
}

FVector UShootingComponent::GetHitscanSourceLocation_Implementation()
{
	return FVector();
}

FVector UShootingComponent::GetHitscanDirection_Implementation()
{
	return FVector(1.f, 0.f, 0.f);
}

void UShootingComponent::NativeGetReferences()
{
	ACharacter* OwnerCharacter = Cast<ACharacter>(GetOwner());
}

void UShootingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

