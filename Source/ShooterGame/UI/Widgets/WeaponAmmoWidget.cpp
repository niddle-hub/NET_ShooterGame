#include "WeaponAmmoWidget.h"
#include "Components/TextBlock.h"

void UWeaponAmmoWidget::UpdateAmmo(const int32& NewAmmo, const int32& NewTotalAmmo) const
{
	AmmoAmount->SetText(FText::Format(FText::FromString("{0}/{1}"), NewAmmo, NewTotalAmmo));
}
