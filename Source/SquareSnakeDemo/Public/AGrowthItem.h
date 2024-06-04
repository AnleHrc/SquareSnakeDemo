// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "AGrowthItem.generated.h"

UCLASS()
class SQUARESNAKEDEMO_API AAGrowthItem : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAGrowthItem();
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION() // 反射？
	void GrowthBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
    UFUNCTION()
	void GrowthEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Category = "GrowthItem")
	class USkeletalMeshComponent* GrowthItem;

	UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Category= "GrowthItem")
	UBoxComponent* BoxCollision;

};
