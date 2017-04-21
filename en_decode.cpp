//
//  main.cpp
//  enco_decode_str
//
//  Created by Asmita on 2017/04/21.
//  Copyright © 2017年 Asmita. All rights reserved.
//

#include <iostream>
//3#bec10#btracgrdcg2#ab
#include <vector>
#include <string>
using namespace std;
class Codec{
public:
    string encode(vector<string> &strs)
    {
        string rslt{};
        for(const auto &item:strs)
            rslt+=to_string(item.size())+'#'+item;
        return rslt;
    }
    
    vector<string> decode(string &str)
    {
        vector<string> rslt{};
        size_t pos,size,index=0;
        while(index<str.size())
        {
            pos=str.find('#',index);
            if(pos==string::npos) break;
            size=stoi(str.substr(index,pos-index));
            rslt.push_back(str.substr(pos+1,size));
            index=pos+size+1;
        }
        
        return rslt;
    }
    
};


int main(int argc, const char * argv[]) {
    // insert code here...
    shared_ptr<Codec> pcod(new Codec());
    vector<string> strs{"abc","123","d"};
    string firslt= pcod->encode(strs);
    cout<<firslt;
    vector<string> serslt=pcod->decode(firslt);
    for(const auto &elem:serslt) cout<<elem<<" ";
    cout<<endl;
    return 0;
}
