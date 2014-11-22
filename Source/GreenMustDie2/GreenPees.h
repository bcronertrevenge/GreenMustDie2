// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "PathNode.h"
#include "GreenPees.generated.h"

/**
 * 
 */
UCLASS()
class GREENMUSTDIE2_API AGreenPees : public APawn
{

public:
	APathNode* getNextNodeToReach();
	void setNextNodeToReach(APathNode*);
	float m_fLifePoint;
	float m_fSpeed;

protected:
		APathNode* m_oNextNode;

		GENERATED_UCLASS_BODY()
};
