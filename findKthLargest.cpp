class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
if(nums.empty()||nums.size()<k) return 0;
return getk(nums,k,0,nums.size()-1);
}
private:
int getk(vector<int> &nums, int k, int start, int end){
	int pivot=nums[0];
while(left<right){
while(left<right&&nums[right]>=pivot) --right;
if(left<right) nums[left++]=nums[right--];

while(left<right&&nums[left]<=pivot) ++left;
if(left<right) nums[right--]=nums[left++];
}
nums[left]=pivot;
int range=end-right+1;
if(range==k) return pivot;
else if(range<k) return getk(nums,k-range,start,left-1);
else return getk(nums,nums,k,left+1,right);
}
};