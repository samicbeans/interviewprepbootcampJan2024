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
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // if one list is empty, return the other list
        if (list1 == nullptr)
        {
            return list2;
        }
        if (list2 == nullptr)
        {
            return list1;
        }
        ListNode *smaller = nullptr; // smaller represents the head of the merged list.
        // set smaller to start with the smaller of the 2 head nodes of the given lists
        if (list1->val > list2->val)
        {
            smaller = list2;
            list2 = list2->next;
        }
        else
        {
            smaller = list1;
            list1 = list1->next;
        }
        ListNode *p2 = smaller;
        while (p2 != nullptr and list1 != nullptr and list2 != nullptr)
        {
            if (list1->val >= list2->val)
            {
                p2->next = list2;
                list2 = list2->next;
            }
            else //(list2->val > list1->val)
            {
                p2->next = list1;
                list1 = list1->next;
            }
            p2 = p2->next;
        }
        // if list1 or list2 still have nodes left over, p2->next connects the rest of list1/list2 to the merged list since those are already sorted and connected
        if (list1 != nullptr)
        {
            p2->next = list1;
        }
        if (list2 != nullptr)
        {
            p2->next = list2;
        }
        return smaller;
    }
};