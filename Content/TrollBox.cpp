#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TrollBox.generated.h"

UCLASS()
class Animation_MechanicFr_API ATrollBox : public APawn
{
    GENERATED_BODY()

public:
    ATrollBox();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY(EditAnywhere, Category = "TrollBox")
    float RotationSpeed = 60.f;   // Degrees per second

    UPROPERTY(EditAnywhere, Category = "TrollBox")
    float FloatAmplitude = 50.f;  // Height range

    UPROPERTY(EditAnywhere, Category = "TrollBox")
    float FloatSpeed = 2.f;       // Speed of bobbing motion

    FVector StartLocation;
    float RunningTime = 0.f;
};
