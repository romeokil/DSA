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
    void reverse(ListNode* &newhead,ListNode* curr){
        // 
        if(curr->next==NULL){
            newhead=curr;
            return ;
        }
        reverse(newhead,curr->next);
        ListNode* prev=curr;
        curr->next->next=prev;
        curr->next=NULL;
    }
    ListNode* removeNodes(ListNode* head) {
        stack<int> st;
        ListNode* temp=head;
        while(temp!=NULL){
            while(!st.empty()  && (temp->val)>st.top()){
                st.pop();
            }
            st.push(temp->val);
            temp=temp->next;
        }
        ListNode* newhead=NULL;
        temp=newhead;
        while(!st.empty()){
            int top=st.top();
            if(newhead==NULL){
                ListNode* newNode=new ListNode(top);
                newhead=newNode;
                temp=newhead;
            }
            else{
                ListNode *newNode=new ListNode(top);
                temp->next=newNode;
                temp=temp->next;
            }
            st.pop();
        }
        ListNode* curr=newhead;
        reverse(newhead,curr);
        return newhead;
    }
};