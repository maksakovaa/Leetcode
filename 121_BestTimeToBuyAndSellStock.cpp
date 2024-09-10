/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

*/

#include <vector>
#include <algorithm>
#include <iostream>
using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int profit = 0;
        int min{0};
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < prices[min])
            {
                min = i;
            }

            if (prices[i] - prices[min] > profit)
            {
                profit = prices[i] - prices[min];
            }
        }
        return profit;
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
    testCase({7,1,5,3,6,4}, 5);
    testCase({7,6,4,3,1}, 0);
}