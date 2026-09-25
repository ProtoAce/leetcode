
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

    int bfs(vector<vector<int>> & grid, int r, int c)
    {
        queue<pair<int,int>> q;

        q.push({r, c});

        int result = 0;
        
        while(!q.empty())
        {
            pair<int,int> coordinates = q.front();
            int row = coordinates.first;
            int col = coordinates.second;
            q.pop();

            if(grid[row][col] == 1)
            {
                grid[row][col] = 0;
                result++;

                if(row > 0)
                {
                    q.push({row-1,col});
                }
                if(row < grid.size() - 1)
                {
                    q.push({row+1,col});
                }
                if(col > 0)
                {
                    q.push({row,col-1});
                }
                if(col < grid[0].size() -1)
                {
                    q.push({row,col+1});
                }
            }
        }

        return result;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int result = 0;

        for(int row = 0; row < grid.size(); row++)
        {
            for(int col = 0; col < grid[0].size(); col++)
            {
                if(grid[row][col] == 0)
                {
                    continue;
                }

                result = max(bfs(grid, row, col), result);

            }
        }

        return result;
    }
};