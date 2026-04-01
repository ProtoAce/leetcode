#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        std::unordered_map<string, int> anagrams;
        std::vector<std::vector<string>> result;


        for(int i = 0; i < strs.size(); i++)
        {
            string sorted = strs[i];
            std::sort(sorted.begin(), sorted.end());

            auto it = anagrams.find(sorted);

            if(it != anagrams.end())
            {
                result[it->second].push_back(strs[i]);
            }
            else{
                anagrams[sorted] = result.size();
                result.push_back({strs[i]});
            }

        }
        return result;
        
    }
};