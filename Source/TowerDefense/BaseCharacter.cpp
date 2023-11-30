// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseCharacter::Init(FName RowName, UDataTable* DT)
{

}

FString ABaseCharacter::GetName()
{
	return CharacterDate.Name;
}

int32 ABaseCharacter::GetMaxHealth()
{
	return CharacterDate.Health;
}

int32 ABaseCharacter::GetCurrentHealth()
{
	return Health;
}

bool ABaseCharacter::LoseHealth(int32 Damage, EDamageType Type)
{

	if (bDead)
		return true;

	switch (Type)
	{

	case EDamageType::Physical:
		Health -= (Damage * (1 - CharacterDate.PhysicalArmor* 0.15f));
		break;
	case EDamageType::Magical:
		Health -= (Damage * (1 - CharacterDate.MagicalArmor * 0.15f));
		break;
	default:
		UE_LOG(LogTemp,Error£¬TEXT("UNKNOWN DAMAGETYPE!!!"));
		break;
	}
	
	if (Health<=0)
	{
		bDead = true;
		Dead();
		return true;
	}
	return false;
}

bool ABaseCharacter::IsDead()
{
	return bDead;
}

int32 ABaseCharacter::GetDamageMin()
{
	return CharacterDate.DamageMin;
}

int32 ABaseCharacter::GetDamageMax()
{
	return CharacterDate.DamageMax;
}

int32 ABaseCharacter::GetPhysicalArmor()
{
	return CharacterDate.PhysicalArmor;
}

int32 ABaseCharacter::GetMagicalArmor()
{
	return CharacterDate.MagicalArmor;
}

float ABaseCharacter::GetAttackCoolDownTime()
{
	return CharacterDate.AttackCoolDownTime;
}

int32 ABaseCharacter::GetSpeed()
{
	return CharacterDate.Speed;
}

EDamageType ABaseCharacter::GetDamageType()
{
	return CharacterDate.DamageType;
}

TSubclassOf<ABaseCharacter> ABaseCharacter::GetBPClass()
{
	return CharacterDate.BPClass;
}


