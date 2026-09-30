
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>

using namespace std;


class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int len = s.length();
        for(int i = 0; i < len; i++)
        {
            if(s[i] == 'M')
            {
                result += 1000;
            }else if(s[i] == 'D')
            {
                result += 500;
            }else if(s[i] == 'C')
            {   
                if((i+1 < len) && s[i + 1]== 'D')
                {
                    result += 400;
                    i++;
                }else if((i+1 < len) &&s[i+1] == 'M')
                {
                    result += 900;
                    i++;
                }else
                {
                    result += 100;
                }
            }else if(s[i] == 'L')
            {
                result += 50;
            }else if(s[i] == 'X')
            {

                if((i+1 < len) &&s[i+1]== 'L')
                {
                    result += 40;
                    i++;
                }else if((i+1 < len) &&s[i+1] == 'C')
                {
                    result += 90;
                    i++;
                }else
                {
                    result += 10;
                }
            }else if(s[i] == 'V')
            {
                result += 5;
            }else if(s[i] == 'I')
            {
                if((i+1 < len) &&s[i+1]== 'V')
                {
                    result += 4;
                    i++;
                }else if((i+1 < len) &&s[i+1] == 'X')
                {
                    result += 9;
                    i++;
                }else
                {
                    result += 1;
                }
            }
        }
        return result;
        
    }
};