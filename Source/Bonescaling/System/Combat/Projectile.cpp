// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"

AProjectile::AProjectile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
	SetActorEnableCollision(true);
	ProjectileBounds = CreateDefaultSubobject<USphereComponent>(FName("Projectile Bounds"));
	RootComponent = ProjectileBounds;
	ProjectileBounds->InitSphereRadius(16.f);
	ProjectileBounds->SetShouldUpdatePhysicsVolume(true);
	ProjectileBounds->SetCanEverAffectNavigation(false);
	ProjectileBounds->CanCharacterStepUpOn = ECanBeCharacterBase::ECB_No;
	ProjectileBounds->SetCollisionProfileName(FName("Projectile"));
	ProjectileBounds->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile Movement"));
	ProjectileMovement->ProjectileGravityScale = 0.f;
	if (ProjectileMovement)
		ProjectileMovement->UpdatedComponent = ProjectileBounds;
}



