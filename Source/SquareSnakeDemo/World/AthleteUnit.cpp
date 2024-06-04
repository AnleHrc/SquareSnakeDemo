// Fill out your copyright notice in the Description page of Project Settings.


#include "AthleteUnit.h"
#include "SS_WorldUtils.h"


// Sets default values
AAthleteUnit::AAthleteUnit()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	Origin = CreateDefaultSubobject<USceneComponent>("Origin");
	check(Origin);
	SetRootComponent(Origin);

	UnitMesh = CreateDefaultSubobject<UStaticMeshComponent>("UnitMesh");
	check(UnitMesh);
	UnitMesh->SetupAttachment(Origin);
}

void AAthleteUnit::SetModel(uint32 InCellSize)
{
	SquareSnakeDemo::WorldUtils::ScaleMesh(UnitMesh, InCellSize);
}
