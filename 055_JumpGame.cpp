/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.

Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

*/

#include <vector>
#include <algorithm>
#include <iostream>
using std::vector;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i, minjump = 0;
        for(i = nums.size()-2; i >= 0; i--){
            minjump++;
            if(nums[i] >= minjump)
			    minjump = 0;
        }
        if(minjump == 0) 
		    return true;
        else 
		    return false;
    }
};
void checkResult(bool out, bool result)
{
    if (out == result)
    {
        std::cout << "Test passed!" << std::endl;
    }
    else
    {
        std::cout << "Test failed! Result is: " << out << std::endl;
    }
}


void testCase1()
{
    Solution s;
    vector<int> nums = {2,3,1,1,4};
    bool output = true;
    checkResult(s.canJump(nums), output);
}

void testCase2()
{
    Solution s;
    vector<int> nums = {3,2,1,0,4};
    bool output = false;
    checkResult(s.canJump(nums), output);
}

void testCase3()
{
    Solution s;
    vector<int> nums = {2,0};
    bool output = true;
    checkResult(s.canJump(nums), output);
}

void testCase4()
{
    Solution s;
    vector<int> nums = {2,5,0,0};
    bool output = true;
    checkResult(s.canJump(nums), output);
}

int main()
{
    testCase1();
    testCase2();
    testCase3();
    testCase4();
}