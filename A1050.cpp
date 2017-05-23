#include<cstdio>
#include<cstring>
char a[10005],b[10005];
int HashTable[128]={0};
int main(){
	gets(a);
	gets(b);
	int lenA=strlen(a);
	int lenB=strlen(b);
	for(int i=0;i<lenB;i++){
		HashTable[b[i]]=1;
	} 
	for(int i=0;i<lenA;i++){
		if(HashTable[a[i]]==0){
			printf("%c",a[i]);
		}
	}
	return 0;
}
