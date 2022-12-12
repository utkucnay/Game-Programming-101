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

		TArray<FVector4f> color;
		float length = textureLength.X * textureLength.Y;
		color.Reserve(length);
		
		for (int y = 0; y < textureLength.Y; y++)
		{
			for (int x = 0; x < textureLength.X; x++)
			{
				auto noise = FMath::PerlinNoise2D(FVector2D((float)x / textureLength.X * dt, (float)y / textureLength.Y) * dt);
				noise = (noise * .5f) + .5f;
				color.Add(FVector4f(noise, noise, noise, 1));
			}
		}

		//fractal algorithm
		for (int z = 0; z < 20; z++) {
			for (int y = 0; y < textureLength.Y - 1; y++)
			{
				for (int x = 0; x < textureLength.X - 1; x++)
				{
					color[y * textureLength.Y + x] = (color[y * textureLength.Y + x + 1] + color[(y + 1) * textureLength.Y + x + 1] +
						color[(y + 1) * textureLength.Y + x]) / 3;
				}
			}
		}


		return color;
	}
};
