#include<cstdio>
#include<map>
using namespace std;
int main(){
	map<char,int> mp;
	mp['x']=1;
	mp['z']=6;
	mp['a']=3;
	mp.erase('x');//ɾ��һ��Ԫ�� 
	for(map<char,int>::iterator it=mp.begin();it!=mp.end();it++){
		printf("%c %d\n",it->first,it->second);
	}
	return 0;
} 
