#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>
#include <algorithm>


class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int buy = prices[0];
        int sell = 0;
        int profit = 0;

        if(prices.size() == 1)
        {
            return 0;
        }

        for(int i = 1; i < prices.size(); i++)
        {
            if(buy > prices[i])
            {
                buy = prices[i];
                sell = 0;
                continue;
            }

            if(sell < prices[i])
            {
                sell = prices[i];

                profit = std::max(profit, sell - buy);
            }

        }   
        return profit;
        
    }
};