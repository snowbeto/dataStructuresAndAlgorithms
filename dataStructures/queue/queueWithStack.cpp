#include <iostream>
#include<stack>

/* There are two possible solutions and in both cases two stacks are used: 
 * 
 * Class QueueWithExpensiveEnqueue:
 * A queue is implemented using two stacks by making the enqueue method expensive O(n):
 * 	1.- Move all elements from stack1 to stack2 
 *  2.- Push the new element into stack1
 *  3.- Push back all elements from stack2 into stack1
 * 
 * Class QueueWithExpensiveDequeue:
 * A queue is implemented using two stack by making the dequeue method expensive O(n):
 * 	1.- Push all elements from stack 1 into stack 2 only if stack 2 is empty.
 *  2.- Pop and return the top item from stack 2
 *  This solution is more efficient as not all elemets are moved between stacks everytime
 * 
 * */
 
 
template<class T>
class Queue
{
  public:
  Queue():length(0){};
  virtual ~Queue(){};
  virtual void enqueue (T element) = 0;
  virtual T dequeue () = 0;
  int length;

  protected:
  std::stack<T> stack1, stack2;  
  class QueueError: public std::exception{
    virtual const char* what() const throw(){
      return "Queue is empty";
    }

   }queueError;
};

template<class T>
class QueueWithExpensiveEnqueue: public Queue<T>{
  public:
  QueueWithExpensiveEnqueue(): Queue<T>() {};
  /* O(n)*/ 
  void enqueue(T element){
    while(!this->stack1.empty())
    {
      this->stack2.push(this->stack1.top());
      this->stack1.pop();
    }

    this->stack1.push(element);

    while(!this->stack2.empty())
    {
      this->stack1.push(this->stack2.top());
      this->stack2.pop();
    }

    this->length++;
  }

  /*O(1)*/
  T dequeue()
  {
    if(this->stack1.empty()){
      throw this->queueError;
    }

    T element = this->stack1.top();
    this->stack1.pop();
    this->length--;
    return element;
    
  }




};


template<class T>
class QueueWithExpensiveDequeue: public Queue<T>{
  public:
  QueueWithExpensiveDequeue(): Queue<T>() {};
  /* O(1)*/ 
  void enqueue(T element){
    this->stack1.push(element);
    this->length++;
  }

  /*O(n)*/
  T dequeue()
  {
    if(this->stack1.empty() && this->stack2.empty()){
      throw this->queueError;
    }

    if(this->stack2.empty())
    {
      while(!this->stack1.empty())
      {
        this->stack2.push(this->stack1.top());
        this->stack1.pop();
      }
    }

    T element = this->stack2.top();
    this->stack2.pop();
    this->length--;
    return element;
    
  }


};

template <class T>
void testQueue(Queue<T> &queue){
  for(int i = 0; i < 10; i ++)
  {
    queue.enqueue(i);
    std::cout << i << " ";
  }
  std::cout << std::endl << "Queue size: " << queue.length << std::endl;  
  
  while(queue.length > 0){
    
    std::cout << queue.dequeue() << " ";
  }

  std::cout << std::endl;
}


int main() {
  
  QueueWithExpensiveEnqueue<int> queue1;
  QueueWithExpensiveDequeue<int> queue2;
  
  testQueue<int>(queue1);
  testQueue<int>(queue2);
  
}
