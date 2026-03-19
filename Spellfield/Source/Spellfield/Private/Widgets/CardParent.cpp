// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/CardParent.h"

void UCardParent::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	//Reposition Functionality

	//Bool acts as a gate access
	if (bIsRepositioning)
	{

		//Make In Progress Reposition Transform
		float RepositionAngle = FMath::FInterpTo(GetRenderTransform().Angle, DesiredTransform.Angle, InDeltaTime, RepositionSpeed);

		FVector2D RepositionTranslation = { FMath::FInterpTo(GetRenderTransform().Translation.X, DesiredTransform.Translation.X, InDeltaTime, RepositionSpeed) ,
											FMath::FInterpTo(GetRenderTransform().Translation.Y, DesiredTransform.Translation.Y, InDeltaTime, RepositionSpeed) };

		FWidgetTransform RepositionTransform = FWidgetTransform(RepositionTranslation, { 1.0f,1.0f }, { 0.0f,0.0f }, RepositionAngle);

		//Apply Reposition
		SetRenderTransform(RepositionTransform);

		//Check For End
		if (GetRenderTransform().Translation == DesiredTransform.Translation)
		{
			//Close Gate
			bIsRepositioning = false;

			//UE_LOG(LogTemp, Warning, TEXT("Card Moved To New Desired Locations"));
		}

	}

}

void UCardParent::UpdateCardDesiredTransform(FWidgetTransform NewTransform, float InterpSpeed)
{
	//Setting this to CurrentTransform allows for emergent transitions for between states
	StartingTransform = GetRenderTransform();
	DesiredTransform = NewTransform;

	//UE_LOG(LogTemp, Warning, TEXT("Desired X Translation Is: %d"), FMath::RoundToInt32(NewTransform.Translation.X));

	RepositionSpeed = InterpSpeed;

	//Open Gate
	bIsRepositioning = true;
}

void UCardParent::CardHovered_Implementation()
{
	//Animation Logic To Be Applied In Blueprint

	UE_LOG(LogTemp, Warning, TEXT("CardHovered_Implementation Called"));

	OnCardHovered.Broadcast(this);
}

void UCardParent::CardUnhovered_Implementation()
{
	//Animation Logic To Be Applied In Blueprint

	UE_LOG(LogTemp, Warning, TEXT("CardUnhovered_Implementation Called"));

	OnCardUnhovered.Broadcast(this);
}

void UCardParent::CardPressed_Implementation()
{
	//Animation Logic To Be Applied In Blueprint

	UE_LOG(LogTemp, Warning, TEXT("CardPressed_Implementation Called"));

	OnCardPressed.Broadcast(this);
}

void UCardParent::CardReleased_Implementation()
{
	//Animation Logic To Be Applied In Blueprint

	UE_LOG(LogTemp, Warning, TEXT("CardReleased_Implementation Called"));

	OnCardReleased.Broadcast(this);
}

void UCardParent::CardSetUp_Implementation()
{
	//This should be avoided being called as timer based animation should be included to stop bad feeling interaction
	UE_LOG(LogTemp, Warning, TEXT("CardSetUp_Implementation Called"));
}

void UCardParent::CardCleanUp_Implementation()
{
	//This should be avoided being called as timer based animation should be included to stop bad feeling interaction
	UE_LOG(LogTemp, Warning, TEXT("CardCleanUp_Implementation Called"));
}

void UCardParent::NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	CardHovered();
}

void UCardParent::NativeOnMouseLeave(const FPointerEvent& InMouseEvent)
{
	CardUnhovered();
}

FReply UCardParent::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	CardPressed();

	return FReply::Handled();
}

FReply UCardParent::NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	CardReleased();

	return FReply::Handled();
}
