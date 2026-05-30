// ============================================================================
// LinkedList.tpp
//
// Template implementations of LinkedList class
// ============================================================================

#pragma once

#include "LinkedList.hpp"
#include <iostream>

template <typename AnyType>
LinkedList<AnyType>::LinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

template <typename AnyType>
LinkedList<AnyType>::LinkedList(AnyType array[], int length)
    : LinkedList()
{
    for (int i = 0; i < length; i++)
    {
        this->Append(array[i]);
    }
}

template <typename AnyType>
LinkedList<AnyType>::~LinkedList()
{
    while (this->head != nullptr)
    {
        this->RemoveHead();
    }
} 

template <typename AnyType>
void LinkedList<AnyType>::Prepend(AnyType item)
{
    LLNode<AnyType>* newHead = new LLNode<AnyType>(item);

    if (this->head == nullptr)
    {
        this->head = this->tail = newHead;
        this->size++;
        return;
    }

    newHead->SetNext(this->head);
    this->head = newHead;

    this->size++;
}

template <typename AnyType>
void LinkedList<AnyType>::Append(AnyType item)
{
    LLNode<AnyType>* newTail = new LLNode<AnyType>(item);

    if (this->head == nullptr)
    {
        this->head = this->tail = newTail;
        this->size++;
        return;
    }

    this->tail->SetNext(newTail);
    this->tail = newTail;

    this->size++;
}

template <typename AnyType>
AnyType LinkedList<AnyType>::Get(int index)
{
    if (index < 0 || index >= this->size)
        return AnyType();

    LLNode<AnyType>* currNode = this->head;

    for (int i = 0; i < index; i++)
    {
        currNode = currNode->GetNext();
    }

    return currNode->GetItem();
}

template <typename AnyType>
int LinkedList<AnyType>::GetIndexOf(AnyType item)
{
    LLNode<AnyType>* currNode = this->head;
    int currIndex = 0;

    while (currNode != nullptr)
    {
        if (currNode->GetItem() == item)
            return currIndex;

        currNode = currNode->GetNext();
        currIndex++;
    }

    return -1;
}

template <typename AnyType>
AnyType LinkedList<AnyType>::PeekFront()
{
    if (this->head == nullptr)
        return AnyType();

    return this->head->GetItem();
}

template <typename AnyType>
AnyType LinkedList<AnyType>::PeekBack()
{
    if (this->tail == nullptr)
        return AnyType();

    return this->tail->GetItem();
}

template <typename AnyType>
AnyType LinkedList<AnyType>::RemoveHead()
{
    if (this->head == nullptr)
        return AnyType();

    if (this->head == this->tail)
        this->tail = nullptr;

    LLNode<AnyType>* prevHead = this->head;

    AnyType prevHeadItem = prevHead->GetItem();

    this->head = prevHead->GetNext();

    delete prevHead;

    this->size--;

    return prevHeadItem;
}

template <typename AnyType>
AnyType LinkedList<AnyType>::RemoveTail()
{
    if (this->head == nullptr)
        return AnyType();

    if (this->head == this->tail)
    {
        AnyType item = this->head->GetItem();

        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
        this->size--;

        return item;
    }

    LLNode<AnyType>* currNode = this->head;

    while (currNode->GetNext() != this->tail)
    {
        currNode = currNode->GetNext();
    }

    AnyType item = tail->GetItem();

    delete this->tail;
    this->tail = currNode;
    currNode->SetNext(nullptr);
    this->size--;

    return item;
}

template <typename AnyType>
void LinkedList<AnyType>::PrintList()
{
    LLNode<AnyType>* currNode = this->head;

    if (currNode == nullptr)
    {
        std::cout << "(empty)" << std::endl;
    }

    while (currNode != nullptr)
    {
        std::cout << currNode->GetItem() << std::endl;
        currNode = currNode->GetNext();
    }
}

template <typename AnyType>
int LinkedList<AnyType>::Size()
{
    return this->size;
}