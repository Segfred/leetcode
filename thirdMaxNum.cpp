class Solution {
public:
    int thirdMax(vector<int>& nums) {
//empty handling
long first=LONG_MIN,second=LONG_MIN,third=LONG_MIN;//can't first=second=third
for(int &ele:nums){
if(ele>first){
if(second!=LONG_MIN) third=second;
if(first!=LONG_MIN) second=first;
first=ele;}
else if(first>ele>second){//要放到第二位了，往后看还有没有可以移动的
if(second!=LONG_MIN) {third=second;cout<<"second is"<<second;}
second=ele;
}
else if(second>ele>third) {cout<<"third is"<<third<<","<<ele;third=ele;}//不能这样比较，a<b<c,a<b返回结果是bool 0或者1
}//end for   
cout<<"first is"<<first<<"second is"<<second<<"third is"<<third<<endl;
return third==LONG_MIN? first:third;
    }
};