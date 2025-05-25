#include <iostream>
#include <string>
#include <unordered_map>

int testCount = 0;
class Solution {
    public:
        bool isIsomorphic(std::string s, std::string t)
        {
            if (s.length() != t.length()) {
                return false;
            }
        
            std::unordered_map<char, char> s_to_t;
            std::unordered_map<char, char> t_to_s;
        
            for (size_t i = 0; i < s.length(); ++i) {
                char char_s = s[i];
                char char_t = t[i];
        
                if (s_to_t.find(char_s) == s_to_t.end() && t_to_s.find(char_t) == t_to_s.end()) {
                    // No mapping exists, create one
                    s_to_t[char_s] = char_t;
                    t_to_s[char_t] = char_s;
                } else {
                    // Mapping exists, check consistency
                    if (s_to_t[char_s] != char_t || t_to_s[char_t] != char_s) {
                        return false;
                    }
                }
            }
            return true;
        }
    };

void testCase(const std::string s, const std::string t)
{
    testCount++;
    Solution sol;
    std::cout << "test"<< testCount << ": " << sol.isIsomorphic(s, t) << std::endl;
}

int main()
{
    testCase("egg", "add");
    testCase("foo", "bar");
    testCase("paper", "title");
}