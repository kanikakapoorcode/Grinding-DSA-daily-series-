class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int tot_sum = 0;
        int f = 0;
        for(int i = 0 ; i < n ; i++){
            tot_sum += nums[i];
            f += i*nums[i];
        }
        int res = f;
        for(int k = 1 ; k < n ; k++){
            f += tot_sum ;
            f -= n*nums[n-k];
            res = max(res,f);
        }
        return res;
    }
};