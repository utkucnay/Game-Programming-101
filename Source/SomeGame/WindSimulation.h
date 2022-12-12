// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WindSimulation.generated.h"

UCLASS()
class SOMEGAME_API AWindSimulation : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnyWhere)
		FVector globalWind;

public:	
	AWindSimulation();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
