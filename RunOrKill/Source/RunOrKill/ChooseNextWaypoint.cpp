// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "Runtime/AIModule/Classes/Blueprint/AIBlueprintHelperLibrary.h"
#include "AIController.h"
#include "PatrollingGuard.h"
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	
	//TODO: Protect empty PatrolPoints

	//Get Patrol Points 
	auto AIController = OwnerComp.GetAIOwner();
	auto ControllerPawn = AIController->GetPawn();
	auto PatrollingGuard = Cast<APatrollingGuard>(ControllerPawn);
	auto PatrollingPoints = PatrollingGuard->GetPatrolPoints();

	//Set Next Patrolling Point
	auto Blackboardcomponent = OwnerComp.GetBlackboardComponent();
	auto Index = Blackboardcomponent->GetValueAsInt(IndexKey.SelectedKeyName);
	Blackboardcomponent->SetValueAsObject(PatrolPointKey.SelectedKeyName,PatrollingPoints[Index]);


	//Cycle the index
	auto Length = PatrollingPoints.Num();
	auto NextIndex = (Index+1) % Length;
	Blackboardcomponent->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);
	
	return EBTNodeResult::Succeeded;
}
