#include <iostream>
/*
 * Basic implementation of a Binary Search Tree
 * It keeps search and insert methods O(log n) as long as the tree is balanced
 * If a binary tree is not balanced, performanced can to up to O(n)
 * */

template <class T>
class BST {


protected:
  class Node{
    private:
      Node *left;
      Node *right;
      T value;

    public:
    Node(T value): left(NULL), right(NULL), value(value){
    }
    Node *getLeft()const {return left;}
    Node *getRight()const {return right;}
    T getValue() const {return value;}
    void setLeft(Node *left){ this->left = left;}
    void setRight(Node *right){ this->right = right;}
  };

public:

BST():root(NULL) {};
~BST(){
  cleanTree(root);
}

/*Public interface to the serach method*/
Node *search(T value){
  return search(root, value);
}

/*Public interface to the insert method*/
void insert(T value){
  root = insert(root, value);
}

private: 
Node *root;

/*Time complexity: O(log n) if the tree is balanced*/
void cleanTree(Node *node)
{
  if(node != NULL)
  {
    cleanTree(node->getLeft());    
    cleanTree(node->getRight());
    //std::cout << "Deleting: " << node->getValue() << std::endl;
    delete node;
    node = NULL;
  }
}

/*Time complexity: O(log n) if the tree is balanced*/
Node * insert(Node *node, T value){
  /*Return new  node only if the subtree is empty*/
  if (node == NULL)
    return new Node(value);

  /*If not recur down the tree based along the right path*/
  if(value < node->getValue())
    node->setLeft(insert(node->getLeft(), value));
  else if(value > node->getValue())
    node->setRight(insert(node->getRight(), value));

  /*return the current node*/
  return node;
}

/*Time complexity: O(log n) if the tree is balanced*/
Node * search(Node *node, T value){
  /*Return null if we have reached dead end or if the cuurent node is the one we are looking for*/
  if (node == NULL || node->getValue() == value)
    return node;
  
  /*If not recur down the tree based along the right path*/
  if(value < node->getValue())
    return search(node->getLeft(), value);
  
  return search(node->getRight(), value);
}

};






int main() {

  BST<int> myTree;
  myTree.insert(15);
  myTree.insert(1);
  myTree.insert(10);
  myTree.insert(65);
  myTree.insert(66);

  if (myTree.search(1) != NULL)
    std::cout<< "1 has been found" << std::endl;
  
  if (myTree.search(100) != NULL)
    std::cout<< "10 has been found" << std::endl;
}
