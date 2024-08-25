#include<iostream>
using namespace std;

int n,num;
int arr[12][12];
int vitri[12][2];

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int min_c,max_c;
int len;
void backtrack(int index, int c,int core){
	if(index==num+1){
		if(core>max_c){
			max_c=core;
			min_c=c;
		}
		 else if(core==max_c){
			min_c=min_c > c ? c:min_c;
		}
		return;
	}
	for(int j=0; j<4; j++){
		int x=vitri[index][0]+dx[j];
		int y=vitri[index][1]+dy[j];
		int check=1;
		int count=0;
		while(x>=0 && x<n && y>=0 && y<n){
			if(arr[x][y]==1){
				check=0;
				break;
			}
			count++;
			arr[x][y]=1;
			x=x+dx[j];
			y=y+dy[j];
		}
		if(check){
			backtrack(index+1,c+count,core+1);}
			int x2=x-dx[j];
			int y2=y-dy[j];
			while(x2!= vitri[index][0] || y2 !=vitri[index][1]) {
				arr[x2][y2]=0;
				x2=x2-dx[j];
				y2=y2-dy[j];
			}
		
	}
	backtrack(index+1,c,core);
}
	

int main(){
	freopen("Text.txt","r",stdin);
	int T;cin>>T;
	for(int t=0;t<T; t++){
		num=-1;
		max_c=0;
		min_c=5000;
		len=0;
		cin>>n;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin>>arr[i][j];
				if(arr[i][j]==0) 
				if(i==0 || i==n-1 || j==0 ||j==n-1){
					continue;
				}
				if(arr[i][j]==1){
					num++;
					vitri[num][0]=i;
					vitri[num][1]=j;
				}
			}
		}
		backtrack(0,0,0);
		cout<<"#"<<t+1<<" "<<min_c<<endl;

	}
	return 0;
}
0 0 1 0 0 0 0
0 0 1 0 0 0 0
0 0 0 0 0 1 0
0 0 0 0 0 0 0
1 1 0 1 0 0 0
0 1 0 0 0 0 0
0 0 0 0 0 0 0
9
0 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0
0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0
0 0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0 1
11
0 0 1 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 1
0 0 0 1 0 0 0 0 1 0 0
0 1 0 1 1 0 0 0 1 0 0
0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 1 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0