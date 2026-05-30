# LinkedList

## Overview
A linked list is a data structure that acts as a chain of nodes.

```
0x42          +--> 0x19          +--> 0x98
+------+      |    +------+      |    +------+
|  62  |      |    |  42  |      |    |  12  |
|------|      |    |------|      |    |------|
| 0x19 | -----+    | 0x98 | -----+    | null |
+------+           +------+           +------+

   ^^                                    ^^
  Head (0x42)                           Tail (0x98)
```

- The **head** of the linked list is the first node in the chain.
- The **tail** of the linked list is the last node in the chain.
- Each **node** is a data container that store some data and a pointer/reference to the *next* node in the chain

## Pros and Cons
**Pros:**
- LinkedLists have dynamic sizing
- Adding and Deleting the head node is an O(1) operation
- Non-Contiguous nodes can be separate in memory

**Cons:**
- Searching for a specified index is O(n), where *n* is the number of nodes in the list
- Less memory efficient than an array

## Implementation
In `src/` is an implementation of a LinkedList in C++ that can store any data type using templates. The following operations are implemented:

- `LinkedList()`: Constructs an empty list

- `LinkedList(AnyType array[], int length)`: Constructs a LinkedList with elements of array

- `~LinkedList()`: Deconstructs the LinkedList

- `void Prepend(AnyType item)`: Add item to beginning of the LinkedList

- `void Append(AnyType item)`: Add item to end of the LinkedList

- `AnyType Get(int index)`: Get the item at the specified index

- `int GetIndexOf(AnyType item)`: Get the index of the first occurrence of item in LinkedList

- `AnyType PeekFront()`: Returns the first item in LinkedList

- `AnyType PeekBack()`: Returns the last item in LinkedList

- `AnyType RemoveHead()`: Delete the head of the LinkedList

- `AnyType RemoveTail()`: Delete the tail of the LinkedList

- `void PrintList()`: Prints the contents of the LinkedList

- `int Size()`: Returns the current size of the LinkedList

## Unit Testing
In `tests/` is a list of test suites that test the functionality of the LinkedList implementation. The tests were developed using CMake and the GoogleTest framework. The following test suites are defined:

- `testsuite_01.cpp`: Tests Constructors

- `testsuite_02.cpp`: Tests Functionality of `Prepend()`

- `testsuite_03.cpp`: Tests Functionality of `Get()`

- `testsuite_04.cpp`: Tests Functionality of `GetIndexOf()`

- `testsuite_05.cpp`: Tests Functionality of `RemoveHead()`

- `testsuite_06.cpp`: Tests Functionality of `RemoveTail()`

- `testsuite_07.cpp`: Tests Functionality of `PeekFront()`

- `testsuite_08.cpp`: Tests Functionality of `PeekBack()`

- `testsuite_09.cpp`: Tests Functionality of `Append()`

### Running Unit Tests
First, ensure CMake is installed on your system.

Once CMake is installed, run the following commands:
```
cd Data-Structures/LinkedList   # Go to LinkedList root directory

mkdir build                     # Create a directory called build

cd build                        # Go into the build directory

cmake ..                        # Run CMake

cmake --build .                 # Build test files

ctest                           # Run test files
```