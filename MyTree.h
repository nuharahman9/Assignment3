

#ifndef _MYTREE_H
#define _MYTREE_H

#include <cstdio>
#include <vector>
#include <string>

using namespace std;

typedef struct BinaryNode {
    int myInt;
    string myString;
    BinaryNode *parent;
    BinaryNode *left;
    BinaryNode *right;

    BinaryNode(const string &s, int x) : myString(s), myInt(x), parent(nullptr), left(nullptr), right(nullptr) {}
} BinaryNode;

class MyTree {
public:
    MyTree();
    ~MyTree();  // Delete all nodes in the tree

    size_t NumNodes() const { return numNodes_; };

    // Insert new node into first available position (to keep the tree almost
    // complete), return the created node.
    BinaryNode *Insert(const string &s, int x);

    // Output all strings in pre-order
    // all the strings will be print in one line separated by spaces
    void Preorder() const;

    // Returns a pointer to the node with maximum myInt
    BinaryNode *FindMax() const;

    // Converts the binary tree into a binary search tree (BST) with respect to
    // myInt. That is, move around node values (myString and myInt) to satisfy the
    // BST property.
    void MakeBST();

private:
    BinaryNode *root_;
    void PreorderRecursive(BinaryNode* curr) const;
    void VectorToBST(BinaryNode* curr, vector<pair <string, int> > vec, int index);
    vector<pair <string, int> > createVector() const;
    void deleteTree(BinaryNode* curr);
    size_t numNodes_;
};

#endif //_MYTREE_H
