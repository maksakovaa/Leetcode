#include <vector>
#include <iostream>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums)
    {
        int cur = 0;
        while ((cur+1) < nums.size())
        {
            if (nums.at(cur+1) > nums.at(cur))
            {
                ++cur;
            }
            else
            {
                nums.erase(nums.begin() + cur);
            }
        }      

        return cur+1;
    }
};

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
    }
    
}
void testCase1()
{
    std::vector<int> nums = {1,1,2};
    std::vector<int> result = {1, 2 };
    int num = 2;
    check(nums, result, num);
}

int main()
{
    testCase1();
}