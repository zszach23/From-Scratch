// ============================================================================
// AVLTree.hpp
//
// Interface of the AVLTree class
// ============================================================================

#pragma once

#include "TreeNode.hpp"
#include <vector>

template <typename AnyType>
class AVLTree
{
public:
    /// @brief Construct an empty AVL tree
    AVLTree();

    /// @brief Construct an AVL tree that has a root with item
    /// @param item 
    AVLTree(AnyType item);

    /// @brief Deconstruct the AVL tree
    ~AVLTree();

    /// @brief Performs InOrder Traversal in the AVL Tree
    /// @return Vector with InOrder elements
    std::vector<AnyType> InOrder();

    /// @brief Add an item to the AVL tree, disallows duplicates
    /// @param item 
    void AddItem(AnyType item);

    /// @brief Determine if item is in the AVL tree
    /// @param item 
    /// @return
    bool ContainsItem(AnyType item);

    /// @brief Delete an item in the AVL tree
    /// @param item 
    void DeleteItem(AnyType item);

    /// @brief Returns the height of the AVL tree
    /// @return
    int GetHeight();

private:

    /// @brief The root of the AVL tree
    TreeNode<AnyType>* root;

    /// @brief Recursive function that adds elements to resultList in InOrder
    /// @param root The root of the (sub)tree
    /// @param resultList vector reference to add elements to
    void InOrder(TreeNode<AnyType>* root, std::vector<AnyType>& resultList);

    /// @brief Recursive function that adds item to AVL tree and balances
    /// @param root The root of the (sub)tree
    /// @param item
    /// @return The root of the (sub)tree
    TreeNode<AnyType>* AddItem(TreeNode<AnyType>* root, AnyType item);

    /// @brief Recursive function that deletes item from AVL tree and balances
    /// @param root The root of the (sub)tree
    /// @param item
    /// @return The root of the (sub)tree
    TreeNode<AnyType>* DeleteItem(TreeNode<AnyType>* root, AnyType item);

    /// @brief Balance the tree at the given node if needed
    /// @param root The root of (sub)tree to balance
    /// @return Updated root of (sub)tree
    TreeNode<AnyType>* Balance(TreeNode<AnyType>* root);

    /// @brief Performs a single left rotation at given node
    /// @param root The node to perform the rotation on
    TreeNode<AnyType>* RotateLeft(TreeNode<AnyType>* root);

    /// @brief Performs a single right rotation at given node
    /// @param root The node to perform the rotation on
    TreeNode<AnyType>* RotateRight(TreeNode<AnyType>* root);

    /// @brief Get the max of the heights of root's children
    /// @param root The root of the (sub)tree
    /// @return
    int GetMaxSubtreeHeight(TreeNode<AnyType>* root);

    /// @brief Find the max value in (sub)tree
    /// @param root The root of the (sub)tree
    /// @return The item with the maximum value
    AnyType FindMax(TreeNode<AnyType>* root);

    /// @brief Recursively deletes nodes in the AVL tree
    /// @param root The root of the given (sub)tree
    /// @return Null pointer
    TreeNode<AnyType>* DestroyTree(TreeNode<AnyType>* root);
};

#include "AVLTree.tpp"