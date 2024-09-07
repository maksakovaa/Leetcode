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

Solution s;

void test1()
{
    std::vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };
    std::vector<int> nums2 = { 2, 5, 6 };
    std::vector<int> result = { 1,2,2,3,5,6 };
    s.merge(nums1, 3, nums2, 3);
    checkResult(nums1, result);
}

void test2()
{
    std::vector<int> nums1 = { 1 };
    std::vector<int> nums2;
    std::vector<int> result = { 1 };
    s.merge(nums1, 1, nums2, 0);
    checkResult(nums1, result);
}

void test3()
{
    std::vector<int> nums1 = { 0 };
    std::vector<int> nums2 = { 1 };
    std::vector<int> result = { 1 };
    s.merge(nums1, 0, nums2, 1);
    checkResult(nums1, result);
}

void test4()
{
    std::vector<int> nums1 = { 2, 0 };
    std::vector<int> nums2 = { 1 };
    std::vector<int> result = { 1, 2 };
    s.merge(nums1, 1, nums2, 1);
    checkResult(nums1, result);
}

void test5()
{
    std::vector<int> nums1 = { 4, 5, 6, 0, 0, 0 };
    std::vector<int> nums2 = { 1, 2, 3 };
    std::vector<int> result = { 1, 2, 3, 4, 5, 6 };
    s.merge(nums1, 3, nums2, 3);
    checkResult(nums1, result);
}

void test6()
{
    std::vector<int> nums1 = { 4,0,0,0,0,0 };
    std::vector<int> nums2 = { 1, 2, 3, 5, 6 };
    std::vector<int> result = { 1, 2, 3, 4, 5, 6 };
    s.merge(nums1, 1, nums2, 5);
    checkResult(nums1, result);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
}
