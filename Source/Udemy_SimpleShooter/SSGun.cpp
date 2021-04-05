// Fill out your copyright notice in the Description page of Project Settings.


#include "SSGun.h"


#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ASSGun::ASSGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("GunMesh"));
	Mesh->SetupAttachment(Root);

}

// Called when the game starts or when spawned
void ASSGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASSGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASSGun::PullTrigger()
{
	UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, Mesh, TEXT("MuzzleFlashSocket"));

	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if(!OwnerPawn) return;
	AController* OwnerController = OwnerPawn->GetController();
	if(!OwnerController) return;

	FVector ViewLocation;
	FRotator ViewRotation;
	OwnerController->GetPlayerViewPoint(ViewLocation, ViewRotation);

	DrawDebugCamera(GetWorld(), ViewLocation, ViewRotation, 90, 2, FColor::Red, true);
	
	UE_LOG(LogTemp, Warning, TEXT("Shoot!"));
}

