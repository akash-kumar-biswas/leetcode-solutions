class Solution
{
public:
    int No_Of_Ones(vector<int> &vec)
    {
        int low = 0, high = vec.size() - 1;

        int mid;

        while (low <= high)
        {
            mid = low + (high - low) / 2;

            if (vec[mid] == 1)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }

    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < mat.size(); i++)
        {
            pq.push({No_Of_Ones(mat[i]), i});

            if (pq.size() > k)
                pq.pop();
        }

        vector<int> ans(k);
        for (int i = k - 1; i >= 0; i--)
        {
            ans[i] = pq.top().second;
            pq.pop();
        }

        return ans;
    }
};