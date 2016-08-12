#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

string command,s2;
char s[260];

int main(){
    // freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    string EndOfInput("ENDOFINPUT");
    string start("START");
    string end("END");
    while(cin>>command){
    	if(command==EndOfInput) break;
    	memset(s,'\0',sizeof(s));
    	getchar();
    	gets(s);
    	cin>>s2;
    	int len=strlen(s);
    	for(int i=0;i<len;i++){
    		if(s[i]>='F'&&s[i]<='Z') s[i]-=5;
    		else if(s[i]<'F'&&s[i]>='A') s[i]+=21;
    		printf("%c",s[i]);
    	}
    	puts("");

    }
    return 0;
}