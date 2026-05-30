// ============================================================================
// AVLTree: testsuite_06.cpp
//
// Test Suite for AVL Tree GetHeight()
// ============================================================================

#include "AVLTree.hpp"
#include <cstdlib>
#include <cmath>
#include <gtest/gtest.h>

TEST(AVL_GetHeight, EmptyTree)
{
    AVLTree<int> tree;

    EXPECT_EQ(tree.GetHeight(), -1);
}

TEST(AVL_GetHeight, OneItemInTree)
{
    AVLTree<int> tree(5);

    EXPECT_EQ(tree.GetHeight(), 0);
}

TEST(AVL_GetHeight, ManyRandomItemsInTree)
{
    AVLTree<int> tree;

    for (int i = 0; i < 1000; i++)
    {
        tree.AddItem(rand() % 1000);
    }

    // Loose upper bound
    EXPECT_LE(tree.GetHeight(), 2 * std::ceil(std::log2(1001)));
}

TEST(AVL_GetHeight, ManySequentialItemsInTree)
{
    AVLTree<int> tree;

    for (int i = 0; i < 1000; i++)
    {
        tree.AddItem(i);
    }

    EXPECT_LE(tree.GetHeight(), std::log2(1000) + 1);
}