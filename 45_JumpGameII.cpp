/*
You are given a 0-indexed array of integers nums of length n.
You are initially positioned at nums[0].
Each element nums[i] represents the maximum length of a forward jump from index i.
In other words, if you are at nums[i], you can jump to any nums[i + j] where:

    0 <= j <= nums[i] and
    i + j < n

Return the minimum number of jumps to reach nums[n - 1].
The test cases are generated such that you can reach nums[n - 1].

Example 1:
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [2,3,0,1,4]
Output: 2

Constraints:

    1 <= nums.length <= 104
    0 <= nums[i] <= 1000
    It's guaranteed that you can reach nums[n - 1].
*/

#include <vector>
#include <iostream>
#include <algorithm>
using std::vector;

int testCounter = 0;
class Solution {
public:
    int jump(vector<int>& nums)
    {
        int n = nums.size();
        if (n == 1) return 0;
        int count = 0, next = 0, temp = 0; 
        for (int i = 0; i < n - 1; i++)
        {
            next = std::max(next, i + nums[i]);
            
            if (i == temp)
            {
                count++;                
                temp = next;
                if (temp >= n - 1)
                {
                    break;
                }
            }
        }
        return count;
    }
    void checkResult(int result, int expected)
    {
        ++testCounter;
        if (result == expected)
        {
            std::cout << "test" << testCounter << " passed" << std::endl;
        }
        else
        {
            std::cout << "test" << testCounter << " failed, result is: " << result << ", expected: " << expected << std::endl;
        }
        
    }
};

void testCase(vector<int> nums, int out)
{
    Solution s;
    s.checkResult(s.jump(nums), out);
}
int main()
{
    testCase({2, 3, 1, 1, 4}, 2);                               // 1
    testCase({2, 3, 0, 1, 4}, 2);                               // 2
    testCase({0}, 0);                                           // 3
    testCase({1, 2}, 1);                                        // 4
    testCase({1, 1, 1, 1}, 3);                                  // 5
    testCase({3, 2, 1}, 1);                                     // 6
    testCase({2, 3, 1}, 1);                                     // 7
    testCase({4, 1, 1, 3, 1, 1, 1}, 2);                         // 8
    testCase({5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0}, 3);          // 9
    testCase({2, 1}, 1);                                        // 10
    testCase({1, 2, 3}, 2);                                     // 11
    testCase({10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 0}, 2);         // 12
    testCase({7, 0, 9, 6, 9, 6, 1, 7, 9, 0, 1, 2, 9, 0, 3}, 2); // 13
}