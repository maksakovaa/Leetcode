/*
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:
Input: s = "axc", t = "ahbgdc"
Output: false

Constraints:
    0 <= s.length <= 100
    0 <= t.length <= 104
    s and t consist only of lowercase English letters.
Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k >= 109, and you want to check one by one to see if t has its subsequence. In this scenario, how would you change your code?
*/

#include <string>
#include <iostream>

using std::string;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        if (s.empty())
        {
            return true;
        }
        
        int i = 0;
        for (auto ch: t)
        {
            if (ch == s[i])
            {
                if (i != s.length() - 1)
                {
                    ++i;
                }
                else
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};

int testCounter = 1;
void checkResult(bool result, bool output)
{
    if (output == result)
    {
        std::cout << "test" << testCounter << " complete!\n";
    }
    else
    {
        std::cout << "test" << testCounter << " failed! Current result is: " << output << std::endl;;
    }
    testCounter++;
}

void testCase(string str1, string str2, bool result)
{
    Solution s;
    checkResult(s.isSubsequence(str1, str2), result);
}

int main()
{
    testCase("abc", "ahbgdc", true);
    testCase("axc", "ahbgdc", false);
}
