// ============================================================================
// LinkedList: testsuite_08.cpp
//
// Test Suite for LinkedList PeekBack()
// ============================================================================

#include "LinkedList.hpp"
#include <gtest/gtest.h>

TEST(LL_PeekBack, EmptyList)
{
    LinkedList<int> list;

    EXPECT_EQ(list.PeekBack(), 0);
}

TEST(LL_PeekBack, OneItemInList)
{
    int array[1] = {1};
    LinkedList<int> list(array, 1);

    EXPECT_EQ(list.PeekBack(), 1);
}

TEST(LL_PeekBack, MultipleItemsInList)
{
    int array[5] = {1, 2, 3, 4, 5};
    LinkedList<int> list(array, 5);

    EXPECT_EQ(list.PeekBack(), 5);
}