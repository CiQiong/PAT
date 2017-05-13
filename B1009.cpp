/*
#include<cstdio>
int main(){
	int num=0;
	char ans[90][90];
	while(scanf("%s",ans[num])!=EOF){//<Ctrl+Z>组合键+<Enter> 
		num++;
	}
	for(int i=num-1;i>=0;i--){
		printf("%s",ans[i]);
		if(i>0)printf(" ");
	}
	return 0;
}
*/
#include<cstdio>
#include<cstring>
int main(){
	char str[90];
	gets(str);
	int len=strlen(str),r=0,h=0;//r为行，h为列
	char ans[90][90];
	for(int i=0;i<len;i++){
		if(str[i]!=' '){
			ans[r][h++]=str[i];
		}else{
			ans[r][h]='\0';//说明第r个单词输入完毕，结束 
			r++;
			h=0; 
		}
	} 
	for(int i=r;i>=0;i--){
		printf("%s",ans[i]);
		if(i>0)printf(" ");
	}
	return 0;
}
