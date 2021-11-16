// CORNU Luc

#include "Spectator.h"

ASpectator::ASpectator()
{
	bReplicates = true;

	SetReplicates(true);
	SetReplicateMovement(true);

}

void ASpectator::BeginPlay()
{
	Super::BeginPlay();

}

void ASpectator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


// Added
void ASpectator::SpawnPlane()
{
	if (GetLocalRole() == ROLE_Authority)
	{
		ServerSpawnPlane();
	}

}

void ASpectator::ServerSpawnPlane_Implementation()
{
	FActorSpawnParameters SpawnParams;
	ACharacter* Character = GetWorld()->SpawnActor<ACharacter>(GermanPlane, FVector(0, 0, 0), FRotator(0, 0, 0), SpawnParams);

//	Possess(Cast<APawn>(Character));

}

void ASpectator::Possess(APawn* Target)
{
	ClientPossess(Target);

}

void ASpectator::ClientPossess_Implementation(APawn* Target)
{
	AController* CurrentController = GetController();
	CurrentController->UnPossess();
	CurrentController->Possess(Target);
	Target->SetOwner(CurrentController);

}

void ASpectator::SetupPlayerInputComponent(class UInputComponent* InputComp)
{
	Super::SetupPlayerInputComponent(InputComp);

	InputComponent->BindAxis("Forward", this, &ASpectator::MoveForward);
	InputComponent->BindAxis("Right", this, &ASpectator::MoveRight);

	InputComponent->BindAction("ChoosePlane", IE_Pressed, this, &ASpectator::SpawnPlane);

}

void ASpectator::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector(), AxisValue, false);

}

void ASpectator::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector(), AxisValue, false);

}

void ASpectator::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	DOREPLIFETIME(ASpectator, TargetPawn);

}