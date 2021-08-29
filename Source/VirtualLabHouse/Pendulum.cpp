// Fill out your copyright notice in the Description page of Project Settings.


#include "Pendulum.h"

// Sets default values
APendulum::APendulum()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Base=CreateDefaultSubobject<USceneComponent>(TEXT("Base"));
	RootComponent=Base;//Making root component as Base
	Ball=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball"));
	Ball->SetupAttachment(RootComponent);//Attaching Ball to Root component
	PlaceHolder=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlaceHolder"));
	PlaceHolder->SetupAttachment(RootComponent);
	Rod=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Rod"));
	Rod->SetupAttachment(RootComponent);

	//Agnle slider range
	PlaceHolder_pos=PlaceHolder->GetRelativeLocation();
	// PlaceHolder_pos=FVector(PlaceHolder->GetWorld()->OriginLocation);
//Making the Rod scale and rotation according to the ball
	Ball_pos=PlaceHolder_pos;
	Rod_pos=PlaceHolder_pos;
	Ball_pos.Z=PlaceHolder_pos.Z+StringLength;
	Ball->SetWorldLocation(Ball_pos);
	FVector Ball_Scale{0.2f,0.2f,0.2f};
	Ball->SetRelativeScale3D(Ball_Scale);
	FVector PlaceHolder_scale{0.1f,0.1f,0.1f};
	PlaceHolder->SetRelativeScale3D(PlaceHolder_scale);
	Rod->SetRelativeLocation(Rod_pos);
	Rod_scale.Z=-0.01*StringLength;
	Rod->SetRelativeScale3D(Rod_scale);

}

// Called when the game starts or when spawned
void APendulum::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APendulum::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APendulum::GeneralMotion(float Deltatime)
{
	angleA=gravity*sin(angle)/StringLength;//Angular accleration of ball at given positioin theta
	angleV=angleA*Deltatime+angleV;// Angular velocity of ball at given position theta
	angle=angleV*Deltatime+angle; //Updated angle after one_frame
	Ball_pos.X=StringLength*sin(angle)+PlaceHolder_pos.X;//Updated Position-x after one frame for ball
	Ball_pos.Z=StringLength*cos(angle)+PlaceHolder_pos.Z;//Updated Position-z after one frame for ball
	Ball->SetRelativeLocation(Ball_pos); //Updated location of ball
	Rod_rot.Pitch=-FMath::RadiansToDegrees(angle);  //Updated rotation of Rod
	Rod->SetRelativeRotation(Rod_rot);
	
	
}



void APendulum::StopMotion()
{
	// GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
	
	
	
	Rod_rot.Pitch=0.f;
	Rod_rot.Roll=0.f;
	Rod_rot.Yaw=0.0f;
	Rod->SetRelativeRotation(Rod_rot);//Rod Relative location 
	Ball_pos.X=PlaceHolder_pos.X;//It will change the position-X of ball as the position of Rod
	Ball_pos.Y=PlaceHolder_pos.Y;//It will change the position-Y of ball as the position of Rod
	Ball_pos.Z=StringLength+PlaceHolder_pos.Z;
	Ball->SetRelativeLocation(Ball_pos);
	
}

void APendulum::StartMotion()
{
	angle=0.78539816339f;
	
}

void APendulum::Earth(float Deltatime)
{
	gravity=981.f;
	GeneralMotion(Deltatime);
	
	
}

void APendulum::Mars(float Deltatime)
{
	gravity=372.1f;
	GeneralMotion(Deltatime);
	
}

void APendulum::Moon(float Deltatime)
{
	gravity=162.f;
	GeneralMotion(Deltatime);
	
}


