// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SquareSnakeDemo/Core/Grid.h"
#include "SquareSnakeDemo/Core/Game.h"
#include "SquareSnakeDemo/World/SS_Grid.h"
#include "PlayerGameModeBase.generated.h"

/**
 * 
 */

/*class AGameSession;
class AGameStateBase;
class AHUD;
class APlayerState;
class ASpectatorPawn;
class UNetConnection;
class UPlayer;*/
class ASS_Grid;
class AExponentialHeightFog;
class ASS_Athlete;

//UCLASS(Config = Game,Meta = (ShortTooltip = "The base game mode class used by this project."))
UCLASS()

class APlayerGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

	//APlayerGameModeBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	APlayerGameModeBase();
	
	virtual void StartPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	
protected:
	UPROPERTY(EditDefaultsOnly,meta = (ClampMin = "10", ClampMax = "100"), Category=Settings)
	FUintPoint GridDim{20,10};

	UPROPERTY(EditDefaultsOnly,meta = (ClampMin = "10", ClampMax = "100"), Category=Settings)
	uint32 CellSize{20};

	/*UPROPERTY(EditDefaultsOnly,meta = (ClampMin = "4", ClampMax = "10"), Category=Settings)
	uint32 AltheteSize{5};*/
	
	UPROPERTY(EditDefaultsOnly, Category=Design)
	TObjectPtr<UDataTable> AthleteColorsTable;

	UPROPERTY(EditDefaultsOnly, Category=Design)
	TSubclassOf<ASS_Grid> GridVisualClass;

	UPROPERTY(EditDefaultsOnly, Category=Design)
	TSubclassOf<ASS_Athlete> AthleteVisualClass;
	
private:
	SquareSnakeDemo::Settings MakeSettings() const;
	void FindFog();
	void UpdateColors();
	TSharedPtr<SquareSnakeDemo::Game> Game;
	uint32 CurrentColorIndex {0};
	TObjectPtr<ASS_Grid> GridVisual;
	TObjectPtr<ASS_Athlete> AthleteVisual;
	//需要先声明 AExponentialHeightFog 类
	AExponentialHeightFog* Fog;
	
};
