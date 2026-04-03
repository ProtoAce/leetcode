class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total = 1; 
        int zeroCount = 0;
        int zeroIndex;

        for(int i = 0; i < nums.size(); i ++)
        {
            if(nums[i] == 0)
            {
                zeroCount ++;
                zeroIndex = i;
            }
            else
            {
                total *= nums[i];
            }
        }
        std::vector<int> result(nums.size(), 0);
        
        if(zeroCount > 1)
        {
            return result;
        }
        else if(zeroCount == 1)
        {
            result[zeroIndex] = total;
            return result;
        }

        for(int i =0; i <nums.size(); i++)
        {
            result[i] = total/nums[i];
        }

        return result;

    }
};