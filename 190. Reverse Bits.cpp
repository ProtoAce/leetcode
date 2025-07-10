
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>
#include <bitset>


class Solution {
public:
    std::uint32_t reverseBits(std::uint32_t n) {
        std::uint32_t res = 0;

        int i = 0;

        while(n != 0)
        {
            std::uint32_t bit = (n >> i) & 1;
            
            if(bit == 0)
            {   
                i++;
                continue;
            }
            
            std::uint32_t mask = 1 << i;

            n = n ^ mask;

            res = res | (bit << (31-i));

            i++;

        }

        return res;
        
    }
};