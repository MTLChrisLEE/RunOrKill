// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "Runtime/AIModule/Classes/Blueprint/AIBlueprintHelperLibrary.h"
#include "AIController.h"
#include "PatrolRoute.h"
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	//Get Patrol Points 
	auto AIController = OwnerComp.GetAIOwner();
	auto ControllerPawn = AIController->GetPawn();

	auto PatrolRoute = ControllerPawn->FindComponentByClass<UPatrolRoute>();
	if (!ensure(PatrolRoute)) {
		return EBTNodeResult::Failed;
	}


	auto PatrollingPoints = PatrolRoute->GetPatrolPoints();	
	if (PatrollingPoints.Num() == 0) {
		UE_LOG(LogTemp, Warning, TEXT("A guard is missinig patrol points"));
		return EBTNodeResult::Failed;

	}
	

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
