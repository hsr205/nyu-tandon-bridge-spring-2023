/*
INSTRUCTIONS
In this assignment, it is required that you fill out areas under comments labeled as "TODO" appropriately based on the accompanying directions.
You are also required to follow any directions accompanying comments such as "NOTE".
You can add/modify code anywhere, with the exception of the provided "main" (which we will use for testing).
You can use the constants RED and BLACK, instead of the ints 0 and 1, when appropriate.
*/

#include <iostream>
#include <math.h> // for asserting height
#include <cassert>
#include <queue>

using namespace std;

#define RED 0
#define BLACK 1

template <class T>
class RBT;

// swapColor swaps the color from red to black and vice versa
int swapColor(int c)
{
    return (c == 0) ? 1 : 0;
}

template <class T>
class RBTNode
{
private:
    T data;
    int color;
    RBTNode<T> *parent;
    RBTNode<T> *left;
    RBTNode<T> *right;

public:
    RBTNode(T data)
        : data(data),
          color(RED),
          parent(nullptr),
          left(nullptr),
          right(nullptr) {}

    friend class RBT<T>;

    template <class T1>
    friend void swapColor(RBTNode<T1> *node)
    {
        if (node != nullptr)
        {
            node->color = swapColor(node->color);
        }
    };

    template <class T1>
    friend int getColor(RBTNode<T1> *node)
    {
        if (node != nullptr)
        {
            return node->color;
        }
        return BLACK;
    };

    void prettyPrint(int indent) const
    {
        if (right != nullptr)
        {
            right->prettyPrint(indent + 1);
        }
        int margin = indent * 2;
        for (int i = 0; i < margin; ++i)
        {
            cout << '\t';
        }
        cout << "DATA: " << data << endl;
        for (int i = 0; i < margin; ++i)
        {
            cout << '\t';
        }
        cout << "COLOR: " << (color == RED ? "RED" : "BLACK") << endl;
        if (left != nullptr)
        {
            left->prettyPrint(indent + 1);
        }
    };

    int height() const
    {
        int left_h = 0;
        int right_h = 0;

        if (left != nullptr)
        {
            left_h = left->height();
        }
        if (right != nullptr)
        {
            right_h = right->height();
        }
        return 1 + max(left_h, right_h);
    };
};

template <class T>
class RBT
{
private:
    RBTNode<T> *root;
    void singleCCR(RBTNode<T> *&point)
    {
        RBTNode<T> *grandparent = point;
        RBTNode<T> *parent = point->right;
        // TODO: ADD ROTATION CODE HERE
    };
    void doubleCR(RBTNode<T> *&point)
    {
        singleCCR(point->left);
        singleCR(point);
    };
    void singleCR(RBTNode<T> *&point)
    {
        RBTNode<T> *grandparent = point;
        RBTNode<T> *parent = point->left;
        // TODO: ADD ROTATION CODE HERE
    };
    void doubleCCR(RBTNode<T> *&point)
    {
        singleCR(point->right);
        singleCCR(point);
    };

public:
    RBT() : root(nullptr) {}

    void insert(const T &);
    void insert(const T &toInsert, RBTNode<T> *&point, RBTNode<T> *parent)
    {
        if (point == nullptr)
        {                                     // leaf location is found so insert node
            point = new RBTNode<T>(toInsert); // modifies the pointer itself since *point
                                              // is passed by reference
            point->parent = parent;

            RBTNode<T> *curr_node = point; // curr_node will be set appropriately when walking up the tree
            // TODO: ADD RBT RULES HERE
        }
        else if (toInsert < point->data)
        { // recurse down the tree to left to find correct leaf location
            insert(toInsert, point->left, point);
        }
        else
        { // recurse down the tree to right to find correct leaf location
            insert(toInsert, point->right, point);
        }
    };

    void prettyPrint() const
    {
        root->prettyPrint(0);
    }

    int height() const
    {
        return root->height();
    }
};

template <class T>
void RBT<T>::insert(const T &toInsert)
{
    insert(toInsert, root, nullptr);
}

// NOTE: DO NOT MODIFY THE MAIN FUNCTION BELOW
int main()
{
    RBT<int> b;
    int count = 10;
    for (int i = 0; i < count; i++)
    {
        b.insert(i);
    }
    b.prettyPrint();
    /* EXPECTED OUTPUT:
                                                                    Data: 9
                                                                    COLOR: RED
                                                    Data: 8
                                                    COLOR: BLACK
                                    Data: 7
                                    COLOR: RED
                                                    Data: 6
                                                    COLOR: BLACK
                    Data: 5
                    COLOR: BLACK
                                    Data: 4
                                    COLOR: BLACK
    Data: 3
    COLOR: BLACK
                                    Data: 2
                                    COLOR: BLACK
                    Data: 1
                    COLOR: BLACK
                                    Data: 0
                                    COLOR: BLACK
    */
    // TEST
    // the below tests the validity of the height of the RBT
    // if the assertion fails, then your tree does not properly self-balance
    int height = b.height();
    assert(height <= 2 * log2(count));
    cout << endl;
    cout << "---------------------" << endl;
    cout << endl;
    RBT<int> c;
    count = 5;
    for (int i = count; i > 0; i--)
    {
        c.insert(i);
    }
    c.prettyPrint();
    /* EXPECTED OUTPUT:
                    Data: 5
                    COLOR: BLACK
    Data: 4
    COLOR: BLACK
                                    Data: 3
                                    COLOR: RED
                    Data: 2
                    COLOR: BLACK
                                    Data: 1
                                    COLOR: RED
    */
    height = c.height();
    assert(height <= 2 * log2(count));
}