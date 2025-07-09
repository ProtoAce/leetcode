#include <iostream>
#include <unordered_set>
#include <vector>
#include <cassert>
class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
            std::unordered_set <int> map = {};

            for (int number: nums){
                if (map.find(number) != map.end())
                {
                    return true;
                }
                else
                {
                    map.insert({number, number});
                }
            }
            return false;
    }
};

// main() is where program execution begins.
int main() {
    std::vector test = {1,2,3,4,1};
    Solution solution;
    assert(solution.containsDuplicate(test));
 }