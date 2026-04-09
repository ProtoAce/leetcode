#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        for(int i = 0; i < intervals.size() -1; i++)
        {
            vector<int> first = intervals[i];
            vector<int> second = intervals[i+1];

            if(first[1] >= second[0])
            {
                intervals[i+1][0] = first[0];
                if(second[1] < first[1])
                {
                    intervals[i+1][1] =  first[1];
                }
            }
            else
            {
                result.push_back(first);
            }

        }

        result.push_back(intervals.back());
        return result;


    }
};