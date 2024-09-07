#include <vector>
using std::vector;

class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        vector<int>::iterator it = nums.begin();
        int counter = 0;
        while (it != nums.end())
        {
            if (*it == val)
            {
                it = nums.erase(it);
            }
            else
            {
                ++it;
                ++counter;
            }
        }
        
    }
};



Solution s;

void testCase1()
{
    vector<int> nums = {3,2,2,3};
    int val = 3;
    vector<int> result = {2,2};
    int count = 2;
}

int main()
{
    testCase1();
}