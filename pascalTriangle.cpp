class Solution {
public:
    vector<vector<int>> generate(int numRows) {
vector<vector<int>> res{};
if(numRows==0) return res;
vector<int> item(1,1);//先生成第一个
res.emplace_back(item);
for(int i=1;i<numRows;++i){
int pre=1;//每行都要重新声明pre,pre初始值为dp[i-1][0]都是1
  for(int j=1;j<i;++j){//必须正向，因为无法事先声明数组大小,dp[i][j]=dp[i-1][j-1]+dp[i-1][j]
int temp=item[j];//还要防止覆盖，只能用滚动数组
item[j]+=pre;//pre存的时候是dp[i-1][j]下次循环就成了dp[i-1][j-1]
pre=temp;
}//each row of number
item.emplace_back(1);//生成最后一个元素,push进去1没事，以后还会更新
res.emplace_back(item);    
}//generate all rows
return res;
    }
};

class Solution {
public:
    vector<int> getRow(int rowIndex) {
if(rowIndex<0) return {};
vector<int> res(rowIndex+1,1);
for(int i=1;i<=rowIndex;++i)
 for(int j=i-1;j>=1;--j) res[j]+=res[j-1];

return res;
    }
};