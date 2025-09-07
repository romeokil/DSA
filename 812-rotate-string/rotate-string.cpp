class Solution {
public:
    bool rotateString(string s, string goal) {
        queue<char> q1;
        queue<char> q2;
        for(int i=0;i<s.length();i++){
            q1.push(s[i]);
        }
        for(int j=0;j<goal.length();j++){
            q2.push(goal[j]);
        }
        // lekin tm ye while loop rok ni paoge.
        int k=q1.size()-1;
        while(k>=0){
            char ch=q1.front();q1.pop();
            q1.push(ch);
            if(q1==q2)  return true;
            k--;
        }
        return false;
    }
};