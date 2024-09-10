/*
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal
substring
consisting of non-space characters only.

 

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.

Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.

Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.

 

Constraints:

    1 <= s.length <= 104
    s consists of only English letters and spaces ' '.
    There will be at least one word in s.


*/

#include <string>
#include <algorithm>
#include <iostream>

int testCounter = 0;

class Solution {
public:
    int lengthOfLastWord(std::string s)
    {
        int curr = s.length() -1;
        bool isWordFound = false;
        int counter = 0;
        while (curr >= 0)
        {
            if (!isWordFound && !std::isspace(s[curr]))
            {
                isWordFound = true;
            }
            if (isWordFound && !std::isspace(s[curr]))
            {
                ++counter;
            }
            else if (isWordFound && std::isspace(s[curr]))
            {
                break;
            }
            --curr;           
        }
        return counter;       
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

void testCase(std::string str, int out)
{
    Solution s;
    s.checkResult(s.lengthOfLastWord(str), out);
}

int main()
{
    testCase("Hello World", 5);
    testCase("   fly me   to   the moon  ", 4);
    testCase("luffy is still joyboy", 6);
}