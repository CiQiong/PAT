#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<string>
using namespace std;
map<string,set<int> > mpTitle,mpAuthor,mpKey,mpPub,mpYear;
//在map中查找str(不用引用的话可能会超时，字符串/map传递的速度慢) 
void query(map<string,set<int> >& mp,string& str){
	if(mp.find(str)==mp.end())printf("Not Found\n");//找不到
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
		char c=getchar();//接收掉id后面的换行
		getline(cin,title);//读入书名
		mpTitle[title].insert(id);//把id加入title对应的集合中
		getline(cin,author);
		mpAuthor[author].insert(id);
		while(cin>>key){//每次读入单个关键词key 
			mpKey[key].insert(id);//把id加入key对应的集合中 
			c=getchar();//接受关键词key之后的字符(空格或换行符)
			if(c=='\n')break;//如果是换行符，说明关键词输入完毕 
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
