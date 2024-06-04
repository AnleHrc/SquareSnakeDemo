// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterBase.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"


//static FName NAME_PlayerCharacterCollisionProfile_Capsule(TEXT("PlayerPawnCapsule"));
//static FName NAME_PlayerCharacterCollisionProfile_Mesh(TEXT("PlayerPawnMesh"));

APlayerCharacterBase::APlayerCharacterBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(FName("PlayerCapsule"));
	//check(CapsuleComponent);
	CapsuleComponent->SetupAttachment(RootComponent);
	CapsuleComponent->InitCapsuleSize(40.0f, 90.0f);
	//CapsuleComponent->SetCollisionProfileName(NAME_PlayerCharacterCollisionProfile_Capsule);
	
	ArrowComponent = CreateDefaultSubobject<UArrowComponent>(FName("PlayerArrowView"));
	ArrowComponent->SetupAttachment(CapsuleComponent);
	ArrowComponent->SetRelativeLocation(FVector(0.0f,-90.0f,0.0f));
	
	
	PlayerCameraBoom = CreateDefaultSubobject<UCameraComponent>(FName("PlayerCamera"));
	//PlayerCameraBoom->SetupAttachment(ArrowComponent);
	PlayerCameraBoom->SetRelativeLocation(FVector(0.0f,-90.0f,0.0f));
	
	//CameraComponent->SetRelativeLocation(FVector(-300.0f,0.0f,75.0f));
	

	
	
}

/*// Sets default values
APlayerCharacterBase::APlayerCharacterBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}*/

// Called when the game starts or when spawned
void APlayerCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

