//To be used in conjunction with BSTree.h and Node.h
//When you modify this, please add your name and list any changes that you made
//A few member functions have been left blank so you, the student can implemement

/*Template Directions: #include "BSTREEInt.hpp"
but do NOT compile it (or add it to the project)*/
#include "Node.h"
#include "BSTree.h"

// Constructor
template <typename DATATYPE, typename KEYTYPE>
BSTree<DATATYPE, KEYTYPE>::BSTree() {
    root = nullptr;
}

// Destructor
template <typename DATATYPE, typename KEYTYPE>
BSTree<DATATYPE, KEYTYPE>::~BSTree() {
    if (root !=nullptr)
        freeNode(root);
}

// Copy constructor
//
// Never mind
//
// template <typename DATATYPE, typename KEYTYPE>
// BSTree<DATATYPE, KEYTYPE>::BSTree(const BSTree<DATATYPE, KEYTYPE> & t1){
//     DATATYPE data;
//     while(iterReturn(data)){
// 
//     }
// }
// Iteritive return
// Ech call returns one node it the tree untill all are viseted.
template <typename DATATYPE, typename KEYTYPE>
bool BSTree<DATATYPE, KEYTYPE>::iterReturn(DATATYPE & data){
    // If the last node is a nullptr this is eather the start or end of a call set
    if(pastNodes.empty()){
        if(done){
            // the next run will be start so reset done
           done = false;
            // indicat a end of tree
            return false;
        }
        // See if there is any tree
        if (Root() == nullptr){
            return false;// You are done return false
        }
        // other wise get the min pointer
        else{
            Node<DATATYPE, KEYTYPE> * current = Root();
            /* loop down to find the leftmost leaf */
            while (current->Left() != nullptr){
                // push back all pasing nodes for lator
                pastNodes.push(current);
                current = current->Left();
            }
            if(current->Right() != nullptr)
                pastNodes.push(current->Right());

            data = current->Data();
            //TEST//cout << data;
            return true;
        }
    }    
    // If it is not empty then the next node is the top node
    else{
        Node<DATATYPE, KEYTYPE> * current = pastNodes.front();
        pastNodes.pop();
        data = current->Data();
        //TEST//cout << data;
        if(current->Right() != nullptr){
            current = current->Right();
            while (current->Left() != nullptr){
                // push back all pasing nodes for lator
                pastNodes.push(current);
                current = current->Left();
            }
            pastNodes.push(current);
            return true;
      }
      else{
          if(pastNodes.empty())
              done =true;
          return true;
      }
    }
    
}

// Free the node
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::freeNode(Node<DATATYPE, KEYTYPE> * leaf)
{
    //Student must fill in
    //if the root is the leaf, delete that leaf
    // otherwise if the leaf is not null
        //recursive call of the leaf's left
    if(leaf->Left() != nullptr){
        freeNode(leaf->Left());
    }
        //recursive call of the leaf's right
    if(leaf->Right() != nullptr){
        freeNode(leaf->Right());
    }
        //now delete the leaf
    delete leaf;
    
}

// Add a node
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::addNode(KEYTYPE key, DATATYPE &data)
{
    if (Root() == nullptr)
    {
        Node<DATATYPE, KEYTYPE> * newNodePtr = new Node<DATATYPE, KEYTYPE>;
        newNodePtr->setKey(key);
        newNodePtr->setData(data);
        root = newNodePtr;
        root->setParent(root);

    }
    else
        addNode(key, root, data);
}

// Add a node (private)
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::addNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * leaf, DATATYPE& data) {
    //Student must fill in
    //Don't forget to set your key, Parent, then left or right
    //Based on the case you use you will addNode recursively to the left or right
 
    //First check if root is null
    if(Root() == nullptr){
        cout << "something is wrong\n";
        //make a new node
        Node<DATATYPE, KEYTYPE> * newNodePtr = new Node<DATATYPE, KEYTYPE>;
        //set the key and data
        newNodePtr->setKey(key);
        newNodePtr->setData(data);
        //set the root
        root = newNodePtr;
        root->setParent(root);
    }
    //Otherwise
    else{
        //Check to see if the key is < the leaf's key
        if(key < leaf->Key()){
            // if left is not null then
            if(leaf->Left() != nullptr){
                //TEST//cout << "left\n";
                //Add the node to the left (recursively)
                addNode(key, leaf->Left(), data);
            }
            else{
                // Otherwise make a new node and attach it to the left
                //TEST//cout << "add Left\n";
                //make a new node
                Node<DATATYPE, KEYTYPE> * newNodePtr = new Node<DATATYPE, KEYTYPE>;
                //set the key and data
                newNodePtr->setKey(key);
                newNodePtr->setData(data);
                //set the root
                leaf->setLeft(newNodePtr);
                leaf->Left()->setParent(leaf);
            }
        }
        //Check to see if the key >= leaf's key
        else if(key >= leaf->Key()){
            // if leaf's right is not null then
            if(leaf->Right() != nullptr){
                //TEST//cout << "right\n";
                //Add the node to the right (recursively)
                addNode(key, leaf->Right(), data);
            }
            // Otherwise make new node and attach it to the right
            else {
                //TEST//cout << "add Right\n";
                //make a new node
                Node<DATATYPE, KEYTYPE> * newNodePtr = new Node<DATATYPE, KEYTYPE>;
                //set the key and data
                newNodePtr->setKey(key);
                newNodePtr->setData(data);
                //set the root
                leaf->setRight(newNodePtr);
                leaf->Right()->setParent(leaf);
            }
        }
    }
}

