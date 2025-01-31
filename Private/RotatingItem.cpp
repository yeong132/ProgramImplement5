#include "RotatingItem.h"

ARotatingItem::ARotatingItem()
{
	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SetRootComponent(SceneComp);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneComp);


	// 회전하는 큐브
	// /Game/EOL_Content/Meshes/Props/SM_Crate.SM_Crate
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/EOL_Content/Meshes/Props/SM_Crate.SM_Crate"));
	if (MeshAsset.Succeeded()) 
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed = FVector(0.0f, 90.0f, 0.0f);

}

void ARotatingItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARotatingItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// FRotator의 인자는 순서대로  Pitch, Yaw, Roll
	AddActorLocalRotation(FRotator(RotationSpeed.X * DeltaTime, RotationSpeed.Y * DeltaTime, RotationSpeed.Z * DeltaTime));
}

