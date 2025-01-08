#include "MyActor2.h"

// Sets default values
AMyActor2::AMyActor2(): start(FVector2D(0.0f, 0.0f)), eventCount(0), totalDistance(0), floatDist(0) // �ʱ�ȭ ����Ʈ�� �ʱ�ȭ
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// move �Լ�
void AMyActor2::move() {
	// 2d ��ǥ�� �����ϴ� �迭 ����
	TArray<FVector2D> Vector2dArray;
	int maxCount = 10;
	
	// �򰥷��� ��ŸƮ ���� Ȯ���� ����ϱ�
	UE_LOG(LogTemp, Display, TEXT("Start!!!!!!!!!!!!!"));
	// �������� 0, 0���� ��µǵ��� �ϱ�!
	Vector2dArray.Add(FVector2D(0, 0));
	// ������ �߰�
	for (int i = 0; i < maxCount; i++)
	{
		start.X += step();
		start.Y += step();
		Vector2dArray.Add(FVector2D(start.X, start.Y)); // X, Y ���� start.���� ������
	}

	// ������ ���
	for (int i = 0; i < Vector2dArray.Num(); i++)
	{
		const FVector2D& Vec = Vector2dArray[i];
		int x = Vec.X;
		int y = Vec.Y;

		UE_LOG(LogTemp, Warning, TEXT("Move %d: X = %d, Y = %d"), i, x, y);
		createEvent();
		if (i < Vector2dArray.Num() - 1) {
			float dt = AMyActor2::distance(Vector2dArray[i + 1], Vector2dArray[i]);
			floatDist += dt;
			
			UE_LOG(LogTemp, Warning, TEXT("Distance : %f"), dt);
		}
	}
	totalDistance = floatDist;
	UE_LOG(LogTemp, Warning, TEXT("Total Distance : %d, Event Count : %d"), totalDistance, eventCount);
}

// step �Լ�
int AMyActor2::step() {
	int randomValue = FMath::RandRange(0, 1); // 0 �Ǵ� 1 ����
	return randomValue;
}

// distance �Լ�
float AMyActor2::distance(FVector2D first, FVector2D second) {
	float dx = first.X - second.X;
	float dy = first.Y - second.Y;

	// FMath�� Sqrt�� ���ڸ� ��Ʈ�� ��ȯ�����ش�.
	return FMath::Sqrt(dx * dx + dy * dy);
}

// createEvent �Լ�
void AMyActor2::createEvent() {
	int RandomValue = FMath::RandRange(1, 100); // 1 ~ 100�� ���� ����
	if (RandomValue <= 50) // Ȯ�� 50�۷� �����
	{
		UE_LOG(LogTemp, Warning, TEXT("Coin Collected!!"));
		eventCount++;
	}
}

// Called when the game starts or when spawned
void AMyActor2::BeginPlay()
{
	Super::BeginPlay();
	move();
}

// Called every frame
void AMyActor2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

