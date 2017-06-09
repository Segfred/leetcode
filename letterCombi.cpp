class Solution {
public:
    vector<string> letterCombinations(const string &str) {
if(str.empty()) return {};
vector<string> res{};
string dict[8]{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};//直接声明的时候才可以赋值初始化
string item{};
dfs(0,item, str, res,dict); 
return res;   
    }
private:

void dfs(size_t level, string &item, const string &str, vector<string> &res, string dict[]){//别忘了dict可见范围，传进去参数或者类内部
if(level==str.length()) {res.push_back(item); return;}
//if(str[level]<'2'||str[level]>'9') error handling
string cur=dict[str[level]-'2'];
for(char &ch:cur){
item.push_back(ch);
dfs(level+1,item,str,res,dict);
item.pop_back();
}//end for
}//end dfs
};