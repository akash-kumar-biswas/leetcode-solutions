#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int cnt_0 = 0, cnt_1 = 0;
        int cnt_ans = 0;

        int n = s.size();
        int i = 0, j = 0;
        while(j < n){
            if(s[j]=='0')
                cnt_0++;
            if(s[j]=='1')
                cnt_1++;
            
            while(i <= j && (cnt_0 > k && cnt_1 > k)){
                if(s[i]=='0')
                    cnt_0--;
                if(s[i]=='1')
                    cnt_1--;
                i++;
            }
            cnt_ans += (j-i+1);
            j++;
        }
        return cnt_ans;

    }
};

int main() {
    Solution sol;
    cout << sol.countKConstraintSubstrings("1010101", 2) << endl; 
    return 0;
}