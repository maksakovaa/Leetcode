/*
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
Each letter in magazine can only be used once in ransomNote.

Example 1:
Input: ransomNote = "a", magazine = "b"
Output: false

Example 2:
Input: ransomNote = "aa", magazine = "ab"
Output: false

Example 3:
Input: ransomNote = "aa", magazine = "aab"
Output: true

Constraints:
    1 <= ransomNote.length, magazine.length <= 105
    ransomNote and magazine consist of lowercase English letters.
*/

#include <string>
#include <iostream>

using std::string;

class Solution 
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        for (int i = 0; i < ransomNote.length(); i++)
        {
            size_t cur = magazine.find_first_of(ransomNote[i]);
            if (cur == std::string::npos)
            {
                return false;
            }
            else
            {
                magazine.erase(magazine.begin()+cur);
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

void testCase(string str1, string str2, bool result)
{
    Solution s;
    checkResult(s.canConstruct(str1, str2), result);
}

int main()
{
    testCase("a", "b", false);
    testCase("aa", "ab", false);
    testCase("aa", "aab", true);
}
