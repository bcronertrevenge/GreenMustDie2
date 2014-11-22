// Fill out your copyright notice in the Description page of Project Settings.

#include "GreenMustDie2.h"
#include "PathNode.h"


APathNode::APathNode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	m_oNextNode = NULL;
	m_oPreviousNode = NULL;
}

const APathNode* APathNode::getNextNode()
{
	return m_oNextNode;
}

void APathNode::setNextNode(APathNode* next)
{
	m_oNextNode = next;
}

const APathNode* APathNode::getPreviousNode()
{
	return m_oPreviousNode;
}

void APathNode::setPreviousNode(APathNode* previous)
{
	m_oPreviousNode = previous;
}
