#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AMyActor::move() {
	FVector2D start = FVector2D(0, 0); // 시작 좌표
	int maxCount = 10;
	int x = start.X;
	int y = start.Y;

	UE_LOG(LogTemp, Display, TEXT("Current Point : (%d, %d)"), x, y);
	for (int i = 0; i < maxCount; ++i) {
		start.X += step();
		start.Y += step();
		x = start.X;
		y = start.Y;
		UE_LOG(LogTemp, Display, TEXT("Current Point : (%d, %d)"), x, y);
	}
}

int AMyActor::step() {
	int randomValue = FMath::RandRange(0, 1); // 0 또는 1 생성
	return randomValue;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	move();
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

