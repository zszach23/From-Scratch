// ============================================================================
// AVLTree: testsuite_03.cpp
//
// Test Suite for AVL Tree DeleteItem()
// ============================================================================

#include "AVLTree.hpp"
#include <gtest/gtest.h>
#include <vector>

TEST(AVL_DeleteItem, DeleteFromEmptyTree)
{
    AVLTree<int> tree;

    tree.DeleteItem(5);

    EXPECT_EQ(tree.ContainsItem(5), false);
}

TEST(AVL_DeleteItem, DeleteRootWithNoChildren)
{
    AVLTree<int> tree(5);

    tree.DeleteItem(5);

    std::vector<int> v = tree.InOrder();

    EXPECT_EQ(v.size(), 0);
    EXPECT_EQ(tree.ContainsItem(5), false);
}

TEST(AVL_DeleteItem, DeleteRootWithLeftChild)
{
    AVLTree<int> tree(5);

    tree.AddItem(1);

    tree.DeleteItem(5);

    std::vector<int> v = tree.InOrder();

    EXPECT_EQ(v.size(), 1);
    EXPECT_EQ(tree.ContainsItem(1), true);
    EXPECT_EQ(tree.ContainsItem(5), false);
}

TEST(AVL_DeleteItem, DeleteRootWithRightChild)
{
    AVLTree<int> tree(5);

    tree.AddItem(10);

    tree.DeleteItem(5);

    std::vector<int> v = tree.InOrder();

    EXPECT_EQ(v.size(), 1);
    EXPECT_EQ(tree.ContainsItem(10), true);
    EXPECT_EQ(tree.ContainsItem(5), false);
}

TEST(AVL_DeleteItem, DeleteRootWithBothChildren)
{
    AVLTree<int> tree(5);

    tree.AddItem(1);
    tree.AddItem(10);

    tree.DeleteItem(5);

    std::vector<int> v = tree.InOrder();

    EXPECT_EQ(v.size(), 2);
    EXPECT_EQ(tree.ContainsItem(1), true);
    EXPECT_EQ(tree.ContainsItem(10), true);
    EXPECT_EQ(tree.ContainsItem(5), false);
}

TEST(AVL_DeleteItem, DeleteNonRootWithNoChildren)
{
    AVLTree<int> tree;

    tree.AddItem(10);
    tree.AddItem(5);
    tree.AddItem(15);
    
    tree.DeleteItem(5);

    int array[2] = {10, 15};
    std::vector<int> v = tree.InOrder();

    EXPECT_EQ(v.size(), 2);
    EXPECT_EQ(tree.ContainsItem(5), false);

    for (int i = 0; i < 2; i++)
    {
        EXPECT_EQ(v.at(i), array[i]);
    }
}

TEST(AVL_DeleteItem, DeleteNonRootWithLeftChild)
{
    AVLTree<int> tree;

    tree.AddItem(10);
    tree.AddItem(5);
    tree.AddItem(15);
    tree.AddItem(3);
    
    tree.DeleteItem(5);

    int array[3] = {3, 10, 15};
    std::vector<int> v = tree.InOrder();

    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(tree.ContainsItem(5), false);

    for (int i = 0; i < 3; i++)
    {
        EXPECT_EQ(v.at(i), array[i]);
    }
}

TEST(AVL_DeleteItem, DeleteNonRootWithRightChild)
{
    AVLTree<int> tree;

    tree.AddItem(10);
    tree.AddItem(5);
    tree.AddItem(15);
    tree.AddItem(7);
    
    tree.DeleteItem(5);

    int array[3] = {7, 10, 15};
    std::vector<int> v = tree.InOrder();

    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(tree.ContainsItem(5), false);

    for (int i = 0; i < 3; i++)
    {
        EXPECT_EQ(v.at(i), array[i]);
    }
}

TEST(AVL_DeleteItem, DeleteNonRootWithBothChildren)
{
    AVLTree<int> tree;

    tree.AddItem(10);
    tree.AddItem(5);
    tree.AddItem(15);
    tree.AddItem(3);
    tree.AddItem(7);
    
    tree.DeleteItem(5);

    int array[4] = {3, 7, 10, 15};
    std::vector<int> v = tree.InOrder();

    EXPECT_EQ(v.size(), 4);
    EXPECT_EQ(tree.ContainsItem(5), false);

    for (int i = 0; i < 4; i++)
    {
        EXPECT_EQ(v.at(i), array[i]);
    }
}

