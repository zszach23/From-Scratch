// ============================================================================
// LinkedList.hpp
//
// Interface of the LinkedList class
// ============================================================================

#pragma once

#include "LLNode.hpp"

template <typename AnyType>
class LinkedList
{
public:

    /// @brief Construct an empty LinkedList
    LinkedList();

    /// @brief Construct a LinkedList with elements of array
    /// @param  array An array of elements
    LinkedList(AnyType array[], int length);

    /// @brief Deconstruct the LinkedList
    ~LinkedList();

    /// @brief Add item to beginning of list
    /// @param item 
    void Prepend(AnyType item);

    /// @brief Add item to end of list
    /// @param item Item to insert
    void Append(AnyType item);

    /// @brief Return the item at the specified index
    /// @param index 
    /// @return 
    AnyType Get(int index);

    /// @brief Return the index of the first occurrence of item
    /// @param item
    /// @return 
    int GetIndexOf(AnyType item);

    /// @brief Gets the first item in the list
    /// @return The first item in list, null-equivalent otherwise
    AnyType PeekFront();

    /// @brief Gets the last item in the list
    /// @return The last item in list, null-equivalent otherwise
    AnyType PeekBack();

    /// @brief Remove the head of the list
    /// @return The item that was removed, null-equivalent otherwise
    AnyType RemoveHead();

    /// @brief Remove the tail of the list
    /// @return The item that was removed, null-equivalent otherwise
    AnyType RemoveTail();

    /// @brief Prints the contents of the list
    void PrintList();

    /// @brief Returns the current size of the list
    /// @return 
    int Size();

private:

    /// @brief The head node of the list
    LLNode<AnyType>* head;

    /// @brief The tail node of the list
    LLNode<AnyType>* tail;

    /// @brief The current size of the list
    int size;
};

#include "LinkedList.tpp"