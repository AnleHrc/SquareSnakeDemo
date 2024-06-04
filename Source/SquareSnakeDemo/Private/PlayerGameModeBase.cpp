// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerGameModeBase.h"


#include "PlayerControllerBase.h"
#include "../World/SS_Grid.h"
#include "SSCharcterBase.h"
#include "Components/ExponentialHeightFogComponent.h"
#include "Engine/ExponentialHeightFog.h"
#include "Kismet/GameplayStatics.h"
#include "SquareSnakeDemo/Character/SS_Pawn.h"
#include "World/SS_Athlete.h"

APlayerGameModeBase::APlayerGameModeBase()
//APlayerGameModeBase::APlayerGameModeBase(const FObjectInitializer& ObjectInitializer) 
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// 这里需要设置为 true, 否则 Tick() 函数不生效，默认为false
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 1.f;
	//PlayerControllerClass = APlayerControllerBase::StaticClass();
	
	//DefaultPawnClass = ASSCharcterBase::StaticClass();
}

void APlayerGameModeBase::StartPlay()
{
	Super::StartPlay();

	//初始化游戏,调用Game.h
	Game  = MakeShared<SquareSnakeDemo::Game>(MakeSettings());

	const FTransform Origin = FTransform::Identity;

	// Init world
	check(GetWorld());
	GridVisual = GetWorld()->SpawnActorDeferred<ASS_Grid>(GridVisualClass, Origin);
	GridVisual->SetModel(Game->grid(), CellSize);
	GridVisual->FinishSpawning(Origin);

	AthleteVisual = GetWorld()->SpawnActorDeferred<ASS_Athlete>(AthleteVisualClass, Origin);
	AthleteVisual->SetModel(Game->athlete(), CellSize, Game->grid()->dim());
	AthleteVisual->FinishSpawning(Origin);

	//更新角色的位置
	auto* PC = GetWorld()->GetFirstPlayerController();
	check(PC);
	ASS_Pawn* Pawn = Cast<ASS_Pawn>(PC->GetPawn());
	check(Pawn);
	Pawn->UpdateLocation(Game->grid()->dim(), CellSize, Origin);

	//Get Fog
	FindFog();
	//Update colors
	check(AthleteColorsTable->GetRowNames().Num() > 0);

	CurrentColorIndex = FMath::RandRange(0, AthleteColorsTable->GetRowNames().Num() - 1);

	UpdateColors();
}

void APlayerGameModeBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f,FColor::Red, TEXT("GameMode Tick"));
	if (Game) Game->update(DeltaSeconds);

}

//设置生成的网格大小
SquareSnakeDemo::Settings APlayerGameModeBase::MakeSettings() const
{
	using namespace SquareSnakeDemo;
	Settings GS;
	GS.dim = Dim(GridDim.X,GridDim.Y);
	GS.athlete.startPos = Grid::center(GS.dim);
	//GS.athlete.initSize = AltheteSize;
	// 贪吃蛇的起始位置
	//GS.athlete.startPos = SquareSnakeDemo::Position{4,0};
	return GS;
}

void APlayerGameModeBase::FindFog()
{
	TArray<AActor*> Fogs;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),AExponentialHeightFog::StaticClass(),Fogs);

	if (Fogs.Num() > 0)
	{
		Fog = Cast<AExponentialHeightFog>(Fogs[0]);
	}
}

void APlayerGameModeBase::UpdateColors()
{
	FAthleteColors* FoundRow = AthleteColorsTable->FindRow<FAthleteColors>(AthleteColorsTable->GetRowNames()[CurrentColorIndex], {});

	GridVisual->UpdateColors(*FoundRow);

	if (Fog)
	{
		Fog->GetComponent()->SetFogInscatteringColor(FoundRow->FogColor);
	}
}
