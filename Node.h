// Created by Dr. Augustine and Modified by Rory Flynn 
// 11/29/2018
// Removed the general struct it will be replaced by the content in ActoressPictsDef.h
#ifndef NODE_
#define NODE_
#include <iostream>
#include <string>
using namespace std;

// A tree node class for ints

//Placeholder for a composite data type
//struct GeneralData
//{
//    int number; //Update this to your data field  
//	string name;
//};
typedef std::string word;

//Binary Tree Node
template <typename DATATYPE, typename KEYTYPE>
class Node {
private:
    word key; //This should be the datatype of your key...sorted field in tree
    DATATYPE data;
    Node<DATATYPE, KEYTYPE> * left;
    Node<DATATYPE, KEYTYPE> * right;
    Node<DATATYPE, KEYTYPE> * parent;
public:
    Node() {left=nullptr; right=nullptr; parent = nullptr;};
    void setKey(KEYTYPE aKey) { key = aKey; };
	void setData(DATATYPE aData) { data = aData; }
    void setLeft(Node<DATATYPE, KEYTYPE> * aLeft) { left = aLeft; };
    void setRight(Node<DATATYPE, KEYTYPE> * aRight) { right = aRight; };
    void setParent(Node<DATATYPE, KEYTYPE> * aParent) { parent = aParent; };
    KEYTYPE Key() { return key; };
	DATATYPE Data() { return data; }
    Node<DATATYPE, KEYTYPE> * Left() { return left; };
    Node<DATATYPE, KEYTYPE> * Right() { return right; };
    Node<DATATYPE, KEYTYPE> * Parent() { return parent; };
};

#endif
