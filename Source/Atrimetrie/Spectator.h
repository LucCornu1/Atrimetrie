// CORNU Luc

#pragma once

#include "Net/UnrealNetwork.h"
#include "GameFramework/Character.h"
#include "CoreMinimal.h"
#include "GameFramework/SpectatorPawn.h"
#include "Spectator.generated.h"

/**
 * 
 */
UCLASS()
class ATRIMETRIE_API ASpectator : public ASpectatorPawn
{
	GENERATED_BODY()

public:
	ASpectator();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;


// Added
private:
	UPROPERTY(Replicated)
		APawn* TargetPawn;

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Characters")
		TSubclassOf<class ACharacter> Resistant;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Characters")
		TSubclassOf<class ACharacter> Mecha;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Characters")
		TSubclassOf<class ACharacter> GermanPlane;

	UPROPERTY(BlueprintReadWrite, Category = "Default")
		bool bIsReady = false;

	void MoveForward(float AxisValue);

	void MoveRight(float AxisValue);
	
public:
	void SpawnPlane();

	UFUNCTION(BlueprintCallable, NetMulticast, Reliable, Category = "InGame")
		void ServerSpawnPlane();

	void Possess(APawn* Target);

	UFUNCTION(BlueprintCallable, Client, Reliable, Category = "InGame")
		void ClientPossess(APawn* Target);

	virtual void SetupPlayerInputComponent(class UInputComponent* InputComp) override;

};
