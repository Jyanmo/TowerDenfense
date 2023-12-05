// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseTower.h"

// Sets default values
ABaseTower::ABaseTower()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseTower::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseTower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseTower::Init(FName RowName, UDataTable* DT)
{
}

int32 ABaseTower::GetTowerLevel()
{
	return int32();
}

int32 ABaseTower::GetDamageMin()
{
	return int32();
}

int32 ABaseTower::GetDamageMax()
{
	return int32();
}

int32 ABaseTower::GetAttackRange()
{
	return int32();
}

int32 ABaseTower::GetNextCost()
{
	return int32();
}

float ABaseTower::GetAttackCoolDownTime()
{
	return 0.0f;
}

UStaticMesh* ABaseTower::GetStaticMesh()
{
	return nullptr;
}

USkeletalMesh* ABaseTower::GetSkeletalMesh()
{
	return nullptr;
}

UAnimationAsset* ABaseTower::GetAnim()
{
	return nullptr;
}

EDamageType ABaseTower::GetDamageType()
{
	return EDamageType();
}

