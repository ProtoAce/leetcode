#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>
#include <tuple>
#include <stack>

class Solution {
public:
    bool detect_rules(std::vector<std::string>& words, std::unordered_map<char, std::vector<char>>& rules)
    {

        for(int i = 0; i < words.size()-1; i++)
        {
            for(int j = 0; j < words[i].length(); j++)
            {
                // next word is shorter and identical so not possible
                if(j > words[i+1].length())
                {
                    return false;
                }

                // letters do not match.
                if(words[i][j] != words[i+1][j])
                {
                    auto it = rules.find(words[i+1][j]);
                    if(it != rules.end())
                    {
                        for(int k = 0; k < it->second.size(); k++)
                        {
                            //conflicting rule a < b && b < a
                            if(it->second[k] == words[i][j])
                            {
                                return false;
                            }
                        }
                    }
                    it = rules.find(words[i][j]);

                    bool rule_exists = false;

                    // words[i][j] already in map.
                    if(it != rules.end())
                    {
                        for(int k = 0; k < it->second.size(); k++)
                        {
                            //rule already exist
                            if(it->second[k] == words[i+1][j])
                            {
                                rule_exists = true;
                                break;
                            }
                        }
                        
                        if(!rule_exists)
                        {
                            
                            rules[words[i][j]].push_back(words[i+1][j]);
                        }

                    }
                    rules[words[i][j]] = {words[i+1][j]};
                    break;
                
                }


            }
        }

        std::cout << "rules" << std::endl;
        for(auto it = rules.begin(); it != rules.end(); it++)
        {   
            for(int i = 0; i < it->second.size(); i++)
            {
                std::cout << "test\n";
                std::cout << it->first << "<" << it->second[i] << std::endl;
                std::cout << "\n";
            }
        }
        return true;

    }

    int node_in_solution(std::vector<char>& solution , char node)
    {
        for(int i = 0; i < solution.size(); i++)
        {

            if (solution[i] == node)
            {
                return i;
            }
        }
        return -1;
    }

    std::unordered_set<char>  all_chars(std::vector<std::string>& words)
    {
        std::unordered_set<char> letters;
        
        for(std::string word: words)
        {
            for(char letter: word)
            {
                letters.insert(letter);
            }
        }
        return letters;
    }

    void print_solution(std::vector<char> solution)
    {
        std::string answer = "";

        for(int i = 0; i < solution.size(); i++)
        {
            answer.push_back(solution[i]);
        }

        std::cout << answer << "> sol" << std::endl;
    }

    std::string foreignDictionary(std::vector<std::string>& words) {

       std::unordered_map<char, std::vector<char>> rules;

       if(!detect_rules(words, rules))
       {
            return "";
       }
       std::vector<char> solution;
       std::stack<char> nodes;
       for(auto it = rules.begin(); it != rules.end(); it++)
       {
            nodes.push(it->first);
       }

       while(!nodes.empty())
       {
            char node = nodes.top();
            nodes.pop();

            //print_solution(solution);
            int position = node_in_solution(solution, node);
            auto it = solution.begin();

            std::cout << node << "-" << position << std::endl;



            if(position != -1)
            {
                std::vector<char> hot_nodes(it+position, solution.end());

                for(int i = 0; i < rules[node].size(); i ++)
                {
                    for(int j = 0; j < hot_nodes.size(); j++)
                    {
                        if( rules[node][i] == hot_nodes[j])
                        {
                            return "";
                        }
                    }
                }

                it += position;
                solution.erase(it);

                solution.push_back(node);

                for(char child: rules[node])
                {
                    solution.push_back(child);
                }


            }
            // if the node is not in the solution, nothing has pointed to it,
            // so there is no rule that node < solution. so it goes at the start.
            else
            {
                it = solution.insert(it, node);
            

                for(int i = 0; i < rules[node].size(); i++)
                {   
                    it = it + 1;
                    it = solution.insert(it, rules[node][i]);
                }


            }

           
        }

        std::unordered_set letters = all_chars(words);

        for(auto it = letters.begin(); it != letters.end(); it++)
        {
            bool in_solution = false;
            for(int i = 0; i < solution.size(); i++)
            {

                if(solution[i] == *it)
                {
                    in_solution = true;
                    break;
                }
            }

            if(!in_solution)
            {
                solution.insert(solution.begin(), *it);
            }
        }

        std::string answer = "";

        for(int i = 0; i < solution.size(); i++)
        {
            answer.push_back(solution[i]);
        }

        

        return answer;
    }
};
