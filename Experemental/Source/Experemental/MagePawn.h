// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MagePawn.generated.h"

UCLASS()
class EXPEREMENTAL_API AMagePawn : public APawn
{
    GENERATED_BODY()

public:
    // Sets default values for this pawn's properties
    AMagePawn();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:	
    // Called every framevirtual
     void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
    
};
