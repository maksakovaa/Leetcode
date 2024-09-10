/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.

Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.

Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.

*/

#include <vector>
#include <algorithm>
#include <iostream>
using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int min{0};
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < prices[min])
            {
                min = i;
            }

            if (prices[i] - prices[min] > 0)
            {
                profit += prices[i] - prices[min];
                min = i;
            }
        }
        return profit;
    }
private:
    int profit =0;
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
void checkResult(int out, int result)
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

void testCase(vector<int> nums, int output)
{
    Solution s;
    checkResult(s.maxProfit(nums), output);
}

int main()
{
    testCase({7,1,5,3,6,4}, 7);
    testCase({1,2,3,4,5}, 4);
    testCase({7,6,4,3,1}, 0);
}