class Solution {
public:
    int differenceOfSums(int n, int m) {
        int firstsum=0;
        int originalsum=(n*(n+1))/2;
        for(int i=1;i<=n;i++){
            if(i%m!=0) firstsum+=i;
        }
        cout<<"originalsum->"<<originalsum<<endl;
        return firstsum==0?-originalsum:firstsum-(originalsum-firstsum);
    }
};