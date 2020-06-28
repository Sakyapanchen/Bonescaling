// Fill out your copyright notice in the Description page of Project Settings.


#include "BonescalingAnimInstance.h"
#include "Bonescaling/System/Combat/DefensiveComponent.h"


void UBonescalingAnimInstance::NativeBeginPlay()
{
	BonescalingData.BoneList.Empty();
	
	APawn* OwnerPawn = TryGetPawnOwner();
	if (IsValid(OwnerPawn))
	{
		UActorComponent* FindedComponent = OwnerPawn->FindComponentByClass(OwnerDefensiveComponent->StaticClass());
		if(IsValid(FindedComponent))
			OwnerDefensiveComponent = Cast<UDefensiveComponent>(FindedComponent);
	}
}

void UBonescalingAnimInstance::UpdateBonescalingData(TMap<FName, int32> AccumulatedHits)
{
	FReferenceSkeleton ReferenceSkeleton = CurrentSkeleton->GetReferenceSkeleton();
	
	for(TPair<FName, int32> Elem : AccumulatedHits)
	{
		FVector CurrentScale = FVector::OneVector + FVector::OneVector * Elem.Value * ScalePerHit;
		
		if(BonescalingData.BoneList.Contains(Elem.Key))
		{
			BonescalingData.BoneList.Emplace(Elem.Key, CurrentScale);
		}
		else
		{
			BonescalingData.BoneList.Add(Elem.Key, CurrentScale);
		}
	}
	
	if (BonescalingData.BoneList.Num() <= 1)
		return;

	BonescalingData.BoneList.KeySort([&ReferenceSkeleton](FName A, FName B)
	{
		int32 A1 = ReferenceSkeleton.FindBoneIndex(A);
		int32 B1 = ReferenceSkeleton.FindBoneIndex(B);
		return A1 < B1;
	}
	);	
}
