class Solution {
public:
    char kthCharacter(int k) {
        int countsetbits=0;
        int index=k-1;
        while(index>0){
            int temp=index%2;
            // cout<<"temp->"<<temp<<endl;
            if(temp==1) countsetbits++;
            index=index/2;
        }
        cout<<"countsetbits"<<countsetbits<<endl;
        return char('a'+countsetbits);
    }
};