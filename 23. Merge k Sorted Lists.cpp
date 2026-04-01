/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode * head;
        ListNode * i1 = list1;
        ListNode * i2 = list2;
        ListNode * current;

        if(i1 == nullptr)
        {
            return i2;
        }
        else if(i2 == nullptr)
        {
            return i1;
        }
        if(i1->val <= i2->val)
        {
            head = i1;
            i1 = i1->next;
        }
        else
        {
            head = i2;
            i2 = i2->next;
        }

        current = head;

        while(i1 != nullptr && i2 != nullptr)
        {
            if(i1->val <= i2->val)
            {
                current -> next = i1;
                current = current->next;
                i1 = i1->next;
            }
            else
            {
                current -> next = i2;
                current = current->next;
                i2 = i2->next;
            }
        }
        if(i1 == nullptr)
        {
            current -> next = i2;
        }
        else
        {
            current ->next = i1;
        }
        return head;

        
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        
        if(lists.size() == 0)
        {
            return nullptr;
        }
        else if(lists.size() == 1)
        {
            return lists[0];
        }

        ListNode* result = lists[0];
        
        for(int i = 1; i < lists.size(); i++)
        {
           result = mergeTwoLists(result, lists[i]);
        }
            
    
        return result;
        
    }
};