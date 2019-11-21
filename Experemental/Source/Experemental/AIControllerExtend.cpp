// Fill out your copyright notice in the Description page of Project Settings.


#include "AIControllerExtend.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISenseConfig_Hearing.h"

AAIControllerExtend::AAIControllerExtend()
{
	SetGenericTeamId(FGenericTeamId(5));
	perceptionComp = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PerceptionComp"));
	sightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("sightConfig"));
	hearingConfig = CreateDefaultSubobject<UAISenseConfig_Hearing>(TEXT("hearingConfig"));

	if (perceptionComp && sightConfig, perceptionComp && hearingConfig)
	{
		perceptionComp->ConfigureSense(*hearingConfig);
		perceptionComp->ConfigureSense(*sightConfig);
		perceptionComp->SetDominantSense(sightConfig->GetSenseImplementation());

		sightConfig->SightRadius = 1000.f;
		sightConfig->LoseSightRadius = 1200.f;
		sightConfig->PeripheralVisionAngleDegrees = 85.f;

		sightConfig->DetectionByAffiliation.bDetectNeutrals = false;
		sightConfig->DetectionByAffiliation.bDetectEnemies = true;
		sightConfig->DetectionByAffiliation.bDetectFriendlies = false;

		hearingConfig->HearingRange = 1400.f;

		hearingConfig->DetectionByAffiliation.bDetectNeutrals = false;
		hearingConfig->DetectionByAffiliation.bDetectEnemies = true;
		hearingConfig->DetectionByAffiliation.bDetectNeutrals = false;
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
			if (OtherTeamID == 10) {
				return ETeamAttitude::Neutral;
			}
			else {
				return ETeamAttitude::Hostile;
			}
		}
	}

	return ETeamAttitude::Neutral;
}
