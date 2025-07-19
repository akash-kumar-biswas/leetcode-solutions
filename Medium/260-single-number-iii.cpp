class Solution {
public:
    int solve(int x_or){
        int k = 0;
        while(x_or !=0 ){
            if(x_or & 1)
                return k;
            k++;
            x_or >>= 1;
        }
        return -1;
    }

    vector<int> singleNumber(vector<int>& nums) {
        int x_or = 0;
        for(auto num: nums){
            x_or ^= num;
        }
        int pos_1st_differbit = solve(x_or);

        int n1 = 0, n2 = 0;
        for(auto num: nums){
            if(num & (1 << pos_1st_differbit))
                n1 ^= num;
            else
                n2 ^= num;
        }
        return {n1, n2};
    }
};