#include "MovingItem.h"

AMovingItem::AMovingItem()
{
	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SetRootComponent(SceneComp);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneComp);


	// �̵��ϴ� ����
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

	// X, Y, Z ���� ������ġ, ������ġ+MaxLange �϶� ���� ����
	if (NewLocation.X >= StartLocation.X + MaxRange.X || NewLocation.X <= StartLocation.X)
	{
		MoveSpeed.X *= -1; // X ���� ����
	}
	if (NewLocation.Y >= StartLocation.Y + MaxRange.Y || NewLocation.Y <= StartLocation.Y)
	{
		MoveSpeed.Y *= -1; // Y ���� ����
	}
	if (NewLocation.Z >= StartLocation.Z + MaxRange.Z || NewLocation.Z <= StartLocation.Z)
	{
		MoveSpeed.Z *= -1; // Z ���� ����
	}

	SetActorLocation(NewLocation);
}
