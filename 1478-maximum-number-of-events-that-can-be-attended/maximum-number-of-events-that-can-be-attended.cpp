class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        // ab dekho hmlog priority queue me sirf end day hi daal rhe hai 
        // qki hmko usi se mtlb hai otherwise tm pair bhi daal skte ho.
        int day=events[0][0];
        int count=0;
        int i=0;
        while(!pq.empty() || i<n){

            // same day wala saaara lounda ko daal diye.
            while(i<n && events[i][0]==day){
                pq.push(events[i][1]);
                i++;
            }

            if(!pq.empty()){
                pq.pop();
                count++; // 1 event attend kr liye.
            }
            day++;

            // check kr lo agr hmara day hi aage badh gy hai toh
            // ky hi fayda usko priority_queue me rkh ke
            while(!pq.empty() && day>pq.top()){
                pq.pop();
            }
        }
        return count;
    }
};