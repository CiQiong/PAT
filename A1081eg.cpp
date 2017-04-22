#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){//�������������Լ�� 
	return b==0?a:gcd(b,a%b);
} 
struct Fraction{
	ll up,down;
}; 
Fraction reduction(Fraction result){//����һ������ 
	if(result.down<0){
		result.down=-result.down;
		result.up=-result.up;
	}
	if(result.up==0){
		result.down=1;
	}else{
		int d=gcd(abs(result.up),result.down);
		result.up/=d;
		result.down/=d;
	}
	return result;
}
Fraction add(Fraction a,Fraction b){//����������� 
	Fraction result;
	result.up=a.up*b.down+a.down*b.up;
	result.down=a.down*b.down;
	return reduction(result);
}
void showResult(Fraction r){//������� 
	reduction(r);
	if(r.down==1)printf("%lld\n",r.up);
	else if(abs(r.up)>r.down){
		printf("%lld %lld/%lld\n",r.up/r.down,abs(r.up%r.down),r.down);
	}else{
		printf("%lld/%lld\n",r.up,r.down);
	}
} 
int main(){
	int n;
	scanf("%d",&n);
	Fraction sum,temp;
	sum.up=0;
	sum.down=1;
	while(n--){
		scanf("%lld/%lld",&temp.up,&temp.down);
		sum=add(sum,temp);
	}
	showResult(sum);
	return 0;
}
