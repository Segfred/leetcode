class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
if(nums.empty()) return 1;
const int len=(int)nums.size();
int i=0;
while(i<len){//不能这里i++，那样下一行的i就是加过的
if(nums[i]>0&&nums[i]<=len&&nums[i]!=nums[nums[i]-1]&&nums[i]!=i+1) swap(nums[i],nums[nums[i]-1]);
//错的，要判断是否相等,否则一直交换,比如3,4,3,1
else ++i;//一直循环下去，直到前面的数符合要求才能放心往后走，不然就换一次前面还没好就往后容易出事
}       
for(int j=0;j<len;++j) if(nums[j]!=j+1) return j+1;
return len+1;
    }
};