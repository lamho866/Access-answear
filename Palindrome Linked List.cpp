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

//step 1: take all element in the singly-linked list.
//setp 2: check it whether is Palindrome.
class Solution {
public:
    bool isPalindrome(ListNode* head) {

        //step 1:take all element in the singly-linked list.
        while(head != nullptr)
            vtr.push_back(head->val), head = head -> next;
        j = vtr.size() - 1;
        
        //step 2:check it whether is Palindrome
        while(i < j)
        {
            if(vtr[i] != vtr[j])
                return false;
            ++i, --j;
        }
        
        return true;
    }
private:
    int i = 0, j = 0;
    vector<int> vtr; //save the singly-linked element
};
