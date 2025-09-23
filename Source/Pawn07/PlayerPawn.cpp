#include "PlayerPawn.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "MyPlayerController.h"

APlayerPawn::APlayerPawn()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("SceneRoot")); //�浹������Ʈ
	SetRootComponent(CapsuleComp);
    CapsuleComp->SetSimulatePhysics(false);

	SkeletalMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("StaticMesh"));
	SkeletalMeshComp->SetupAttachment(CapsuleComp);
    SkeletalMeshComp->SetSimulatePhysics(false);


	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComp->SetupAttachment(CapsuleComp);
	SpringArmComp->TargetArmLength = 300.0f; // SpringArm ����
	SpringArmComp->bUsePawnControlRotation = true; // ��Ʈ�ѷ� ȸ�������� ���� ȸ�� 
    

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName); // SpringArm���� ���� 
	CameraComp->bUsePawnControlRotation = false;

    MoveSpeed = 600.0f; // �̵��ӵ�
    TurnSpeed = 100.0f; // ȸ���ӵ�
}

void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Enhanced InputComponent�� ĳ����
    if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        // IA�� �������� ���� ���� ���� ���� Controller�� AMyPlayerController�� ĳ����
        if (AMyPlayerController* PlayerController = Cast<AMyPlayerController>(GetController()))
        {
            if (PlayerController->MoveAction)
            {
                // IA_Move �׼� Ű�� "Ű�� ������ �ִ� ����" Move() ȣ��
                EnhancedInput->BindAction(
                    PlayerController->MoveAction,
                    ETriggerEvent::Triggered,
                    this,
                    &APlayerPawn::Move
                );
            }

            if (PlayerController->LookAction)
            {
                // IA_Look �׼� ���콺�� "������ ��" Look() ȣ��
                EnhancedInput->BindAction(
                    PlayerController->LookAction,
                    ETriggerEvent::Triggered,
                    this,
                    &APlayerPawn::Look
                );
            }
        }
    }
}

void APlayerPawn::Move(const FInputActionValue& value)
{
    if (!Controller) return;
    const FVector2D MoveInput = value.Get<FVector2D>();

    if (!FMath::IsNearlyZero(MoveInput.X))
    {
        //�̵����� * �Է� * �̵��ӵ� * ��ŸŸ��     
        AddActorLocalOffset(FVector(MoveInput.X,0,0) * MoveSpeed * GetWorld()->GetDeltaSeconds());
            
    }

    if (!FMath::IsNearlyZero(MoveInput.Y))
    {
        //�̵����� * �Է� * �̵��ӵ� * ��ŸŸ��     
        AddActorLocalOffset(FVector(0,MoveInput.Y, 0) * MoveSpeed * GetWorld()->GetDeltaSeconds());

    }

}

void APlayerPawn::Look(const FInputActionValue& value)
{
    FVector2D LookInput = value.Get<FVector2D>();

    if (!FMath::IsNearlyZero(LookInput.X)) //Z�� �߽����� �¿�ȸ�� ok
    {
        AddActorLocalRotation(FRotator(0.0f, TurnSpeed * LookInput.X * GetWorld()->GetDeltaSeconds(), 0.0f));
    }


    if (!FMath::IsNearlyZero(LookInput.Y)) // Y�� �߽����� ���� ȸ�� SpringArm�� ��ġ�� �����δ�
    {
        FRotator ArmRot = SpringArmComp->GetRelativeRotation();
        ArmRot.Pitch = FMath::Clamp(ArmRot.Pitch + (-LookInput.Y) * TurnSpeed * GetWorld()->GetDeltaSeconds(), -60.f, 60.f);
        SpringArmComp->SetRelativeRotation(ArmRot);
    }
 
}
//AddActorLocalRotation( Y,  Z,  X )


void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}


void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}




