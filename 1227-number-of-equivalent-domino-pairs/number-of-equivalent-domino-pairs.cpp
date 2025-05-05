class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n=dominoes.size();
        int count=0;
        // time limit excedded de diya re->

        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         vector<int> p=dominoes[i];
        //         vector<int> q=dominoes[j];
        //         int a=0,b=0,c=0,d=0;
        //         a=p[0],b=p[1];
        //         c=q[0],d=q[1];
        //         if(a==c && b==d || a==d && b==c){
        //             count++;
        //         }
        //     }
        // }
        // return count;

        // using map
        // jo bada hai usko change kr de rhe hai.
        for(vector<int>& v:dominoes){
            int first=v[0];
            int second=v[1];
            if(first>second){
                swap(v[0],v[1]);
            }
        }
        // saara ka map me entry kr de rhe hai.
        map<pair<int,int>,int> um;
        for(vector<int>& v:dominoes){
            if(um.find({v[0],v[1]})!=um.end()){
                count+=um[{v[0],v[1]}];
            }
            um[{v[0],v[1]}]++;
        }
       return count;
    }
};