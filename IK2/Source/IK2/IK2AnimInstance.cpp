// Fill out your copyright notice in the Description page of Project Settings.


#include "IK2AnimInstance.h"
#include "IK2Character.h"




UIK2AnimInstance::UIK2AnimInstance()
{
		
}

UIK2AnimInstance::~UIK2AnimInstance()
{
}

void UIK2AnimInstance::SetCharacter(AIK2Character * Char)
{
	MyCharacter = Char;
}
