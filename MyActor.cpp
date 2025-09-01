// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "CoreMinimal.h"
#include <iostream>

void PrintFVector2DArray()
{
    // FVector2D 배열 생성
    TArray<FVector2D> VectorArray;
    int32_t step();
    void TriggerEventWithProbability(int Probability);


    VectorArray.Add(FVector2D(0, 0)); // 처음 시작위치

    // 데이터 추가
    for (int32 i = 1; i < 10; i++)
    {

        FVector2D Location = VectorArray[i - 1]; // 이전위치
        

        int32 LocationX = Location.X + step(); // 이전좌표 + 랜덤 숫자 X
        int32 LocationY = Location.Y + step(); // 이전좌표 + 랜덤 숫자 X

        VectorArray.Add(FVector2D(LocationX, LocationY));
       

    }


    // 데이터 출력
    for (int32 i = 0; i < VectorArray.Num(); i++)
    {
        const FVector2D& Vec = VectorArray[i];
        UE_LOG(LogTemp, Warning, TEXT("%d Move: X = %f, Y = %f"), i, Vec.X, Vec.Y);
        TriggerEventWithProbability(50); //50퍼센트 확률로 발생
    }


}

int32_t step()// 0 ~ 1까지 숫자중 랜덤으로 반환
{
    int32 RandomValue = FMath::RandRange(0, 1); 
    (RandomValue == 0)? -1 : 1; // 0이라면 -1칸 1이라면 +1칸
    return RandomValue;
}

// 메인 함수 또는 다른 위치에서 호출
void SomeFunction()
{
    PrintFVector2DArray();
}

//10회 이동시 각 스텝마다 이전 좌표기준 이동거리계산해서 출력
float distance(FVector first, FVector second) // 두 좌표간 거리구하기
{
    float dx = first.X - second.X; // X 거리
    float dy = first.Y - second.Y; // Y 거리
    return FMath::Sqrt(dx * dx + dy * dy);
}


void TriggerEventWithProbability(int Probability) //특정 확률로 이벤트 발생시키기
{
    int32 RandomValue = FMath::RandRange(1, 100); // 1 ~ 100의 난수 생성
    if (RandomValue <= Probability)
    {
        UE_LOG(LogTemp, Error, TEXT("Bang!!")); // 해당 조건에 맞는다면 Bang!! TEXT를 출력한다
    }

}



// Sets default values
AMyActor::AMyActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay() // 시작하자마자
{
    Super::BeginPlay();
    SomeFunction(); // x,y값 출력

}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

