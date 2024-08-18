#include<iostream>
using namespace std;

int n;
int arr[10][10];
int rowDir[2]={0,1};
int colDir[2]={1,0};
int visited[10][10];
int vs[10][10];

void backtrack(int index,int &count){

	if(index==56){	
		count+=1;
		return;
	}
	int i=index / 8;
	int j=index % 8;
	if(vs[i][j]==1){
		backtrack(index+1,count);
	}else{
		vs[i][j]=1;
		for(int k=0; k<2; k++){
			int x=i+rowDir[k];
			int y=j+colDir[k];
			if(x>=0 && x<7 && y>=0 && y<8 && visited[arr[i][j]][arr[x][y]]==0 && vs[x][y]==0){
				visited[arr[i][j]][arr[x][y]]=1;
				visited[arr[x][y]][arr[i][j]]=1;
				vs[x][y]=1;
				backtrack(index+1,count);
				visited[arr[i][j]][arr[x][y]]=0;
				visited[arr[x][y]][arr[i][j]]=0;
				vs[x][y]=0;
			}
		}
		vs[i][j]=0;
	}
	
	
	
}

int main(){
	freopen("Text.txt","r",stdin);
	int q;cin>>q;
	for(int t=0;t<q; t++){

		for(int i=0; i<10; i++){
			for(int j=0; j<10; j++) visited[i][j]=0,vs[i][j]=0;
		}
		
		for(int i=0; i<7; i++){
			for(int j=0; j<8; j++){
				cin>>arr[i][j];
			}
		}
		
		int count=0;
		backtrack(0,count);
		cout<<"Case "<<"#"<<t+1<<endl;
		cout<<count<<endl;
	}
	return 0;
}