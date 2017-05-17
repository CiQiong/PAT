//A1014
#include<cstdio>
#include<queue>
#include<algorithm>//min(,)
using namespace std;
const int maxNode=1111;
int n,m,k,query,q;
int convertToMinute(int h,int m){
	return h*60+m;//��ʱ�䵥λת��Ϊmin�������¼����� 
}
struct Window{
	int endTime,popTime;
	queue<int> q; 
}window[20];
int ans[maxNode],needTime[maxNode];//�������ʱ��ͷ�����Ҫʱ��
int main(){
	int inIndex=0;//��ǰ��һ��δ��ӵĿͻ����
	scanf("%d%d%d%d",&n,&m,&k,&query);
	for(int i=0;i<k;i++){
		scanf("%d",&needTime[i]);//���������Ҫʱ�� 
	}
	for(int i=0;i<n;i++){
		window[i].popTime=window[i].endTime=convertToMinute(8,0);
	}
	for(int i=0;i<min(n*m,k);i++){
		//ѭ�����
		window[inIndex%n].q.push(inIndex);
		//���´��ڵķ������ʱ��endTime
		window[inIndex%n].endTime+=needTime[inIndex];
		//�Դ��ڵ�һ���û�������popTime
		if(inIndex<n) window[inIndex].popTime=needTime[inIndex];
		//��ǰ��ӵĿͻ�����ʱ��ֱ�ӱ�����Ϊ�𰸣��������޸ģ�
		ans[inIndex]=window[inIndex%n].endTime;
		inIndex++; 
	}
	for(;inIndex<k;inIndex++){//����ʣ��ͻ������ 
		int idx=-1,minPopTime=1<<30;//Ѱ�����д��ڵ���СpopTime
		for(int i=0;i<n;i++){
			if(window[i].popTime<minPopTime){
				idx=i;
				minPopTime=window[i].popTime;
			}
		} 
		//�ҵ���С��popTime�Ĵ��ڱ��Ϊidx��������¸ô��ڵĶ������
		//���ã���������W����window[idx]�����ĸ�����
		Window& W=window[idx];
		W.q.pop();//���׿ͻ��뿪
		W.q.push(inIndex);//�ͻ�inIndex���
		W.endTime+=needTime[inIndex];//���¸ô��ڶ��е�endTime
		W.popTime+=needTime[W.q.front()];//���¸ô��ڵ�popTime
		//�ͻ�inIndex�ķ������ʱ��Ϊ�ô��ڵ�endTime
		ans[inIndex]=W.endTime; 
	}
	for(int i=0;i<query;i++){
		scanf("%d",&q);
		if(ans[q-1]=needTime[q-1]>=convertToMinute(17,0)){
			printf("Sorry\n");//����ʼʱ��ﵽ17:00�����Sorry 
		} else {
			printf("%02d:%02d\n",ans[q-1]/60,ans[q-1]%60);
		}
	}
	return 0;
} 
