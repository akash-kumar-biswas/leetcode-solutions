class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxArea = 0;
        double maxDiagonal = 0;

        for(int i = 0; i < dimensions.size(); i++){
            double diagonal = sqrt(dimensions[i][0]* dimensions[i][0] + dimensions[i][1]* dimensions[i][1]);
            if(maxDiagonal < diagonal){
                maxArea = dimensions[i][0]* dimensions[i][1];
                maxDiagonal = diagonal;
            }

            else if(maxDiagonal == diagonal && maxArea < dimensions[i][0]* dimensions[i][1]){
                maxArea = dimensions[i][0]* dimensions[i][1];
            }
        }
        return maxArea;
    }
};