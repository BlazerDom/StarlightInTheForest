// Fill out your copyright notice in the Description page of Project Settings.


#include "AIControllerExtend.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

AAIControllerExtend::AAIControllerExtend()
{
	perceptionComp = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PerceptionComp"));
	sightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("sightConfig"));

	if (perceptionComp && sightConfig)
	{
		perceptionComp->ConfigureSense(*sightConfig);
		perceptionComp->SetDominantSense(sightConfig->GetSenseImplementation());

		sightConfig->SightRadius = 2000.f;
		sightConfig->LoseSightRadius = 2200.f;
		sightConfig->PeripheralVisionAngleDegrees = 90.f;

		sightConfig->DetectionByAffiliation.bDetectNeutrals = true;
		sightConfig->DetectionByAffiliation.bDetectEnemies = true;
		sightConfig->DetectionByAffiliation.bDetectFriendlies = true;	
	}
}