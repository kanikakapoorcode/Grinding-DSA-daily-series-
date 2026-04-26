class Solution {
public:
    int f(int i,int j1 ,int j2,int r, int c,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        if(j1 < 0 || j1 >= c || j2 < 0 || j2 >= c)return -1e8;
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        if(i == r-1){
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        int maxi = -1e8;
        for(int d1 = -1 ; d1 <= 1 ; d1++){
            for(int d2 = -1 ; d2 <= 1 ; d2++){
                int value;
                if(j1 == j2) value = grid[i][j1];
                else value = grid[i][j1] + grid[i][j2];
                value += f(i+1, j1+d1, j2+d2, r, c, grid,dp);
                maxi = max(maxi, value);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1))) ;
        return f(0,0,c-1,r,c,grid,dp);
    }
};