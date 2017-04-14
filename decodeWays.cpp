#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
int numDecodings(string s) {
    if (s.empty()||s[0]=='0') return 0;
    int w2 (1);
    int w1 (1);
    int w=w1;//w=w1+w2 but w2 is unvisible now,so w＝0，w+=w1
    for (size_t i=2; i<=s.size(); i++) {//begin from the third number 
        w = (s[i-1] == '0') ? 0 : w1;
        if (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] >= '0' && s[i-1] <= '6'))
            w += w2;
        w2 = w1;
        w1 = w;
    }
    return w;
}
};