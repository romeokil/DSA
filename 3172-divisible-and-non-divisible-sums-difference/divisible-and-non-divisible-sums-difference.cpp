class Solution {
public:
    int differenceOfSums(int n, int m) {
        int noofelementsdivisible=n/m;
        int sumofnoofelementsdivisible=(m*(noofelementsdivisible*(noofelementsdivisible+1)))/2;
        int originalsum=(n*(n+1))/2;
        // cout<<"originalsum->"<<originalsum<<endl;
        // cout<<"sumofelementsdivisible->"<<sumofnoofelementsdivisible<<endl;
        return originalsum-2*sumofnoofelementsdivisible;
    }
};