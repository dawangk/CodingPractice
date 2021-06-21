//LEETCODE FORMAT
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int k = 4;
        vector<int> v, ans;
        for(int i = 0;i<k;i++){
            v.push_back(nums[i]);
        }
        
        sort(v.begin(), v.end());
        for(int i = k;i<nums.size();i++){
            ans.push_back(v[0]);
            v.erase(v.begin());
            auto x = lower_bound(v.begin(), v.end(), nums[i]);
            v.insert(x, nums[i]);
        }
        for(int x: v){
            ans.push_back(x);
        }
        return ans;
    }
};
