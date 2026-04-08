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
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        for(int row = 0; row < grid.size(); row++)
        {
            for(int col = 0; col < grid[0].size(); col++)
            {

                if(grid[row][col] == '0')
                {
                    continue;
                }

                stack<pair<int,int>> s;
                s.push({row,col});

                while(!s.empty())
                {
                    pair<int,int> current = s.top();
                    s.pop();
                    
                    if(grid[current.first][current.second] == '1')
                    {

                        grid[current.first][current.second] = '0';
                        
                        if(current.first > 0)
                        {
                            s.push({current.first-1, current.second});
                        }
                        if(current.first < grid.size() - 1)
                        {
                            s.push({current.first + 1, current.second});
                        }
                        if(current.second > 0)
                        {
                            s.push({current.first, current.second -1});
                        }
                        if(current.second < grid[0].size() - 1)
                        {
                            s.push({current.first, current.second + 1});
                        }
                    }



                }
                result++;


            }
        }

        return result;

    }
};


[["1","1","0","0","0"],
 ["1","1","0","0","0"],
 ["0","0","1","0","0"],
 ["0","0","0","1","1"]]