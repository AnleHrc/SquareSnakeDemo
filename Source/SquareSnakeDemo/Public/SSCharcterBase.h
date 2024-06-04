// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "SSCharcterBase.generated.h"

UCLASS()
class SQUARESNAKEDEMO_API ASSCharcterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASSCharcterBase(const FObjectInitializer& ObjectInitializer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Input Action Function
	void Action_SSCBForwardMove(const FInputActionValue& value);
	
	void Action_SSCBRightMove(const FInputActionValue& value);
	

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintReadOnly,VisibleAnywhere,Category = "PlayerCharacterBase")
	class USpringArmComponent* PlayerSpringArmComp;
	
	UPROPERTY(BlueprintReadOnly,VisibleAnywhere,Category = "PlayerCharacterBase")
	class UCameraComponent* PlayerCameraBoom;

	UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Category = "GrowthItem")
	class USkeletalMeshComponent* GrowthBody;
	
	//UPROPERTY(BlueprintReadOnly,VisibleAnywhere,Category = "PlayerCharacterBase")
	//class UArrowComponent* PlayerArrowComponent;
    
	//UPROPERTY(BlueprintReadOnly,VisibleAnywhere,Category = "PlayerCharacterBase")
	//UCapsuleComponent* PlayerCapsuleComponent;

	//enhanced input Mapping Context
	UPROPERTY(EditAnywhere, Category="EnhancedInput")
	TObjectPtr<UInputMappingContext> InputMappingContext;

	UPROPERTY(EditAnywhere, Category="EnhancedInput|Basic")
	TObjectPtr<UInputAction> SSCBControllerYaw;
	
	UPROPERTY(EditAnywhere, Category="EnhancedInput|Basic")
	TObjectPtr<UInputAction> SSCBControllerPitch;
	
	UPROPERTY(EditAnywhere, Category="EnhancedInput|Basic")
	TObjectPtr<UInputAction> SSCBForwardMove;
	
	UPROPERTY(EditAnywhere, Category="EnhancedInput|Basic")
	TObjectPtr<UInputAction> SSCBRightMove;

	UPROPERTY(EditAnywhere,Category="PlayerCharacterBase|Body")
	float BodyScale=0.5f;

};
