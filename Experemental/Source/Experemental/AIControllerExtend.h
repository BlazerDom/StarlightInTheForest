// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIControllerExtend.generated.h"

/**
 * 
 */
UCLASS()
class EXPEREMENTAL_API AAIControllerExtend : public AAIController
{
	GENERATED_BODY()
	

public:

	AAIControllerExtend();

	UPROPERTY(VisibleAnywhere, Category = "Perception")
		class UAIPerceptionComponent * perceptionComp;

	UPROPERTY(EditDefaultsOnly, Category = "Perception")
		class UAISenseConfig_Sight * sightConfig;
};

