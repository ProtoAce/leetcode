
// // Definition for a Node.
// class Node {
// public:
//     int val;
//     Node* next;
//     Node* random;
    
//     Node(int _val) {
//         val = _val;
//         next = nullptr;
//         random = nullptr;
//     }
// };


#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>
#include <stack>


class Solution {
public:
    Node* copyRandomList(Node* head) {
    
        std::unordered_map<Node*,Node*> nodeMap;

        Node* newHead = nullptr;
        Node* cur = head;
        Node* newCur = nullptr;

        while(cur != nullptr)
        {
            Node* newNode = new Node(cur->val);
            nodeMap[cur] = newNode;
            cur = cur->next;            
        }

        if (head != nullptr)
        {
            newHead = nodeMap[head];
        }

        cur = head;
        while(cur != nullptr)
        {
            newCur = nodeMap[cur];
            if(cur->next != nullptr)
            {
                newCur->next = nodeMap[cur->next];
            }
            else
            {
                newCur->next = nullptr;
            }
            if(cur->random != nullptr)
            {
                newCur->random = nodeMap[cur->random];
            }
            else
            {
                newCur->random = nullptr;
            }

            cur = cur->next;
            newCur = newCur->next;
        }

        return newHead;

        

        
    }
};