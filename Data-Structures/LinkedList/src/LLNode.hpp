// ============================================================================
// LLNode.hpp
//
// Interface of the LLNode class
// ============================================================================

#pragma once

template <typename AnyType>
class LLNode
{
public:

    /// @brief Construct a default node with item = null and next = null
    LLNode();

    /// @brief Construct a node with item and next = null
    /// @param item 
    LLNode(AnyType item);

    /// @brief Construct a node with item and next
    /// @param item 
    /// @param next 
    LLNode(AnyType item, LLNode* next);

    /// @brief Deconstruct the node
    ~LLNode();

    /// @brief Get the item stored in node
    /// @return
    AnyType GetItem();

    /// @brief Get the next node in list
    /// @return 
    LLNode* GetNext();

    /// @brief Set the current node's next node
    /// @param newNextNode 
    /// @return 
    void SetNext(LLNode* newNextNode);

private:

    /// @brief Item stored in node
    AnyType item;

    /// @brief Next node in the list
    LLNode* next;
};

#include "LLNode.tpp"