class Solution {
public:
    int minFlips(int a, int b, int c) {
        int  i = 0;
        int cnt = 0;
        while(i <= 32){
            if((c & 1) == 1){
                if(!(a & 1) && !(b & 1)){
                    cnt++;
                }
            }
            else{
                if((a & 1) && (b & 1)){
                    cnt+=2;
                }
                else if((a&1)){
                    cnt++;
                }
                else if(b&1){
                   cnt++; 
                }
            }
            i++;
            c >>= 1;
            a >>= 1;
            b >>= 1;
        }
        return cnt;
    }
};