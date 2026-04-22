#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {

        unordered_set<int> mem;
        int current = n;
        while(mem.find(current) == mem.end())
        {
            mem.insert(current);
            
            if(current == 1)
            {
                return true;
            }

            int newNum = 0;
            while(current > 0)
            {
                int tmp = current % 10;
                std::cout << tmp << " -- ";
                current = current / 10;
                newNum += tmp * tmp;
            }

            current = newNum;
            std::cout << endl;
        }

        return false;
        
    }
};