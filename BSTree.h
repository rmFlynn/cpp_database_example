//To be used in conjunction with Node.h and BSTree<DATATYPE, KEYTYPE>.cpp
//If you modify this, please add your name and list any changes that you made
#ifndef BSTREEINT_H
#define BSTREEINT_H
#include <iostream>
#include <queue>
using namespace std;
#include "Node.h"

// Binary Search Tree class
template <typename DATATYPE, typename KEYTYPE>
class BSTree {
private:
    Node<DATATYPE, KEYTYPE> * root;
    void addNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * leaf, DATATYPE& data);
    Node<DATATYPE, KEYTYPE> * deleteNode(Node<DATATYPE, KEYTYPE> * node, KEYTYPE key);
    void freeNode(Node<DATATYPE, KEYTYPE> * leaf);
	void printInorder(Node<DATATYPE, KEYTYPE> * node);
	Node<DATATYPE, KEYTYPE> * findNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * node);
    //Values for iterReturn
    queue<Node<DATATYPE, KEYTYPE> * > pastNodes;
    //Node<DATATYPE, KEYTYPE> * lastNode = nullptr;
    bool done = false;
public:
    BSTree<DATATYPE, KEYTYPE>();
    ~BSTree<DATATYPE, KEYTYPE>();
    BSTree<DATATYPE, KEYTYPE>(const BSTree<DATATYPE, KEYTYPE> & t1);
    Node<DATATYPE, KEYTYPE> * Root() { return root; }
    void setRoot(Node<DATATYPE, KEYTYPE> * _root) {root = _root;}
    void addNode(KEYTYPE key, DATATYPE &data);
	Node<DATATYPE, KEYTYPE> * findNode(KEYTYPE key);
	void printInorder();
	void print(ostream & out, const DATATYPE & data);
    void deleteNode(KEYTYPE key);
	Node<DATATYPE, KEYTYPE> * min(Node<DATATYPE, KEYTYPE> * node);
    //My functions
    bool iterReturn(DATATYPE & data);
    bool minPop(DATATYPE & mini);
	Node<DATATYPE, KEYTYPE> * max(Node<DATATYPE, KEYTYPE> * node);
};
#endif  //BST
