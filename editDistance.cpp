//f[i][j]=f[i-1][j-1];
//else min(f[i][j-1].f[i-1][j],
class Solution {
public:
    int minDistance(const string& from, const string& to) {
if(from.length()<to.length()) return minDistance(to, from);
const int len=to.size();//虽然最大只有minLen但可以动态增长
int* pnewdp=new int[len+1];     
int* pdp=new int[len+1];
for(int j=0;j<=len;++j){
pdp[j]=j;//初始化一定要做，之后new还依赖于旧的dp,相当于f[0][j]全为0，第一行
}
for(int i=0;i<=(int)from.length();++i){//要从0开始，dp初始化了，new还没有
pnewdp[0]=i;//代表前i个字符，一共前from.length()个
for(int j=1;j<=len;++j){//注意下标从1开始    
if(from[i-1]==to[j-1]) pnewdp[j]=pdp[j-1];//注意下标序号
else pnewdp[j]=min(min(pnewdp[j-1],pdp[j]),pdp[j-1])+1;//f[i-1][j]不是new[j]而是旧的,new[j]是new[i][j]
}
swap(pnewdp,pdp);
}
int res=pdp[len];//最后还换了一次，所以是pdp而不是pnewdp
delete []pnewdp;
delete []pdp;
return res;
    }
};