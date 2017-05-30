class Solution {
public:
    vector<int> findAnagrams(const string &str, const string &ptn) {
if(ptn.empty()||str.empty()) return {};
int hash[256];
memset(hash,0,sizeof(hash));
for(const char &c:ptn) ++hash[c];
vector<int> res{};
int left=0,right=0, count=(int)ptn.size(),len=count;
while(right<str.size()){//不是小于ptn.size()
if(hash[str[right++]]-->0) --count;
if(!count) res.emplace_back(left);
if(right-left==len&&hash[str[left++]]++>=0) ++count;//别忘了left右边的++
} 
return res;  
    }
};