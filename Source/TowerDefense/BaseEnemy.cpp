// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseEnemy.h"
#include "GameFramework/CharacterMovementComponent.h"






void ABaseEnemy::Init(FName RowName, UDataTable* DT)
{
	EnemyDate = *DT->FindRow<FEnemyProperty>(RowName, FString(""));
	CharacterDate = EnemyDate.CharacterProperty;
	Health = CharacterDate.Health;

	GetCharacterMovement()->MaxWalkSpeed = GetSpeed();
}

int32 ABaseEnemy::GetValue()
{
	return EnemyDate.Value;
}