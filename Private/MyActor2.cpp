#include "MyActor2.h"

// Sets default values
AMyActor2::AMyActor2(): start(FVector2D(0.0f, 0.0f)), eventCount(0), totalDistance(0), floatDist(0) // 초기화 리스트로 초기화
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// move 함수
void AMyActor2::move() {
	// 2d 좌표를 저장하는 배열 선언
	TArray<FVector2D> Vector2dArray;
	int maxCount = 10;
	
	// 헷갈려서 스타트 지점 확실히 출력하기
	UE_LOG(LogTemp, Display, TEXT("Start!!!!!!!!!!!!!"));
	// 시작점인 0, 0부터 출력되도록 하기!
	Vector2dArray.Add(FVector2D(0, 0));
	// 데이터 추가
	for (int i = 0; i < maxCount; i++)
	{
		start.X += step();
		start.Y += step();
		Vector2dArray.Add(FVector2D(start.X, start.Y)); // X, Y 값을 start.에서 가져옴
	}

	// 데이터 출력
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

// step 함수
int AMyActor2::step() {
	int randomValue = FMath::RandRange(0, 1); // 0 또는 1 생성
	return randomValue;
}

// distance 함수
float AMyActor2::distance(FVector2D first, FVector2D second) {
	float dx = first.X - second.X;
	float dy = first.Y - second.Y;

	// FMath의 Sqrt는 숫자를 루트로 변환시켜준다.
	return FMath::Sqrt(dx * dx + dy * dy);
}

// createEvent 함수
void AMyActor2::createEvent() {
	int RandomValue = FMath::RandRange(1, 100); // 1 ~ 100의 난수 생성
	if (RandomValue <= 50) // 확률 50퍼로 만들기
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

