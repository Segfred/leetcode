class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
if(heights.empty()) return 0;
heights.push_back(0);//to get the last element
stack<int> stc{};        
int right=0,area=0;
while(right<(int)heights.size()){
if(stc.empty()||heights[right]>heights[stc.top()]) stc.push(right), ++right;//注意不是大于stc.top()那只是下标
else {
int curIndex=stc.top();
stc.pop();
area=max(area, heights[curIndex]*(stc.empty()? right:right-stc.top()-1));//空的情况实际上是right-(-1)-1，跑到了左边成了负值
}//end of else
}//end of while
return area;
    }
};