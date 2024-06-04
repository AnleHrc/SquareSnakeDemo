// Fill out your copyright notice in the Description page of Project Settings.


#include "SSCharcterBase.h"

#include "Camera/CameraComponent.h"
#include "Chaos/ClusterUnionManager.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"


static FName NAME_SSCharacterCollisionProfile_Capsule(TEXT("SSPawnCapsule"));
static FName NAME_SSCharacterCollisionProfile_Mesh(TEXT("SSPawnMesh"));
// Sets default values

ASSCharcterBase::ASSCharcterBase(const FObjectInitializer& ObjectInitializer)
{
	// Avoid ticking characters if possible.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;


	UCapsuleComponent* CapsuleComp = GetCapsuleComponent();
	check(CapsuleComp);
	CapsuleComp->InitCapsuleSize(40.0f,90.0f);
	CapsuleComp->SetCollisionProfileName(NAME_SSCharacterCollisionProfile_Capsule);
	
	USkeletalMeshComponent* MeshComp = GetMesh();
	check(MeshComp);
	MeshComp->SetRelativeRotation(FRotator(0.0f,-90.0f,0.0f));
	MeshComp->SetCollisionProfileName(NAME_SSCharacterCollisionProfile_Mesh);

	GrowthBody = CreateDefaultSubobject<USkeletalMeshComponent>(FName("GrowthBody"));

	FVector GrowthBodyScale(1.0f, BodyScale, 1.0f);
	
	GrowthBody->SetRelativeScale3D(GrowthBodyScale);
	
	GrowthBody->SetupAttachment(MeshComp);
	



	//Init character movement
	
	
	PlayerSpringArmComp = CreateDefaultSubobject<USpringArmComponent>(FName("PlayerSpringArm"));
	PlayerSpringArmComp->SetupAttachment(RootComponent);
	PlayerSpringArmComp->SetRelativeLocation(FVector(0.0f,0.0f,3200.0f));
	PlayerSpringArmComp->SetRelativeRotation(FRotator(-90.0f,180.0f,-90.0f));
	
	PlayerCameraBoom = CreateDefaultSubobject<UCameraComponent>(FName("PlayerCamera"));
	PlayerCameraBoom->SetupAttachment(PlayerSpringArmComp);

	

	
	
}

// Called when the game starts or when spawned
void ASSCharcterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASSCharcterBase::Action_SSCBForwardMove(const FInputActionValue& value)
{
	//GEngine->AddOnScreenDebugMessage(-1,5.0f,FColor::Blue,FString::Printf(TEXT("This is Forward")));
	//Get ControllerRotation and ForawdVector
	
	AddMovementInput(UKismetMathLibrary::GetForwardVector(GetControlRotation()),value.Get<float>(),false);
	
	
}

void ASSCharcterBase::Action_SSCBRightMove(const FInputActionValue& value)
{
	//GEngine->AddOnScreenDebugMessage(-1,5.0f,FColor::Red,FString::Printf(TEXT("This is Right")));
	//Get ControllerRotation RightVector
	UKismetMathLibrary::GetForwardVector(GetControlRotation());
	AddMovementInput(UKismetMathLibrary::GetRightVector(GetControlRotation()),value.Get<float>(),false);
}

// Called every frame
void ASSCharcterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ASSCharcterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Enhanced Input
	/*UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	Input->BindAction(AimingInputAction, ETriggerEvent::Triggered, this, &AFooBar::SomeCallbackFunc);*/

	if (APlayerController* PlayerController = CastChecked<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* EnhancedInputLocalPS = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			EnhancedInputLocalPS->AddMappingContext(InputMappingContext,0);
			
		}
	}
	if (UEnhancedInputComponent* EnhancedInputComp = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComp->BindAction(SSCBForwardMove,ETriggerEvent::Triggered,this,&ASSCharcterBase::Action_SSCBForwardMove);
		EnhancedInputComp->BindAction(SSCBRightMove,ETriggerEvent::Triggered,this,&ASSCharcterBase::Action_SSCBRightMove);
	}
	
}

