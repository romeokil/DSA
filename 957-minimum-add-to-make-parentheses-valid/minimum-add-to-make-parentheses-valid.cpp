class Solution {
public:
    int minAddToMakeValid(string s) {
        // yr parenthesis wla hai toh stack aana chahiya tha dimag me tmhaare
        stack<int> st;
        int open=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else{
                if(st.size()==0) open++;
                else st.pop();
            }
        }
        // ye st.size() closing braces kitna required hai.
        // and ye opening braces kitna requreid hai.
        return st.size()+open;
    }
};