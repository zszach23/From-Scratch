// ============================================================================
// LLNode.tpp
//
// Template implementations for LLNode class
// ============================================================================

#pragma once

#include "LLNode.hpp"

template <typename AnyType>
LLNode<AnyType>::LLNode()
    : item(AnyType()), next(nullptr)
{ 
}

template <typename AnyType>
LLNode<AnyType>::LLNode(AnyType item)
    : item(item), next(nullptr)
{
}

template <typename AnyType>
LLNode<AnyType>::LLNode(AnyType item, LLNode* next)
    : item(item), next(next)
{
}

template <typename AnyType>
LLNode<AnyType>::~LLNode()
{
}

template <typename AnyType>
AnyType LLNode<AnyType>::GetItem()
{
    return this->item;
}

template <typename AnyType>
LLNode<AnyType>* LLNode<AnyType>::GetNext()
{
    return this->next;
}

template <typename AnyType>
void LLNode<AnyType>::SetNext(LLNode<AnyType>* newNextNode)
{
    this->next = newNextNode;
}