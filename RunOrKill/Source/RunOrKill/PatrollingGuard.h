// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "PatrollingGuard.generated.h"

/**
 *
 */
UCLASS()
class RUNORKILL_API APatrollingGuard : public ATP_ThirdPersonCharacter
{
	GENERATED_BODY()

public:

	TArray<AActor*> GetPatrolPoints();


private:
	UPROPERTY(EditInstanceOnly, Category = "Patrol Points")
		TArray<AActor*> PatrolPoints;

};
