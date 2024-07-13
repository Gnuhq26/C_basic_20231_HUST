#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node{
int id ;
struct Node* next ;	
}Node;

Node* makeNode(int id){
	Node* new_Node =(Node*)malloc(sizeof(Node));
	new_Node->id = id ; 
	new_Node->next = NULL;
	return new_Node;
}

Node* insertLast(Node* h, int i){
	Node* p = h ;
	if(h == NULL) return makeNode(i);
	while(p->next != NULL){
		p = p->next;
	}
	Node* q = makeNode(i);
	p->next = q;
	return h;
}

Node* removeFirst(Node* h,int v){
	Node* p = h ; 
	if(h == NULL) return NULL;
	while(p->next != NULL){
		if(p->next->id = v) break;
		p=p->next;
	}
	if(p->next != NULL){
		Node *q = p->next;
		p->next = q ;
	}
	return h;
}
int cnt ;
int countNode(Node *p){
	if(p == NULL) return 0;
	Node *h = p ;
	while(h->next != NULL){
		cnt++;
		h = h->next;
	}
	return cnt+1;
}

int main(){
	Node* b ;
	insertLast(b,10);
	insertLast(b,11);
	printf("%d ",b->id);
}
