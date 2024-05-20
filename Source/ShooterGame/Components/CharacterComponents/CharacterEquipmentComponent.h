#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ShooterGame/ShooterGameTypes.h"
#include "CharacterEquipmentComponent.generated.h"

typedef TArray<int32, TInlineAllocator<static_cast<uint32>(EAmmunitionType::AT_MAX)>> TAmmunitionArray;
typedef TArray<class AEquipableItem*, TInlineAllocator<static_cast<uint32>(EEquipmentSlot::ES_MAX)>> TItemsArray;

DECLARE_MULTICAST_DELEGATE_TwoParams(FOnEquippedWeaponAmmoChangedSignature, const int32&, const int32&);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnequippedThrowableItemAmountChangedSignature, const int32&);
DECLARE_MULTICAST_DELEGATE(FOnWeaponChangedSignature);

class ARangeWeaponItem;
class AThrowableItem;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHOOTERGAME_API UCharacterEquipmentComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	EEquipableItemType GetEquippedItemType() const;

	FORCEINLINE ARangeWeaponItem* GetEquippedRangeWeapon() const { return EquippedWeapon; }

	FORCEINLINE AThrowableItem* GetEquippedThrowableItem() const { return EquippedThrowableItem; }

	FORCEINLINE bool IsEquipping() const { return bIsEquipping; }

	FOnEquippedWeaponAmmoChangedSignature OnEquippedWeaponAmmoChangedDelegate;
	FOnequippedThrowableItemAmountChangedSignature OnEquippedThrowableItemAmountChangedDelegate;
	FOnWeaponChangedSignature OnWeaponChangedDelegate;

	void ReloadEquippedWeapon() const;

	void ReloadAmmoInEquippedWeapon(int32 NumberOfAmmo = 0, bool CheckIsFull = false);
	
	void EquipItemInSlot(EEquipmentSlot Slot);
	void AttachEquippedItem() const;

	void EquipNext();
	void EquipPrevious();

	void LaunchEquippedThrowableItem();

	int32 GetAvailableAmmunitionForEquippedWeapon() const;
	int32 GetAvailableAmountOfEquippedThrowableItem() const;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Equipment")
	TMap<EAmmunitionType, int32> MaxAmmunitionAmount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Equipment")
	TMap<EEquipmentSlot, TSubclassOf<AEquipableItem>> ItemsLoadout;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Equipment")
	TSet<EEquipmentSlot> IgnoreSlotsWhileSwitching;

private:
	TAmmunitionArray AmmunitionArray;
	TItemsArray ItemsArray;

	uint32 NextItemsArraySlotIndex(uint32 CurrentSlotIndex) const;
	uint32 PreviousItemsArraySlotIndex(uint32 CurrentSlotIndex) const;

	void OnWeaponChanged() const;
	void CreateLoadout();

	void UnequipCurrentItem();
	void OnEquipMontageEnd();

	FDelegateHandle OnEquippedWeaponAmmoChangedHandle;
	FDelegateHandle OnEquippedWeaponReloadedHandle;

	EEquipmentSlot PreviousEquippedSlot = EEquipmentSlot::ES_None;
	EEquipmentSlot EquippedSlot = EEquipmentSlot::ES_None;
	
	TObjectPtr<AEquipableItem> EquippedItem;
	TObjectPtr<ARangeWeaponItem> EquippedWeapon;
	TObjectPtr<AThrowableItem> EquippedThrowableItem;

	UFUNCTION()
	void OnEquippedWeaponAmmoChanged(int32 NewAmmo) const;

	UFUNCTION()
	void OnEquippedWeaponReloaded();

	TWeakObjectPtr<class ABaseCharacter> OwnerCharacter;

	bool bIsEquipping = false;
	FTimerHandle EquipTimerHandle;
};
