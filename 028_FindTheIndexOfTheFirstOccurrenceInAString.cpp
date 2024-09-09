/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.


*/

#include <string>
#include <vector>
#include <iostream>
using std::string;

int testCounter = 0;

class Solution {
public:
    int strStr(string haystack, string needle)
    {
        int j = 0, i = 0, index = -1;
        if (haystack.length() < needle.length())
        {
            return index;
        }
        while (i < haystack.length())
        {
            if (haystack[i] == needle[j])
            {
                for (int k = i; k < haystack.length(); k++)
                {
                    if (haystack[k] == needle[j])
                    {
                        if (j == needle.length() - 1)
                        {
                            index = k - j;
                            return index;
                        }
                        j++;
                    }
                    else
                    {
                        j = 0;
                        break;
                    }
                    
                }
            }
            else
            {
                if (haystack.length() - i < needle.length())
                {
                    break;
                }
            }
            i++;
        }       
        return index;
    }
    void checkResult(int res, int expected)
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



void testCase1()
{
    Solution s;
    string haystack = "sadbutsad";
    string needle = "sad";
    int out = 0;
    s.checkResult(s.strStr(haystack, needle), out);
}

void testCase2()
{
    Solution s;
    string haystack = "leetcode";
    string needle = "leeto";
    int out = -1;
    s.checkResult(s.strStr(haystack, needle), out);
}

void testCase3()
{
    Solution s;
    string haystack = "mississippi";
    string needle = "issip";
    int out = 4;
    s.checkResult(s.strStr(haystack, needle), out);
}

int main()
{
    testCase1();
    testCase2();
    testCase3();
}