//Google Question
//Given an array = [2,5,1,2,3,5,1,2,4]:
//It should return 2

//Given an array = [2,1,1,2,3,5,1,2,4]:
//It should return 1

//Given an array = [2,3,4,5]:
//It should return undefined


//Bonus... What if we had this:
// [2,5,5,2,3,5,1,2,4]
// return 5 because the pairs are before 2,2
#include <iostream>
#include <vector> 
#include<unordered_set>


/*
 Time complexity: O(N) bacause a hash table is used to keep track of any previously seen elements
 Space complexity: O(N) because a unordered_set is created which can be as big as the given input in the worse case.
*/
int firstRecurringCharacter(std::vector<int>& input){
std::unordered_set<int> mySet;

for(int index = 0; index <=input.size(); index++)
{
  auto got = mySet.insert(input[index]);
  if(!got.second){
    return input[index];
  }
}

 return -1;
} 


int main() {
  std::vector<int> array1 = {2,5,1,2,3,5,1,2,4};
  std::vector<int> array2 = {2,1,1,2,3,5,1,2,4};
  std::vector<int> array3 = {2,3,4,5};
  std::vector<int> array4 = {2,5,5,2,3,5,1,2,4};
 
  std::cout << firstRecurringCharacter(array1) << std::endl;
  std::cout << firstRecurringCharacter(array2) << std::endl;
  std::cout << firstRecurringCharacter(array3) << std::endl;
  std::cout << firstRecurringCharacter(array4) << std::endl;
 
 
}
