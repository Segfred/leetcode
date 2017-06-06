class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
if(nums.size()<k) return {};
vector<int> res{};
deque<int> deq{};
for(int i=0;i<(int)nums.size();++i){
if(!deq.empty()&&deq.back()==i-k) deq.pop_back();//也可以先判断是否窗口满了，这样不会超过size，并且更快
while(!deq.empty()&&nums[i]>=nums[deq.front()]) deq.pop_front();//是和nums[front]比较，不是和front比较，注意存的是下标！
deq.emplace_front(i);//存的是下标，不是数本身，先存入新数，再判断窗口是否满了
if(i>=k-1) res.emplace_back(nums[deq.back()]);//存到结果的是nums[]下标，不是下标
}        
return res;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
if(nums.size()<k) return {};
vector<int> res{};
deque<int> deq{};//decreasing deque to save the index
int i=0;
while(i<(int)nums.size()){
while(!deq.empty()&&nums[i]>nums[deq.front()]) deq.pop_front();//在删掉我之前，我的潜力最大
deq.push_front(i);
if(i++>=k-1) res.push_back(nums[deq.back()]);//maximum is on the bottom，只是加1还没参与计算，deq元素个数所以不会超
if(deq.back()==i-k) deq.pop_back();
}        
return res;
    }
};
