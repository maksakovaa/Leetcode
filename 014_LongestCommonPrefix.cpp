/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

*/

#include <string>
#include <vector>
#include <iostream>

int testCounter = 0;

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& s)
    {
        std::string str = "";
        if(s.empty())
        {
            return str;
        }
        if(s.size() == 1)
        {
            return s[0];
        }
        size_t maxIndex = s[0].length();
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i].length() == 0)
            {
                return str;
            }
            if (s[i].length() < maxIndex)
            {
                maxIndex = s[i].length();
            }
        }
        bool exists;
        char ch;
        for (size_t i = 0; i < maxIndex; i++)
        {
            exists = true;
            ch = s[0][i];
            for (size_t j = 0; j < s.size(); j++)
            {
                if (s[j][i] != ch)
                {
                    exists = false;
                    break;
                }
            }
            if (exists)
            {
                str += ch;
            }
            else
            {
                break;
            }
            
        }
        return str;
    }
    void checkResult(std::string res, std::string expected)
    {
        ++testCounter;
        if (res == expected)
        {
            std::cout << "test" << testCounter << " passed" << std::endl;
        }
        else
        {
            std::cout << "test" << testCounter << " failed, result is: " << res << std::endl;
        }
        
    }
};


void testCase(std::vector<std::string> str, std::string out)
{
    Solution s;
    s.checkResult(s.longestCommonPrefix(str), out);
}

int main()
{
    testCase({"flower","flow","flight"}, "fl");
    testCase({"dog","racecar","car"}, "");
    testCase({"cir", "car"}, "c");
    testCase({"flower","flower","flower","flower"}, "flower");
}