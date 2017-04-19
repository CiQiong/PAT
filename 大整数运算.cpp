#include<cstdio>
#include<cstring>
//定义大整数类型bign 
struct bign{
	int d[1000];//记录大整数各个位上的值(注意是反过来的) 
	int len;//保存大整数的长度 
	bign(){//初始化 
		memset(d,0,sizeof(d));
		len=0;
	}
}; 
//将整数转换为bign 
bign change(char str[]){
	bign a;
	a.len=strlen(str);
	for(int i=0;i<a.len;i++){
		a.d[i]=str[a.len-1-i]-'0';
	}
	return a;
}
//比较两个大整数大小
int compare(bign a,bign b){
	if(a.len>b.len)return 1;//a大 
	else if(a.len<b.len)return -1;//a小 
	else{
		for(int i=a.len-1;i>=0;i--){
			if(a.d[i]>b.d[i])return 1; 
			else if(a.d[i]<b.d[i])return -1;
		} 
		return 0;//a,b大小一样 
	}
} 
//高精度加法(正数)
bign add(bign a,bign b){
	bign c;
	int carry=0;//表示进位数量
	for(int i=0;i<a.len||i<b.len;i++){//a，b中比较长的为界限 
		int temp=a.d[i]+b.d[i]+carry;//对应位的和加上进位值 
		c.d[c.len++]=temp%10; 
		carry=temp/10;
	} 
	if(carry!=0){//如果最后的进位不为0，则直接赋给结果的最高位 
		c.d[c.len++]=carry;
	}
	return c; 
}
//高精度减法(正数，且第一个数大于第二个数)
bign sub(bign a,bign b){
	bign c;
	for(int i=0;i<a.len||i<b.len;i++){
		if(a.d[i]<b.d[i]){//如果不够减 
			a.d[i+1]--;//向高位借位 
			a.d[i]+=10;//当前位加10 
		}
		c.d[c.len++]=a.d[i]-b.d[i];
	}
	while(c.len-1>=1&&c.d[c.len-1]==0){
		c.len--;//去除最高位的所有可能的0，同时保证个位有数字 
	}
	return c; 
}
//高精度与低精度的乘法(正数) 
bign multi(bign a,int b){
	bign c;
	int carry=0;//保存进位数量 
	for(int i=0;i<a.len;i++){
		int temp=a.d[i]*b+carry;//让大整数的每一位都乘以小整数 
		c.d[c.len++]=temp%10;
		carry=temp/10; 
	}
	while(carry!=0){//进位值可能不止一位，因此用while 
		c.d[c.len++]=carry%10;
		carry/=10;
	}
	return c;
} 
//高精度与低精度的除法(正数) 
bign divide(bign a,int b,int &r){//r为余数 
	
} 
//输出一个bign
void print(bign a){
	for(int i=a.len-1;i>=0;i--){
		printf("%d",a.d[i]);
	}
} 
int main(){
	char str1[1000],str2[1000];
	int c;
	scanf("%s%s%d",str1,str2,&c);
	bign a=change(str1);
	bign b=change(str2);
	
	print(add(a,b));//输出两数之和 
	printf("\n");
	print(sub(a,b));//输出两数之差 
	printf("\n");
	print(multi(a,c));//输出两数之积 
	printf("\n");
	return 0;
}
