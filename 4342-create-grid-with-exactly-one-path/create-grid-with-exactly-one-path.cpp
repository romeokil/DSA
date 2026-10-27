class Solution {
public:
    vector<string> createGrid(int m, int n) {
        // aise hmlog hardcode eslie kr pae qki hmlog ko pata h ki ye jo tarika ye saare cells ke liye work krega
        // right tb tk jao jb tk ja skte ho , and then down jao
        vector<string> result(m);
        result[0]=string(n,'.');
        if(m==1) return result;
        string temp=string(n-1,'#')+string(1,'.');
        for(int i=1;i<m;i++){
            result[i]=temp;
        }
        return result;
    }
};