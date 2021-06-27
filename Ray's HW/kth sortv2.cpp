//LEETCODE FORMAT
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int k = 4;
        vector<int>ans;
        priority_queue<int> q;
        for(int i = 0;i<k;i++){
            q.push(nums[i]);
        }
        for(int i = k;i<nums.size();i++){
            ans.push_back(q.top());
            q.pop();
            q.push(nums[i]);
        }
        for(int x: v){
            ans.push_back(x);
        }
        return ans;
    }
};
