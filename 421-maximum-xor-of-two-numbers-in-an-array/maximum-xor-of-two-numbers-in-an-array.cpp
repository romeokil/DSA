class Solution {
public:
    struct TrieNode{
        TrieNode* left;
        TrieNode* right;
    };
    void insert(TrieNode* root,int num){
        // saara number ko TrieNode me daalna hai.
        TrieNode* pcrawl=root;
        for(int i=31;i>=0;i--){
            int ith_bit = (num>>i) & 1;
            if(ith_bit==0){
                if(pcrawl->left==NULL){
                    pcrawl->left=new TrieNode();
                }
                pcrawl=pcrawl->left;
            }
            else{
                if(pcrawl->right==NULL){
                    pcrawl->right=new TrieNode();
                }
                pcrawl=pcrawl->right;
            }
        }
    }
    int findmaxXor(TrieNode* root,int num){
        TrieNode* pcrawl=root;
        int maxXor=0;
        for(int i=31;i>=0;i--){
            int ith_bit=(num >> i) & 1; // no ka ith bit pe 1 hai ye 0 isse pata chal jaega.
            if(ith_bit==0){ // agr 0 mila mtlb hmlog ko 1 doondhna pdega taaki maximum bna pae.
                if(pcrawl->right!=NULL){
                    maxXor+=pow(2,i);
                    pcrawl=pcrawl->right;
                }
                else pcrawl=pcrawl->left; // esme eslie maxXor ni calculate kiye 
                //  qki ye toh majburi me gy hai or same no se xor kroge toh 0 hi milega.
                // toh ultimately wo result me contribute ni krega.
            }
            else{
                if(pcrawl->left!=NULL){
                    maxXor+=pow(2,i);
                    pcrawl=pcrawl->left;
                }
                else pcrawl=pcrawl->right; // same chiz ye bhi krege agr 1 se 1 ka xor krege
                // toh phir result me hmlog ko 0 hi milega koi frk ni pdega result me.
            }
        }
        return maxXor;
    }
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root=new TrieNode();
        int result=INT_MIN;
        // pehle TrieNode me saara number insert kr dete hai.
        for(int &num:nums){
            insert(root,num);
        }
        for(int i=0;i<nums.size();i++){
            int temp=findmaxXor(root,nums[i]);
            result=max(result,temp);
        }
        return result;
    }
};