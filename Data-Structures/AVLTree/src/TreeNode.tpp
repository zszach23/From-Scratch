// ============================================================================
// TreeNode.tpp
//
// Template implementations for TreeNode class
// ============================================================================

#include "TreeNode.hpp"

template <typename AnyType>
TreeNode<AnyType>::TreeNode()
    : item(AnyType()), leftChild(nullptr), rightChild(nullptr), height(0)
{
}

template <typename AnyType>
TreeNode<AnyType>::TreeNode(AnyType item)
    : item(item), leftChild(nullptr), rightChild(nullptr), height(0)
{
}

template <typename AnyType>
TreeNode<AnyType>::TreeNode(AnyType item, TreeNode* leftChild, TreeNode* rightChild, int height)
    : item(item), leftChild(leftChild), rightChild(rightChild), height(height)
{
}

template <typename AnyType>
TreeNode<AnyType>::~TreeNode()
{
}

template <typename AnyType>
AnyType TreeNode<AnyType>::GetItem()
{
    return this->item;
}

template <typename AnyType>
TreeNode<AnyType>* TreeNode<AnyType>::GetLeftChild()
{
    return this->leftChild;
}

template <typename AnyType>
TreeNode<AnyType>* TreeNode<AnyType>::GetRightChild()
{
    return this->rightChild;
}

template <typename AnyType>
int TreeNode<AnyType>::GetHeight()
{
    return this->height;
}

template <typename AnyType>
int TreeNode<AnyType>::GetBalanceFactor()
{
    int leftHeight = (this->leftChild == nullptr) ? -1 : this->leftChild->height;
    int rightHeight = (this->rightChild == nullptr) ? -1: this->rightChild->height;

    return leftHeight - rightHeight;
}