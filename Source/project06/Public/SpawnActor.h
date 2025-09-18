
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnActor.generated.h"

UCLASS()
class PROJECT06_API ASpawnActor : public AActor //소환 액터
{
	GENERATED_BODY()
	
	// SpawnActor클래스에서  만들어보기로 하고 일정 시간이 지나면 리셋이 생성된 
	// 에셋을 지우게 만들어야겠다

public:	
	ASpawnActor();

	virtual void Tick(float DeltaTime) override;
	
protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnActor")
	class USphereComponent* SphereComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnActor")
	UStaticMeshComponent* StaticMeshComp;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnActor")
	class UParticleSystemComponent* ParticleComp;
	
	

	virtual void BeginPlay() override;

	

};
