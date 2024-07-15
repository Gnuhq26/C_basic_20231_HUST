#include <bits/stdc++.h>
using namespace std;
int X[100],n, a[100], cnt = 0, k, daxet[100]; 
int sum = 0; 
void in(){
	for(int i=1 ; i<=n ; i++){
		cout<<X[i]; 
	} 
} 
/*Sinh nhi phan*/ 
//void Try(int i){
//	++cnt; 
//	//gan cac gia tri co the cho bit thu i 
//	for(int j = 0; j<=1 ; j++){
//		X[i] = j;
//		if( i == n){
//			in(); 
//			cout<<endl; 
//		}
//		else Try(i+1); 
//	} 
//	cout<< cnt <<endl; 
//}
/*To hop chap k cua n*/ 
//void Try(int i){
//	//gan cac gia tri co the cho bit thu i 
//	for(int j = X[i-1] +1 ; j<= n-k+i ; j++){
//		X[i] = j;
//		if(i==k){
//			in(); cout<<endl; 
//		} 
//		else Try(i+1); 
//	} 
//} 

/*Sinh hoan vi*/
//daxet[i] = true : gia tri cua i da dc dung
//daxet[i] = false : gia tri cua i chua dc dung 

//void Try(int i){
//    //gan cac gia tri co the cho bit thu i 
//	for(int j = 1 ; j<=n ; j++){
//		//ktra xem có the gán giá tri j cho X[i] du?c hay khong 
//		if(daxet[j] == 0){
//			X[i] = j;
//			daxet[j] = 1;
//			if(i==n){
//				in();
//				cout<<endl; 
//			}
//			else Try(i+1); 
//			daxet[j] = 0;//Bo ghi nhan 
//		} 
//		
//	}	
//} 

/*Baitap*/

void Try(int i, int pos){
	for(int j = pos ; j<=n ;j++){
		X[i] = a[j];
		sum += a[j];
		if(sum == k){
			for(int l=1; l<=i ; l++){
				cout<<X[l]<<" "; 
			}
			cout<<endl; 
		}
		else Try(i+1, j+1); 
		sum -= a[j]; 
	} 
} 
int main(){
	int t;
	cin>>t;
//	while(t--){
//		cin>>n>>k;
//		for(int i=1 ; i<=n ;i++) cin>>a[i];
//		memset(daxet, 0, sizeof(daxet)); 
//		cout<<endl;
//		Try(1,1); 
//	}
    Try(1);
	return 0;  
} 

