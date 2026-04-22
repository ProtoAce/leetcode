#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>

using namespace std;

struct Node
{
    int key;
    int val;
    Node * prev;
    Node * next;

    Node(int key, int val): key(key), val(val), prev(nullptr), next(nullptr){}
};


class LRUCache {

    Node * head = nullptr;
    Node * tail = nullptr;
    unordered_map<int, Node *> addressMap;

    int capacity;

    void insert(Node * node)
    {
        Node * prev = tail->prev;
        prev->next = node;
        node->prev = prev;
        tail ->prev = node;
        node->next = tail;
    }

    void remove(Node * node)
    {
        Node * prev = node->prev;
        Node * next = node->next;
        prev->next = next;
        next->prev = prev;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        
    }
    
    int get(int key) {
        if(addressMap.find(key) == addressMap.end())
        {
            return -1;
        }
        
        Node * node = addressMap[key];
        remove(node);
        insert(node);

        return node->val;
    }
    
    void put(int key, int value) {
        
        if(addressMap.find(key) != addressMap.end())
        {
            remove(addressMap[key]);
        }
        
        Node * newNode = new Node(key, value);
        addressMap[key] = newNode;
        insert(newNode);

        if(addressMap.size() > capacity)
        {
            Node * removed = head->next;
            remove(removed);

            addressMap.erase(removed->key);
            delete removed;

        }
       
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */