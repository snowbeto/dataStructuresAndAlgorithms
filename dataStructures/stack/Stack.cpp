#include <iostream>
#include <exception>

/*
 * This is an implementetaion of a stack using a linked list. The advantage of using 
 * a linked list over dynamic arrays is that the size of the collection can increase without
 * a resizing the list. The dowbacks are that extra memory is required for elements and slower access time
 * to each element as they are not stored one to another like in dynamic arrays.  
*/

template <class T> 
class Stack
{
  public: 
  Stack(): head(NULL), length(0) {};
  ~Stack();
  void push(T data);
  T pop();
  T peek();
  int length;
  
  protected:
    class Node {
      private: 
        Node *next;
        T data;
      public: 
        Node(Node *next, T data): next(next), data(data){};
        Node *getNext() const {return next;}
        T value() const {return data;}     
    };

  class StackError: public std::exception{
    virtual const char* what() const throw(){
      return "Stack is empty";
    }

} stackError;

 Node *head;
};

/*Time complexity O(n)*/
template <class T>
Stack<T>::~Stack(){
  
  while(head)
  {
    Node *next = head->getNext();
    
    delete head;
    head = next;
  }
}

/*Time complexity O(1)*/
template <class T>
void Stack<T>::push(T data){

  Node *newNode = new Node(head, data);
  
  head = newNode;
  length++;
}

/*Time complexity O(1)*/
template<class T> 
T Stack<T>::pop(){ 
 
  if(length == 0){
    throw stackError;
  }
  
  T value = head->value();
  Node * next = head->getNext();
  
  delete head;
  head = next;
  length--;
  
  return value;

}

/*Time complexity O(1)*/
template<class T> 
T Stack<T>::peek(){ 
 
  if(length == 0){
    throw stackError;
  }
  
  return  head->value();
}



int main() {
  
  Stack<int> myStack;
  
  std::cout <<"Length: " << myStack.length << std::endl;

  for(int i = 0; i< 1000; i++){
    myStack.push(i);
  }
  std::cout <<"Length: " << myStack.length << std::endl;

  for(int i = 0; i < 200; i++){
    myStack.pop();
  }
  std::cout <<"Length: " << myStack.length << std::endl;

  for(int i = 0; i < 200; i++){
    myStack.peek();
  }
  std::cout <<"Length: " << myStack.length << std::endl;

 
}
