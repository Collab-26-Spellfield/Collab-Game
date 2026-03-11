// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CardParent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCardHovered, UCardParent*, HoveredCard);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCardUnhovered, UCardParent*, UnhoveredCard);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCardPressed, UCardParent*, PressedCard);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCardReleased, UCardParent*, ReleasedCard);


UCLASS()
class SPELLFIELD_API UCardParent : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime);

	UFUNCTION()
	void UpdateCardDesiredTransform(FWidgetTransform DesiredTransform, float InterpSpeed);

	//Delegates
	UPROPERTY(BlueprintAssignable)
	FOnCardHovered OnCardHovered;

	UPROPERTY(BlueprintAssignable)
	FOnCardUnhovered OnCardUnhovered;

	UPROPERTY(BlueprintAssignable)
	FOnCardPressed OnCardPressed;

	UPROPERTY(BlueprintAssignable)
	FOnCardReleased OnCardReleased;

protected:

	//Core Card Widget Functionality

	UFUNCTION(BlueprintNativeEvent)
	void CardHovered();
	virtual void CardHovered_Implementation();

	UFUNCTION(BlueprintNativeEvent)
	void CardUnhovered();
	virtual void CardUnhovered_Implementation();

	UFUNCTION(BlueprintNativeEvent)
	void CardPressed();
	virtual void CardPressed_Implementation();

	UFUNCTION(BlueprintNativeEvent)
	void CardReleased();
	virtual void CardReleased_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void CardSetUp();
	virtual void CardSetUp_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void CardCleanUp();
	virtual void CardCleanUp_Implementation();



	//Mouse Inputs (Will Call Established Function)
	void NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent);
	void NativeOnMouseLeave(const FPointerEvent& InMouseEvent);

	FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent);
	FReply NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent);

	private:

	UPROPERTY()
	FWidgetTransform StartingTransform;

	UPROPERTY()
	FWidgetTransform DesiredTransform;

	UPROPERTY()
	bool bIsRepositioning = false;

	UPROPERTY()
	float RepositionTime = 0.0f;
	
};
