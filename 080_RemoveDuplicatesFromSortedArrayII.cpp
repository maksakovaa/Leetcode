#include <vector>
#include <iostream>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums)
    {
        int cur = 0;
        int duplicateCounter = 0;
        while ((cur+1) < nums.size())
        {
            if (nums.at(cur+1) > nums.at(cur))
            {
                duplicateCounter = 0;
                ++cur;
            }
            else
            {
                ++duplicateCounter;
                if (duplicateCounter > 1)
                {
                    nums.erase(nums.begin() + cur);
                }
                else
                {
                    ++cur;
                }
            }
        }      

        return cur+1;
    }
};

void prinVec(std::vector<int> nums)
{
    std::cout << "Result vector is: ";
    for (int i: nums)
    {
        std::cout << i << ", ";
    }
    std::cout << "\n";
}

void check(std::vector<int>& nums, std::vector<int>& result, int out)
{
    Solution s;
    int x = s.removeDuplicates(nums);
    if (nums == result && x == out)
    {
        std::cout << "test completed!" << std::endl;
    }
    else
    {
        std::cout << "test failed! x: " << x << std::endl;
        prinVec(nums);
    }
    
}

void testCase1()
{
    std::vector<int> nums = {1,1,1,2,2,3};
    std::vector<int> result = {1, 1, 2, 2, 3 };
    int num = 5;
    check(nums, result, num);
}

int main()
{
    testCase1();
}