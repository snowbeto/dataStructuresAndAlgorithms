#include <iostream>
#include <algorithm>
#include <vector>
#include <functional> 
#include <chrono>

std::string reverseString1(std::string inputString)
{
  //Time comlexity O(n) as it loops over all elements
  //Space complexity O(n) as it creates a new resulting array
  std::string reversedString; 
  for(int index = inputString.length() - 1; index >= 0; index--)
  {
    reversedString.push_back(inputString[index]);
  }

  return reversedString;
}

std::string reverseString2(std::string inputString)
{
  //Time comlexity  O(n) 
  //No need to store aditional space
  int size = inputString.size();
  for(int index = 0; index < size / 2; index++){
    std::swap(inputString[index],inputString[size - index - 1]);
  }

  return inputString;

}

std::string reverseString3(std::string inputString)
{
  //Implemented by using the standard method reverse
   //Time comlexity O(n) 
   //No need to store aditional space
   //This is more flexible allows you to swtich any given interval
  std::reverse(inputString.begin(), inputString.end());
  return inputString;
}

int main() {
  std::cout << "Hello World!\n";
  std::string myTestString("Hello my dear Friend!");
  std::cout << reverseString1(myTestString) << std::endl;
  std::cout << reverseString2(myTestString) << std::endl;
  std::cout << reverseString3(myTestString) << std::endl;
}

