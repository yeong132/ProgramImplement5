#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor2.generated.h"

UCLASS()
class CPPUSEPROJECT_API AMyActor2 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor2();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FVector2D start;
	int eventCount;
	int totalDistance;
	float floatDist;
public:
	void move();
	int step();
	float distance(FVector2D first, FVector2D second);
	void createEvent();
};
