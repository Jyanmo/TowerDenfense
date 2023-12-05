// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseEnemy.h"
#include "BaseTower.generated.h"

USTRUCT(BlueprintType)
struct FtowerProperty:public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly,EditAnywhere)
	TArray<float> AttackRange;
	UPROPERTY(BlueprintReadOnly,EditAnywhere)
	TArray<int32> DamageMin;
	UPROPERTY(BlueprintReadOnly,EditAnywhere)
	TArray<int32> DamageMax;
	UPROPERTY(BlueprintReadOnly,EditAnywhere)
	TArray<float> AttackCoolDownTime;
	UPROPERTY(BlueprintReadOnly,EditAnywhere)
	EDamageType DamageType;
	UPROPERTY(BlueprintReadOnly,EditAnywhere)
	TArray<int32> Cost;
	UPROPERTY(BlueprintReadOnly,EditAnywhere)
	TArray<UStaticMesh*> StaticMeshes;
	UPROPERTY(BlueprintReadOnly,EditAnywhere)
	TArray<USkeletalMesh*> SkeletalMeshes;
	UPROPERTY(BlueprintReadOnly,EditAnywhere)
	TArray<UAnimationAsset*> Animations;
};




UCLASS()
class TOWERDEFENSE_API ABaseTower : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseTower();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FtowerProperty TowerData;
public:
	UPROPERTY(BlueprintReadWrite)
	int32 Level;

public:
	UFUNCTION(BlueprintCallable)
	void Init(FName RowName,UDataTable* DT);
	UFUNCTION(BlueprintCallable, BlueprintPure)
	int32 GetTowerLevel();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	int32 GetDamageMin();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	int32 GetDamageMax();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	int32 GetAttackRange();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	int32 GetNextCost();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetAttackCoolDownTime();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	UStaticMesh* GetStaticMesh();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	USkeletalMesh* GetSkeletalMesh();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	UAnimationAsset* GetAnim();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	EDamageType GetDamageType();

};
