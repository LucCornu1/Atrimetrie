// CORNU Luc

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MultiplayerGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ATRIMETRIE_API AMultiplayerGameMode : public AGameModeBase
{
	GENERATED_BODY()
	

public:
	AMultiplayerGameMode();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

};
