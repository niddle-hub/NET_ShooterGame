// ReSharper disable CppMemberFunctionMayBeConst
#include "BaseCharacterController.h"
#include "ShooterGame/Components/CharacterComponents/CharacterAttributesComponent.h"
#include "ShooterGame/Components/CharacterComponents/CharacterEquipmentComponent.h"
#include "ShooterGame/UI/Widgets/CharacterAttributesWidget.h"
#include "ShooterGame/UI/Widgets/ReticleWidget.h"
#include "ShooterGame/UI/Widgets/ThrowableItemWidget.h"
#include "ShooterGame/UI/Widgets/WeaponAmmoWidget.h"

void ABaseCharacterController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	CachedCharacter = Cast<ABaseCharacter>(InPawn);
}

void ABaseCharacterController::BeginPlay()
{
	Super::BeginPlay();
	CreateWidgets();
}

UPlayerHUDWidget* ABaseCharacterController::GetPlayerHUD()
{
	return PlayerHUDWidget;
}

void ABaseCharacterController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAxis("MoveForward", this, &ABaseCharacterController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ABaseCharacterController::MoveRight);
	InputComponent->BindAxis("Turn", this, &ABaseCharacterController::Turn);
	InputComponent->BindAxis("LookUp", this, &ABaseCharacterController::LookUp);
	InputComponent->BindAxis("TurnAtRate", this, &ABaseCharacterController::TurnAtRate);
	InputComponent->BindAxis("LookUpAtRate", this, &ABaseCharacterController::LookUpAtRate);
	InputComponent->BindAxis("SwimForward", this, &ABaseCharacterController::SwimForward);
	InputComponent->BindAxis("SwimRight", this, &ABaseCharacterController::SwimRight);
	InputComponent->BindAxis("SwimUp", this, &ABaseCharacterController::SwimUp);
	InputComponent->BindAxis("ClimbLadderUp", this, &ABaseCharacterController::ClimbLadderUp);
	InputComponent->BindAction("Mantle", IE_Pressed, this, &ABaseCharacterController::Mantle);
	InputComponent->BindAction("Jump", IE_Pressed, this, &ABaseCharacterController::Jump);
	InputComponent->BindAction("Crouch", IE_Pressed, this, &ABaseCharacterController::ChangeCrouchState);
	InputComponent->BindAction("Sprint", IE_Pressed, this, &ABaseCharacterController::StartSprint);
	InputComponent->BindAction("Sprint", IE_Released, this, &ABaseCharacterController::EndSprint);
	InputComponent->BindAction("InteractWithLadder", IE_Pressed, this, &ABaseCharacterController::InteractWithLadder);
	InputComponent->BindAction("Zipline", IE_Pressed, this, &ABaseCharacterController::Zipline);
	InputComponent->BindAction("Fire", IE_Pressed, this, &ABaseCharacterController::InternalStartFire);
	InputComponent->BindAction("Fire", IE_Released, this, &ABaseCharacterController::InternalStopFire);
	InputComponent->BindAction("Aim", IE_Pressed, this, &ABaseCharacterController::StartAiming);
	InputComponent->BindAction("Aim", IE_Released, this, &ABaseCharacterController::StopAiming);
	InputComponent->BindAction("Reload", IE_Pressed, this, &ABaseCharacterController::Reload);
	InputComponent->BindAction("NextItem", IE_Pressed, this, &ABaseCharacterController::NextItem);
	InputComponent->BindAction("PrevItem", IE_Pressed, this, &ABaseCharacterController::PreviousItem);
	InputComponent->BindAction("EquipPrimaryItem", IE_Pressed, this, &ABaseCharacterController::EquipPrimaryItem);
}

void ABaseCharacterController::MoveForward(float Value)
{
	if (CachedCharacter.IsValid())
	{
		CachedCharacter->MoveForward(Value);
	}
}

void ABaseCharacterController::MoveRight(float Value)
{
	if (CachedCharacter.IsValid())
	{
		CachedCharacter->MoveRight(Value);
	}
}

void ABaseCharacterController::Turn(float Value)
{
	if (CachedCharacter.IsValid())
	{
		CachedCharacter->Turn(Value);
	}
}

void ABaseCharacterController::LookUp(float Value)
{
	if (CachedCharacter.IsValid())
	{
		CachedCharacter->LookUp(Value);
	}
}

void ABaseCharacterController::TurnAtRate(float Value)
{
	if (CachedCharacter.IsValid())
	{
		CachedCharacter->TurnAtRate(Value);
	}
}

void ABaseCharacterController::LookUpAtRate(float Value)
{
	if (CachedCharacter.IsValid())
	{
		CachedCharacter->LookUpAtRate(Value);
	}
}

void ABaseCharacterController::Mantle()
{
	if (CachedCharacter.IsValid())
	{
		CachedCharacter->Mantle();
	}
}

void ABaseCharacterController::Jump()
{
	if (CachedCharacter.IsValid())
	{
		CachedCharacter->Jump();
	}
}

void ABaseCharacterController::ClimbLadderUp(float Value)
{
	if (CachedCharacter.IsValid())
	{
		CachedCharacter->ClimbLadderUp(Value);
	}
}

