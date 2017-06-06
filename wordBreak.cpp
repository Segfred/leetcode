
//word break I
#define contain(i,j,str,dict) find(dict.begin(),dict.end(),str.substr(j,i-j))!=dict.end()
class Solution {
public:
    bool wordBreak(string &str, vector<string>& dict) {
        if(str.empty()||dict.empty()) return false;
        const int n=(int)str.length();
        vector<bool> dp(n+1,false);
        dp[0]=true;
        for(int i=1;i<n+1;++i){
            for(int j=i-1;j>=0;--j)
                if(dp[j]&&contain(i,j,str,dict)) {dp[i]=true;break;}            
        }//end i loop
        return dp[n];
    }
};
//word break II
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
bool possible[s.length()+1];//possible[i]往后，意味着[i,n]这个区间有解
memset(possible,1,sizeof(possible));  
string item{};
vector<string> res{};
dfs(s,wordDict,item,res,possible,0);
return res;  
    }

private:
void dfs(const string &str, vector<string> &dict, string &item, vector<string> &res, bool possible[], size_t start){
if(start==str.length()) res.push_back(item.substr(0,item.length()-1));
for(size_t i=start;i<str.length();++i){

if(possible[i+1]&&find(dict.begin(),dict.end(),str.substr(start,i-start+1))!=dict.end() ){
size_t curSize=res.size();
item.append(str.substr(start,i-start+1)).append(" ");//append必须字符串" "不能字符''
dfs(str,dict,item,res,possible,i+1);
if(res.size()==curSize) possible[i+1]=false;//res不是item长度，而是以start开头，当前节点i结尾的字符串往后找不到解
item.resize(item.size()-i-1+start-1);//还要减1去掉多加的空格，知道了i后面的无解，前面怎么划分都不会有解，是为前面划分方式省去计算
}//end of if比如第一次[0~i~n]无解，后面[0~j,j~i,i~n]也还是无解，此时possible[i+1]作用就出来了
}//end of i loop

}//end of dfs
};
