#include "MovingItem.h"

AMovingItem::AMovingItem()
{
	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SetRootComponent(SceneComp);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneComp);


	// 이동하는 발판
	// /Game/EOL_Content/Meshes/Buildings/SM_Modules_Floor1.SM_Modules_Floor1
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/EOL_Content/Meshes/Buildings/SM_Modules_Floor1.SM_Modules_Floor1"));
	if (MeshAsset.Succeeded()) {
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	PrimaryActorTick.bCanEverTick = true;

	MoveSpeed = FVector(200.0f, 0.0f, 0.0f);
	MaxRange = FVector(600.0f);
}

void AMovingItem::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
}

void AMovingItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();
	FVector NewLocation = CurrentLocation + MoveSpeed * DeltaTime;

	// X, Y, Z 각각 현재위치, 현재위치+MaxLange 일때 방향 반전
	if (NewLocation.X >= StartLocation.X + MaxRange.X || NewLocation.X <= StartLocation.X)
	{
		MoveSpeed.X *= -1; // X 방향 반전
	}
	if (NewLocation.Y >= StartLocation.Y + MaxRange.Y || NewLocation.Y <= StartLocation.Y)
	{
		MoveSpeed.Y *= -1; // Y 방향 반전
	}
	if (NewLocation.Z >= StartLocation.Z + MaxRange.Z || NewLocation.Z <= StartLocation.Z)
	{
		MoveSpeed.Z *= -1; // Z 방향 반전
	}

	SetActorLocation(NewLocation);
}
