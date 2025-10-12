#include "MyCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "MyPlayerController.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AnimalGameState.h"
#include "Components/TextBlock.h"


AMyCharacter::AMyCharacter()
{
 	
	PrimaryActorTick.bCanEverTick = false;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->TargetArmLength = 300.0f;
	SpringArmComp->bUsePawnControlRotation = true;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(SpringArmComp,USpringArmComponent::SocketName);
	CameraComp->bUsePawnControlRotation = false;

	OverheadWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("OverheadWidget"));
	OverheadWidget->SetupAttachment(GetMesh());
	OverheadWidget->SetWidgetSpace(EWidgetSpace::Screen);

	NormalSpeed = 650.0f;
	SpeedDuration = 6.0f;
	SprintSpeedMultiplier = 1.7f;
	
	SprintSpeed = NormalSpeed * SprintSpeedMultiplier;


	PenguinSpeedDown = NormalSpeed -300;

	GetCharacterMovement()->MaxWalkSpeed = NormalSpeed; // 기본속도

	MaxHealth = 100.0f;
	Health = MaxHealth;

	SpeedD = false;


}

void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	UpDateOverheadHP();
}



void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (AMyPlayerController* PlayerController = Cast<AMyPlayerController>(GetController()))
		{
			if (PlayerController->MoveAction)
			{
				EnhancedInput->BindAction(
					PlayerController->MoveAction,
					ETriggerEvent::Triggered,
					this,
					&AMyCharacter::Move
				);
			}
			if (PlayerController->LookAction)
			{
				EnhancedInput->BindAction(
					PlayerController->LookAction,
					ETriggerEvent::Triggered,
					this,
					&AMyCharacter::Look
				);
			}
			if (PlayerController->JumpAction)
			{
				EnhancedInput->BindAction(
					PlayerController->JumpAction,
					ETriggerEvent::Triggered,
					this,
					&AMyCharacter::StartJump
				);
				EnhancedInput->BindAction(
					PlayerController->JumpAction,
					ETriggerEvent::Completed,
					this,
					&AMyCharacter::StopJump
				);
			}
			if (PlayerController->SprintAction)
			{
				EnhancedInput->BindAction(
					PlayerController->SprintAction,
					ETriggerEvent::Triggered,
					this,
					&AMyCharacter::StartSprint
				);
				EnhancedInput->BindAction(
					PlayerController->SprintAction,
					ETriggerEvent::Completed,
					this,
					&AMyCharacter::StopSprint
				);
			}
		}
	}

}

void AMyCharacter::Move(const FInputActionValue& value)
{
	if (!Controller) return;

	const FVector2D MoveInput = value.Get<FVector2D>();

	if (!FMath::IsNearlyZero(MoveInput.X))
	{
		AddMovementInput(GetActorForwardVector(), MoveInput.X);
	}
	if (!FMath::IsNearlyZero(MoveInput.Y))
	{
		AddMovementInput(GetActorRightVector(), MoveInput.Y);
	}
}
void AMyCharacter::Look(const FInputActionValue& value)
{
	FVector2D LookInput = value.Get<FVector2D>();

	AddControllerYawInput(LookInput.X);
	AddControllerPitchInput(LookInput.Y);
}
void AMyCharacter::StartJump(const FInputActionValue& value)
{
	if (value.Get<bool>())
	{
		Jump();
	}
}
void AMyCharacter::StopJump(const FInputActionValue& value)
{
	if (!value.Get<bool>())
	{
		StopJumping();
	}
}
void AMyCharacter::StartSprint(const FInputActionValue& value)
{
	if (GetCharacterMovement())
	{
	
		if (SpeedD)
		{
			GetCharacterMovement()->MaxWalkSpeed = NormalSpeed;

		}
		else
		{
			GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
		}
	}
	
}
void AMyCharacter::StopSprint(const FInputActionValue& value)
{
	if (GetCharacterMovement())
	{
		
		if (SpeedD)
		{
			GetCharacterMovement()->MaxWalkSpeed = PenguinSpeedDown;

		}
		else
		{
			GetCharacterMovement()->MaxWalkSpeed = NormalSpeed;

		}

	}
}

int32 AMyCharacter::GetHealth() const
{
	return Health;
}

void AMyCharacter::AddHealth(float Amount) //회복
{
	Health = FMath::Clamp(Health + Amount, 0.0f, MaxHealth);
	UpDateOverheadHP();

}


void AMyCharacter::SpeedDown() //스피드 다운 
{
	if (GetCharacterMovement())
	{
		GetCharacterMovement()->MaxWalkSpeed = PenguinSpeedDown;
		SpeedD = true;
	}

	GetWorldTimerManager().SetTimer(
		SpeedDownTimerHandle,
		this,
		&AMyCharacter::ResetSpeed,
		SpeedDuration,
		false
	);
}

void AMyCharacter::ResetSpeed()
{
	if (GetCharacterMovement())
	{
		GetCharacterMovement()->MaxWalkSpeed = NormalSpeed;
		SpeedD = false;
	}
}




float AMyCharacter::TakeDamage(
	float DamageAmount,
	struct FDamageEvent const& DamageEvent,
	AController* EventInstigator,
	AActor* DamageCauser)
{
	float ActualDamage =  Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser); //방어력 포함 데미지

	Health = FMath::Clamp(Health - DamageAmount, 0.0f, MaxHealth);
	UpDateOverheadHP();
	
	if (Health <= 0.0f)
	{
		OnDeath();
	}
	return ActualDamage;
}

void AMyCharacter::OnDeath()
{
	AAnimalGameState* AnimalGameState = GetWorld() ? GetWorld()->GetGameState<AAnimalGameState>() : nullptr;
	if (AnimalGameState)
	{
		AnimalGameState->OnGameOver();
	}
}

void AMyCharacter::UpDateOverheadHP()
{
	if (!OverheadWidget) return;

	UUserWidget* OverheadWidgetInstance = OverheadWidget->GetUserWidgetObject();
	if (!OverheadWidgetInstance) return;

	if (UTextBlock* HPText = Cast<UTextBlock>(OverheadWidgetInstance->GetWidgetFromName(TEXT("OverHeadHP"))))
	{
		HPText->SetText(FText::FromString(FString::Printf(TEXT("HP : %.0f"), Health)));
	}
}
