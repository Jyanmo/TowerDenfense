 // Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Engine/DataTable.h"
#include "BaseCharacter.generated.h"


UENUM(BlueprintType)
enum class EDamageType :uint8
{
	None,
	Physical,
	Magical
};

USTRUCT(BlueprintType)
struct FCharacterBaseProperty:public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FString Name;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	int32 Health;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	int32 DamageMin;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	int32 DamageMax;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	int32 PhysicalArmor;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	int32 MagicalArmor;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float AttackCoolDownTime;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	int32 Speed;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	EDamageType DamageType;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TSubclassOf<ABaseCharacter>  BPClass;
	
};

UCLASS()
class TOWERDEFENSE_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected:
	FCharacterBaseProperty CharacterDate;
	int32 Health;
	bool bDead=false;

public:
	virtual void Init(FName RowName, UDataTable* DT);
	 
public:
	UFUNCTION(BlueprintCallable,BlueprintPure)
	FString GetName();
	UFUNCTION(BlueprintCallable,BlueprintPure)
	int32  GetMaxHealth();
	UFUNCTION(BlueprintCallable,BlueprintPure)
	int32  GetCurrentHealth();
	UFUNCTION(BlueprintCallable)
	bool LoseHealth(int32 Damage,EDamageType Type);
	UFUNCTION(BlueprintCallable,BlueprintPure)
	bool IsDead();
	UFUNCTION(BlueprintImplementableEvent)
	void Dead();


	UFUNCTION(BlueprintCallable,BlueprintPure)
	int32  GetDamageMin();
	UFUNCTION(BlueprintCallable,BlueprintPure)
	int32  GetDamageMax();
	UFUNCTION(BlueprintCallable,BlueprintPure)
	int32  GetPhysicalArmor();
	UFUNCTION(BlueprintCallable,BlueprintPure)
	int32  GetMagicalArmor();
	UFUNCTION(BlueprintCallable,BlueprintPure)
	float  GetAttackCoolDownTime();
	UFUNCTION(BlueprintCallable,BlueprintPure)
	int32  GetSpeed();
	UFUNCTION(BlueprintCallable,BlueprintPure)
	EDamageType GetDamageType();
	UFUNCTION(BlueprintCallable,BlueprintPure)
	TSubclassOf<ABaseCharacter> GetBPClass();


};
