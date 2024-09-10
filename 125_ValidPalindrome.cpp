/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.

*/

#include <string>
#include <algorithm>
#include <iostream>
#include <locale>

using std::string;

class Solution {
public:
    bool isPalindrome(string s)
    {
        if (s.length() == 1 || s.empty())
        {
            return true;
        }
        string::iterator iter = s.begin();
        string::reverse_iterator riter = s.rbegin();
        while(iter != s.end() && riter != s.rend()) 
        {
            if (!isalnum(*iter))
            {
                ++iter;
            }
            else if(!isalnum(*riter))
            {
                ++riter;
            }
            else if (isdigit(*iter) && isalpha(*riter) || 
                isalpha(*iter) && isdigit(*riter) || 
                (isdigit(*iter) && isdigit(*riter) && *iter != *riter) ||
                (isalpha(*iter) && isalpha(*riter) && std::tolower(*iter) != std::tolower(*riter))
            )
            {
                return false;
            }
            else
            {
                ++iter;
                ++riter;
            }
        }
        return true;
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

inline void ltrim(std::string &s)
{

}

void testCase(string str, bool result)
{
    Solution s;
    checkResult(s.isPalindrome(str), result);
}

int main()
{
    testCase("A man, a plan, a canal: Panama", true);
    testCase("race a car", false);
    testCase(" ", true);
    testCase("......a.....", true);
    testCase("0P", false);
}
