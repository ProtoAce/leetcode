#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>
#include <algorithm>

class Solution {
public:

    bool helper(std::string s, const std::unordered_set<std::string>& wordSet, std::unordered_map<std::string, bool>& memo)
    {
        bool solution = false;

        if(s.length() == 0 )
        {
            return true;
        }

        if (memo.find(s) != memo.end())
        {
            return memo[s];
        }

        for(int i = 0; i <= s.length(); i++)
        {
            if(wordSet.find(s.substr(0, i)) != wordSet.end())
            {
                if (helper(s.substr(i, s.length()), wordSet, memo))
                {
                    memo[s] = true;
                    solution = true;
                }
            }
        }
        memo[s] = false;
        return solution;
    }

    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        std::unordered_set<std::string> wordSet(wordDict.begin(), wordDict.end());
        std::unordered_map<std::string, bool> memo;
    

        return helper(s, wordSet, memo);
    }
};

// main() is where program execution begins.
int main() {
    return 0;
 }