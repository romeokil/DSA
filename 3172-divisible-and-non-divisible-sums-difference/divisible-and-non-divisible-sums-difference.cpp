class Solution {
public:
    int differenceOfSums(int n, int m) {
        int firstsum=0,secondsum=0;
        for(int i=1;i<=n;i++){
            if(i%m!=0) firstsum+=i;
            else secondsum+=i;
        }
        return firstsum-secondsum;
    }
};