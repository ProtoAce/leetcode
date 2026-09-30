#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;
struct TrieNode {
    bool end;
    unordered_map<char, TrieNode*> children;
    TrieNode(bool terminal) : end(terminal){};
};

class WordDictionary {
public:
    TrieNode *  head;


    WordDictionary() {
        head = new TrieNode(true);
    }
    
    void addWord(string word) {
        TrieNode* cur = head;
        for(int i = 0; i < word.length(); i++)
        {
            if(cur->children.find(word[i]) != cur->children.end())
            {
                cur = cur->children[word[i]];
                if(i == word.length() - 1)
                {
                    cur->end = true;
                }
            }
            else
            {
                TrieNode* newNode = nullptr;
                if(i == word.length() - 1)
                {
                    newNode = new TrieNode(true);
                    cur->children.insert({word[i],  newNode});
                }else
                {
                    newNode = new TrieNode(false);
                    cur->children.insert({word[i], newNode});
                    cur = newNode;
                }
            }
        }
    }
    
    bool search(string word) {
        stack<pair<TrieNode*, int>> s;
        s.push({head, 0});
        while(!s.empty())
        {
            TrieNode * curNode =  s.top().first;
            int idx = s.top().second;
            s.pop();

            if(idx == word.length()) {
                if (curNode->end) return true;
                continue;
            }
            
            if(word[idx] == '.')
            {
                for (auto& [ch, nextNode] : curNode->children)
                {
                    s.push({nextNode, idx + 1});
                }
            }
            else
            {
                auto it = curNode->children.find(word[idx]);
                if (it != curNode->children.end()) {
                    s.push({it->second, idx + 1});
                }
            }
            
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */