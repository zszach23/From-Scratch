// ============================================================================
// AVLTree: testsuite_03.cpp
//
// Test Suite for AVL Tree AddItem()
// ============================================================================

#include "AVLTree.hpp"
#include <gtest/gtest.h>
#include <vector>

TEST(AVL_AddItem, AddToEmptyTree)
{
    AVLTree<int> tree;

    tree.AddItem(5);

    std::vector<int> v = tree.InOrder();

    EXPECT_EQ(v.size(), 1);
    EXPECT_EQ(v.at(0), 5);
}

TEST(AVL_AddItem, AddToTreeWithOneItemGreater)
{
    AVLTree<int> tree(5);

    tree.AddItem(10);

    std::vector<int> v = tree.InOrder();

    EXPECT_EQ(v.size(), 2);
    EXPECT_EQ(v.at(0), 5);
    EXPECT_EQ(v.at(1), 10);
}

TEST(AVL_AddItem, AddToTreeWithOneItemLess)
{
    AVLTree<int> tree(5);

    tree.AddItem(1);

    std::vector<int> v = tree.InOrder();

    EXPECT_EQ(v.size(), 2);
    EXPECT_EQ(v.at(0), 1);
    EXPECT_EQ(v.at(1), 5);
}

TEST(AVL_AddItem, SingleRotationOnNonRootNode)
{
    AVLTree<int> tree;

    tree.AddItem(10);
    tree.AddItem(5);
    tree.AddItem(15);
    tree.AddItem(3);
    tree.AddItem(1);

    int array[5] = {1, 3, 5, 10, 15};
    std::vector<int> v = tree.InOrder();

    for (int i = 0; i < 5; i++)
    {
        EXPECT_EQ(v.at(i), array[i]);
    }
}

TEST(AVL_AddItem, AddDuplicateRoot)
{
    AVLTree<int> tree;

    tree.AddItem(1);
    tree.AddItem(1);

    std::vector<int> v = tree.InOrder();

    EXPECT_EQ(v.size(), 1);
    EXPECT_EQ(v.at(0), 1);
}

TEST(AVL_AddItem, AddDuplicateNonRoot)
{
        AVLTree<int> tree(1);

    tree.AddItem(0);
    tree.AddItem(0);

    tree.AddItem(5);
    tree.AddItem(5);

    std::vector<int> v = tree.InOrder();

    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v.at(0), 0);
    EXPECT_EQ(v.at(1), 1);
    EXPECT_EQ(v.at(2), 5);
}

TEST(AVL_AddItem, DoubleRotationOnNonRootNode)
{
    AVLTree<int> tree;

    tree.AddItem(10);
    tree.AddItem(5);
    tree.AddItem(15);
    tree.AddItem(3);
    tree.AddItem(4);

    int array[5] = {3, 4, 5, 10, 15};
    std::vector<int> v = tree.InOrder();

    for (int i = 0; i < 5; i++)
    {
        EXPECT_EQ(v.at(i), array[i]);
    }
}

TEST(AVL_AddItem, SingleRotationOnRootNode)
{
    AVLTree<int> tree;

    tree.AddItem(10);
    tree.AddItem(5);
    tree.AddItem(3);

    int array[3] = {3, 5, 10};
    std::vector<int> v = tree.InOrder();

    for (int i = 0; i < 3; i++)
    {
        EXPECT_EQ(v.at(i), array[i]);
    }
}

TEST(AVL_AddItem, DoubleRotationOnRootNode)
{
    AVLTree<int> tree;

    tree.AddItem(10);
    tree.AddItem(5);
    tree.AddItem(7);

    int array[3] = {5, 7, 10};
    std::vector<int> v = tree.InOrder();

    for (int i = 0; i < 3; i++)
    {
        EXPECT_EQ(v.at(i), array[i]);
    }
}

TEST(AVL_AddItem, MultipleRotations)
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
    tree.AddItem(7);

    int array[9] = {3, 5, 7, 10, 15, 20, 25, 30, 35};
    std::vector<int> v = tree.InOrder();

    for (int i = 0; i < 9; i++)
    {
        EXPECT_EQ(v.at(i), array[i]);
    }
}