template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::findNode(KEYTYPE key)
{
    return findNode(key, root);
}

// Find a node
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::findNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * node)
{
    //Student must fill in
    // trap nullptr first in case we've hit the end unsuccessfully.
    // success base case
    //Greater than (Right), Less than (Left)
    if(Root() == nullptr){
        return nullptr;
    }
    //Otherwise
    else{
        //Check to see if the key is < the leaf's key
        if(key == node->Key())
            return node;
        else if(key < node->Key()){
            // if left is not null then
            if(node->Left() != nullptr){
                return findNode(key, node->Left());
            }
            else{
                return nullptr;
            }
        }
        //Check to see if the key >= leaf's key
        else if(key >= node->Key()){
            if(node->Right() != nullptr){
                return findNode(key, node->Right());
            }
            else{
                return nullptr;
            }
        }
    }
    
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::printInorder()
{
    printInorder(root);
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::printInorder(Node<DATATYPE, KEYTYPE> * node)
{
    //Student must fill in.  Use recursive algorithm.
    //Note that this prints using an Inorder, Depth-first search
    //but you may want to do something else when "visiting" the node....
    //like moving visited data to another datastructure
    //Don't forget your base case!
    if(root == nullptr)// if the root is null we dont want to print nothin
        return;
    if(node->Left() != nullptr){
        printInorder(node->Left());
    }
    DATATYPE printIt = node->Data();
    cout << printIt;
    if(node->Right() != nullptr){
        printInorder(node->Right());
    }
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::print(ostream & out, const DATATYPE & data)
{
    out << data.number << "\t" << data.name << endl;
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::deleteNode(KEYTYPE key)
{
    setRoot(deleteNode(Root(), key));
}

//deleteNode (Private)
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::deleteNode(Node<DATATYPE, KEYTYPE> * aRoot,KEYTYPE value)
{
   
    /* Given a binary search tree and a key, this function deletes the key
    and returns the new root */
    
    // base case
    if (aRoot == nullptr) return aRoot;

    // If the key to be deleted is smaller than the aRoot's key,
    // then it lies in left subtree
    if (value < aRoot->Key())
        aRoot->setLeft(deleteNode(aRoot->Left(), value));

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (value > aRoot->Key())
        root->setRight(deleteNode(aRoot->Right(), value));

    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (aRoot->Left() == nullptr)
        {
            Node<DATATYPE, KEYTYPE> *temp = aRoot->Right();
            delete aRoot;    
            return temp;
        }
        else if (aRoot->Right() == nullptr)
        {
            Node<DATATYPE, KEYTYPE> *temp = aRoot->Left();
            delete aRoot;
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        Node<DATATYPE, KEYTYPE> * temp = min(aRoot->Right());

        // Copy the inorder successor's content to this node
        aRoot->setKey(temp->Key());
        aRoot->setData(temp->Data());

        // Delete the inorder successor
        aRoot->setRight(deleteNode(aRoot->Right(), temp->Key()));
    }
    return aRoot;
}

// Find the node with min key
// Traverse the left sub-BSTree recursively
// till left sub-BSTree is empty to get min
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::min(Node<DATATYPE, KEYTYPE> * node)
{
    Node<DATATYPE, KEYTYPE> * current = node;

    /* loop down to find the leftmost leaf */
    while (current->Left() != nullptr)
        current = current->Left();

    return current;
}

// Find the node with min key
// Traverse the left sub-BSTree recursively
// till left sub-BSTree is empty to get min
// 
// Delete that node
// then returnits data
template <typename DATATYPE, typename KEYTYPE>
bool BSTree<DATATYPE, KEYTYPE>::minPop(DATATYPE & mini){

    Node<DATATYPE, KEYTYPE> * current;

    // if empty never mind
    if(root == nullptr)
        return false;
    else
        // get the smalest
        current = min(Root());

    // get the data
    mini = current->Data();

    deleteNode(current->Key());

    // get rid of the node
    
    return true;
}

// Find the node with max key
// Traverse the right sub-BSTree recursively
// till right sub-BSTree is empty to get max
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::max(Node<DATATYPE, KEYTYPE> * node)
{
    Node<DATATYPE, KEYTYPE> * tempNode = node;
    if (node == nullptr)
        tempNode = nullptr;
    else if (node->Right())
        tempNode = max(node->Right());
    else
        tempNode = node;

    return tempNode;
}
