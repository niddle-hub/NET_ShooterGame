#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "KillfeedSubsystem.generated.h"

UCLASS()
class SHOOTERGAME_API UKillfeedSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_ThreeParams(FOnRegisterKillSignature, UKillfeedSubsystem, OnRegisterKill, const AController*, KilledController, const AController*, InstigatedBy, const AActor*, DamageCauser);
	UPROPERTY(BlueprintAssignable, Category="Killfeed")
	FOnRegisterKillSignature OnRegisterKill;
	
	UFUNCTION(BlueprintCallable, Category="Killfeed")
	void RegisterKillEvent(const AController* KilledController, const AController* InstigatedBy, const AActor* DamageCauser = nullptr);
	
};
