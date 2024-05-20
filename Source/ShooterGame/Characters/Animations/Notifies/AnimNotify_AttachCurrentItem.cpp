#include "AnimNotify_AttachCurrentItem.h"

#include "ShooterGame/Characters/BaseCharacter.h"
#include "ShooterGame/Components/CharacterComponents/CharacterEquipmentComponent.h"

void UAnimNotify_AttachCurrentItem::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	const ABaseCharacter* Owner = Cast<ABaseCharacter>(MeshComp->GetOwner());
	if (!IsValid(Owner))
	{
		return;
	}
	Owner->GetCharacterEquipmentComponent_Mutable()->AttachEquippedItem();
}
