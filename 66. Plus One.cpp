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
    vector<int> plusOne(vector<int>& digits) {
        
        for(int i = digits.size() -1; i >=0; i--)
        {
            if(digits[i] < 9)
            {
              digits[i]++;
              break;
            }
            else
            {
                
                digits[i] = 0;
                if(i == 0)
                {
                    digits.insert(digits.begin(), 1);
                }
            }
           
        }
        return digits;

        // bool carry = false;

        // for(int i = digits.size() -1; i >=0; i--)
        // {
        //     if(digits[i] <=8)
        //     {
        //         if(carry == false)
        //         {
        //             digits[i] +=1;
        //         }else
        //         {
        //             digits[i] += 2;
        //             carry = false;
        //         }
        //         break;
        //     }

        //     if(carry == true && digits[i] == 8 || carry == false && digits[i] == 9)
        //     {
        //         digits[i] = 0;
        //         if(i == 0)
        //         {
        //             digits.insert(digits.begin(), 1);
        //         }
        //     }

        //     if(carry == false && digits[i] == 8)
        //     {
        //         digits[i] = 9;
        //         break;
        //     }

        //     if(carry == true && digits[i] == 9)
        //     {
        //         digits[i] = 1;

        //         if(i == 0)
        //         {
        //             digits.insert(digits.begin(), 1);
        //         }
        //     }
        //     carry = true;
        // }

        // return digits;
        

    }
};