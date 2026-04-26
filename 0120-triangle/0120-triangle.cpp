class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        for(int i = m-2 ; i >= 0 ; i--){
            for(int j = 0  ; j < triangle[i].size() ; j++){
                int blw = triangle[i+1][j];
                int blwR = triangle[i+1][j+1];
                triangle[i][j] += min(blw,blwR);
            }
        }
        return triangle[0][0];
    }
};