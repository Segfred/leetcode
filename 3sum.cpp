class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
vector<vector<int>> res{};
if(nums.size()<3) return res;  
sort(nums.begin(),nums.end());//don't forget to sort
for(size_t i=0;i<nums.size()-2;++i){
if(nums[i]>0) break;//pruning
if(i>0&&nums[i]==nums[i-1]) continue;//don't forget duplicate handling
twoSum(i+1,nums.size()-1,res,nums,nums[i],-nums[i]);//start from the next index, NOt the current	
}
return res;      
    }
private:
void twoSum(size_t s, size_t e, vector<vector<int>> &res, vector<int> &nums, const int &first, const int &target){
while(s<e){
if(nums[s]+nums[e]==target){
res.push_back({first,nums[s++],nums[e--]});
while(s<e&&nums[s]==nums[s-1]) ++s;
while(s<e&&nums[e]==nums[e+1]) --e;
}
else if(nums[s]+nums[e]<target) ++s;
else --e;
}//end of while
}//end function
};