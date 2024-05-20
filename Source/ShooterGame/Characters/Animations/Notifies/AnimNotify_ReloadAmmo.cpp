#include "AnimNotify_ReloadAmmo.h"
#include "ShooterGame/Characters/BaseCharacter.h"
#include "ShooterGame/Components/CharacterComponents/CharacterEquipmentComponent.h"

void UAnimNotify_ReloadAmmo::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	const ABaseCharacter* Character = Cast<ABaseCharacter>(MeshComp->GetOwner());
	if (!IsValid(Character))
	{
		return;
	}
	Character->GetCharacterEquipmentComponent_Mutable()->ReloadAmmoInEquippedWeapon(NumberOfAmmo, true);
}
