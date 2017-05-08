#include<cstdio>
#include<cstring>
const int maxn=1010;
char S[maxn];
int main(){
	gets(S);
	int len=strlen(S),maxlen=1;
	for(int i=0;i<len;i++){
		for(int j=i+1;j<len;j++){
			int a=i,b=j;
			while(a<b){
				if(S[a]!=S[b]){
					break;
				}
				a++;
				b--;
			}
			if(a>=b&&j-i+1>maxlen){
				maxlen=j-i+1;
			}
		}
	}
	printf("%d\n",maxlen);
	return 0;
} 
 
