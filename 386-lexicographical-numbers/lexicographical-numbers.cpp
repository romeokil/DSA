class Solution {
public:
    void solve(int no,vector<int>& temp,int n){
        if(no>n) return ;
        temp.push_back(no);
        for(int i=0;i<=9;i++){
            int newno=10*no+i;
            solve(newno,temp,n);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> temp;
        for(int i=1;i<=9;i++){
            solve(i,temp,n);
        }
        return temp;
    }
};