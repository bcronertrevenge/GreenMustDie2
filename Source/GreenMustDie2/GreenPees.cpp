// Fill out your copyright notice in the Description page of Project Settings.

#include "GreenMustDie2.h"
#include "GreenPees.h"
#include "PathNode.h"

AGreenPees::AGreenPees(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	m_oNextNode = NULL;
}


APathNode* AGreenPees::getNextNodeToReach()
{
	return m_oNextNode;
}

void AGreenPees::setNextNodeToReach(APathNode* next)
{
	m_oNextNode = next;
}