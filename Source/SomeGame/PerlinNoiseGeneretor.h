// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class SOMEGAME_API PerlinNoiseGeneretor
{
public:
	static TArray<FVector4f> GetPerlinNoiseSquare(const int length, float dt) {

		TArray<FVector4f> color;
		color.Reserve(length * length);
		float halfLength = length / 2.0f;
		
		for (int y = 0; y < length; y++)
		{
			for (int x = 0; x < length; x++)
			{
				auto noise = FMath::PerlinNoise2D(FVector2D((float)x / length * dt, (float)y / length) * dt);
				color.Add(FVector4f(noise, FMath::RandHelper(360), 0, 0));
				UE_LOG(LogTemp, Warning,TEXT("noise: %f"), noise);
			}
		}
		return color;
	}
};
