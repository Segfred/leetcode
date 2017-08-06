class Solution {
public:
    string multiply(string& from, string& to) {
        	if(from.empty()||to.empty()) return "";
	if(from=="0"||to=="0") return "0";//即使一个字符也不能写成'0'，必须双引号，因为是字符串
	reverse(from.begin(),from.end());
	reverse(to.begin(),to.end());
	const size_t m=from.length(), n=to.length();
	string res(m+n,'0');
	int carry, temp;
	for(size_t j=0;j<n;++j){
		carry=0, temp=0;
		for(size_t i=0;i<m;++i){
		//carry+=(from[i]-'0')*(to[j]-'0');错误，结果必须加上原来的数，carry这里是结果，除10之后才是进位
        //carry=(from[i]-'0')*(to[j]-'0')+res[i+j]-'0';错，carry必须是加
        temp=(from[i]-'0')*(to[j]-'0')+res[i+j]-'0'+carry;//加上原来有的和上次的进位，对照345*78去理解
		//res[i+j]+=carry%10;错误，上面加过就不能再加了
        res[i+j]=temp%10+'0';//每次都更新到最新的   
		carry=temp/10;
		}
        //if(carry!=0) res[m+j]+=carry错误
        if(carry!=0) res[m+j]+=carry;//和下面一样，都是第一次出现，这里的加不是累加，而是加上'0'肯定在当前的最高位
		//if(carry!=0) res[m+j]=carry+'0';//进位不一定是1，45的话进位就是4，不用加,前面的carry那里会加上
	}
	//if(res[m+n-1]=='0') res=res.substr(1);
	reverse(res.begin(),res.end());//最后还要翻转
    if(res[0]=='0') return res.substr(1);
	return res;
    }
};