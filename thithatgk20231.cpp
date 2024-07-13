#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
     char type[20];
     char name[20];
	 int cost; 
}pro;

typedef struct{
	int id;
	char date[30];
	char idbuyer[20];
	char name1[20];
	char idpro[20];
	char type[20];
	int money;
	int ispay; 
}buyer;

int getprobytype(pro* sp, int N, char*type){
	for(int i=0 ; i<N ; i++){
		if(strcmp(sp[i].type, type)==0){
			return sp[i].cost; 
		} 
	}
}

int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	
	pro sp[N];
	for(int i=0 ; i<N ; i++){
		scanf("%s %s %d",sp[i].type,sp[i].name, &sp[i].cost);
	}
	
	buyer Buyer[M];
	for(int i=0 ; i<M ; i++){
		scanf("%d",&Buyer[i].id);
		scanf("%s",Buyer[i].date);
		scanf("%s",Buyer[i].idbuyer);
		scanf("%s",Buyer[i].name1);
		scanf("%s",Buyer[i].idpro);
		scanf("%s",Buyer[i].type);
		scanf("%d %d",&Buyer[i].money,&Buyer[i].ispay); 
	}
	
	char cmd[256];
	scanf("%s", cmd);
	
	if(strcmp(cmd,"0")==0){
		int max = Buyer[0].money;
		int index;
		for(int i=1 ; i<M ; i++){
			if(Buyer[i].money >= max){
				index = Buyer[i].id; 
			} 
		}
		printf("%s", Buyer[index].name1); 
	} 
	
	if(strcmp(cmd,"1")==0){
		int idx;
		int cnt=0;
		int max = -1; 
		for(int i=0 ; i<M ; i++){
			int count=0; 
			if(Buyer[i].ispay == 1){
				count = Buyer[i].money / getprobytype(sp,M,Buyer[i].type);
				for(int j=i+1 ; j<M ; j++){
					if(Buyer[j].ispay==1 && strcmp(Buyer[j].name1,Buyer[i].name1)==0){
						count +=  Buyer[i].money / getprobytype(sp,M,Buyer[i].type);
					} 
				} 
			}
			if(count > max){
				max = count;
				idx = i;
				cnt = 0; 
			} else if(count == max){
				cnt++; 
			}
			if(cnt ==0){
				printf("%s", Buyer[idx].name1); 
			}else{
				printf("%d", cnt+1); 
			} 
		} 
		
	} 
	return 0; 
} 
