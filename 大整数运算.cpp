#include<cstdio>
#include<cstring>
//�������������bign 
struct bign{
	int d[1000];//��¼����������λ�ϵ�ֵ(ע���Ƿ�������) 
	int len;//����������ĳ��� 
	bign(){//��ʼ�� 
		memset(d,0,sizeof(d));
		len=0;
	}
}; 
//������ת��Ϊbign 
bign change(char str[]){
	bign a;
	a.len=strlen(str);
	for(int i=0;i<a.len;i++){
		a.d[i]=str[a.len-1-i]-'0';
	}
	return a;
}
//�Ƚ�������������С
int compare(bign a,bign b){
	if(a.len>b.len)return 1;//a�� 
	else if(a.len<b.len)return -1;//aС 
	else{
		for(int i=a.len-1;i>=0;i--){
			if(a.d[i]>b.d[i])return 1; 
			else if(a.d[i]<b.d[i])return -1;
		} 
		return 0;//a,b��Сһ�� 
	}
} 
//�߾��ȼӷ�(����)
bign add(bign a,bign b){
	bign c;
	int carry=0;//��ʾ��λ����
	for(int i=0;i<a.len||i<b.len;i++){//a��b�бȽϳ���Ϊ���� 
		int temp=a.d[i]+b.d[i]+carry;//��Ӧλ�ĺͼ��Ͻ�λֵ 
		c.d[c.len++]=temp%10; 
		carry=temp/10;
	} 
	if(carry!=0){//������Ľ�λ��Ϊ0����ֱ�Ӹ�����������λ 
		c.d[c.len++]=carry;
	}
	return c; 
}
//�߾��ȼ���(�������ҵ�һ�������ڵڶ�����)
bign sub(bign a,bign b){
	bign c;
	for(int i=0;i<a.len||i<b.len;i++){
		if(a.d[i]<b.d[i]){//��������� 
			a.d[i+1]--;//���λ��λ 
			a.d[i]+=10;//��ǰλ��10 
		}
		c.d[c.len++]=a.d[i]-b.d[i];
	}
	while(c.len-1>=1&&c.d[c.len-1]==0){
		c.len--;//ȥ�����λ�����п��ܵ�0��ͬʱ��֤��λ������ 
	}
	return c; 
}
//�߾�����;��ȵĳ˷�(����) 
bign multi(bign a,int b){
	bign c;
	int carry=0;//�����λ���� 
	for(int i=0;i<a.len;i++){
		int temp=a.d[i]*b+carry;//�ô�������ÿһλ������С���� 
		c.d[c.len++]=temp%10;
		carry=temp/10; 
	}
	while(carry!=0){//��λֵ���ܲ�ֹһλ�������while 
		c.d[c.len++]=carry%10;
		carry/=10;
	}
	return c;
} 
//�߾�����;��ȵĳ���(����) 
bign divide(bign a,int b,int &r){//rΪ���� 
	
} 
//���һ��bign
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
	
	print(add(a,b));//�������֮�� 
	printf("\n");
	print(sub(a,b));//�������֮�� 
	printf("\n");
	print(multi(a,c));//�������֮�� 
	printf("\n");
	return 0;
}
