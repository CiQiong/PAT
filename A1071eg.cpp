#include<iostream>
#include<string>
#include<map>
using namespace std;
bool check(char c){//����ַ�c�Ƿ��ǹ涨�ַ� 
	if(c>='0'&&c<='9')return true;
	if(c>='A'&&c<='z')return true;
	if(c>='a'&&c<='z')return true;
	return false;
} 
int main(){
	map<string,int> count;//count�����ַ������ֵĴ���
	string str;
	getline(cin,str);//��ȥ�����ַ��� 
	int i=0;//�����±� 
	while(i<str.length()){//���������ַ��� 
		string word;
		while(i<str.length()&&check(str[i])==true){//����ǵ����ַ��Ļ� 
			if(str[i]>='A'&&str[i]<='Z'){//����Ǵ�д��ĸ 
				str[i]+=32;//ת��ΪСд��ĸ 
			}
			word+=str[i];//����ĩβ��������ַ� 
			i++; //�±����һλ 
		}
		if(word!=""){//������ʷǿգ��������1 
			if(count.find(word)==count.end())count[word]=1;//��ǰû���ֹ�������ʣ�������Ϊ1 
			else count[word]++; //��ǰ���ֹ�������ʣ�������1 
		}
		while(i<str.length()&&check(str[i])==false){//���iλ���ǵ����ַ� 
			i++;//������һλ 
		} 
	} 
	string ans;//�𰸣����ִ������ĵ���
	int max=0;//���ִ������ĵ��ʳ��ֵĴ��� 
	for(map<string,int>::iterator it=count.begin();it!=count.end();it++) {
		if(it->second>max){//Ѱ�ҳ��ִ������ĵ���
			max=it->second;
			ans=it->first;
		}
	}
	cout<<ans<<" "<<max<<endl;
	return 0; 
}
