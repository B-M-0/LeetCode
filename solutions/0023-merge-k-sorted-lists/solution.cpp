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
#include <list>
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        list<int> ls ;

        for(int i =0 ;i < lists.size();i++)
        {
            ListNode* t = lists[i];
            while(t != nullptr)
            {
                ls.push_back((*t).val);
                t = t->next;
            }
        }
        ls.sort();


        ListNode dummy = ListNode();
        ListNode* curr = &dummy;         
        
        for(int i : ls)
        {
            curr->next = new ListNode(i);
            curr = curr->next;
        }
        return dummy.next;
    }
};
