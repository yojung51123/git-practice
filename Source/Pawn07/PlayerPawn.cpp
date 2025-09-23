#include "PlayerPawn.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "MyPlayerController.h"

APlayerPawn::APlayerPawn()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("SceneRoot")); //충돌컴포넌트
	SetRootComponent(CapsuleComp);
    CapsuleComp->SetSimulatePhysics(false);

	SkeletalMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("StaticMesh"));
	SkeletalMeshComp->SetupAttachment(CapsuleComp);
    SkeletalMeshComp->SetSimulatePhysics(false);


	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComp->SetupAttachment(CapsuleComp);
	SpringArmComp->TargetArmLength = 300.0f; // SpringArm 길이
	SpringArmComp->bUsePawnControlRotation = true; // 컨트롤러 회전에따라 같이 회전 
    

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName); // SpringArm끝에 부착 
	CameraComp->bUsePawnControlRotation = false;

    MoveSpeed = 600.0f; // 이동속도
    TurnSpeed = 100.0f; // 회전속도
}

void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Enhanced InputComponent로 캐스팅
    if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        // IA를 가져오기 위해 현재 소유 중인 Controller를 AMyPlayerController로 캐스팅
        if (AMyPlayerController* PlayerController = Cast<AMyPlayerController>(GetController()))
        {
            if (PlayerController->MoveAction)
            {
                // IA_Move 액션 키를 "키를 누르고 있는 동안" Move() 호출
                EnhancedInput->BindAction(
                    PlayerController->MoveAction,
                    ETriggerEvent::Triggered,
                    this,
                    &APlayerPawn::Move
                );
            }

            if (PlayerController->LookAction)
            {
                // IA_Look 액션 마우스가 "움직일 때" Look() 호출
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
        //이동방향 * 입력 * 이동속도 * 델타타임     
        AddActorLocalOffset(FVector(MoveInput.X,0,0) * MoveSpeed * GetWorld()->GetDeltaSeconds());
            
    }

    if (!FMath::IsNearlyZero(MoveInput.Y))
    {
        //이동방향 * 입력 * 이동속도 * 델타타임     
        AddActorLocalOffset(FVector(0,MoveInput.Y, 0) * MoveSpeed * GetWorld()->GetDeltaSeconds());

    }

}

void APlayerPawn::Look(const FInputActionValue& value)
{
    FVector2D LookInput = value.Get<FVector2D>();

    if (!FMath::IsNearlyZero(LookInput.X)) //Z축 중심으로 좌우회전 ok
    {
        AddActorLocalRotation(FRotator(0.0f, TurnSpeed * LookInput.X * GetWorld()->GetDeltaSeconds(), 0.0f));
    }


    if (!FMath::IsNearlyZero(LookInput.Y)) // Y축 중심으로 상하 회전 SpringArm의 위치로 움직인다
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




