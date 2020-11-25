//
// Created by Nuha Rahman on 11/12/20.
//
#include <ctime>
#include <vector>
#include <iostream>
#include "MyTree.h"
#include <string>

using namespace std;
// Testing (you must implement yours for the perfomance studies)




string createString() {
    //hexadecimal characters
    string str;
    char hex_characters[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F', 'g', 'h', 'x'};

    int i;
    for(unsigned i=0; i < 7; i++) {
        str += hex_characters[rand()%16];
    }

    return str;
}


int main() {
    MyTree tree;
    srand(time(0));
    int size;
    string str;
    vector<int> myInts;
    vector<string> myStrings;

    cout << "size?" << endl;
    cin >> size;
    myStrings.resize(size);
    myInts.resize(size);

    for (unsigned int i = 0; i < size; i++) {
        str = createString();
        myStrings.push_back(str);
        myInts.push_back(rand() % (size - 34));

    }



    auto start = std::chrono::high_resolution_clock::now();
    for (unsigned int i = 0; i < size; i++) {
        tree.Insert(myStrings[i], myInts[i]);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    cout << "Insert: " << elapsed.count() << endl;


    start = std::chrono::high_resolution_clock::now();
    tree.Preorder();
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    cout << "Preorder: " << elapsed.count() << endl;



    start = std::chrono::high_resolution_clock::now();
    tree.FindMax();
    end = std::chrono::high_resolution_clock::now();
     elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    cout << "FindMax: " << elapsed.count() << endl;


    start = std::chrono::high_resolution_clock::now();
    tree.MakeBST();
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    cout << "MakeBST: " << elapsed.count() << endl;



/*

    tree.Insert("b", 2);
    tree.Insert("a", 1);
    tree.Insert("g", 7);
    tree.Insert("c", 3);
    tree.Insert("f", 6);
    tree.Insert("e", 5);
    tree.Insert("d", 4);

    tree.Preorder();
    tree.FindMax();

    tree.MakeBST();
*/


    // ...
    return 0;
}