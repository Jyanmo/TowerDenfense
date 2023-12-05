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
	TowerData = *DT->FindRow<FtowerProperty>(RowName, FString(""));
	Level = 1;
}

int32 ABaseTower::GetTowerLevel()
{
	return Level;
}

int32 ABaseTower::GetDamageMin()
{
	return TowerData.DamageMin[Level-1];
}

int32 ABaseTower::GetDamageMax()
{
	return TowerData.DamageMax[Level-1];
}

int32 ABaseTower::GetAttackRange()
{
	return TowerData.AttackRange[Level-1];
}

int32 ABaseTower::GetNextCost()
{
	if (Level == 4)
		return 0;
	return TowerData.Cost[Level];
}

float ABaseTower::GetAttackCoolDownTime()
{
	return TowerData.AttackCoolDownTime[Level-1];
}

UStaticMesh* ABaseTower::GetStaticMesh()
{
	return TowerData.StaticMeshes[Level-1];
}

USkeletalMesh* ABaseTower::GetSkeletalMesh()
{
	return TowerData.SkeletalMeshes[Level-1];
}

UAnimationAsset* ABaseTower::GetAnim()
{
	return TowerData.Animations[Level-1];
}

EDamageType ABaseTower::GetDamageType()
{
	return TowerData.DamageType;
}

