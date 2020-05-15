/*
 * 
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *
 *		Example:
 *
 *			Given nums = [2, 7, 11, 15], target = 9,
 *			Because nums[0] + nums[1] = 2 + 7 = 9,
 *			return [0, 1].
 *
* */


/*
 *  Time complexity : O(n)
 *	Space complexity: O(n) as we create a new hash_map
 *	We check if we have seen the compliment of this number before by searching for it in the hash map
 *	If we have seen it, we will return the indexes
 *	else, we will add the current number and its index in the hash_map
 * */
	
vector<int> twoSum(vector<int>& nums, int target) {
	std::vector<int> result;
	std::unordered_map<int,int> myMap; 
	for(int i = 0; i < nums.size(); i++)
	{
		int compliment = target - nums[i];
		auto got = myMap.find (compliment);

		if(got != myMap.end())
		{
			result.push_back(i);
			result.push_back(got->second);
			break;
		}
		else 
			myMap.insert(std::make_pair(nums[i], i));
	}
	
	return result;
}
