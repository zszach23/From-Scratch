// ============================================================================
// LinkedList: testsuite_06.cpp
//
// Test Suite for LinkedList RemoveTail()
// ============================================================================

#include "LinkedList.hpp"
#include <gtest/gtest.h>

TEST(LL_RemoveTail, EmptyList)
{
    LinkedList<int> list;

    EXPECT_EQ(list.RemoveTail(), 0);
    EXPECT_EQ(list.Size(), 0);
}

TEST(LL_RemoveTail, OneItemInList)
{
    int array[1] = {1};
    LinkedList<int> list(array, 1);

    EXPECT_EQ(list.RemoveTail(), 1);
    EXPECT_EQ(list.Size(), 0);
}

TEST(LL_RemoveTail, MultipleItemsInList)
{
    int array[5] = {1, 2, 3, 4, 5};
    LinkedList<int> list(array, 5);

    EXPECT_EQ(list.RemoveTail(), 5);
    EXPECT_EQ(list.Size(), 4);
    
    EXPECT_EQ(list.RemoveTail(), 4);
    EXPECT_EQ(list.Size(), 3);

    EXPECT_EQ(list.RemoveTail(), 3);
    EXPECT_EQ(list.Size(), 2);

    EXPECT_EQ(list.RemoveTail(), 2);
    EXPECT_EQ(list.Size(), 1);

    EXPECT_EQ(list.RemoveTail(), 1);
    EXPECT_EQ(list.Size(), 0);
}