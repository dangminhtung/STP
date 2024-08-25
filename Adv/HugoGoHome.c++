#include<iostream>
using namespace std;
int n;
int gate[100][10];
int soilder[100];
int min_fee;


void backtrack(int index, int fee, int soilder1, int soilder2, int soilder3){
	if(index==n){
		min_fee=min(min_fee,fee);
		return;
	}
	if(fee>=min_fee){
		return;
	}
	for(int i=0; i<3;i++){
		if(i==0){
			backtrack(index+1,fee+gate[index][1],soilder1,soilder2,soilder3);
		}else if(i==1){
			//soilder[2]+=gate[index][0];
			backtrack(index+1,fee+(gate[index][1]*2),soilder1,soilder2,soilder3+gate[index][0]);
		}else {
			int sum=soilder1+soilder2+soilder3;
			if(sum>=gate[index][0]){
				if(soilder1>=gate[index][0]){
					soilder1-=gate[index][0];
				}else if(soilder2+soilder1>=gate[index][0]){
					soilder2=soilder2+soilder1 -gate[index][0];
					soilder1=0;
				}else{
					soilder3=soilder1+soilder2+soilder3-gate[index][0];
					soilder1=0;
					soilder2=0;
				}
				backtrack(index+1,fee,soilder2,soilder3,0);
			}
			
		}
	}
}
int main(){
	freopen("Text.txt","r",stdin);
	int T;cin>>T;
	for(int t=0;t<T; t++){
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>gate[i][0];
			cin>>gate[i][1];
			gate[i][2]=0;
		}
		min_fee=500000;
		backtrack(0,0,0,0,0);
		cout<<"#"<<t+1<<" "<<min_fee<<endl;
	}
	return 0;
}
// so linh so , tien phai tra 
20
7
10 100
70 5
80 15
20 60
50 90
30 80
10 10
9
600 800
300 400
300 400
1000 400
300 600
100 300
600 300
600 500
1000 300
11
1000 10
700 900
400 500
300 10
900 900
300 10
50 900
50 900
700 900
500 900
50 10