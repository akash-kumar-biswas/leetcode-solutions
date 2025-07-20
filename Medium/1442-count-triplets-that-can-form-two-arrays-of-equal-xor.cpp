class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> pref_xor(arr.size());
        pref_xor[0] = arr[0];

        for(int i = 1; i < arr.size(); i++){
            pref_xor[i] = arr[i]^pref_xor[i-1];
        }
        int ans = 0;
        for(int i = 0; i < arr.size()-1; i++){
            for(int k = i+1; k < arr.size(); k++){
            
                int xor_i_to_k = pref_xor[k] ^ ((i==0)?0:pref_xor[i-1]);

                if(xor_i_to_k == 0)
                    ans += (k - i);
            }
        }
        return ans;
    }
};