#include "Timer.h"
#include "SpawnActor.h"
#include "FireSpawner.h"
#include "Kismet/GameplayStatics.h"


ATimer::ATimer()
{
 	
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);


}


void ATimer::BeginPlay() 
{
	Super::BeginPlay();
	
	GetWorld()->GetTimerManager().SetTimer( // ����
		SpawnTimerHandle, //���� 
		this,// �� �ڽ�
		&ATimer::SpawnActors, // ȣ���� Ŭ���� ����Լ�
		0.7f, // �ݺ��ֱ�
		true // �ݺ�����
	);

	GetWorld()->GetTimerManager().SetTimer( // ���� 30�� ����
		DestoryTimerHandle,
		this,
		&ATimer::DestroyActors,
		30.0f,
		true
	);
}


void ATimer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ATimer::SpawnActors()
{
	AActor* SpawnActor = UGameplayStatics::GetActorOfClass(GetWorld(), AFireSpawner::StaticClass());
	AFireSpawner* SpawnerRef = Cast<AFireSpawner>(SpawnActor);
	
	if (SpawnerRef)
	{
		SpawnerRef->SpawnActor();
	}
}

void ATimer::DestroyActors()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnActor::StaticClass(), FoundActors);

	for (AActor* Actor : FoundActors)
	{
		Actor->Destroy();
	}
	
}
