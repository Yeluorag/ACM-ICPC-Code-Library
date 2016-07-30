#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char cube[13],c1[7],c2[7];
int Rleft[6]={4,0,2,3,5,1},Rup[6]={2,1,5,0,4,3};

void rotate(int *rot,char *str){
	char temp[7];
	strcpy(temp,str);
	for(int i=0;i<6;i++) str[i]=temp[rot[i]];
}

bool solve(){
	char temp[6];
	
	for(int i=0;i<6;i++){
		strcpy(temp,c1);
		switch(i){
			case 0: rotate(Rleft,temp);rotate(Rup,temp);break;
			case 1: rotate(Rleft,temp);rotate(Rleft,temp);rotate(Rup,temp);break;
			case 2: rotate(Rleft,temp);rotate(Rleft,temp);rotate(Rleft,temp);rotate(Rup,temp);break;
			case 3:	rotate(Rup,temp);break;
			case 4: rotate(Rup,temp);rotate(Rup,temp);break;
			default: break;
		}
		for(int i=0;i<4;i++){
			rotate(Rleft,temp);
			if(strcmp(temp,c2)==0) return true;
		}
	}

	return false;
}

int main(){
    freopen("/Users/apple/input.txt","r",stdin);
 //	freopen("/Users/apple/out.txt","w",stdout);
    while(~scanf("%s",cube)){
    	for(int i=0;i<6;i++){
    		c1[i]=cube[i];
    		c2[i]=cube[i+6];
    	}
    	c1[6]='\0';c2[6]='\0';
    	printf("%s\n",solve()?"TRUE":"FALSE");
    }
    return 0;
}
