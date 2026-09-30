#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>
#include <stack>
#include <cmath>
using namespace std;



class Solution {
public:
    int integerBreak(int n) {
        
        if(n == 4)
        {
            return 4;
        }
        if(n == 3)
        {
            return 2;
        }
        if(n == 2)
        {
            return 1;
        }

        if(n%3 == 0)
        {
            return pow(3, n/3);
        }
        else if(n%3 == 2)
        {
            return n + 2;
        }
        else if(n%3 == 1)
        {
            return n + 1;
        }
        return 0;
    }
};