/*
You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.
Return the merged string.

Example 1:
Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r

Example 2:
Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s

Example 3:
Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d

*/

#include <string>
#include <iostream>

using std::string;

class Solution {
public:
    string mergeAlternately(string word1, string word2)
    {
        int i = 0, j = 0;
        string merged;
        while (i < word1.size() && j < word2.size())
        {
            merged += word1[i++];
            merged += word2[j++];
        }
        if (i < word1.size())
        {
            merged.append(word1.substr(i));
        }
        if (i< word2.size())
        {
            merged.append(word2.substr(j));
        }
        return merged;           
    }
};

int testCounter = 1;
void checkResult(string result, string out)
{
    if (out == result)
    {
        std::cout << "test" << testCounter << " complete!\n";
    }
    else
    {
        std::cout << "test" << testCounter << " failed! Current result is: " << result << std::endl;
    }
    testCounter++;
}

void testCase(string str1, string str2, string out)
{
    Solution s;
    checkResult(s.mergeAlternately(str1, str2), out);
}

int main()
{
    testCase("abc", "pqr", "apbqcr");
    testCase("ab", "pqrs", "apbqrs");
    testCase("abcd", "pq", "apbqcd");
}
