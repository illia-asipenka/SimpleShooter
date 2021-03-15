// Fill out your copyright notice in the Description page of Project Settings.


#include "SSCharacter.h"

// Sets default values
ASSCharacter::ASSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASSCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ASSCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &ASSCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ASSCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &ASSCharacter::LookRight);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
}

void ASSCharacter::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void ASSCharacter::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void ASSCharacter::LookUp(float AxisValue)
{
	AddControllerPitchInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}

void ASSCharacter::LookRight(float AxisValue)
{
	AddControllerYawInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}
