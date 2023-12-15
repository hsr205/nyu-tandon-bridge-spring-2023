#include <iostream>

using namespace std;

class Node
{

private:
    int value;

public:
    Node() = default;
    ~Node() = default;

    int getValue()
    {
        return value;
    }
};

/*
    NOTE:

    *THIS SHOULD BE DONE RECURSIVELY*

    The parent (or root) node needs to check it's value (valid values are 0,1,2) and then proceed to check it's children (if there are any).

    Scenarios:

    (1) If the root node has a value of 0 then it should NOT have any children and return false as this structure is not a tree but a single node.

    (2) If the root node has a value of 1 then it should have one child and return false as this structure is not a tree but a linked list.

    (3) If the root node is 2 and the children have values of 0 then return true.

    (4) If the parent node (that is not the root) is 0 then it should have no children and return true. If it has children then return false.

    (5) If the parent node (that is not the root) is 1 then 1 of it's children should not point to nullptr and return true. If both children point to nullptr return false.

    (6) If the parent node (that is not the root) is 2 then both of it's children should not point to nullptr and return true. If either child points to nullptr return false.

    

*/

class BinarySearchTree
{

private:
public:
    Node data;
    Node *left = nullptr;
    Node *right = nullptr;
    Node *parent = nullptr;

    BinarySearchTree() = default;
    ~BinarySearchTree() = default;

    bool is_valid(Node *root)
    {

        if (root->getValue() == 0 || root->getValue() == 1 || root->getValue() > 2)
        {
            return false;
        }

        if (root->getValue() == 2 && left == nullptr || right == nullptr)
        {
            return true;
        }

        if (parent->getValue() == 0 && left == nullptr || right == nullptr)
        {
            return true;
        }

        if (parent->getValue() == 1 && left == nullptr && right == nullptr)
        {
            return false;
        }

        if (parent->getValue() == 1 && left != nullptr || right != nullptr)
        {
            return true;
        }

        if (parent->getValue() == 2 && left != nullptr && right != nullptr)
        {
            return true;
        }

        return false;
    }
};
