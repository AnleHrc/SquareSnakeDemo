// Fill out your copyright notice in the Description page of Project Settings.


#include "AGrowthItem.h"

#include "SSCharcterBase.h"
#include "Camera/CameraComponent.h"
#include "ProfilingDebugging/BootProfiling.h"


// Sets default values
AAGrowthItem::AAGrowthItem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	GrowthItem = CreateDefaultSubobject<USkeletalMeshComponent>(FName("GrowthItem"));
	GrowthItem->SetupAttachment(RootComponent);
	
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(FName("BoxCollision"));
	BoxCollision->SetupAttachment(GrowthItem);


}

// Called when the game starts or when spawned
void AAGrowthItem::BeginPlay()
{
	Super::BeginPlay();

    // Add the created custom collision detection function to the box collision delegate variable
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this,&AAGrowthItem::GrowthBeginOverlap);
	// Add the created custom collision detection function to the box collision delegate variable
	BoxCollision->OnComponentEndOverlap.AddDynamic(this,&AAGrowthItem::GrowthEndOverlap);
	
	
}

void AAGrowthItem::GrowthBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (CastChecked<ASSCharcterBase>(OtherActor))
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.0f,FColor::Red,TEXT("This is SSCharacterBase"));
	}
	
}

void AAGrowthItem::GrowthEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (CastChecked<ASSCharcterBase>(OtherActor))
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.0f,FColor::Blue,TEXT("EndOverlap is SSCharacterBase"));
	}
	
}


// Called every frame
void AAGrowthItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

