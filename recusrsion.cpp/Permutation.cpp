class Solution {
public:
    void solve(int ind,vector<int>&nums,vector<vector<int>>&ans){
        // if(ds.size()==nums.size()){
        //     ans.push_back(ds);
        //     return;
        // }
        // for(int i=0;i<nums.size();i++){
        //     if(!mp[i]){
        //         ds.push_back(nums[i]);
        //         mp[i]=1;
        //         solve(ds,nums,ans,mp);
        //         mp[i]=0;
        //         ds.pop_back();
        //     }
        // }
        if(ind==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            solve(ind+1,nums,ans);
            swap(nums[ind],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        // vector<int>ds;
        // vector<int>mp(nums.size(),0);
        solve(0,nums,ans);
        return ans;
    }
};
