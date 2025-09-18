
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingPlatform.generated.h"

UCLASS()
class PROJECT06_API ARotatingPlatform : public AActor // È¸Àü ÇÃ·§Æû 
{
	GENERATED_BODY()
	
public:	
	
	ARotatingPlatform();

	virtual void Tick(float DeltaTime) override;

protected:
	
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "RotationPlatform")
	float RotationSpeed; // È¸Àü
	
	virtual void BeginPlay() override;

	USceneComponent* SceneRoot;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "StaticMesh")
	UStaticMeshComponent* StaticMeshComp;


	

};
