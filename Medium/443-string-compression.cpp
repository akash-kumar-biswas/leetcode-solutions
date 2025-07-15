class Solution {
public:
    void solve(vector<char>& chars, int &len, int &j, int l, int cnt){
        
        len++;
        chars[j] = chars[l-1];
        j++;
        string s(4, '$');
        int k = 0;
        while(cnt!=0){
            char mod = cnt%10 + '0';
            s[k] = mod;
            cnt/=10;
            k++;
            len++; 
        }
        for(int i = 3; i>= 0; i--){
            if(s[i]!='$'){
                chars[j] = s[i];
                j++;
            }
        }
        
    }
    
    int compress(vector<char>& chars) {
        int n = chars.size();
        if(n == 1)
            return 1;

        string str;
        char ch1 = chars[n-2];
        
        int cnt = 1;
        int len = 0;
        int j = 0;
        for(int i = 1; i < n; i++){
            if(chars[i-1] != chars[i]){     // 1 2 3 3 2
                if(cnt != 1){  
                    solve(chars, len, j, i, cnt);
                    cnt = 1;
                }
                else{
                    len++;
                    chars[j] = chars[i-1];
                    j++;
                }
            }
            else
                cnt ++;
        }
        if(ch1 != chars[n-1]){
            len++;
            chars[j] = chars[n-1];
        }
        else{
            solve(chars, len, j, n, cnt);
        }
        return len;
    }
};