void ABaseCharacterController::InteractWithLadder()
{
	if (CachedCharacter.IsValid())
	{
		CachedCharacter->InteractWithLadder();
	}
}

void ABaseCharacterController::Zipline()
{
	if (CachedCharacter.IsValid())
	{
		CachedCharacter->Zipline();
	}
}

void ABaseCharacterController::ChangeCrouchState()
{
	if (CachedCharacter.IsValid())
	{
		CachedCharacter->ChangeCrouchState();
	}
}

void ABaseCharacterController::StartSprint()
{
	if (CachedCharacter.IsValid())
	{
		CachedCharacter->StartSprint();
	}
}

void ABaseCharacterController::EndSprint()
{
	if (CachedCharacter.IsValid())
	{
		CachedCharacter->EndSprint();
	}
}

void ABaseCharacterController::SwimForward(float Value)
{
	if (CachedCharacter.IsValid())
	{
		CachedCharacter->SwimForward(Value);
	}
}

void ABaseCharacterController::SwimRight(float Value)
{
	if (CachedCharacter.IsValid())
	{
		CachedCharacter->SwimRight(Value);
	}
}

void ABaseCharacterController::SwimUp(float Value)
{
	if (CachedCharacter.IsValid())
	{
		CachedCharacter->SwimUp(Value);
	}
}

void ABaseCharacterController::InternalStartFire()
{
	if (CachedCharacter.IsValid())
	{
		CachedCharacter->StartFire();
	}
}

void ABaseCharacterController::InternalStopFire()
{
	if (CachedCharacter.IsValid())
	{
		CachedCharacter->StopFire();
	}
}

void ABaseCharacterController::StartAiming()
{
	if(CachedCharacter.IsValid())
	{
		CachedCharacter->StartAiming();
	}
}

void ABaseCharacterController::StopAiming()
{
	if (CachedCharacter.IsValid())
	{
		CachedCharacter->StopAiming();
	}
}

void ABaseCharacterController::Reload()
{
	if (CachedCharacter.IsValid())
	{
		CachedCharacter->ReloadEquippedWeapon();
	}
}

void ABaseCharacterController::NextItem()
{
	if (CachedCharacter.IsValid())
	{
		CachedCharacter->NextItem();
	}
}

void ABaseCharacterController::PreviousItem()
{
	if (CachedCharacter.IsValid())
	{
		CachedCharacter->PreviousItem();
	}
}

void ABaseCharacterController::EquipPrimaryItem()
{
	if (CachedCharacter)
	{
		CachedCharacter->EquipPrimaryItem();
	}
}

void ABaseCharacterController::CreateWidgets()
{
	if (!IsLocalController())
	{
		return;
	}
	
	if (!IsValid(PlayerHUDWidget))
	{
		PlayerHUDWidget = CreateWidget<UPlayerHUDWidget>(GetWorld(), PlayerHUDWidgetClass);
		if (IsValid(PlayerHUDWidget))
		{
			PlayerHUDWidget->AddToViewport();
		}
	}

	if (CachedCharacter.IsValid() && IsValid(PlayerHUDWidget))
	{
		UReticleWidget* ReticleWidget = PlayerHUDWidget->GetReticleWidget();
		if (IsValid(ReticleWidget))
		{
			CachedCharacter->OnAimingStateChanged.AddUFunction(ReticleWidget, FName("OnAimingStateChanged"));
		}

		UWeaponAmmoWidget* WeaponAmmoWidget = PlayerHUDWidget->GetWeaponAmmoWidget();
		if (IsValid(WeaponAmmoWidget))
		{
			UCharacterEquipmentComponent* EquipmentComponent = CachedCharacter->GetCharacterEquipmentComponent_Mutable();
			EquipmentComponent->OnEquippedWeaponAmmoChangedDelegate.AddUObject(WeaponAmmoWidget, &UWeaponAmmoWidget::UpdateAmmo);
		}

		UThrowableItemWidget* ThrowableItemWidget = PlayerHUDWidget->GetThrowableItemWidget();
		if (IsValid(ThrowableItemWidget))
		{
			UCharacterEquipmentComponent* EquipmentComponent = CachedCharacter->GetCharacterEquipmentComponent_Mutable();
			EquipmentComponent->OnEquippedThrowableItemAmountChangedDelegate.AddUObject(ThrowableItemWidget, &UThrowableItemWidget::UpdateAmount);
		}

		UCharacterAttributesWidget* CharacterAttributesWidget = PlayerHUDWidget->GetCharacterAttributesWidget();
		if (IsValid(CharacterAttributesWidget))
		{
			UCharacterAttributesComponent* CharacterAttributesComponent = CachedCharacter->GetCharacterAttributesComponent_Mutable();
			CharacterAttributesComponent->OnHealthChangedEvent.AddUFunction(CharacterAttributesWidget, FName("UpdateHealth"));
			CharacterAttributesComponent->OnStaminaChangedEvent.AddUFunction(CharacterAttributesWidget, FName("UpdateStamina"));
			CharacterAttributesComponent->OnOxygenChangedEvent.AddUFunction(CharacterAttributesWidget, FName("UpdateOxygen"));
		}
	}

	BP_CreateWidgets();
}