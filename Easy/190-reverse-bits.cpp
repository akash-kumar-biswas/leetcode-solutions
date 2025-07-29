class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;

        int i = 0;
        while(i <= 31){
            int LSB = n & 1;
            if(LSB == 1)
                ans |= 1 << (31 - i);
            i++;
            n >>= 1;
        }
        return ans;
    }
};