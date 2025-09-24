#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>
#include <tuple>

class Solution {
public:

    bool search_adjacent(std::vector<std::vector<char>>& board, std::string word, int r, int c, std::vector<std::vector<bool>>& visited)
    {

        if(word.size() == 0)
        {
            return true;
        }
        std::cout << word << visited.size()<<  std::endl;

        if(r-1 >= 0 && board[r-1][c] == word[0] && !visited[r-1][c])
        {
            visited[r-1][c] = true;
            if(search_adjacent(board, word.substr(1, word.size()), r-1, c, visited))
            {
                return true;
            }
            visited[r-1][c] = false;

        }
        if(r+1 < board.size() && board[r+1][c] == word[0] && !visited[r+1][c])
        {
            visited[r+1][c] = true;
            if(search_adjacent(board, word.substr(1, word.size()), r+1, c, visited))
            {
                return true;
            }
            visited[r+1][c] = false;

        }
        if(c-1 >= 0 && board[r][c-1] == word[0] && !visited[r][c-1])
        {
            visited[r][c-1] = true;
            if(search_adjacent(board, word.substr(1, word.size()), r, c-1, visited))
            {
                return true;
            }
            visited[r][c-1] = false;

        }
        if(c + 1 < board[0].size() && board[r][c+1] == word[0] && !visited[r][c+1])
        { 
            visited[r][c+1] = true;
            if(search_adjacent(board, word.substr(1, word.size()), r, c+1, visited))
            {
                return true;
            }
            visited[r][c+1] = false;

        }
        return false;

    }

    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                
                if(board[i][j] == word[0])
                {
                    std::vector<std::vector<bool>> visited(board.size(), std::vector<bool>(board[0].size(), false));
                    visited[i][j] = true;
                    if(search_adjacent(board, word.substr(1, word.size()), i, j, visited))
                    {
                        return true;
                    }
                }

                
            }
        }
        return false;
    }
};