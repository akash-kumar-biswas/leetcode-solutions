class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq;

        for(auto num: nums){
            pq.push(num);
        }

        int maxNum = pq.top();
        pq.pop();
        int sec_maxNum = pq.top();

        return (maxNum - 1) * (sec_maxNum - 1);
    }
};