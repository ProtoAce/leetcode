#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        if(edges.size() == 0)
        {
            return true;
        }
        if(edges.size() > n-1)
        {
            return false;
        }

        vector<vector<int>> adjacencyList(n);
        for(int i = 0; i < edges.size(); i++)
        {
            adjacencyList[edges[i][0]].push_back(edges[i][1]);
            adjacencyList[edges[i][1]].push_back(edges[i][0]);
        }

        std::unordered_set<int> visited;

        stack<pair<int, int>> s;

        s.push({edges[0][0], -1});

        while(!s.empty())
        {
            pair<int, int> current = s.top();
            s.pop();

            if(visited.find(current.first) != visited.end())
            {
                return false;
            }
            visited.insert(current.first);
            for(int i = 0; i < adjacencyList[current.first].size(); i++)
            {
                if(adjacencyList[current.first][i] != current.second)
                {
                    s.push({adjacencyList[current.first][i], current.first});
                }
                
            }

        }
        return visited.size() == n;
    }
};
