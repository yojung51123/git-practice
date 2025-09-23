
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

class UCapsuleComponent;
class USpringArmComponent;
class UCameraComponent;

struct FInputActionValue;

UCLASS()
class PAWN07_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	
	APlayerPawn();

	
	virtual void Tick(float DeltaTime) override;

	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Pawn")
	UCapsuleComponent* CapsuleComp;

	UPROPERTY(EditAnywhere, Category = "Pawn")
	USkeletalMeshComponent* SkeletalMeshComp;

	UPROPERTY(EditAnywhere, Category = "Pawn")
	USpringArmComponent* SpringArmComp;
	
	UPROPERTY(EditAnywhere, Category = "Pawn")
	UCameraComponent* CameraComp;

	UPROPERTY(EditAnywhere, Category = "Move")
	float MoveSpeed;

	UPROPERTY(EditAnywhere, Category = "Move")
	float TurnSpeed;


	UFUNCTION()
	void Move(const FInputActionValue& value);
	
	UFUNCTION()
	void Look(const FInputActionValue& value);

	

	

	
};
