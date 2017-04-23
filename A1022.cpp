#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<string>
using namespace std;
map<string,set<int> > mpTitle,mpAuthor,mpKey,mpPub,mpYear;
//��map�в���str(�������õĻ����ܻᳬʱ���ַ���/map���ݵ��ٶ���) 
void query(map<string,set<int> >& mp,string& str){
	if(mp.find(str)==mp.end())printf("Not Found\n");//�Ҳ���
	else{
		for(set<int>::iterator it=mp[str].begin();it!=mp[str].end();it++){
			printf("%07d\n",*it);
		}
	} 
}
int main(){
	int n,m,id,type;
	string title,author,key,pub,year;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&id);//id
		char c=getchar();//���յ�id����Ļ���
		getline(cin,title);//��������
		mpTitle[title].insert(id);//��id����title��Ӧ�ļ�����
		getline(cin,author);
		mpAuthor[author].insert(id);
		while(cin>>key){//ÿ�ζ��뵥���ؼ���key 
			mpKey[key].insert(id);//��id����key��Ӧ�ļ����� 
			c=getchar();//���ܹؼ���key֮����ַ�(�ո���з�)
			if(c=='\n')break;//����ǻ��з���˵���ؼ���������� 
		} 
		getline(cin,pub);
		mpPub[pub].insert(id);
		getline(cin,year);
		mpYear[year].insert(id); 
	}
	string temp;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d: ",&type);
		getline(cin,temp);
		cout<<type<<": "<<temp<<endl;
		if(type==1)query(mpTitle,temp);
		else if(type==2)query(mpAuthor,temp);
		else if(type==3)query(mpKey,temp);
		else if(type==4)query(mpPub,temp);
		else query(mpYear,temp);
	}
	return 0;
} 
