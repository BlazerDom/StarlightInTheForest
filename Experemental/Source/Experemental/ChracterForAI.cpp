// Fill out your copyright notice in the Description page of Project Settings.


#include "ChracterForAI.h"

// Sets default values
AChracterForAI::AChracterForAI()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AChracterForAI::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AChracterForAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AChracterForAI::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AChracterForAI::GetActorEyesViewPoint(FVector & Location, FRotator & Rotation) const
{
	GetPerceptionLocRot(Location, Rotation);
}

void AChracterForAI::GetPerceptionLocRot_Implementation(FVector & OutLocation, FRotator & OutRotation) const
{
	OutLocation = GetActorLocation() + FVector(0, 0, 50);
	OutRotation = GetActorRotation();
}