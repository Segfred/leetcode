#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;

class Solution1 {
public:
    void reverseWords1(string &s) {
        istringstream is(s);
        string str;
        is>>s;
        while(is>>str){
            s=str+' '+s;//空字符串也要写成" "不能""
        }
        if(!s.empty()&&s[0]==' ') s.clear();
    }
};

class Solution {
public:
    void reverseWords2(string &str) {
        if(str.empty()) return;
        size_t left=0;
        for(size_t i=0;i<=str.size();++i){//最后末尾超出的范围也要遍历
            if(str[i]==' '||i==str.size()) {reverse(str.begin()+left, str.begin()+i);
                left=i+1;}//注意这里要加括号
        }
        reverse(str.begin(), str.end());
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sol;
    string str="the sky is blue";
    sol.reverseWords2(str);
    cout <<str<<endl;
    return 0;
}
//below is the recursive method
#include <iostream>
#include <sstream>
//#include <string>
using namespace std;
void help(istringstream &in, ostringstream &out){
    string temp{};
    if(in>>temp) help(in,out);
    out<<temp<<" ";
}

void rever(string &str){
    if(str.empty()) return;
    istringstream in(str);
    ostringstream out{};
    help(in,out);
    str=out.str().substr(0,out.str().size()-1);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string str{"I love it"};
    rever(str);
    cout << str<<endl;
    return 0;
}
