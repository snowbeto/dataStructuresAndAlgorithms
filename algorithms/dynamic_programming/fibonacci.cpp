#include <iostream>
#include <vector>
#include <unordered_map>

/*
Given a number N return the index value of the Fibonacci sequence, where the sequence is: 

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89. 144 ..
*/


/*
Time Complexity: O(2^n)

A recursive solution which is more  more readable but is not the ideal solution as it will expand repeated branches of the tree. 
*/
int fibonacciRecursive(int index){
  if(index < 2)
   return index;

   return fibonacciRecursive(index - 1) + fibonacciRecursive(index - 2);
}

/*
Time Complexity: O(n)
Space Complexity: O(n)

A recursive solution that reducudes the time complexity by using a hash table to store and find values that have been computed. By using a hash table it is possible to prevent the expansion of repeated branches of the tree. This solves the problem with a top-down approach.  
*/
std::unordered_map<int, int> chachedValues;
int fibonacciRecursiveDP(int index){

  auto got = chachedValues.find(index);
  if (got != chachedValues.end())
      return got->second; 

  if(index < 2)
   return index;

  int result = fibonacciRecursiveDP(index - 1) + fibonacciRecursiveDP(index - 2);
  chachedValues.insert({index, result});
  return result;
   
}

/*
Time Complexity: O(n)
Space Complexity: O(n)

An iterative solution which stores the computed values in an array to use them
in the upcoming computations. This solves the problem with a down-top approach.
*/
int fibonacciIterative(int index)
{
  std::vector<int> array(index, 0);
  array[0] = 0;
  array[1] = 1;

  for(int i = 2; i <= index; i ++){
    array[i] = array[i - 2] + array[i - 1];
  }
  return array[index];
}

int main() {

  //std::cout << fibonacciRecursive(40) << std::endl; // too slow
  std::cout << fibonacciRecursiveDP(40) << std::endl;
  std::cout << fibonacciIterative(40) << std::endl;
}
