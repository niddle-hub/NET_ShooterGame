#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WeaponAmmoWidget.generated.h"

class UTextBlock;

UCLASS()
class SHOOTERGAME_API UWeaponAmmoWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void UpdateAmmo(const int32& NewAmmo, const int32& NewTotalAmmo) const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(BindWidget))
	UTextBlock* AmmoAmount;
};
