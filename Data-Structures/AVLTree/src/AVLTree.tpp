// ============================================================================
// AVLTree.tpp
//
// Template implementations of the AVLTree class
// ============================================================================

#include "AVLTree.hpp"
#include <vector>

#define UNBALANCED_LEFT 2
#define HEAVY_LEFT 1
#define BALANCED 0
#define HEAVY_RIGHT -1
#define UNBALANCED_RIGHT -2

template <typename AnyType>
AVLTree<AnyType>::AVLTree()
    : root(nullptr)
{
}

template <typename AnyType>
AVLTree<AnyType>::AVLTree(AnyType item)
    : root(new TreeNode<AnyType>(item))
{
}

template <typename AnyType>
AVLTree<AnyType>::~AVLTree()
{
    this->root = DestroyTree(this->root);
}

template <typename AnyType>
TreeNode<AnyType>* AVLTree<AnyType>::DestroyTree(TreeNode<AnyType>* root)
{
    if (root == nullptr)
        return nullptr;

    if (root->leftChild == nullptr)
        DestroyTree(root->leftChild);

    if (root->rightChild == nullptr)
        DestroyTree(root->rightChild);

    return nullptr;
}

template <typename AnyType>
std::vector<AnyType> AVLTree<AnyType>::InOrder()
{
    std::vector<AnyType> resultList;
    AVLTree<AnyType>::InOrder(this->root, resultList);

    return resultList;
}

template <typename AnyType>
void AVLTree<AnyType>::InOrder(TreeNode<AnyType>* root, std::vector<AnyType>& resultList)
{
    if (root == nullptr)
        return;

    AVLTree<AnyType>::InOrder(root->leftChild, resultList);
    resultList.push_back(root->item);
    AVLTree<AnyType>::InOrder(root->rightChild, resultList);
}

template <typename AnyType>
void AVLTree<AnyType>::AddItem(AnyType item)
{
    this->root = AddItem(this->root, item);
}

template <typename AnyType>
TreeNode<AnyType>* AVLTree<AnyType>::AddItem(TreeNode<AnyType>* root, AnyType item)
{
    if (root == nullptr)
        return new TreeNode<AnyType>(item);

    // Do not allow duplicates
    if (root->item == item)
        return root;

    if (item < root->item)
        root->leftChild = AddItem(root->leftChild, item);
    else
        root->rightChild = AddItem(root->rightChild, item);

    root->height = 1 + GetMaxSubtreeHeight(root);

    root = Balance(root);

    return root;
}

template <typename AnyType>
bool AVLTree<AnyType>::ContainsItem(AnyType item)
{
    TreeNode<AnyType>* currNode = this->root;

    while (currNode != nullptr)
    {
        if (currNode->item == item)
            return true;

        if (item < currNode->item)
            currNode = currNode->leftChild;
        else
            currNode = currNode->rightChild;
    }

    return false;
}

template <typename AnyType>
void AVLTree<AnyType>::DeleteItem(AnyType item)
{
    this->root = DeleteItem(this->root, item);
}

template <typename AnyType>
TreeNode<AnyType>* AVLTree<AnyType>::DeleteItem(TreeNode<AnyType>* root, AnyType item)
{
    if (root == nullptr)
        return nullptr;

    if (item < root->item)
        root->leftChild = DeleteItem(root->leftChild, item);

    if (item > root->item)
        root->rightChild = DeleteItem(root->rightChild, item);

    if (item == root->item)
    {
        // Case 1: root has no children
        if (root->leftChild == nullptr && root->rightChild == nullptr)
        {
            delete root;
            return nullptr;
        }

        // Case 2: root has only left child
        // Move left child up to root
        else if (root->leftChild != nullptr && root->rightChild == nullptr)
        {
            AnyType leftChildItem = root->leftChild->item;

            root->item = leftChildItem;

            delete root->leftChild;
            root->leftChild = nullptr;
        }

        // Case 3: root has only right child
        // Move right child up to root
        else if (root->leftChild == nullptr && root->rightChild != nullptr)
        {
            AnyType rightChildItem = root->rightChild->item;

            root->item = rightChildItem;

            delete root->rightChild;
            root->rightChild = nullptr;
        }

        // Case 4: root has left and right child
        // Replace with max value in left subtree
        else
        {
            AnyType maxItem = FindMax(root->leftChild);

            root->item = maxItem;

            root->leftChild = DeleteItem(root->leftChild, maxItem);
        }

        root->height = 1 + GetMaxSubtreeHeight(root);

        root = Balance(root);

        return root;
    }

    return root;
}

template <typename AnyType>
TreeNode<AnyType>* AVLTree<AnyType>::Balance(TreeNode<AnyType>* root)
{
    int balanceFactor = root->GetBalanceFactor();

    if (balanceFactor == UNBALANCED_LEFT)
    {
        // Double rotation if root is left heavy and left child is right heavy
        if (root->leftChild->GetBalanceFactor() == HEAVY_RIGHT)
            root->leftChild = RotateLeft(root->leftChild);

        root = RotateRight(root);
    }

    if (balanceFactor == UNBALANCED_RIGHT)
    {
        // Double rotation if root is right heavy and right child is left heavy
        if (root->rightChild->GetBalanceFactor() == HEAVY_LEFT)
            root->rightChild = RotateRight(root->rightChild);
        
        root = RotateLeft(root);
    }

    return root;
}

template <typename AnyType>
TreeNode<AnyType>* AVLTree<AnyType>::RotateLeft(TreeNode<AnyType>* root)
{
    TreeNode<AnyType>* newRoot = root->rightChild;

    root->rightChild = newRoot->leftChild;

    newRoot->leftChild = root;

    root->height = 1 + GetMaxSubtreeHeight(root);
    newRoot->height = 1 + GetMaxSubtreeHeight(newRoot);

    return newRoot;
}

template <typename AnyType>
TreeNode<AnyType>* AVLTree<AnyType>::RotateRight(TreeNode<AnyType>* root)
{
    TreeNode<AnyType>* newRoot = root->leftChild;

    root->leftChild = newRoot->rightChild;

    newRoot->rightChild = root;

    root->height = 1 + GetMaxSubtreeHeight(root);
    newRoot->height = 1 + GetMaxSubtreeHeight(newRoot);

    return newRoot;
}

template <typename AnyType>
int AVLTree<AnyType>::GetMaxSubtreeHeight(TreeNode<AnyType>* root)
{
    int leftHeight = (root->leftChild == nullptr) ? -1 : root->leftChild->height;
    int rightHeight = (root->rightChild == nullptr) ? -1: root->rightChild->height;

    return (leftHeight < rightHeight) ? rightHeight: leftHeight;
}

template <typename AnyType>
AnyType AVLTree<AnyType>::FindMax(TreeNode<AnyType>* root)
{
    if (root == nullptr)
        return AnyType();

    if (root->rightChild == nullptr)
        return root->item;

    return FindMax(root->rightChild);
}

template <typename AnyType>
int AVLTree<AnyType>::GetHeight()
{
    return (this->root == nullptr) ? -1 : this->root->height;
}