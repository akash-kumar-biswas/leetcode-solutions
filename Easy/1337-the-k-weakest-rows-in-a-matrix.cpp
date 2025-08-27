class Solution {
public:

    static bool cmp(pair<int, int> &a, pair<int, int> &b){
        if(a.first == b.first)
            return a.second < b.second;
        else
            return a.first < b.first;
    }

    int No_Of_Ones(vector<int> &vec){
        int low = 0, high = vec.size() - 1;

        int mid;

        while(low <= high){
            mid = low + (high - low)/2;

            if(vec[mid] == 1)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> myPair;

        for(int i = 0; i < mat.size(); i++){
            myPair.push_back({No_Of_Ones(mat[i]), i});
        }

        sort(myPair.begin(), myPair.end(), cmp);

        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(myPair[i].second);
        }

        return ans;
    }
};