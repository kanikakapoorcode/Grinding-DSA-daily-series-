class Solution {
public:
    int findWays(vector<int>& arr, int k){
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(k+1, 0));
        if(arr[0] == 0) dp[0][0] = 2;  
        else dp[0][0] = 1;
        if(arr[0] != 0 && arr[0] <= k)dp[0][arr[0]] = 1;
        for(int i = 1; i < n; i++){
            for(int sum = 0; sum <= k; sum++){
                int notpick = dp[i-1][sum];
                int pick = 0;
                if(arr[i] <= sum) pick = dp[i-1][sum - arr[i]];
                dp[i][sum] = (pick + notpick);
            }
        }
        return dp[n-1][k];
    }
    int countPartitions(vector<int>& arr, int diff) {
        int totsum = 0 ;
        for(auto &it : arr){
            totsum += it;
        }
        if(totsum - diff < 0 || (totsum - diff)% 2) return 0;
        return findWays(arr,(totsum-diff)/2);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums,target);
    }
};