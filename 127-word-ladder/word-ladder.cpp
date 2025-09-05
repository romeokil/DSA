class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            string curword=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(curword==endWord) return steps;
            for(int i=0;i<curword.length();i++){
                char originalcharacter=curword[i];
                for(char ch='a';ch<='z';ch++){
                    curword[i]=ch;
                    if(st.find(curword)!=st.end()){
                        q.push({curword,steps+1});
                        st.erase(curword);
                    }
                }
                curword[i]=originalcharacter;
            }
        }
        return 0;
    }
};