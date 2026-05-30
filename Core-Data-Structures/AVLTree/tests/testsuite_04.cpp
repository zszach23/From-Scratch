// ============================================================================
// AVLTree: testsuite_04.cpp
//
// Test Suite for AVL Tree ContainsItem()
// ============================================================================

#include "AVLTree.hpp"
#include <gtest/gtest.h>
#include <vector>

TEST(AVL_ContainsItem, EmptyTree)
{
    AVLTree<int> tree;

    EXPECT_EQ(tree.ContainsItem(0), false);
}

TEST(AVL_ContainsItem, OneItemInTree)
{
    AVLTree<int> tree(5);

    EXPECT_EQ(tree.ContainsItem(5), true);
}

TEST(AVL_ContainsItem, MultipleItemsInTree)
{
    AVLTree<int> tree;

    tree.AddItem(1);
    tree.AddItem(2);
    tree.AddItem(3);
    tree.AddItem(4);
    tree.AddItem(5);

    EXPECT_EQ(tree.ContainsItem(1), true);
    EXPECT_EQ(tree.ContainsItem(2), true);
    EXPECT_EQ(tree.ContainsItem(3), true);
    EXPECT_EQ(tree.ContainsItem(4), true);
    EXPECT_EQ(tree.ContainsItem(5), true);
}