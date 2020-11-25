//
// Created by Nuha Rahman on 11/12/20.
//
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <stack>
#include "MyTree.h"

using namespace std;

MyTree::MyTree() : root_(nullptr), numNodes_(0) {}

MyTree::~MyTree() {
    // Delete all nodes except the root
    deleteTree(root_);
    root_ = nullptr;
}

BinaryNode *MyTree::Insert(const string &s, int x) {
    BinaryNode *node = new BinaryNode(s, x);
    BinaryNode* temp;
    if (root_ == nullptr) {
        root_ = node;
        numNodes_++;
        return node;
    }

    queue<BinaryNode*> treeQ;
    treeQ.push(root_);

    while (!treeQ.empty()) {
        temp = treeQ.front();
        treeQ.pop();

        if (temp->left == nullptr) {
            temp->left = node;
            node->parent = temp;
            break;
        }

        else {
            treeQ.push(temp->left);
        }

        if (temp->right == nullptr) {
            temp->right = node;
            node->parent = temp;
            break;
        }

        else {
            treeQ.push(temp->right);
        }

    }

    numNodes_++;
    return node;

}




void MyTree::Preorder() const {
    PreorderRecursive(root_);
    cout << endl;
}


BinaryNode *MyTree::FindMax() const {
    vector <pair <string, int> > inOrderVec = createVector();
    int i = 0;

    int max = inOrderVec[0].second;
    int maxIndex = 0;

    for (unsigned i = 1; i < numNodes_; i++) {
        if (inOrderVec[i].second > max) {
            max = inOrderVec[i].second;
            maxIndex = i;
        }
    }


    BinaryNode* curr = new BinaryNode(inOrderVec[maxIndex].first, inOrderVec[maxIndex].second);
    //cout << "MAX: " << curr->myInt << endl;

    return curr;

}

void MyTree::MakeBST() {
    vector<pair <string, int> > vec = createVector();
    int index = 0;
    unsigned int k = 0;
    pair <string, int> temp;
    for (unsigned i = 1; i < numNodes_; i++) {
        k = i;
        while (k > 0 && (vec[k].second < vec[k - 1].second)) {
            temp = vec[k];
            vec[k] = vec[k - 1];
            vec[k - 1] = temp;
            k--;
        }

    }
        VectorToBST(root_, vec, index);



    return;
}

void MyTree::VectorToBST(BinaryNode* curr, vector<pair <string, int> > vec, int index) {
    if (curr != nullptr) { //idk chief
        VectorToBST(curr->left, vec, index);
        // change the current element of Tree with current element of list
        curr->myInt = vec[index].second;
        curr->myString = vec[index].first;
        index++;

        VectorToBST(curr->right, vec, index + 1);
    }


}





void MyTree::PreorderRecursive(BinaryNode* curr) const {
    if (curr != nullptr) { //can u access my string like this?
        cout << curr->myString << ' ';
        PreorderRecursive(curr->left);
        PreorderRecursive(curr->right);
    }

    return;


}



vector<pair <string, int> > MyTree::createVector() const {
    stack <BinaryNode*> temp;
    vector <pair <string, int> > vec;
    vec.resize(numNodes_);
    unsigned int i = 0;
    BinaryNode *node;
    BinaryNode *curr = root_;
    while (curr != nullptr || !(temp.empty())) {
        while (curr != nullptr) {
            temp.push(curr);
            curr = curr->left;
        }
        curr = temp.top();
        temp.pop();
        string tempStr = curr->myString;
        int tempInt = curr->myInt;
        vec[i] = make_pair(tempStr, tempInt);
        i++;
        curr = curr->right;

    }

    return vec;
}


void MyTree::deleteTree(BinaryNode* curr) {
    if (curr == nullptr) {
        return;
    }
    deleteTree(curr->left);
    deleteTree(curr->right);


    //cout << "Deleting node: " << curr->myInt << endl;
    delete curr;

}



