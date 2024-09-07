/*

Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times.
You may assume that the majority element always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2

*/

#include <vector>
#include <algorithm>
#include <iostream>
using std::vector;

class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n/2];
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
void checkResult(int output, int result)
{
    if (output == result)
    {
        std::cout << "Test passed!" << std::endl;
    }
    else
    {
        std::cout << "Test failed! Output " << result << std::endl;
    }
}


void testCase1()
{
    Solution s;
    std::vector<int> nums = { 3,2,3 };
    int output = 3;
    int result = s.majorityElement(nums);
    checkResult(output, result);
}

void testCase2()
{
    Solution s;
    std::vector<int> nums = { 2,2,1,1,1,2,2 };
    int output = 2;
    int result = s.majorityElement(nums);
    checkResult(output, result);
}

int main()
{
    testCase1();
    testCase2();
}