
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnActor.generated.h"

UCLASS()
class PROJECT06_API ASpawnActor : public AActor //��ȯ ����
{
	GENERATED_BODY()
	
	// SpawnActorŬ��������  ������� �ϰ� ���� �ð��� ������ ������ ������ 
	// ������ ����� �����߰ڴ�

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
