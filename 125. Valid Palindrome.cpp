#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>
#include <stack>

class Solution {
    public:
        bool isPalindrome(std::string s) {
            std::string lower_alphanumeric = "";
            for(char c: s)
            {
                if( c >= 65 && c <= 90 || c >= 97 && c <=122)
                {
                    lower_alphanumeric += std::tolower(c);
                }
                else if (c>= 48 && c <=57)
                {
                    lower_alphanumeric += c;
                }
            }
            
            std::cout << lower_alphanumeric << std::endl;

            int length = lower_alphanumeric.length();
            for(int i = 0; i < length/2; i++)
            {
                if (lower_alphanumeric[i] != lower_alphanumeric[length-1-i])
                {
                    return false;
                }
            }
            return true;
        }
    };
// main() is where program execution begins.
int main() {
    Solution sol;
    sol.isPalindrome("A man, a plan, a canal: Panama");
    return 0;
 }