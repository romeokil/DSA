class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> um;
        int n=s.length();
        for(int i=0;i<n;i++){
            um[s[i]]++;
        }
        // agr hmko maximum difference chahiye toh max ko bada and min ko chota krna chahiye
        int oddFreq=INT_MIN,evenFreq=INT_MAX;
        for(const pair<char,int> &p:um){
            if((p.second)%2==1) oddFreq=max(oddFreq,p.second);
            else evenFreq=min(evenFreq,p.second);
        }
        return oddFreq-evenFreq;
    }
};