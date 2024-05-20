#include "KillfeedSubsystem.h"

void UKillfeedSubsystem::RegisterKillEvent(const AController* KilledController, const AController* InstigatedBy, const AActor* DamageCauser)
{
	if (OnRegisterKill.IsBound())
	{
		OnRegisterKill.Broadcast(KilledController, InstigatedBy, DamageCauser);
	}
}
