#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> txt[1005];
string code,te;
int maxlen[255];

void print(string s,int len){
	for(int i=0;i<s.size();i++) cout<<s[i];
	for(int i=0;i<=len-s.size();i++) cout<<' ';
}
int main(){
    // freopen("/Users/apple/input.txt","r",stdin);
 //	freopen("/Users/apple/out.txt","w",stdout);
    int col=0,row=0;
    while(getline(cin,code)){
    	stringstream tran(code);
    	col=0;
    	while(tran>>te){
    		maxlen[col]=max(maxlen[col],(int)te.size());
    		col++;
    		txt[row].push_back(te);
    	}
    	row++;
    }
    for(int i=0;i<row;i++){
    	for(int j=0;j<txt[i].size()-1;j++)
    		print(txt[i][j],maxlen[j]);
    	cout<<txt[i][txt[i].size()-1]<<endl;
    }
    return 0;
}
