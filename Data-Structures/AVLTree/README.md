# AVL Tree

## Overview
An AVL Tree is a self-balancing Binary Search Tree (BST). Its purpose is to prevent a BST from devolving into a LinkedList by keeping the height of the tree logarithmic in relation to the number of nodes in the tree.

```
    10      <-- root
   /  \     
  5    15
 / \  /  \
3   7 12  20
```

- The **root** of the AVL Tree is the top-most node with no parent
- Each **node** is a data container that store some data and a pointer/reference to its *left* and *right* child nodes
- Any given node has a **left child** and a **right child**
- Any item in a node's **left subtree** must be **smaller** than the node's item
- Any item in a node's **right subtree** must be **greater** than the node's item
- The **height** of the given tree is how many "vertical layers" there are in the subtree

## Self-Balancing
AVL trees' main goal is to maintain a logarithmic height in relation to the number of nodes in the tree. It does so by performing self-balance operations.

A node's **balance factor** can be thought of as the difference between the left subtree's height and the right subtree's height. In other words, `BF = height(leftChild) - height(rightChild)`. An AVL tree is balanced in any of these cases:
- `BF = -1`: The left subtree has one less level than the right subtree (right heavy)
- `BF = 0`: The left subtree has the same number of levels as the right subtree
- `BF = 1`: The left subtree has one more level than the right subtree (left heavy)

```
                10 (BF = 0)
               /  \     
    (BF = 1)  5    15  (BF = -1)
             /       \
  (BF = 0)  3         20 (BF = 0)
```

When an imbalance occurs (BF > 1 or BF < -1), we perform **rotations** on the nodes in order to balance the tree.

### Left Rotation
When the **root** is **right heavy** and the **right child** is **right heavy**:
1. The **right child** is pulled up to become the **new root**
2. The **old root** is pulled down to become **new root's** **left child**
3. The **old root** takes in **new root's** orphaned **left child** as its **left child**

### Right Rotation
When the **root** is **left heavy** and the **left child** is **left heavy**:
1. The **left child** is pulled up to become the **new root**
2. The **old root** is pulled down to become **new root's** **right child**
3. The **old root** takes in **new root's** orphaned **right child** as its **right child**

### Double Rotation
When the **root** is **left heavy** and the **right child** is **right heavy**:
1. Perform a **left rotation** on **right child**.
2. Perform a **right rotation** on **root**.

When the **root** is **left heavy** and the **left child** is **right heavy**:
1. Perform a **right rotation** on **left child**.
2. Perform a **left rotation** on **root**.


## Implementation
In `src/` is an implementation of an AVL Tree in C++ that can store any data type that can use comparison operators using templates. The following operations are implemented:

- `AVLTree()`: Constructs an empty tree

- `AVLTree(AnyType item)`: Constructs a tree that has a root with item

- `~AVLTree()`: Deconstructs the tree

- `std::vector InOrder()`: Creates a vector containing the in-order traversal of items in tree

- `void AddItem(AnyType item)`: Add item to the tree, disallows duplicates

- `bool ContainsItem(AnyType item)`: Determines if item is in the tree

- `void DeleteItem(AnyType item)`: Deletes item from tree

- `int GetHeight()`: Returns the height of the tree

## Unit Testing
In `tests/` is a list of test suites that test the functionality of the LinkedList implementation. The tests were developed using CMake and the GoogleTest framework. The following test suites are defined:

- `testsuite_01.cpp`: Tests Constructors

- `testsuite_02.cpp`: Tests Functionality of `InOrder()`

- `testsuite_03.cpp`: Tests Functionality of `AddItem()`

- `testsuite_04.cpp`: Tests Functionality of `ContainsItem()`

- `testsuite_05.cpp`: Tests Functionality of `DeleteItem()`

- `testsuite_06.cpp`: Tests Functionality of `GetHeight()`

### Running Unit Tests
First, ensure CMake is installed on your system.

Once CMake is installed, run the following commands:
```
cd Data-Structures/AVLTree      # Go to AVLTree root directory

mkdir build                     # Create a directory called build

cd build                        # Go into the build directory

cmake ..                        # Run CMake

cmake --build .                 # Build test files

ctest                           # Run test files
```