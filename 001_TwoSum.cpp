/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
*/

#include <vector>
#include <unordered_map>
#include <iostream>

using std::vector;
using std::unordered_map;

class SolutionSlow {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (i != j && nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return{};
    }
};

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (numMap.count(complement)) {
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }

        return {};
    }
};

int testCounter = 1;
void checkResult(vector<int> result, vector<int>& out)
{
    if (out == result)
    {
        std::cout << "test" << testCounter << " complete!\n";
    }
    else
    {
        std::cout << "test" << testCounter << " failed! Current result is: " << std::endl;
        for (int i: result)
        {
            std::cout << i << ", ";
        }
        std::cout << std::endl;
    }
    testCounter++;
}

void testCase(vector<int> nums, int target, vector<int> out)
{
    Solution s;
    checkResult(s.twoSum(nums, target), out);
}

int main()
{
    testCase({2,7,11,15}, 9, {0,1});
    testCase({3,2,4}, 6, {1,2});
    testCase({3,3}, 6, {0,1});
    testCase({0,4,3,0}, 0, {0,3});
    testCase({-1,-2,-3,-4,-5}, -8, {2,4});
    testCase({-3,4,3,90}, 0, {0,2});
}
