#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <queue>
#include <string>

using namespace std;


// DFS solution. 

// class Solution {
// public:
//     int countComponents(int n, vector<vector<int>>& edges) {

        
//         if(n == 0 || n == 1)
//         {
//             return n;
//         }
        
//         unordered_map<int, vector<int>> adjecencies;

//         for(int i = 0; i < edges.size(); i++)
//         {
//             int left = edges[i][0];
//             int right = edges[i][1];

//             adjecencies[left].push_back(right);
//             adjecencies[right].push_back(left);
//         }

//         queue<int> q;
//         unordered_set<int> searched;
//         int result = 0;

//         for(auto it = adjecencies.begin(); it != adjecencies.end(); it++)
//         {
//             bool newcomponent = false;
//             q.push(it->first);

//             while(!q.empty())
//             {
//                 int current = q.front();
//                 q.pop();
//                 if(searched.find(current) == searched.end())
//                 {
//                     newcomponent = true;
//                     searched.insert(current);
//                     for(int i = 0; i  < adjecencies[current].size(); i++)
//                     {
                        
//                         q.push(adjecencies[current][i]);
//                     }
//                 }
        
//             }
//             if (newcomponent) 
//             {
//                 result ++;
//             }          
//         }

//         result += n - searched.size();

//         return result;


//     }
// };
