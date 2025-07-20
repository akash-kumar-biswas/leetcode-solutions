class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> pref_xor(arr.size());
        pref_xor[0] = arr[0];

        for(int i = 1; i < arr.size(); i++){
            pref_xor[i] = arr[i]^pref_xor[i-1];
        }
        int cnt = 0;
        for(int i = 0; i < arr.size()-1; i++){
            for(int j = i+1; j < arr.size(); j++){
                for(int k = j; k < arr.size(); k++){
                    int a = pref_xor[j-1] ^ ((i==0)?0:pref_xor[i-1]);
                    int b = pref_xor[k] ^ pref_xor[j-1];

                    if(a == b)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};