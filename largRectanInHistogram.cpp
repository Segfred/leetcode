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
area=max(area, heights[curIndex]*(stc.empty()? right:right-stc.top()-1));//空的情况实际上是right-(-1)-1，跑到了左边成了负值，
}//end of else，right-curIndex是错误的，比如1，3，5，6来了个4变成1，3，4，下次再1.5，实际上对于4为矩形高前面已经消去了2，还原回来要再往前看
}//end of while，而right-curIndex就是5-4=1,right-top-1=5-1-1=3是正确的。
return area;
    }
};
