// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "Runtime/AIModule/Classes/Blueprint/AIBlueprintHelperLibrary.h"
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	auto Blackboardcomponent = OwnerComp.GetBlackboardComponent();
	auto index = Blackboardcomponent->GetValueAsInt(IndexKey.SelectedKeyName);
	auto Name = OwnerComp.GetOwner()->GetName();
	
	UE_LOG(LogTemp, Warning, TEXT("%s is on way to its patrolpoint index: %i"), *Name, index);

	return EBTNodeResult::Succeeded;
}
