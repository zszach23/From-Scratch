// ============================================================================
// AVLTree: testsuite_01.cpp
//
// Test Suite for AVL Tree Constructors
// ============================================================================

#include "AVLTree.hpp"
#include <gtest/gtest.h>

TEST(AVL_Constructor, DefaultConstructor)
{
    AVLTree<int> tree;

    EXPECT_EQ(tree.GetHeight(), -1);
}

TEST(AVL_Constructor, RootConstructor)
{
    AVLTree<int> tree(5);

    EXPECT_EQ(tree.GetHeight(), 0);
    EXPECT_EQ(tree.ContainsItem(5), true);
}

