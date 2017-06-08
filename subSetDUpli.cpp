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
if(i>start&&nums[i]==nums[i-1]) continue;//注意这里的去重是因为虽然集合可以重复包含一个元素比如{1,2,2,3}但是每次选的都只是一个开头元素
item.emplace_back(nums[i]);//即只选一个，选好了再选下一个，第一个一样了的话后面肯定会有全一样的，比如{1,2,3}第一个2开头，{1,2,3}第二个2开头
res.emplace_back(item);
dfs(i+1,nums,res,item);
item.pop_back();
}
}        
  
};
