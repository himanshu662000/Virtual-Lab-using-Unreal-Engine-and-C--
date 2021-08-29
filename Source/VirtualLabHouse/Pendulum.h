// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pendulum.generated.h"

UCLASS()
class VIRTUALLABHOUSE_API APendulum : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APendulum();
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UStaticMeshComponent* Ball;  //Pendulum Bob For Oscillation
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UStaticMeshComponent* PlaceHolder; 
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UStaticMeshComponent* Rod;      //Penudulum Rod
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	USceneComponent* Base;//It is the default Scene Root component in whihc the ball will be attached
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float StringLength=-70.f;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float gravity=981.f;     //Default Gravity Value for earth
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float angle=0.78539816339f;
	//FFloatRange(0.78539816339,0,1.0471975512);
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float angleA=0.0f;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float angleV=0.0f;
	UPROPERTY(EditAnywhere)
	float velocity_loss=1.f;//Velocity loss 0 percent as change in velocity is zero

	
	FVector PlaceHolder_pos{0.f,0.f,0.f};
	FVector Rod_pos;
	FRotator Rod_rot{0,0,0};
	FVector Rod_scale{1.f,1.f,1.f};
	FVector Ball_pos;

	

	
	

	//Fuctions for Oscillatory Motion
	
	UFUNCTION(BlueprintCallable)
	void GeneralMotion(float Deltatime);//General Motion Function for any value of g
	
	UFUNCTION(BlueprintCallable)
	void Earth(float Deltatime);//S.H.M. Function for Earth

	UFUNCTION(BlueprintCallable)
	void Mars(float Deltatime);//S.H.M. Function for Mars

	UFUNCTION(BlueprintCallable)
	void Moon(float Deltatime);//S.H.M. Function for Moon

	UFUNCTION(BlueprintCallable)
	void StopMotion();//When this function will be called it will the stop motion by changing the position of bob and angle of rod

	UFUNCTION(BlueprintCallable)
	void StartMotion();//It will start the motion changing the position of bob and angle of rod
	
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
