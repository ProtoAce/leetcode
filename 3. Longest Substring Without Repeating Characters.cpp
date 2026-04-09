#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> mem;
        int first = 0;
        int result = 0;
        for(int second = 0; second < s.length(); second++)
        {
            if(mem.find(s[second]) == mem.end())
            {
                mem.insert(s[second]);
                result = max(result, int(mem.size()));
            }
            else
            {
                while(s[first] != s[second])
                {
                    mem.erase(s[first]);
                    first++;
                }
                first++;
                
            }
        }
        result = max(result, int(mem.size()));

        return result;


    }
};