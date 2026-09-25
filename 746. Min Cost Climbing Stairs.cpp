#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>
#include <queue>


using namespace std;

class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {

        if(cost.size() <= 1)
        {
            return 0;
        }

        // vector<int> mem(cost.size());
        // mem[0] = cost[0];
        // mem[1] = cost[1];

        int prevPrevStep = cost[0];
        int prevStep = cost[1];

        for(int i = 2; i < cost.size(); i++)
        {

            int tmp = min(prevStep, prevPrevStep) + cost[i];

            prevPrevStep = prevStep;
            prevStep = tmp;

        }

        return min(prevStep, prevPrevStep);
    }
};