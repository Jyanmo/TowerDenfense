// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "BaseEnemy.generated.h"


USTRUCT(BlueprintType)
struct FEnemyProperty : public FTableRowBase
{
	
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FCharacterBaseProperty CharacterProperty;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	int32 Value;
};


/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API ABaseEnemy : public ABaseCharacter
{
	GENERATED_BODY()
	
private:
	FEnemyProperty EnemyDate;

public:
	UFUNCTION(BlueprintCallable)
	virtual void Init(FName RowName, UDataTable* DT) override;
	UFUNCTION(BlueprintCallable,BlueprintPure)
	int32 GetValue();

};
