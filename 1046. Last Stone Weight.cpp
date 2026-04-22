#include <queue>

using namespace std;

class Solution {

public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> q;
        for (int s : stones) {
            q.push(s);
        }

        while(q.size() > 1)
        {
            int first = q.top();
            q.pop();
            int second = q.top();
            q.pop();
            if(first != second)
            {
                q.push(first - second);
            }
        }
        q.push(0);

        return q.top();
        
    }
};