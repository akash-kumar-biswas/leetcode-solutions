class Solution {
public:
    bool isPartPossible(vector<int> map, vector<int> deck){
        int x = map[deck[0]];
        for(auto num: deck){
            if(map[num] >= 1){
                x = gcd(x, map[num]);
            }
        }
        return x > 1;
    }

    bool hasGroupsSizeX(vector<int>& deck) {
        vector<int> map(1e4, 0);

        for(auto num: deck){
            map[num]++;
        }

        return isPartPossible(map, deck);
    }
};