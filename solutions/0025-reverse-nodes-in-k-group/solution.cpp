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
#include <vector>

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*> ls;

        ListNode* curr = head;
        while(curr!=nullptr)
        {
            ls.push_back(curr);
            curr = curr->next;
        }

        for(int i = 0; i < ls.size();i++)
        {
            int next_k = (i/k)*k + k;
            if(next_k+k <= ls.size())
            {
                if(i%k ==0)
                    ls[i]->next = ls[i + (2*k -1)];
                else 
                    ls[i]->next = ls[i-1];
            }
            else if (next_k == ls.size())
            {
                if(i%k ==0)
                    ls[i]->next = nullptr;
                else 
                    ls[i]->next = ls[i-1];
            }
            else if (next_k < ls.size() && next_k + k >= ls.size() )
            {
                if(i%k ==0)
                    ls[i]->next = ls[i+k];
                else 
                    ls[i]->next = ls[i-1];
            }
        }
        if (ls.size() >= k) {
            return ls[k - 1];
            }
        return ls.empty() ? nullptr : ls[0];
    }
};
