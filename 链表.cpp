#include<cstdio>
#include<stdlib.h>
struct node{//链表节点 
	int data;
	node* next;
};
//创建链表
node* create(int Array[]){
	node *p,*pre,*head;
	head=new node;
	head->next=NULL;
	pre=head;
	for(int i=0;i<5;i++){
		p=new node;
		p->data=Array[i];
		pre->next=p;
		pre=p;
	}
	return head;
} 
//以head为头节点的链表上计数元素x的个数
int search(node* head,int x){
	int count=0;
	node* p=head->next;
	while(p!=NULL){
		if(p->data==x){
			count++;
		}
		p=p->next;
	}
	return count;
} 
//将x插入以head为头节点的链表的第pos个位置上
void insert(node* head,int pos,int x){
	node* p=head;
	for(int i=0;i<pos-1;i++){
		p=p->next;
	}
	node* q=new node;
	q->data=x;
	q->next=p->next;
	p->next=q;
} 
//删除以head为头节点的链表中所有数据域为x的节点
void del(node* head,int x){
	node* p=head->next;
	node* pre=head;
	while(p!=NULL){
		if(p->data==x){
			pre->next=p->next;
			delete(p);
			p=pre->next;
		}else{
			pre=p;
			p=p->next;
		}
	}
} 
int main(){
	int Array[5]={5,3,6,1,2};
	node* L=create(Array);
	L=L->next;
	while(L!=NULL){
		printf("%d",L->data);
		L=L->next;
	}
	return 0;
}
