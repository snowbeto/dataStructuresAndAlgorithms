#include <iostream>
#include <exception>

/*
 * Implementation of a queue using a linked list. The advantage over using an array is that 
 * with a queue the deletion of an element takes O(1) as elements should not be shifted
 * like with an array. 
 * */

template <class T> 
class Queue
{
  public: 
  Queue(): head(NULL), length(0), tail(NULL) {};
  ~Queue();
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
        void setNext(Node *next){ this->next = next;}
        T value() const {return data;}     
    };

  class QueueError: public std::exception{
    virtual const char* what() const throw(){
      return "Queue is empty";
    }

} queueError;

 Node *head;
 Node *tail;

};

/*Time complexity O(n)*/
template <class T>
Queue<T>::~Queue(){
  
  while(head)
  {
    Node *next = head->getNext();
    
    delete head;
    head = next;
  }
}

/*Time complexity O(1)*/
template <class T>
void Queue<T>::push(T data){

  Node *newNode = new Node(NULL, data);
      
  length++;

  if(tail == NULL){
    head = tail = newNode;
    std::cout << "Head is initialized " << head->getNext() << std::endl;
    return;
  }
  
  //inset the new value at the end of the queue and displace the tail to point to the new element
  tail->setNext(newNode);
  tail = newNode; 

  
}

/*Time complexity O(1)*/
template<class T> 
T Queue<T>::pop(){ 

  if(length == 0){
    throw queueError;
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
T Queue<T>::peek(){ 
 
  if(length == 0){
    throw queueError;
  }
  
  return  head->value();
}



int main() {
  
  Queue<int> myQueue;
  
  std::cout <<"Length: " << myQueue.length << std::endl;

  for(int i = 0; i< 6; i++){
    myQueue.push(i);
  }
  std::cout <<"Length: " << myQueue.length << std::endl;

  for(int i = 0; i < 5; i++){
   std::cout << "Value: " <<  myQueue.pop() << std::endl;
  }
  std::cout <<"Length: " << myQueue.length << std::endl;

  for(int i = 0; i < 5; i++){
    myQueue.peek();
  }
  std::cout <<"Length: " << myQueue.length << std::endl;

 
}
