#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
using namespace std;

string s;
int main(){
    // freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    while(getline(cin,s)){	
    	stringstream tran(s);
    	string ans,t;
    	int f=0;
    	while(1){
    		tran>>t;
    		if(tran.fail()) break;
    		if(f++) ans+=" ";
    		if(t=="you") t="we";
    		ans+=t;
    	}
    	cout<<ans<<endl;;
    	
    }
    return 0;
}