TEST(AVL_DeleteItem, SingleLeftRotationOnRootNode)
{
    AVLTree<int> tree;

    tree.AddItem(10);
    tree.AddItem(5);
    tree.AddItem(15);
    tree.AddItem(20);
    
    tree.DeleteItem(5);

    int array[3] = {10, 15, 20};
    std::vector<int> v = tree.InOrder();

    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(tree.ContainsItem(5), false);

    for (int i = 0; i < 3; i++)
    {
        EXPECT_EQ(v.at(i), array[i]);
    }
}

TEST(AVL_DeleteItem, SingleRightRotationOnRootNode)
{
    AVLTree<int> tree;

    tree.AddItem(10);
    tree.AddItem(5);
    tree.AddItem(15);
    tree.AddItem(3);
    
    tree.DeleteItem(15);

    int array[3] = {3, 5, 10};
    std::vector<int> v = tree.InOrder();

    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(tree.ContainsItem(15), false);

    for (int i = 0; i < 3; i++)
    {
        EXPECT_EQ(v.at(i), array[i]);
    }
}

TEST(AVL_DeleteItem, DoubleLeftRightRotationOnRootNode)
{
    AVLTree<int> tree;

    tree.AddItem(10);
    tree.AddItem(5);
    tree.AddItem(15);
    tree.AddItem(7);
    
    tree.DeleteItem(15);

    int array[3] = {5, 7, 10};
    std::vector<int> v = tree.InOrder();

    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(tree.ContainsItem(15), false);

    for (int i = 0; i < 3; i++)
    {
        EXPECT_EQ(v.at(i), array[i]);
    }
}

TEST(AVL_DeleteItem, DoubleRightLeftRotationOnRootNode)
{
    AVLTree<int> tree;

    tree.AddItem(10);
    tree.AddItem(5);
    tree.AddItem(15);
    tree.AddItem(12);
    
    tree.DeleteItem(5);

    int array[3] = {10, 12, 15};
    std::vector<int> v = tree.InOrder();

    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(tree.ContainsItem(5), false);

    for (int i = 0; i < 3; i++)
    {
        EXPECT_EQ(v.at(i), array[i]);
    }
}

TEST(AVL_DeleteItem, SingleLeftRotationOnNonRootNode)
{
    AVLTree<int> tree;

    tree.AddItem(20);
    tree.AddItem(10);
    tree.AddItem(30);
    tree.AddItem(5);
    tree.AddItem(15);
    tree.AddItem(25);
    tree.AddItem(35);
    tree.AddItem(40);
    
    tree.DeleteItem(25);

    int array[7] = {5, 10, 15, 20, 30, 35, 40};
    std::vector<int> v = tree.InOrder();

    EXPECT_EQ(v.size(), 7);
    EXPECT_EQ(tree.ContainsItem(25), false);

    for (int i = 0; i < 7; i++)
    {
        EXPECT_EQ(v.at(i), array[i]);
    }
}

TEST(AVL_DeleteItem, SingleRightRotationOnNonRootNode)
{
    AVLTree<int> tree;

    tree.AddItem(20);
    tree.AddItem(10);
    tree.AddItem(30);
    tree.AddItem(5);
    tree.AddItem(15);
    tree.AddItem(25);
    tree.AddItem(35);
    tree.AddItem(3);
    
    tree.DeleteItem(15);

    int array[7] = {3, 5, 10, 20, 25, 30, 35};
    std::vector<int> v = tree.InOrder();

    EXPECT_EQ(v.size(), 7);
    EXPECT_EQ(tree.ContainsItem(15), false);

    for (int i = 0; i < 7; i++)
    {
        EXPECT_EQ(v.at(i), array[i]);
    }
}

TEST(AVL_DeleteItem, DoubleRotationOnNonRootNode)
{
    AVLTree<int> tree;

    tree.AddItem(20);
    tree.AddItem(10);
    tree.AddItem(30);
    tree.AddItem(5);
    tree.AddItem(15);
    tree.AddItem(25);
    tree.AddItem(35);
    tree.AddItem(13);
    
    tree.DeleteItem(5);

    int array[7] = {10, 13, 15, 20, 25, 30, 35};
    std::vector<int> v = tree.InOrder();

    EXPECT_EQ(v.size(), 7);
    EXPECT_EQ(tree.ContainsItem(5), false);

    for (int i = 0; i < 7; i++)
    {
        EXPECT_EQ(v.at(i), array[i]);
    }
}