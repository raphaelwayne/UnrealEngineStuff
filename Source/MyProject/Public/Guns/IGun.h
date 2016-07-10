// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Items/UsableItem.h"
#include "IGun.generated.h"

USTRUCT()
struct FWeaponData
{
	GENERATED_USTRUCT_BODY()

	/* Max ammo for player */
	UPROPERTY(EditDefaultsOnly, Category = "Weapon Ammo")
	int32 MaxAmmo;

	/* Ammo in clip */
	UPROPERTY(EditDefaultsOnly, Category = "Weapon Ammo")
	int32 ClipAmmo;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon Ammo")
	int32 InitialClips;

	/* Delay between shots */
	UPROPERTY(EditDefaultsOnly, Category = "Weapon Ammo")
	float FireRate;

	FWeaponData()
	{
		MaxAmmo = 100;
		ClipAmmo = 20;
		InitialClips = 4;
		FireRate = 0.2f;
	}
};

USTRUCT()
struct FWeaponAnimation
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, Category = "Weapon Animation")
	UAnimMontage* Animation1P;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon Animation")
	UAnimMontage* Animation3P;
};

USTRUCT()
struct FWeaponSound
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, Category = "Weapon Sounds")
	USoundBase* FireSound1P;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon Sounds")
	USoundBase* FireSound3P;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon Sounds")
	USoundBase* FireLoopSound1P;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon Sounds")
	USoundBase* FireLoopSound3P;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon Sounds")
	USoundBase* FireBurstSound1P;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon Sounds")
	USoundBase* FireBurstSound3P;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon Sounds")
	USoundBase* FireSingleSound1P;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon Sounds")
	USoundBase* FireSingleSound3P;
};

UCLASS(Abstract, Blueprintable)
class MYPROJECT_API AIGun : public AActor
{
	GENERATED_BODY()
	
	
	/* Member-Variables */
protected:
	/* Weapon properties */
	FWeaponData WeaponProperties;

	FWeaponAnimation WeaponAnimations;

	FWeaponSound WeaponSounds;

	/* Player currently owning this weapon */
	class AFPSCharacter* OwningPawn;

	enum class WeaponState
	{
		Idle,
		Firing,
		Reloading,
		Equipping,
	};

	enum class FireMode
	{
		Automatic,
		Burst,
		Single
	};

	/* If i would make this boolean, i would assign 1 byte to each boolean. Since this class will have a lot of this, i can save some space by creating bit fields of "uint32 booleans" */
	uint32 bIsFiring : 1;
	
	uint32 bIsReloading : 1;

	uint32 bIsIdling : 1;

	uint32 bIsEquipped : 1;

	WeaponState CurrentType;

	FireMode CurrentMode;

private:
	/* Mesh first person */
	UPROPERTY(VisibleDefaultsOnly, Category = "Weapon Mesh")
	USkeletalMeshComponent* Mesh1P;

	/* Mesh third person */
	UPROPERTY(VisibleDefaultsOnly, Category = "Weapon Mesh")
	USkeletalMeshComponent* Mesh3P;

	/** Member-Functions */
public:

};
