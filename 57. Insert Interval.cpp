#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>

class Solution {
    public:
        std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
            
            std::vector<std::vector<int>> result;

            int cur = 0;
            int n = intervals.size();

            while(cur < n && intervals[cur][1] < newInterval[0])
            {
                result.push_back(intervals[cur]);
                cur++;
            }

            while(cur < n && newInterval[1] >= intervals[cur][0])
            {
                newInterval[0] = std::min(intervals[cur][0], newInterval[0]);
                newInterval[1] = std::max(intervals[cur][1], newInterval[1]);
                cur++;
            }
            
            result.push_back(newInterval);

            while(cur < n)
            {
                result.push_back(intervals[cur]);
                cur++;
            }
            return result;

        }
    };
// main() is where program execution begins.
int main() {
    return 0;
 }