#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ThrowableItemWidget.generated.h"

class UTextBlock;

UCLASS()
class SHOOTERGAME_API UThrowableItemWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void UpdateAmount(const int32& NewAmount) const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(BindWidget))
	UTextBlock* ThrowableAmount;
};
