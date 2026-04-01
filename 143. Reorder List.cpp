class Solution {
public:
    void reorderList(ListNode* head) {

        if(head == nullptr || head->next == nullptr)
        {
            return;
        }

        ListNode * slow = head;
        ListNode * fast = head;

        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode * second = slow->next;
        slow->next = nullptr;

        ListNode * prev = nullptr;
        ListNode * current = second;
        ListNode * next = nullptr;

        while(current != nullptr)
        {
            next = current ->next;
            current -> next = prev;

            prev = current;
            current = next;
        }

        ListNode * l1 = head;
        ListNode * l2 = prev;
        ListNode * tmp1;
        ListNode * tmp2;

        while(l1 != nullptr && l2 != nullptr)
        {
            
            tmp1 = l1->next;
            tmp2 = l2->next;

            l1->next = l2;
            l2->next = tmp1;

            l1 = tmp1;
            l2 = tmp2;
        }

        
    }
};