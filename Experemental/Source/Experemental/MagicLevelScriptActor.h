// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "MagicLevelScriptActor.generated.h"

/**
 * 
 */
UCLASS()
class EXPEREMENTAL_API AMagicLevelScriptActor : public ALevelScriptActor
{
    GENERATED_BODY()
    
public:
    AMagicLevelScriptActor();

public:
    void Tick(float DeltaTime) override;

    UFUNCTION(BlueprintCallable)
    void CastRhune(class AMagePawn* pawn, int rhune);

private:
    TMap<class AMagePawn*, FString> m_CastingSpells;
};
