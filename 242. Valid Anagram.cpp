#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
            if (s.length() != t.length())
            {
                return false;
            }
            std::unordered_map<char, int> map;

            for(int i = 0; i < s.length(); i++)
            {
                map[s[i]]++;
                map[t[i]]--;
            }
            for( auto term: map)
            {
                if (term.second != 0)
                {
                    return false;
                }
            }
            return true;
    }
};

// main() is where program execution begins.
int main() {
    std::string test = "aacc";
    std::string test2 = "ccac";
    Solution solution;
    std::cout << solution.isAnagram(test, test2);
 }