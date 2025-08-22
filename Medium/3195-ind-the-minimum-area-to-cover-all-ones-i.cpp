class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int leftCol = n;
        int rightCol = 0;

        int topRow = m;
        int bottomRow = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    leftCol = min(leftCol, j);
                    rightCol = max(rightCol, j);

                    topRow = min(topRow, i);
                    bottomRow = max(bottomRow, i);
                }
            }
        }
        int length = rightCol - leftCol + 1;
        int height = bottomRow - topRow + 1;

        return length * height;
    }
};