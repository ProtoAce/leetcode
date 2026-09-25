#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>

using namespace std;


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_map<int, unordered_set<int>> rows;
        unordered_map<int, unordered_set<int>> cols;
        unordered_map<int, unordered_set<int>> squares;


        for(int r = 0; r < board.size(); r ++)
        {
            for(int c = 0; c < board[r].size(); c++)
            {
                if(board[r][c] == '.')
                {
                    continue;
                }

                if(rows[r].contains(board[r][c]))
                {
                    return false;
                }
                rows[r].insert(board[r][c]);

                //checking columns;

                if(cols[c].contains(board[r][c]))
                {
                    return false;
                }
                cols[c].insert(board[r][c]);

                //checking squares;


                int squareIndex = (r / 3) * 3 + (c / 3);
                if(squares[squareIndex].contains(board[r][c]))
                {
                    return false;
                }
                squares[squareIndex].insert(board[r][c]);
            }
        }

        return true;
        
    }
};