// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseEnemy.h"



void ABaseEnemy::Init(FName RowName, UDataTable* DT)
{
	EnemyDate = *DT->FindRow<FEnemyProperty>(RowName, FString(""));
	CharacterDate = EnemyDate.CharacterProperty;
	Health = CharacterDate.Health;


}

int32 ABaseEnemy::GetValue()
{
	return EnemyDate.Value;
}