class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<float, vector<int>>> pq;

        for(int i = 0; i < arr.size(); i++){
            for(int j = i+1; j < arr.size(); j++){
                pq.push({arr[i]*1.0/arr[j], {arr[i], arr[j]}});
                
                if(pq.size() > k)
                    pq.pop();
            }
        }
        return pq.top().second;
    }
};