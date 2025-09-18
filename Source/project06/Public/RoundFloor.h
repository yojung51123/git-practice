
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RoundFloor.generated.h"

UCLASS()
class PROJECT06_API ARoundFloor : public AActor
{
	GENERATED_BODY()
	
public:	

	ARoundFloor();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	USceneComponent* SceneRoot;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "RoundFloor")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "RoundFloor")
	FVector StartLocation;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "RoundFloor")
	FVector EndLocation;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "RoundFloor")
	FVector CurrentLocation;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "RoundFloor")
	float MovingSpeed;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "RoundFloor")
	bool Move = true;

};
