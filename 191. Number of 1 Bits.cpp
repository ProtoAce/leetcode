#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int result = 0;
        while(n > 0)
        {
            if(n & 1)
            {
                result++;
            }
            n >> 1;
        }
        return result;
        
    }
};