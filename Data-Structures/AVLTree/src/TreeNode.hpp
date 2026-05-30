// ============================================================================
// TreeNode.hpp
//
// Interface of the TreeNode class
// ============================================================================

#pragma once

template <typename AnyType>
class TreeNode
{
    // Declare AVLTree as friend class so that AVL tree can update private members
    // Introduces coupling between AVLTree and TreeNode
    template <typename T> friend class AVLTree;

public:

    /// @brief Construct a default TreeNode with item = null and left/right child = null
    TreeNode();

    /// @brief Construct a TreeNode with item and left/right child = null
    TreeNode(AnyType item);

    /// @brief  Construct a TreeNode with item and left/right child
    /// @param item 
    /// @param leftChild 
    /// @param rightChild 
    TreeNode(AnyType item, TreeNode* leftChild, TreeNode* rightChild, int height);

    /// @brief Deconstruct the TreeNode
    ~TreeNode();

    /// @brief Get item stored in TreeNode
    /// @return 
    AnyType GetItem();

    /// @brief Get left child of TreeNode
    /// @return 
    TreeNode* GetLeftChild();

    /// @brief Get right child of TreeNode
    /// @return 
    TreeNode* GetRightChild();

    /// @brief Get height of TreeNode
    /// @return
    int GetHeight();

    /// @brief Get the Balance Factor of TreeNode
    /// @return
    int GetBalanceFactor();

private:

    /// @brief Item stored in TreeNode
    AnyType item;

    /// @brief The left child of the TreeNode
    TreeNode* leftChild;

    /// @brief The right child of the TreeNode
    TreeNode* rightChild;

    /// @brief The height of the TreeNode
    int height;
};

#include "TreeNode.tpp"