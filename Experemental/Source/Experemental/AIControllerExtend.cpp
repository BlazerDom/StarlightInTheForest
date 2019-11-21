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

		sightConfig->SightRadius = 1000.f;
		sightConfig->LoseSightRadius = 1200.f;
		sightConfig->PeripheralVisionAngleDegrees = 85.f;

		sightConfig->DetectionByAffiliation.bDetectNeutrals = false;
		sightConfig->DetectionByAffiliation.bDetectEnemies = true;
		sightConfig->DetectionByAffiliation.bDetectFriendlies = false;	
	}
}


ETeamAttitude::Type AAIControllerExtend::GetTeamAttitudeTowards(const AActor& Other) const
{

	if (const APawn* OtherPawn = Cast<APawn>(&Other)) {

		// DEFAULT BEHAVIOR---------------------------------------------------
		if (const IGenericTeamAgentInterface* TeamAgent = Cast<IGenericTeamAgentInterface>(OtherPawn->GetController()))
		{
			return Super::GetTeamAttitudeTowards(*OtherPawn->GetController());
		}

		//OR CUSTOM BEHAVIOUR--------------------------------------------------
		if (const IGenericTeamAgentInterface* TeamAgent = Cast<IGenericTeamAgentInterface>(OtherPawn->GetController()))
		{
			//Create an alliance with Team with ID 10 and set all the other teams as Hostiles:
			FGenericTeamId OtherTeamID = TeamAgent->GetGenericTeamId();
			if (OtherTeamID == GetGenericTeamId()) {
				return ETeamAttitude::Friendly;
			}
			else {
				return ETeamAttitude::Hostile;
			}
		}
	}

	return ETeamAttitude::Neutral;
}
