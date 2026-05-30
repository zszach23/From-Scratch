// ============================================================================
// AVLTree: testsuite_02.cpp
//
// Test Suite for AVL Tree InOrder()
// ============================================================================

#include "AVLTree.hpp"
#include <gtest/gtest.h>
#include <vector>

TEST(AVL_InOrder, TraverseEmptyTree)
{
    AVLTree<int> tree;

    std::vector<int> v = tree.InOrder();

    EXPECT_EQ(v.empty(), true);
}

TEST(AVL_InOrder, TraverseSingleItemTree)
{
    AVLTree<int> tree(5);

    std::vector<int> v = tree.InOrder();

    EXPECT_EQ(v.size(), 1);
    EXPECT_EQ(v.front(), 5);
}

TEST(AVL_InOrder, TraverseMultipleItemsTree)
{
    AVLTree<int> tree;

    tree.AddItem(5);
    tree.AddItem(10);
    tree.AddItem(15);
    tree.AddItem(0);
    tree.AddItem(1);
    tree.AddItem(4);
    tree.AddItem(2);
    tree.AddItem(3);
    tree.AddItem(20);
    tree.AddItem(25);

    int array[10] = {0, 1, 2, 3, 4, 5, 10, 15, 20, 25};
    std::vector<int> v = tree.InOrder();

    for (int i = 0; i < 10; i++)
    {
        EXPECT_EQ(v.at(i), array[i]);
    }
}