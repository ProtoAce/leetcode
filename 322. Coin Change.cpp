#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>

using namespace std;

class Solution {
    
public:
    int coinChange(vector<int>& coins, int amount) {


        std::vector<int> memory;
        // unordered_map<int, int> memory;
        memory[0] = 0;
        for(int i = 1; i <= amount; i++)
        {
            memory[i] = -1;
        }

        for(int i = 0; i < coins.size(); i ++)
        {
            memory[coins[i]] = 1;
        }

        int currentPrice = 0;

        while(currentPrice <= amount)
        {
            int minCoins = numeric_limits<int>::max();
            for(int i = 0; i < coins.size(); i++)
            {   
                if(coins[i] > currentPrice || memory[currentPrice - coins[i]] == -1)
                {
                    continue;
                }
                
                int coinCount = memory[currentPrice - coins[i]] + 1;
                if(coinCount < minCoins)
                {
                    minCoins = coinCount;
                    memory[currentPrice] = minCoins;
                }
            }
            currentPrice++;
            
        }

        return memory[amount];

        
    }
};