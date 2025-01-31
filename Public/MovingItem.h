#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingItem.generated.h"

UCLASS()
class CPPUSEPROJECT_API AMovingItem : public AActor
{
	GENERATED_BODY()

private:
	FVector StartLocation; // ���� ������ �ܺη� ���� ��ų �ʿ���� ���ο����� ���� ����

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MovingItem|Components")
	USceneComponent* SceneComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingItem|Components")
	UStaticMeshComponent* StaticMeshComp;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingItem|Properties")
	FVector MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingItem|Properties")
	FVector MaxRange;

public:	
	AMovingItem();

	virtual void Tick(float DeltaTime) override;

};
