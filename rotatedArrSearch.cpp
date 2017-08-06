class Solution {
public:
    int search(vector<int>& nums, int target) {
    if(nums.empty()) return -1;
    int left=0, right=(int)nums.size()-1;
    while(left<=right){
    //int mid=left+(right-left)>>1;错误，移位运算级最低
    int mid=left+(right-left>>1);
    if(nums[mid]==target) return mid;
    //if(nums[left]<nums[mid]){//有序数组在左边，没有等号就错了，左右可能重合
    if(nums[left]<=nums[mid]){//有序数组在左边
    //if(nums[left]<=target<nums[mid]) right=mid-1;错误，不能写成连等式，第一个nums[left]<g是个bool值，0或者1
    if(nums[left]<=target&&target<nums[mid]) right=mid-1;
    else left=mid+1;
    }
    else{//有序数组在右边
    if(nums[mid]<target&&target<=nums[right]) left=mid+1;
    else right=mid-1;
    }
    }
    
    return -1;//not found
    }
};