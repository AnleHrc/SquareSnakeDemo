// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Pawn.h"
#include "PlayerCharacterBase.generated.h"

UCLASS()
class SQUARESNAKEDEMO_API APlayerCharacterBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerCharacterBase(const FObjectInitializer& ObjectInitializer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintReadOnly,VisibleAnywhere,Category = "PlayerCharacterBase")
	UCameraComponent* PlayerCameraBoom;

	UPROPERTY(BlueprintReadOnly,VisibleAnywhere,Category = "PlayerCharacterBase")
	UArrowComponent* ArrowComponent;

	UPROPERTY(BlueprintReadOnly,VisibleAnywhere,Category = "PlayerCharacterBase")
	UCapsuleComponent* CapsuleComponent;

	
private:
	



};
