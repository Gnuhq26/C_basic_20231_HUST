#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
typedef struct pp {
	int camxuc;
	int thaido;
	int thoigian[1000];
}pp;
pp nguoi[1000];
int thoigianxe[1000];
int a[1000];
int b[1000];
int n,m;
int res[1000];
void ham1(){
	int dem = 0;
	for(int i=0;i<n;i++){
		if(nguoi[i].camxuc==-1&&nguoi[i].thaido==-1)dem+=res[i];
	}
    printf("%d",dem);
}
void ham2(){
	int dem = 0;
	for(int i=0;i<n;i++){
		if((nguoi[i].camxuc==2&&nguoi[i].thaido==-1)||(nguoi[i].camxuc==-1&&nguoi[i].thaido==0))dem+=res[i];
	}
	printf("%d",dem);
}
void ham3(){
	int dem = 0;
	for(int i=0;i<n;i++){
	if(nguoi[i].camxuc==-1&&nguoi[i].thaido==1)dem+=res[i];
	if(nguoi[i].camxuc==1&&nguoi[i].thaido==-1)dem+=res[i];
	if(nguoi[i].camxuc==0&&nguoi[i].thaido==0)dem+=res[i];
	}
	printf("%d",dem);
}
void ham4(){
	int dem = 0;
	for(int i=0;i<n;i++){
		if(nguoi[i].camxuc==0&&nguoi[i].thaido==1)dem+=res[i];
		if(nguoi[i].camxuc==1&&nguoi[i].thaido==0)dem+=res[i];
		if(nguoi[i].camxuc==2&&nguoi[i].thaido==-1)dem+=res[i];
	}
	printf("%d",dem);
}
void ham5(){
	int dem = 0;
	for(int i=0;i<n;i++){
		if((nguoi[i].camxuc==1&&nguoi[i].thaido==1)||(nguoi[i].camxuc==2&&nguoi[i].thaido==0))dem+=res[i];
	}
	printf("%d",dem);
}
void ham6(){
	int dem = 0;
	for(int i=0;i<n;i++){
		if(nguoi[i].camxuc==2&&nguoi[i].thaido==1)dem+=res[i];
	}
	printf("%d",dem);
}
void ham7(){
	int dem = 0;
	for(int i=0;i<n;i++){
		if((nguoi[i].camxuc==1&&nguoi[i].thaido==1)||(nguoi[i].camxuc==2&&nguoi[i].thaido==1))dem+=res[i];
	}
	printf("%d ",dem);
}
void ham8(){
	int dem = 0;
	for(int i=0;i<n;i++){
		if(nguoi[i].thaido==-1)dem+=res[i];
	}
	printf("%d",dem);
}
int main(){	
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d%d",&nguoi[i].camxuc,&nguoi[i].thaido);
	}
	for(int i=1;i<m+1;i++){
		scanf("%d",&thoigianxe[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m+1;j++){
			scanf("%d",&nguoi[i].thoigian[j]);
		}
	}   
		for(int i=0;i<n;i++){
		int dem=0;
		int stn=0,stx=0,endn=0,endx=0;
		for(int j=1;j<m+1;j++){
		    endn=nguoi[i].thoigian[j]+stn;
		    endx=thoigianxe[j]+stx;
		    int p = fmin(endn,endx)-fmax(stn,stx);
		    if(p>0)dem+=p;
		    stn+=nguoi[i].thoigian[j];
		    stx+=thoigianxe[j];
		    res[i]=dem;
		}	
}

    // for(int i = 0 ; i < n; i++){
    //     printf("%d ", res[i]);
    // }
   	int k;scanf("%d",&k);
    if(k==-2)ham1();
    if(k==-1)ham2();
	if(k==0)ham3();
	if(k==1)ham4();
	if(k==2)ham5();
	if(k==3)ham6();
	if(k==4)ham7();
	if(k==5)ham8();
	if(k==6)printf(">1");
		
}
