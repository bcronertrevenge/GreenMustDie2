// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PathNode.generated.h"

/**
 * 
 */
UCLASS()
class GREENMUSTDIE2_API APathNode : public AActor
{

public:
	const APathNode* getNextNode();
	void setNextNode(APathNode*);

	const APathNode* getPreviousNode();
	void setPreviousNode(APathNode*);

protected:
	APathNode* m_oNextNode;
	APathNode* m_oPreviousNode;

GENERATED_UCLASS_BODY()	
};
