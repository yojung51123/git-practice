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
	
	GetWorld()->GetTimerManager().SetTimer( // 스폰
		SpawnTimerHandle, //변수 
		this,// 나 자신
		&ATimer::SpawnActors, // 호출할 클래스 멤버함수
		0.7f, // 반복주기
		true // 반복여부
	);

	GetWorld()->GetTimerManager().SetTimer( // 삭제 30초 마다
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
