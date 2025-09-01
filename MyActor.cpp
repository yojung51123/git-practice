// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "CoreMinimal.h"
#include <iostream>

void PrintFVector2DArray()
{
    // FVector2D �迭 ����
    TArray<FVector2D> VectorArray;
    int32_t step();
    void TriggerEventWithProbability(int Probability);


    VectorArray.Add(FVector2D(0, 0)); // ó�� ������ġ

    // ������ �߰�
    for (int32 i = 1; i < 10; i++)
    {

        FVector2D Location = VectorArray[i - 1]; // ������ġ
        

        int32 LocationX = Location.X + step(); // ������ǥ + ���� ���� X
        int32 LocationY = Location.Y + step(); // ������ǥ + ���� ���� X

        VectorArray.Add(FVector2D(LocationX, LocationY));
       

    }


    // ������ ���
    for (int32 i = 0; i < VectorArray.Num(); i++)
    {
        const FVector2D& Vec = VectorArray[i];
        UE_LOG(LogTemp, Warning, TEXT("%d Move: X = %f, Y = %f"), i, Vec.X, Vec.Y);
        TriggerEventWithProbability(50); //50�ۼ�Ʈ Ȯ���� �߻�
    }


}

int32_t step()// 0 ~ 1���� ������ �������� ��ȯ
{
    int32 RandomValue = FMath::RandRange(0, 1); 
    (RandomValue == 0)? -1 : 1; // 0�̶�� -1ĭ 1�̶�� +1ĭ
    return RandomValue;
}

// ���� �Լ� �Ǵ� �ٸ� ��ġ���� ȣ��
void SomeFunction()
{
    PrintFVector2DArray();
}

//10ȸ �̵��� �� ���ܸ��� ���� ��ǥ���� �̵��Ÿ�����ؼ� ���
float distance(FVector first, FVector second) // �� ��ǥ�� �Ÿ����ϱ�
{
    float dx = first.X - second.X; // X �Ÿ�
    float dy = first.Y - second.Y; // Y �Ÿ�
    return FMath::Sqrt(dx * dx + dy * dy);
}


void TriggerEventWithProbability(int Probability) //Ư�� Ȯ���� �̺�Ʈ �߻���Ű��
{
    int32 RandomValue = FMath::RandRange(1, 100); // 1 ~ 100�� ���� ����
    if (RandomValue <= Probability)
    {
        UE_LOG(LogTemp, Error, TEXT("Bang!!")); // �ش� ���ǿ� �´´ٸ� Bang!! TEXT�� ����Ѵ�
    }

}



// Sets default values
AMyActor::AMyActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay() // �������ڸ���
{
    Super::BeginPlay();
    SomeFunction(); // x,y�� ���

}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

