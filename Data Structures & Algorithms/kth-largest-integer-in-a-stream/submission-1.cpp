class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int sz;
    KthLargest(int k, vector<int>& nums) {
        sz=k;
        for(int& i: nums ) {
            pq.push(i);
            if(pq.size()>sz) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>sz) pq.pop();
        return pq.top();
        
    }
};
