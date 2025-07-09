#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>
#include <stack>

class Solution {
    public:
        bool isValid(std::string s) {
            if (s.length() % 2 != 0)
            {
                return false;
            }
            std::stack<char> stk;
            for(char character: s)
            {
                if (character == '(' || character == '{' || character == '[')
                {
                    stk.push(character);
                }
                else if (stk.empty())
                {
                    return false;
                }
                else if (character ==')')
                {
                    if (stk.top() == '(')
                    {
                        stk.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (character ==']')
                {
                    if (stk.top() == '[')
                    {
                        stk.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (character =='}')
                {
                    if (stk.top() == '{')
                    {
                        stk.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                
            }
            return stk.size() == 0;
        }
    };

// main() is where program execution begins.
int main() {
    return 0;
 }