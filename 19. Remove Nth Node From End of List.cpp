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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * result = head;
        ListNode * slow = head;
        ListNode * fast = head;

        int delay = 0;
        while(fast != nullptr)
        {
            fast = fast->next;
            
            if(delay > n)
            {
                slow = slow->next;
            }

            delay+=1;
        }

        ListNode * remove = slow;
        if(delay != n)
        {
            remove = remove->next;
        }

        if(remove == result)
        {
            result = result->next;
        }

        if(remove != nullptr)
        {
            slow-> next = remove->next;
        }
        else
        {
            slow->next = nullptr;
        }

        return result;
    


    }
};