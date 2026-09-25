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
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<int> prices(n, INT_MAX);

        prices[src] = 0;

        for(int i = 0; i <= k; i++)
        {
            vector<int> tmpPrices = prices;
            for(int j = 0; j < flights.size(); j++)
            {
                int source = flights[j][0];
                int destination = flights[j][1];
                int price = flights[j][2];
                if(prices[source] != INT_MAX)
                {
                    if(prices[source] + price < tmpPrices[destination])
                    {
                        tmpPrices[destination] =  prices[source] + price;
                    }
                }
            }
            prices = tmpPrices;
        }

        if(prices[dst] == INT_MAX)
        {
            return -1;
        }
        return prices[dst];

    }
};