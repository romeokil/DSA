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
    int getDecimalValue(ListNode* head) {
        ListNode* temp=head;
        int cnt=0;
        while(temp->next!=NULL){
            cnt++;
            temp=temp->next;
        }
        temp=head;
        int result=0;
        while(temp!=NULL){
            result+=(temp->val)*pow(2,cnt);
            cnt--;
            temp=temp->next;
        }
        return result;
    }
};