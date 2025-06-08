class Solution {
public:
    void solve(int no,vector<int>& temp,int n,unordered_set<int>& st){
        if(no>n) return ;
        if(st.find(no)==st.end()){
            temp.push_back(no);
            st.insert(no);
        }
        for(int i=0;i<=9;i++){
            int newno=10*no+i;
            solve(newno,temp,n,st);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> temp;
        unordered_set<int> st;
        for(int i=1;i<=n;i++){
            solve(i,temp,n,st);
        }
        return temp;
    }
};