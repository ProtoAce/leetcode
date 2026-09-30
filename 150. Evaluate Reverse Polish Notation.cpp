#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        for(int i = 0; i < tokens.size(); i++)
        {

            if(tokens[i] == "+")
            {
                int second = stoi(s.top());
                s.pop();
                int first = stoi(s.top());
                s.pop();

                s.push(to_string(first + second));
            }else if(tokens[i] == "-")
            {
                int second = stoi(s.top());
                s.pop();
                int first = stoi(s.top());
                s.pop();

                s.push(to_string(first - second));
            }else if(tokens[i] == "*")
            {
                int second = stoi(s.top());
                s.pop();
                int first = stoi(s.top());
                s.pop();

                s.push(to_string(first * second));
            }
            else if(tokens[i] == "/")
            {
                int second = stoi(s.top());
                s.pop();
                int first = stoi(s.top());
                s.pop();

                s.push(to_string(first / second));
            }else
            {
                s.push(tokens[i]);
            }

        }
        return stoi(s.top());
    }
};