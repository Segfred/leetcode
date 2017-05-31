typedef size_t INDEX;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool hash[256];
        memset(hash,0,sizeof(hash));
        INDEX left=0,right=0,maxlen=0;
        while(right<s.length()){
            if(!hash[s[right]]) hash[s[right++]]=1;//就算包含了right也要前进
            else{
                if(right-left>maxlen) maxlen=right-left;
                while(s[left]!=s[right]) hash[s[left++]]=0;
                ++left,++right;//这里别忘了前进right
            }//end of else
        }//end of while 
        if(right-left>maxlen) maxlen=right-left;
        return (int)maxlen;
    }
};