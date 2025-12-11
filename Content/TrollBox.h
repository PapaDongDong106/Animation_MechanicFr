#include "TrollBox.h"

ATrollBox::ATrollBox()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ATrollBox::BeginPlay()
{
    Super::BeginPlay();

    StartLocation = GetActorLocation(); // Save starting point for floating movement
}

void ATrollBox::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // ---------------- Rotation ----------------
    AddActorLocalRotation(FRotator(0.f, RotationSpeed * DeltaTime, 0.f));

    // ---------------- Up / Down Floating ----------------
    RunningTime += DeltaTime;
    float ZOffset = FMath::Sin(RunningTime * FloatSpeed) * FloatAmplitude;

    FVector NewLocation = StartLocation;
    NewLocation.Z += ZOffset;
    SetActorLocation(NewLocation);
}
