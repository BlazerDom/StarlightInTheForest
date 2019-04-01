// Fill out your copyright notice in the Description page of Project Settings.

#include "MagicLevelScriptActor.h"

AMagicLevelScriptActor::AMagicLevelScriptActor()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AMagicLevelScriptActor::Tick(float DeltaTime)
{

}

void AMagicLevelScriptActor::CastRhune(class AMagePawn* pawn, int rhune)
{
    auto& castingSpellPtr = m_CastingSpells.FindOrAdd(pawn);
    castingSpellPtr.AppendChar((TCHAR)rhune);
}