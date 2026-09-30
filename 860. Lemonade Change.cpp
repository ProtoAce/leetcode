class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int fives = 0;
        int tens = 0;
        int twentys = 0;

        for(int i = 0; i < bills.size(); i++)
        {
            if(bills[i] == 5)
            {
                fives += 5;
            }else if(bills[i] == 10)
            {
                if(fives == 0)
                {
                    return false;
                }else
                {
                    fives -= 5;
                }
                tens+=10;
            }else
            {
               if(fives > 0 && tens > 0)
               {
                fives -= 5;
                tens -=10;
                twentys += 20;
               }
               else if (fives >= 15)
               {
                fives -= 15;
                twentys += 20;
               }
               else
               {
                return false;
               }
            }
        }
        return true;
        
    }
};