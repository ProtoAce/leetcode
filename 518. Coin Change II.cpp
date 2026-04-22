#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>

using namespace std;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        std::vector<uint> mem(amount+1, 0);
        mem[0] = 1;

        for(int j = 0; j < coins.size(); j++)
        {
            
            for(int i  = 1; i <= amount; i++)
            {
                int result = mem[i];
                if(coins[j] <= i)
                {
                    result += mem[i-coins[j]];
                }
                mem[i] = result;
            }
        }

        return mem[amount];

    }
};