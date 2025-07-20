class Solution {
public:
    void positionUnsetBit(vector<int> &map, int num){
        int k = 0;

        while(k < 32){
            if((num & 1) == 0)
                map[k] = 0;
            num >>= 1;
            k++;
        }
    }

    int rangeBitwiseAnd(int left, int right) {
        vector<int> map(32, 1);
        positionUnsetBit(map, right);
        int i = 0;
        long long _left = left;
        while(_left < right){
            if(find(map.begin(), map.end(), 1) != map.end())
                positionUnsetBit(map, _left);
            else
                break;
            _left += 1<<i;
            i++;
        }
        int ans = 0;
        for(int k = 0; k < 32; k++){
            if(map[k] == 1)
                ans |= (1<<k);
        }
        return ans;
    }
};