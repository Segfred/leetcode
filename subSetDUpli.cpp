class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
vector<vector<int>> res(1);
vector<int> item{};
sort(nums.begin(),nums.end());
dfs(0,nums,res,item);
return res;
}
private:
void dfs( size_t start, const vector<int> &nums, vector<vector<int>> &res, vector<int> &item){
for(size_t i=start;i<nums.size();++i){//NOT from 0
if(i>start&&nums[i]==nums[i-1]) continue;//集合不能包括重复元素，可以直接跳过
item.emplace_back(nums[i]);
res.emplace_back(item);
dfs(i+1,nums,res,item);
item.pop_back();
}
}        
  
};