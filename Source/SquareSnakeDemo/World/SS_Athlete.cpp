// Fill out your copyright notice in the Description page of Project Settings.


#include "SS_Athlete.h"

#include "AthleteUnit.h"
#include "SS_WorldUtils.h"

DEFINE_LOG_CATEGORY_STATIC(Links,All,All)
// Sets default values
ASS_Athlete::ASS_Athlete()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called every frame
//为什么 前两节就可以动
void ASS_Athlete::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	auto* Link = Athlete->getLinks().GetHead();
	for (auto AthleteUnit:AthleteUnits)
	{
		if (!Link) // 检查Link是否为空
		{
			UE_LOG(LogTemp, Error, TEXT("Link is nullptr in Tick"));
			return;
		}
		
		// 排除是AthleteUnit为空还是 Athlete->getLinks().GetHead();的问题
		if (AthleteUnit)
		{
			// Assuming AAthleteUnit has a method GetName() or similar
			FString AthleteName = AthleteUnit->GetName();

			// Print to the output log
			UE_LOG(LogTemp, Log, TEXT("AthleteUnit: %s"), *AthleteName);

			// Optionally, print to the screen for debugging purposes
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Green, FString::Printf(TEXT("AthleteUnit: %s"), *AthleteName));
			}
		}
		
		AthleteUnit->SetActorLocation(SquareSnakeDemo::WorldUtils::PositionToVector(Link->GetValue(),CellSize,Dim));
		const auto& Value = Link->GetValue();
		// 假设 ElementType 是结构体，具有成员 X 和 Y
		UE_LOG(LogTemp, Log, TEXT("Tick Link Value: X: %d, Y: %d"), Value.x,Value.y);
		
		Link = Link->GetNextNode();
	}
	
}
void ASS_Athlete::SetModel(const TSharedPtr<SquareSnakeDemo::Athlete>& InAthlete, uint32 InCellSize,
	const SquareSnakeDemo::Dim& InDim)
{
	Athlete = InAthlete;
	CellSize = InCellSize;
	Dim = InDim;
	uint32 i = 0;
	auto* Link = Athlete->getLinks().GetHead();
	// 首先检查这里的Link 节点移动是否有问题
	while (Link) //这里每次都不为空
	{
		//0,1,2,3
		GEngine->AddOnScreenDebugMessage(-1,1.0f,FColor::Red,FString::Printf(TEXT("This is SetMode %d"),i));
		i++;
		FTransform Trans = FTransform(SquareSnakeDemo::WorldUtils::PositionToVector(Link->GetValue(),CellSize,Dim));
		TObjectPtr<AAthleteUnit> AthleteUnit = GetWorld()->SpawnActor<AAthleteUnit>(UnitClass,Trans);
		AthleteUnit->SetModel(CellSize);
		AthleteUnits.Add(AthleteUnit);
		Link = Link->GetNextNode();
	}
}


// Called when the game starts or when spawned
void ASS_Athlete::BeginPlay()
{
	Super::BeginPlay();
	
	
}
