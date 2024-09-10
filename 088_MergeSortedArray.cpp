#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
         std::merge(
            nums1.rbegin() + nums1.size() - m, nums1.rend(), 
            nums2.rbegin() + nums2.size() - n, nums2.rend(), 
            nums1.rbegin(),
            std::greater<>{});
    }
};

void printResult(std::vector<int>& nums)
{
    for (int& i: nums)
    {
        std::cout << i << ", ";
    }
    std::cout << "\n";
}
int testCounter = 1;
void checkResult(std::vector<int>& nums, std::vector<int>& result)
{
    if (nums == result)
    {
        std::cout << "test" << testCounter << " complete!\n";
    }
    else
    {
        std::cout << "test" << testCounter << " failed! Current result is: ";
        printResult(nums);
    }
    testCounter++;
}

void testCase(vector<int> nums1, int nums1c, vector<int> nums2, int nums2c, vector<int> result)
{
    Solution s;
    s.merge(nums1, nums1c, nums2, nums2c);
    checkResult(nums1, result);
}

int main()
{
    testCase({ 1, 2, 3, 0, 0, 0 }, 3, { 2, 5, 6 }, 3, { 1,2,2,3,5,6 });
    testCase({1},1,{0}, 0, {1});
    testCase({0}, 0, {1}, 1, {1});
    testCase({ 2, 0 }, 1, { 1 }, 1, { 1,2});
    testCase({ 4, 5, 6, 0, 0, 0 }, 3, { 1, 2, 3 }, 3, { 1, 2, 3, 4, 5, 6 });
    testCase({ 4,0,0,0,0,0 }, 1, { 1, 2, 3, 5, 6 }, 5, { 1, 2, 3, 4, 5, 6 });
}
