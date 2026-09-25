#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>
#include <algorithm> 
#include <queue>


using namespace std;

class KthLargest {
public:
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    int kth;
    KthLargest(int k, vector<int>& nums) {
        for(int num: nums)
        {
            minHeap.push(num);
        }
        while(minHeap.size() > k)
        {
            minHeap.pop();
        }
        kth = k;
    }
    
    int add(int val) {
        
        if(minHeap.size() < kth)
        {
            minHeap.push(val);
        }
        else if(val > minHeap.top())
        {
            minHeap.pop();
            minHeap.push(val);
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */