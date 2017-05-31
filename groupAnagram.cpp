class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
vector<vector<string>> res{};
if(strs.empty()) return res;
unordered_map<string,vector<size_t>> hash{};//排序后的字符串和下标映射
for(size_t i=0;i<strs.size();++i){
string cur=strs[i];
sort(cur.begin(),cur.end());
hash[cur].emplace_back(i);
}
for(auto &ele:hash){
vector<string> item{};
for(size_t idx:ele.second) item.emplace_back(strs[idx]);//存的是下标，不是字符串本身
res.emplace_back(item);
}
return res;        
    }
};