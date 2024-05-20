#include "ThrowableItemWidget.h"
#include "Components/TextBlock.h"

void UThrowableItemWidget::UpdateAmount(const int32& NewAmount) const
{
	ThrowableAmount->SetText(FText::AsNumber(NewAmount));
}
