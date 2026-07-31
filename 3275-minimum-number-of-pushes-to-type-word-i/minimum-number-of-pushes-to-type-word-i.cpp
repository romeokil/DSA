class Solution {
public:
    int minimumPushes(string word) {
       int n=word.size();
        vector<int> freq(26,0);
        int result=0;
        for(int i=0;i<n;i++){
            freq[word[i]-'a']++;
        }
        // descending order me sort kr diye qki jyada freq
        // wala ko pehle rkhege tb na km baar press krna pdega.
        sort(freq.begin(),freq.end(),greater<int>());
        for(int i=0;i<26;i++){
            int press= i/8+1;
            int freqcount=freq[i];
            result+=press*freqcount;
        }
        return result;
    }
};