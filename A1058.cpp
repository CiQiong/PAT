#include<cstdio>
int main(){
	int a[3],b[3],c[3];
	scanf("%d.%d.%d %d.%d.%d",&a[0],&a[1],&a[2],&b[0],&b[1],&b[2]);
	c[0]=a[0]+b[0];
	c[1]=a[1]+b[1];
	c[2]=a[2]+b[2];
	if(c[2]>=29){
		c[2]=c[2]-29;
		c[1]++;
	}
	if(c[1]>=17){
		c[1]=c[1]-17;
		c[0]++;
	}
	printf("%d.%d.%d",c[0],c[1],c[2]);
	return 0;
}
