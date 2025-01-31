#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingItem.generated.h"

UCLASS()
class CPPUSEPROJECT_API ARotatingItem : public AActor
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "RotatingItem|Components")
	USceneComponent* SceneComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotatingItem|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotatingItem|Properties")
	FVector RotationSpeed;

public:	
	ARotatingItem();

	virtual void Tick(float DeltaTime) override;

};
