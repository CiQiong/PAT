#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int n,boylow=200,girlhigh=-1,temp;
	string boyname,boyid,girlname,girlid,name,tempid;
	char sex;
	cin>>n;
	while(n--){
		cin>>name>>sex>>tempid>>temp;
		if(sex=='M'&& temp<boylow){
			boyname=name;
			boylow=temp;
			boyid=tempid;
		} else if(sex=='F'&&temp>girlhigh) {
			girlname=name;
			girlhigh=temp;
			girlid=tempid;
		}
	}
	if(boylow!=200&&girlhigh!=-1){
		cout<<girlname+" "<<girlid<<endl;
		cout<<boyname+" "<<boyid<<endl;
		cout<<girlhigh-boylow;
	}else if(boylow==200&&girlhigh!=-1){
		cout<<girlname+" "<<girlid<<endl;
		cout<<"Absent"<<endl;
		cout<<"NA";
	}else if(boylow!=200&&girlhigh==-1){
		cout<<"Absent"<<endl;
		cout<<boyname+" "<<boyid<<endl;
		cout<<"NA";
	}else if(boylow==200&&girlhigh==-1){
		cout<<"Absent"<<endl;
		cout<<"Absent"<<endl;
		cout<<"NA";
	}
	return 0;
}
