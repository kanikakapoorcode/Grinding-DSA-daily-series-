class Solution {
public:
    int solve(int i , int j,vector<int>& g, vector<int>& s){
        if (i >= g.size() || j >= s.size()) return 0;
        int notTake = solve(i, j + 1, g, s);
        int take = 0;
        if (s[j] >= g[i]) {
            take = 1 + solve(i + 1, j + 1, g, s);
        }
        return max(take, notTake);
    }
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        return solve(0,0,g,s);
    }
};