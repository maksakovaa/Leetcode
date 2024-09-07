/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

*/

#include <vector>
#include <algorithm>
#include <iostream>
using std::vector;

class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
       k = k % nums.size();
       std::reverse(nums.begin(), nums.end() - k);
       std::reverse(nums.end() - k, nums.end());
       std::reverse(nums.begin(), nums.end());
    }
};

void prinVec(std::vector<int> nums)
{
    std::cout << "Result is: ";
    for (int i: nums)
    {
        std::cout << i << ", ";
    }
    std::cout << "\n";
}
void checkResult(vector<int>& nums, vector<int>& result)
{
    if (nums == result)
    {
        std::cout << "Test passed!" << std::endl;
    }
    else
    {
        std::cout << "Test failed!" << std::endl;
        prinVec(nums);
    }
}


void testCase1()
{
    Solution s;
    std::vector<int> nums = { 1,2,3,4,5,6,7 };
    int k = 3;
    vector<int> result = { 5,6,7,1,2,3,4 };
    s.rotate(nums, k);
    checkResult(nums, result);
}

void testCase2()
{
    Solution s;
    std::vector<int> nums = { -1,-100,3,99 };
    int k = 2;
    vector<int> result = { 3,99,-1,-100 };
    s.rotate(nums, k);
    checkResult(nums, result);
}

int main()
{
    testCase1();
    testCase2();
}