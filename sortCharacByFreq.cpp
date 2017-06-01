class Solution {
public:
    string frequencySort(const string &str) {
    string res{};
if(str.empty()) return res;
int hash[256];//记录每个字符出现次数
memset(hash,0,sizeof(hash));
for(const char &c:str) ++hash[c];//常string要跟常char
string pos[str.length()+1];//把字符放到出现次数的位置aaab,a就放到3处,aaabbbc,同一位置可能放多个字符
for(auto &ele:pos) ele="";//初始化
for(int i=0;i<256;++i) if(hash[i]) pos[hash[i]].append(hash[i],(char)i);//3放了aaabbb
for(int i=(int)str.length();i>0;--i) if(!pos[i].empty()) res.append(pos[i]);
return res;
    }
};