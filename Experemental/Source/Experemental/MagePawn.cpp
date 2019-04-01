// Fill out your copyright notice in the Description page of Project Settings.

#include "MagePawn.h"

// Sets default values
AMagePawn::AMagePawn()
{
    PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMagePawn::BeginPlay()
{
    Super::BeginPlay();
    
}

// Called every frame
void AMagePawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMagePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

}

