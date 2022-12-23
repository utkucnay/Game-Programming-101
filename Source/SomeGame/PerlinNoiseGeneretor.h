// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class SOMEGAME_API PerlinNoiseGeneretor
{
public:
	static TArray<FVector4f> GetPerlinNoise(const FVector2f textureLength, float dt) {

		TArray<FVector4f> texture;
		float length = textureLength.X * textureLength.Y;
		texture.Reserve(length);
		
		for (int y = 0; y < textureLength.Y; y++)
		{
			for (int x = 0; x < textureLength.X; x++)
			{
				auto noise = FMath::PerlinNoise2D(FVector2D((float)x / textureLength.X * dt, (float)y / textureLength.Y) * dt);
				noise = (noise * .5f) + .5f;
				texture.Add(FVector4f(noise, noise, noise, 1));
			}
		}
		return texture;
	}
};
