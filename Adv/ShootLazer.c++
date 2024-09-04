#include<iostream>
using namespace std;

int n,m;
int arr[25][25];
int test;
int max_p;
void check_row(){
	for(int i=0; i<n-1; i++){
		
		for(int x=i+1; x<n; x++){
			int c=1;
			for(int y=0; y<n; y++){
				if(arr[i][y] != arr[x][y]){
					c=0;
					break;
				}
			}
			if(c){
				arr[x][n]=-1;
				arr[i][n]+=1;
			}
		}
	}
}

void solution(){
	int dem=0;
	for(int i=0; i<n; i++){
		dem=0;
		if(arr[i][n]>0){
			for(int j=0; j<n;j++){
				if(arr[i][j]==0) dem++;
			}
			if(dem<=m && dem%2==0 && m%2==0){
				max_p=max(arr[i][n],max_p);
			}else if(dem<=m && dem%2==1 && m%2==1){
				max_p=max(arr[i][n],max_p);
			}
		}
		
	}
}

int main(){
	freopen("Text.txt","r",stdin);
	cin>>test;
	for(int t=0; t<test; t++){
		cin>>n>>m;
		for(int i=0; i<n; i++){
			arr[i][n]=1;
			for(int j=0; j<n; j++){
				cin>>arr[i][j];
			}
		}
		check_row();
		max_p=-1;
		solution();
		cout<<"#"<<t+1<<" "<<max_p<<endl;
	}
	return 0;
}
50
5 10
1 0 1 1 1 
0 1 1 1 1 
1 1 1 1 0 
0 1 1 1 0 
1 1 1 1 1 

5 4
1 0 0 0 1 
0 1 0 0 0 
0 1 1 1 0 
1 0 0 1 1 
0 0 0 1 1 

5 7
1 1 1 0 0 
0 0 1 1 0 
0 0 0 1 0 
1 0 0 1 1 
1 0 1 0 0 

5 13
1 0 0 0 0 
1 0 0 0 0 
1 0 1 1 1 
0 1 0 1 1 
1 0 0 0 0  

5 9
1 0 0 1 0 
1 1 0 1 1 
0 0 0 1 0 
1 0 1 0 1 
1 1 1 1 1 

10 77
1 1 1 1 0 1 1 1 0 1 
1 1 1 1 1 1 0 1 0 0 
1 1 1 0 0 1 0 0 0 1 
0 1 1 0 0 0 1 1 0 1 
0 0 1 0 0 0 1 0 0 0 
1 0 1 0 0 0 0 0 0 1 
0 0 1 0 0 1 1 1 0 1 
0 1 1 0 0 0 1 1 0 1  
1 0 1 1 0 0 0 1 0 0 
0 1 1 0 0 0 1 1 0 1  

10 45
0 1 0 0 1 1 1 1 1 1 
0 0 0 0 1 1 1 1 0 0 
1 1 1 0 0 1 1 1 1 0 
1 0 1 0 1 1 0 0 1 1 
1 1 0 1 1 0 1 0 0 0 
1 1 1 1 0 0 0 1 0 1 
0 0 0 0 0 0 1 1 0 0 
0 0 0 1 0 0 0 1 1 0 
0 0 1 0 0 1 1 1 0 1 
1 0 1 1 0 0 0 1 0 0 

10 31
1 1 0 1 1 1 0 0 1 1 
1 1 0 1 1 1 0 0 1 1 
1 1 0 0 0 1 0 0 1 1 
0 0 1 0 0 0 0 1 0 1 
0 0 0 0 1 0 1 1 1 1 
1 1 1 1 0 1 1 1 0 0 
1 1 0 1 1 1 0 0 1 1
1 0 1 1 1 0 1 0 0 1 
1 1 0 1 1 1 0 0 1 1
0 1 1 1 0 0 0 1 0 0

20 45
1 1 1 1 0 0 0 1 0 0 1 0 0 0 1 1 0 0 1 1 
1 1 0 0 0 0 0 0 0 1 0 0 0 0 0 1 1 0 1 1 
0 0 0 1 0 0 1 0 0 0 1 1 1 0 0 1 1 0 1 0 
0 0 0 0 1 0 1 0 0 0 1 0 0 0 1 0 0 1 1 0 
0 1 0 1 1 0 1 1 1 1 0 1 1 0 0 1 0 1 0 1 
1 1 0 0 0 0 0 0 0 1 0 0 0 0 0 1 1 0 1 1  
0 0 0 1 0 1 1 0 1 0 0 1 1 1 1 1 0 0 1 1 
0 1 1 0 0 1 1 0 1 1 0 0 1 0 1 0 0 0 0 0 
1 1 0 0 0 0 0 1 0 0 0 0 1 1 0 1 0 1 0 1 
1 0 1 1 0 0 1 1 0 1 1 0 0 1 1 1 0 1 1 1 
0 1 0 1 0 1 1 0 1 0 0 1 0 0 1 0 1 0 1 0 
1 1 0 0 0 0 0 0 0 1 0 0 0 0 0 1 1 0 1 1  
0 1 0 1 0 0 0 1 0 0 0 1 0 1 0 0 0 0 0 1 
1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 0 0 0 1 1 
0 1 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 
0 1 0 1 0 1 0 0 1 0 0 1 0 1 0 0 1 0 0 0 
0 1 0 1 0 1 1 1 1 1 1 0 1 1 0 1 1 1 1 0 
1 1 0 0 0 0 0 0 0 1 0 0 0 0 0 1 1 0 1 1  
1 0 0 0 1 0 1 0 0 1 1 1 1 0 0 0 0 0 1 1 
0 1 0 0 0 1 1 1 1 1 0 1 1 0 1 1 0 0 0 1 

20 199
1 1 1 1 1 1 0 0 1 1 1 0 0 1 0 0 1 1 0 1 
1 1 0 0 1 0 1 1 1 0 1 0 1 1 1 1 1 0 1 0 
0 0 1 1 1 0 0 1 0 1 1 0 1 0 0 0 0 1 1 1 
1 1 0 1 1 1 0 0 1 0 0 1 1 0 1 1 1 0 1 1 
1 0 1 1 0 0 0 0 1 0 1 1 0 0 0 0 0 0 1 1 
0 1 1 0 0 1 0 0 0 1 0 1 1 1 1 0 0 0 1 0 
0 0 1 0 0 1 0 1 0 0 1 0 1 1 1 0 1 1 0 1 
0 1 1 0 0 0 1 1 1 0 0 1 0 0 0 0 0 0 0 1 
1 1 1 1 1 1 0 1 1 1 1 1 1 0 1 1 0 1 0 0 
1 0 0 1 0 1 1 0 1 1 0 0 1 1 0 0 0 1 1 1 
0 1 1 1 0 1 0 1 1 1 1 0 0 1 0 1 0 0 0 1 
1 0 1 1 0 0 1 0 0 1 1 1 1 1 1 0 1 0 0 0 
0 1 0 0 1 0 0 1 1 1 0 1 0 0 1 0 0 0 1 1 
1 1 0 0 0 0 1 1 0 0 0 0 0 1 1 0 0 1 1 1 
0 1 0 0 1 1 1 0 0 1 1 0 0 1 1 0 1 0 1 0 
1 0 0 1 1 0 1 0 1 0 1 0 1 0 0 1 1 1 1 1 
1 0 1 0 1 0 0 0 1 0 0 0 1 1 0 1 0 1 1 1 
1 1 0 1 0 1 1 1 0 0 1 1 1 1 0 1 0 0 1 1 
1 0 1 0 1 1 1 0 1 0 1 1 0 0 0 1 0 1 0 1 
1 0 0 1 0 0 0 1 1 1 1 1 1 1 1 1 0 1 0 1  

6 48
0 0 1 1 1 0 
0 0 0 0 0 0 
1 0 1 0 0 0 
0 1 0 0 0 0 
1 0 1 1 1 1 
1 1 1 0 1 1 
8 21
1 0 0 1 1 0 0 1 
0 0 1 1 0 0 1 0 
1 0 0 1 1 1 0 1 
1 0 1 0 0 1 1 0 
0 0 0 0 0 0 1 1 
0 0 1 1 0 1 0 0 
0 1 0 1 1 1 0 1 
1 0 1 0 1 1 0 1 
13 49
1 1 1 1 1 0 1 0 0 1 0 0 1 
1 0 0 0 0 1 1 0 1 0 1 1 0 
1 0 0 0 0 1 0 0 1 0 0 1 0 
0 0 1 1 1 0 0 0 1 1 0 1 0 
0 0 0 1 0 0 1 1 0 1 0 1 1 
0 1 1 0 1 0 0 1 0 0 0 1 1 
1 0 1 0 1 0 0 1 1 1 1 1 0 
1 0 0 0 1 1 1 1 1 1 0 1 1 
1 1 0 0 0 0 0 0 1 0 1 0 0 
0 0 0 0 0 0 0 0 0 0 1 1 1 
1 1 1 1 1 0 1 1 0 1 1 0 0 
1 0 1 0 1 0 0 1 0 0 1 1 0 
0 0 0 0 0 0 0 0 1 0 1 1 0 
14 39
0 0 1 1 0 1 1 1 1 1 0 1 1 0 
1 1 0 1 0 1 0 0 1 0 1 1 1 0 
1 1 1 0 0 1 0 0 0 1 0 0 1 1 
1 1 1 0 0 1 0 0 0 1 1 0 1 0 
0 0 1 1 0 0 1 1 1 0 0 0 1 0 
1 1 0 0 1 0 1 1 1 0 0 1 1 0 
0 1 1 1 0 1 1 0 0 0 0 0 0 0 
0 1 1 0 1 1 0 1 1 1 1 0 1 0 
1 1 1 0 1 1 1 0 0 1 1 1 0 1 
1 1 0 0 0 1 0 1 0 1 0 1 1 0 
0 1 0 1 1 0 0 0 0 1 0 1 0 0 
1 0 0 1 1 1 0 1 1 0 0 0 1 1 
0 1 0 0 0 1 0 1 1 1 0 1 0 1 
0 1 0 0 1 0 0 1 1 0 0 1 1 0 
12 49
0 1 0 1 1 0 1 0 0 1 0 1 
0 1 1 1 0 1 0 0 0 1 1 0 
0 0 0 0 1 1 0 1 1 1 0 1 
0 1 0 0 1 1 0 1 1 1 1 0 
1 0 1 0 0 1 1 1 0 0 1 1 
0 0 1 0 1 0 1 1 1 1 0 1 
0 1 0 1 1 0 0 0 1 1 1 0 
0 1 0 0 1 1 1 1 0 1 0 0 
1 1 0 1 1 1 0 1 0 0 0 1 
1 0 0 0 1 1 1 0 1 0 1 1 
0 1 0 0 1 0 1 1 0 1 0 1 
0 1 1 0 1 0 0 1 0 1 1 0 
12 20
1 0 1 0 1 0 1 0 1 1 1 0 
0 0 1 1 1 0 1 1 1 0 1 1 
1 0 0 1 0 1 1 0 1 1 1 1 
1 1 0 0 0 1 0 1 1 1 1 1 
0 0 1 1 0 1 0 0 0 0 0 1 
1 1 0 1 1 0 0 0 1 0 0 1 
1 0 0 0 1 0 0 1 1 1 0 0 
0 1 1 0 0 0 1 1 1 1 1 0 
1 1 1 0 1 0 0 0 1 1 0 1 
1 0 1 0 0 0 0 0 1 1 0 1 
0 1 1 1 1 1 0 1 1 1 0 0 
1 0 1 1 0 0 1 0 0 1 0 0 
18 17
0 1 0 1 0 1 1 0 0 0 0 0 1 1 0 1 1 0 
1 1 0 1 1 0 1 1 0 1 0 0 0 1 0 1 1 1 
1 1 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 0 
0 1 0 0 1 0 0 1 1 1 1 0 1 0 0 1 1 0 
1 0 1 1 0 0 0 0 0 0 1 1 0 1 1 0 0 1 
0 0 0 1 1 0 1 0 1 1 1 1 0 1 0 1 1 0 
0 0 0 1 0 0 1 0 1 0 1 0 1 1 1 0 1 0 
1 1 0 0 1 1 0 0 1 1 1 1 1 0 0 1 0 0 
1 1 1 1 1 1 0 0 0 1 0 0 0 0 0 0 0 1 
1 1 0 1 0 0 0 0 0 0 0 0 1 0 0 1 0 1 
1 1 0 0 1 1 1 1 1 1 1 1 0 1 0 0 1 1 
0 1 1 1 0 1 0 1 0 1 0 0 1 0 1 0 0 0 
0 1 0 1 0 1 0 1 0 1 0 0 0 0 0 0 0 1 
0 0 1 1 0 1 1 1 1 0 0 1 0 0 0 1 0 0 
1 0 1 0 0 0 1 0 0 0 1 1 1 0 0 1 0 0 
1 0 1 1 1 1 1 0 1 1 0 1 1 0 1 1 0 0 
1 0 1 1 1 1 1 0 0 1 0 0 0 1 1 0 0 1 
1 1 1 0 1 0 1 0 0 0 1 1 0 0 0 1 1 1 
15 43
1 1 0 1 0 1 0 1 0 1 1 0 0 0 1 
1 1 0 0 1 0 1 0 1 1 0 1 0 0 1 
0 0 0 1 1 1 0 0 1 1 1 0 0 0 0 
0 1 0 0 1 1 1 1 1 0 0 0 0 1 1 
0 1 0 1 0 1 0 0 0 1 1 0 0 0 0 
0 0 1 1 1 0 1 1 1 1 0 0 0 0 0 
1 0 0 0 1 1 0 1 1 1 0 0 0 0 1 
0 0 1 0 0 1 1 1 0 0 0 1 0 1 1 
0 0 0 1 0 1 0 0 0 0 1 1 0 1 1 
0 1 1 1 0 1 1 1 1 1 0 1 1 0 1 
1 1 0 1 1 1 1 1 1 1 0 0 0 1 0 
0 0 1 0 1 1 0 0 0 0 1 0 0 0 1 
0 1 0 0 0 1 0 1 1 1 0 1 0 0 0 
1 0 1 0 1 1 1 0 0 1 1 0 1 0 0 
1 1 0 1 0 1 1 1 1 0 0 1 1 1 1 
7 19
1 1 1 0 1 0 0 
1 1 1 0 1 0 0 
0 0 1 0 1 1 0 
1 1 0 0 1 0 1 
1 0 0 0 1 0 0 
0 0 1 0 0 0 1 
1 0 1 0 0 1 0 
6 40
0 0 1 1 1 1 
1 0 0 1 0 1 
0 1 1 1 1 0 
1 1 1 0 1 1 
0 0 0 1 1 1 
0 1 0 0 1 0 
10 47
0 0 1 0 0 1 1 1 0 1 
0 1 0 0 0 0 0 1 0 0 
1 1 0 0 1 1 0 1 1 1 
1 1 1 1 0 1 1 0 1 1 
1 1 0 1 0 0 1 0 1 1 
0 0 1 1 0 1 1 0 0 0 
1 0 0 0 0 1 1 0 0 0 
1 0 1 1 1 0 1 0 0 1 
0 1 0 0 0 0 0 0 0 1 
0 1 1 0 0 0 1 0 0 0 
13 24
0 0 1 0 1 0 0 1 1 0 0 0 0 
1 0 1 0 0 1 1 0 1 0 1 1 1 
1 1 1 0 1 0 0 1 0 0 1 0 1 
0 1 0 0 1 0 0 1 1 1 0 0 1 
1 0 0 0 1 1 0 1 1 1 0 0 1 
1 1 0 0 1 0 1 0 0 0 1 0 0 
1 1 0 0 1 0 1 1 0 0 1 1 0 
0 1 1 1 0 1 0 1 1 1 1 0 0 
0 1 0 0 0 1 0 0 0 0 1 1 1 
1 0 0 0 1 0 1 1 0 0 0 1 1 
0 0 0 0 1 1 1 1 0 0 1 1 1 
0 1 0 0 1 1 1 0 0 0 1 1 0 
0 1 0 0 0 1 1 1 1 1 0 0 0 
16 42
1 0 0 0 0 1 0 0 0 0 0 1 1 1 1 0 
0 0 0 0 0 1 1 0 0 1 0 0 0 0 0 1 
0 1 1 0 1 1 1 0 0 1 0 0 0 0 1 0 
1 0 1 1 0 1 0 1 1 1 1 1 1 0 0 0 
1 1 1 0 0 0 0 0 1 0 1 1 1 1 1 1 
0 1 1 1 1 1 0 1 0 0 0 0 0 1 0 0 
1 0 0 0 0 1 1 0 0 0 0 0 1 1 0 1 
1 0 1 1 0 0 0 0 0 0 0 1 0 0 1 1 
1 1 0 0 0 1 0 0 1 1 1 1 0 1 1 0 
1 0 0 0 1 0 0 1 0 1 0 1 1 0 1 1 
1 1 1 1 1 0 0 0 0 0 0 1 1 1 1 1 
0 0 0 0 1 1 1 0 1 1 1 1 1 1 0 1 
1 0 1 0 0 0 0 1 0 0 0 1 0 1 1 0 
0 0 0 0 1 1 0 0 0 0 1 0 0 1 1 1 
1 0 0 1 0 0 0 1 0 1 0 0 1 1 1 1 
1 1 1 0 0 1 1 0 0 1 0 1 0 0 1 1 
14 46
1 0 1 0 1 0 1 1 0 1 1 1 1 1 
1 1 0 0 0 0 1 0 0 0 1 1 1 0 
1 1 0 1 1 0 1 1 0 0 0 1 1 0 
0 0 0 1 1 0 1 1 0 1 0 1 1 1 
0 1 1 0 1 0 1 1 1 1 1 0 1 1 
1 1 0 1 1 1 0 1 0 0 1 0 1 0 
0 1 0 1 0 0 0 0 0 0 1 0 1 1 
0 1 1 1 1 1 0 1 1 1 1 1 0 1 
0 1 1 0 1 1 0 1 1 1 0 0 1 1 
1 1 0 0 1 0 1 0 0 1 1 0 0 1 
1 0 0 1 1 0 1 0 0 1 0 0 0 0 
0 1 1 1 0 0 0 1 0 0 1 0 0 1 
0 0 0 1 1 0 0 1 0 1 1 0 1 0 
0 1 1 1 1 1 1 1 1 0 1 1 1 1 
12 39
1 1 0 0 1 1 1 1 0 0 1 0 
1 0 0 1 1 1 1 1 0 0 1 1 
0 0 0 0 1 1 0 1 0 0 0 1 
1 0 0 1 1 1 1 0 1 1 1 0 
0 0 0 1 1 1 0 0 0 0 0 1 
1 1 0 1 0 1 1 0 1 1 1 1 
1 1 0 0 1 0 1 0 1 0 1 1 
0 0 1 0 1 1 0 0 0 0 0 0 
1 1 1 0 0 1 1 1 0 1 1 1 
1 0 0 0 0 1 1 1 1 1 0 1 
0 0 1 0 0 0 1 0 0 0 1 0 
1 1 0 1 1 0 1 0 0 0 0 0 
9 45
1 0 0 0 0 0 0 0 0 
0 0 0 0 1 0 1 1 1 
1 1 1 0 0 0 1 0 1 
0 1 1 1 0 0 1 0 1 
1 0 0 1 1 0 1 0 0 
0 0 0 0 1 0 1 1 1 
0 1 0 0 1 1 0 0 1 
1 0 0 0 0 0 0 1 1 
1 0 1 1 1 0 0 0 0 
7 17
0 1 0 0 0 1 1 
1 0 0 0 0 1 1 
1 0 0 0 0 0 0 
0 0 1 1 1 1 1 
0 1 1 0 1 1 0 
0 1 0 1 1 0 0 
1 1 0 0 0 0 1 
6 36
1 0 0 1 0 0 
1 1 1 0 0 0 
1 0 1 1 0 1 
1 0 1 0 1 1 
0 0 1 1 0 1 
1 1 1 1 1 1 
17 32
1 1 0 0 0 1 0 0 0 1 1 1 0 0 1 1 1 
0 0 1 0 1 1 0 0 0 1 0 1 1 1 1 0 0 
1 1 0 0 1 1 1 0 0 1 0 0 1 0 0 1 0 
0 1 0 1 1 1 0 0 0 0 0 0 0 0 1 0 1 
1 1 0 0 1 0 1 0 1 0 1 1 0 0 1 0 1 
0 1 1 0 1 0 0 0 1 1 0 0 1 1 0 0 0 
1 1 0 0 1 1 1 0 0 0 0 1 1 1 0 1 1 
1 1 1 1 0 0 0 0 0 0 0 0 0 1 1 0 1 
1 0 1 0 0 0 0 1 0 0 0 1 0 1 0 1 1 
1 0 0 1 0 0 1 1 1 1 0 1 1 1 0 1 0 
1 0 0 0 1 0 0 0 1 1 1 0 1 0 0 0 1 
0 0 1 0 0 0 0 0 0 0 0 1 1 0 1 0 1 
1 1 0 0 1 0 0 1 1 1 0 1 1 1 0 1 0 
1 1 0 1 0 1 1 1 1 0 0 0 0 1 1 1 0 
1 0 0 0 1 1 0 1 1 0 0 1 0 1 1 1 0 
1 1 1 1 0 0 0 0 0 1 1 0 1 1 0 0 0 
0 0 0 1 0 0 0 0 1 0 0 1 0 0 0 1 1 
6 14
1 1 1 0 0 1 
0 1 0 0 0 0 
1 1 0 1 0 0 
0 1 0 0 0 0 
1 1 0 1 1 1 
1 0 1 0 1 1 
17 39
1 0 0 1 1 0 0 0 1 0 1 0 1 0 1 1 1 
0 0 0 0 0 0 1 1 0 1 1 0 0 1 0 0 0 
1 1 1 1 1 1 0 1 1 0 0 0 0 1 1 1 1 
1 1 1 1 0 0 0 1 0 1 0 1 0 1 1 0 0 
1 1 0 1 1 0 0 1 1 1 1 0 1 0 0 0 1 
1 0 0 1 1 1 1 1 0 1 1 0 1 1 0 0 1 
1 1 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 
0 0 0 1 1 0 0 1 1 0 0 0 1 0 1 1 0 
1 0 0 1 1 1 0 1 0 0 0 1 1 0 0 1 0 
1 0 0 1 0 0 1 0 1 1 1 1 1 0 1 1 0 
1 0 1 0 1 1 0 1 1 0 0 0 0 0 1 1 0 
1 1 0 1 1 0 1 0 0 1 0 1 1 1 1 1 1 
0 0 0 1 0 1 0 0 0 1 0 1 1 1 1 0 0 
0 1 1 1 0 0 0 0 1 0 0 0 1 1 0 0 1 
1 1 0 1 1 0 0 0 1 1 0 1 1 1 0 1 0 
1 0 0 1 0 0 0 0 1 0 1 0 0 0 0 1 1 
1 1 1 0 0 0 1 1 1 0 1 1 0 1 1 0 1 
6 21
0 1 0 0 1 0 
1 0 1 0 0 0 
0 1 0 0 0 1 
0 1 1 1 1 0 
0 0 0 0 0 0 
0 1 0 0 0 0 
19 36
1 1 0 1 1 0 1 0 1 0 1 1 1 0 1 0 0 0 0 
0 0 0 1 1 0 1 0 1 0 0 0 1 0 1 1 1 1 1 
1 1 0 1 0 0 1 1 0 1 1 0 1 1 1 0 0 1 0 
1 0 0 0 1 1 1 0 0 0 1 0 0 0 0 1 1 1 1 
1 1 1 1 1 1 0 1 0 1 0 0 0 0 1 0 1 0 1 
0 1 1 1 0 1 1 1 0 1 0 0 1 0 0 1 1 0 0 
1 0 1 1 0 1 1 1 1 1 1 1 1 1 1 0 1 1 0 
1 0 0 1 1 1 0 0 1 0 1 1 1 0 1 1 0 1 0 
1 0 1 1 1 0 1 0 0 0 0 0 1 1 0 0 0 1 1 
1 0 0 1 0 0 1 0 0 0 0 0 1 1 1 1 1 0 1 
0 0 0 0 1 1 0 1 1 0 1 1 0 0 0 1 1 1 1 
0 1 0 0 1 0 1 1 1 0 0 0 1 0 0 1 0 1 0 
0 0 0 1 1 1 0 0 1 0 0 0 0 1 0 0 1 1 1 
1 0 0 0 1 0 0 1 1 0 1 0 0 1 0 1 1 0 1 
1 0 1 0 0 0 1 1 1 0 0 0 0 1 1 0 1 1 1 
1 1 1 0 0 0 0 0 0 1 1 0 0 1 1 0 1 1 1 
1 1 1 1 1 1 1 1 0 0 0 1 0 1 1 0 1 0 1 
0 1 0 0 1 0 0 1 1 0 1 1 0 1 0 0 1 1 1 
0 1 1 0 0 1 1 0 0 1 0 1 0 0 1 1 0 1 1 
14 42
1 1 1 1 0 1 0 1 1 0 0 0 0 0 
0 0 1 1 0 1 0 0 0 1 0 1 0 0 
1 0 0 1 1 0 0 0 0 1 0 1 1 0 
1 1 0 0 1 0 0 1 1 0 1 0 1 1 
1 0 1 0 1 0 0 0 0 1 0 1 0 0 
1 0 1 0 0 0 0 1 0 0 1 0 1 0 
1 1 1 0 0 1 1 1 1 0 1 0 1 0 
0 0 1 1 1 0 0 0 0 1 0 0 0 1 
0 0 0 0 1 1 1 0 0 0 1 1 1 0 
1 1 0 1 1 1 1 0 0 0 1 1 0 1 
0 1 1 1 1 0 1 0 0 0 0 1 1 0 
1 1 1 1 1 1 1 1 1 1 1 0 1 0 
1 1 0 0 1 0 0 1 0 0 1 1 1 1 
0 0 1 0 1 0 0 1 1 1 1 1 1 1 
15 49
0 1 0 0 0 0 1 0 0 1 1 0 1 0 0 
1 0 1 1 1 0 1 0 0 1 0 0 0 0 0 
1 0 0 1 0 0 1 0 1 0 1 1 1 1 1 
1 0 0 1 0 0 0 0 1 0 1 1 0 0 0 
1 0 1 1 0 0 0 0 1 1 1 1 1 1 0 
1 1 0 1 1 1 0 1 1 0 1 0 0 0 0 
0 1 1 0 1 1 1 0 0 1 0 1 0 1 1 
0 0 1 1 0 1 1 1 1 0 1 0 0 1 0 
1 1 0 1 1 0 1 0 0 1 1 1 0 1 1 
1 0 0 1 1 1 0 0 0 1 0 0 1 1 1 
1 0 0 0 1 0 0 1 1 0 1 0 0 0 1 
0 0 0 1 1 0 1 0 0 1 1 0 1 1 1 
1 1 0 0 0 1 0 0 0 0 1 0 1 1 1 
1 0 1 0 1 1 0 0 0 1 1 0 0 1 1 
1 1 1 1 0 1 0 1 1 1 1 0 1 1 0 
15 18
0 1 0 0 0 0 1 0 1 1 0 0 0 0 0 
1 0 1 1 0 1 0 0 1 0 0 0 1 1 1 
0 1 1 0 0 1 1 0 1 1 1 1 1 0 0 
1 1 0 1 1 1 0 0 0 0 1 0 1 1 1 
0 1 0 1 0 0 1 0 0 1 0 0 1 0 1 
0 1 1 1 1 1 0 1 0 0 0 0 0 1 0 
1 0 1 1 0 0 0 0 1 1 1 1 1 1 1 
0 0 0 1 0 0 0 1 0 0 1 0 0 1 1 
1 1 0 0 0 0 0 1 1 1 0 0 1 1 0 
0 0 0 0 1 0 0 0 1 0 0 1 0 1 1 
0 1 0 0 0 1 1 1 0 0 0 0 0 1 0 
1 1 0 1 1 0 1 0 1 1 1 1 0 1 0 
0 0 1 1 1 0 1 0 1 1 1 1 1 0 0 
1 0 1 0 0 1 1 1 0 1 1 0 0 0 0 
1 0 0 0 0 1 0 0 0 1 0 1 0 1 1 
6 41
0 1 1 1 1 0 
1 1 1 1 0 0 
0 0 0 0 0 1 
1 0 1 0 1 1 
0 0 0 1 0 0 
1 0 0 1 1 1 
8 33
1 0 0 1 0 0 1 0 
0 1 0 0 1 0 0 0 
1 0 0 1 0 0 0 1 
1 0 1 0 1 1 0 0 
0 0 1 0 0 0 1 0 
0 1 1 0 0 0 0 1 
0 0 1 0 1 1 1 1 
1 1 0 1 1 0 1 1 
16 40
1 0 1 1 0 0 1 0 0 1 1 1 0 0 0 1 
1 1 0 1 1 1 1 1 0 0 1 1 1 1 0 0 
0 1 1 0 0 1 1 1 0 1 1 0 1 1 1 0 
0 0 1 1 1 0 1 0 0 0 1 0 1 1 1 1 
0 1 1 1 0 0 0 0 0 1 0 0 1 1 0 0 
0 0 0 1 1 1 1 1 0 1 1 0 1 0 1 0 
0 0 1 0 0 0 0 0 1 0 1 1 0 1 1 0 
0 0 1 0 0 1 0 1 0 0 1 0 1 0 1 0 
0 1 0 0 0 1 0 0 0 0 1 1 0 1 0 0 
0 1 0 1 0 0 1 0 0 1 1 0 1 0 0 1 
1 0 0 1 1 1 0 0 0 1 0 0 0 0 0 0 
0 1 0 0 1 1 0 0 0 0 1 0 0 0 1 0 
0 1 0 0 0 0 0 1 1 0 0 1 0 0 0 0 
1 1 1 0 0 1 0 0 0 0 1 1 1 1 1 1 
1 1 1 1 0 1 0 0 0 0 0 0 0 0 1 0 
0 0 0 0 1 0 1 0 1 1 0 1 0 1 1 0 
8 15
1 0 0 1 0 1 1 0 
0 0 1 1 0 1 1 0 
1 0 1 1 1 1 1 1 
0 0 1 1 0 1 0 0 
0 1 0 1 0 1 1 1 
0 1 1 1 0 1 0 1 
1 0 1 1 1 0 1 0 
1 0 1 0 1 0 1 1 
14 10
1 0 1 0 0 1 1 1 0 0 1 0 1 1 
1 1 0 0 1 0 0 0 1 1 0 1 0 0 
0 0 1 1 1 1 0 1 1 0 0 1 1 1 
1 0 1 0 1 0 1 0 1 0 1 0 1 1 
1 1 1 1 0 1 1 0 1 1 0 0 0 1 
1 0 1 0 1 1 0 0 0 0 1 1 1 1 
1 0 1 1 1 0 1 1 0 0 1 1 0 1 
0 1 0 1 1 1 0 0 0 0 1 0 1 1 
0 0 1 1 1 1 1 0 1 0 1 1 1 0 
0 0 1 1 0 1 1 1 0 0 0 0 0 0 
1 0 0 0 1 0 1 0 0 0 0 0 1 1 
1 1 1 1 0 1 1 1 0 1 1 1 1 0 
0 1 0 1 0 0 0 0 1 1 1 0 0 1 
1 1 0 1 1 0 1 1 1 1 1 1 0 1 
18 19
0 1 0 1 0 0 0 1 0 0 0 1 0 1 0 1 0 1 
0 1 0 1 0 1 0 0 0 1 1 1 0 1 0 0 0 1 
1 1 1 0 0 1 0 1 1 1 0 1 0 0 1 1 0 0 
0 1 0 1 1 0 0 1 0 0 1 1 1 0 1 1 0 1 
0 1 0 0 0 0 0 0 1 0 1 0 1 0 1 0 0 1 
0 0 0 1 0 1 0 1 1 0 0 0 1 1 1 0 1 0 
1 0 1 1 1 0 0 1 0 0 1 0 1 1 1 1 0 1 
0 0 0 1 0 0 1 0 1 0 0 1 1 0 1 1 0 0 
0 0 0 1 1 0 0 1 0 1 1 0 1 1 1 1 0 1 
0 1 0 1 0 0 1 0 1 1 0 1 0 0 1 1 0 0 
0 0 0 0 0 0 0 0 1 1 0 1 0 0 1 0 0 0 
0 0 1 0 1 0 0 0 0 0 1 0 1 0 1 0 0 1 
0 1 0 0 0 0 0 1 0 1 1 1 0 1 1 0 0 1 
1 1 0 1 1 1 0 0 1 0 0 0 0 0 0 1 0 1 
0 1 1 0 1 1 1 1 0 1 1 0 1 1 1 1 0 0 
0 0 0 1 1 0 0 0 1 0 0 0 0 0 0 1 0 1 
1 0 0 1 1 0 1 1 1 1 1 0 0 0 0 0 0 0 
0 1 1 1 0 0 0 0 1 1 0 0 0 1 0 0 0 1 
13 26
0 0 1 0 0 0 0 1 1 0 1 1 1 
0 1 0 1 1 0 0 1 1 0 0 0 0 
0 1 0 0 1 1 1 0 1 0 1 1 1 
1 0 1 1 0 0 0 1 0 1 0 0 1 
1 0 0 1 0 1 0 1 0 0 1 1 1 
1 1 0 1 1 1 1 1 0 1 1 0 1 
0 1 1 0 1 1 1 1 1 1 0 1 1 
1 0 0 0 1 1 1 1 0 0 1 0 0 
1 0 0 1 0 1 0 1 0 0 1 1 0 
0 1 1 1 0 1 1 0 0 0 1 0 1 
0 1 1 0 0 0 0 0 0 1 0 0 0 
1 0 1 0 1 1 1 1 1 1 0 0 0 
0 1 0 0 1 0 0 1 0 0 1 0 0 
8 31
1 0 0 0 1 0 0 0 
1 1 1 1 0 0 1 1 
1 0 1 1 0 0 0 0 
0 0 1 0 0 1 1 1 
0 1 0 1 0 0 0 1 
1 1 1 1 1 0 1 1 
1 0 0 0 1 0 1 1 
0 1 0 1 1 1 1 0 
7 26
1 0 0 0 0 1 1 
1 1 1 0 0 1 0 
1 1 0 1 0 1 1 
1 1 1 0 1 1 1 
1 0 0 0 1 1 1 
0 1 0 0 0 1 1 
0 1 1 1 1 1 0 
20 100
1 0 0 0 0 1 0 0 1 0 1 1 1 0 1 1 1 0 1 0 
0 0 1 0 0 1 0 0 0 0 1 1 0 0 0 1 0 0 1 0 
1 1 1 1 1 0 1 0 1 0 0 1 1 1 0 1 0 0 1 1 
0 0 0 1 0 1 1 1 0 1 1 0 0 1 0 0 1 0 0 1 
0 0 1 1 0 1 1 0 0 1 1 0 1 1 0 0 0 0 0 1 
1 1 0 1 1 1 0 1 0 0 0 1 0 1 1 0 0 0 0 1 
0 1 1 0 1 0 0 1 1 0 0 1 0 0 0 1 1 1 1 0 
1 0 0 1 1 0 1 1 0 0 0 0 1 1 0 0 0 1 1 0 
1 0 1 1 1 0 1 1 1 1 1 0 1 0 1 1 0 0 1 0 
1 1 0 1 0 0 1 1 0 1 1 1 0 1 0 1 0 0 1 0 
0 0 1 0 0 1 1 1 1 0 0 0 1 0 1 0 1 1 1 0 
1 1 1 1 0 1 1 1 1 0 1 1 0 1 1 0 0 0 1 0 
0 0 0 1 1 0 1 0 1 1 0 0 1 1 1 0 0 0 1 0 
1 1 1 0 0 1 1 0 0 1 1 1 1 1 0 1 0 1 1 0 
0 1 1 1 0 0 0 0 1 1 1 0 0 1 0 0 0 0 1 1 
0 1 0 0 0 0 0 0 1 1 1 1 0 0 0 1 1 0 0 0 
1 1 0 1 0 1 1 1 0 1 0 0 1 0 1 1 0 0 1 0 
0 1 1 1 1 1 0 1 0 1 1 0 1 1 1 1 0 1 0 0 
1 1 0 1 1 0 1 1 1 0 1 0 1 0 1 0 0 1 0 1 
1 0 0 1 1 0 1 1 0 1 1 1 1 0 1 1 1 1 0 1 
20 50
1 1 1 0 0 1 0 0 1 0 0 1 0 1 0 1 0 1 0 0 
0 0 0 1 1 0 1 0 1 0 1 1 0 1 1 1 0 0 0 1 
1 1 1 0 0 0 0 0 1 1 0 1 0 1 0 1 1 0 0 1 
0 1 0 0 1 1 1 1 1 1 1 1 0 1 0 1 0 1 0 0 
0 0 1 1 0 0 1 0 0 1 0 1 1 0 1 1 0 1 1 0 
1 0 1 1 0 1 0 1 1 0 0 1 0 0 0 1 0 1 0 0 
0 0 1 0 1 0 1 1 0 0 1 0 0 1 1 1 1 1 0 1 
1 1 1 0 1 1 1 0 1 1 1 1 1 0 0 1 1 1 0 1 
0 0 0 0 0 0 0 1 0 0 0 1 0 1 0 1 1 0 0 0 
1 0 1 1 1 1 0 1 0 0 1 1 1 0 0 0 0 0 1 1 
0 1 1 1 1 0 1 0 0 0 1 0 0 0 1 0 0 1 1 0 
0 0 1 1 1 0 0 1 1 0 0 1 0 1 0 0 0 1 1 0 
0 0 0 0 0 1 1 1 1 1 0 0 0 1 0 1 0 0 1 0 
0 1 0 1 1 0 0 0 1 0 0 0 1 1 1 0 1 0 1 0 
1 0 0 1 0 0 0 1 0 1 1 1 0 0 1 1 1 0 0 1 
0 1 0 0 0 1 1 1 0 0 0 0 1 0 1 1 1 1 0 0 
1 1 0 1 1 1 1 0 1 0 1 1 1 0 1 0 0 0 1 0 
0 1 1 1 1 0 0 0 0 0 0 1 1 0 1 1 0 0 1 0 
0 0 1 0 1 0 1 0 1 1 0 0 0 1 0 1 1 1 1 0 
0 0 0 1 0 1 1 0 0 0 0 1 1 1 1 0 0 0 1 0 
20 85
1 1 0 0 1 1 0 1 0 1 0 1 1 1 0 0 0 0 0 1 
0 1 1 1 1 0 1 1 1 0 1 1 0 0 0 1 1 0 0 0 
0 0 1 1 1 0 1 1 1 1 1 0 1 1 1 1 0 0 1 1 
1 1 0 1 0 0 0 0 0 0 1 1 1 0 0 0 0 1 1 0 
1 1 0 1 0 1 0 0 1 0 1 1 1 1 1 1 1 1 0 0 
0 1 0 0 0 1 1 0 0 0 1 0 1 1 0 0 1 1 1 1 
0 0 0 1 0 0 0 0 1 1 0 1 0 1 0 0 0 1 1 0 
0 1 1 1 1 1 1 1 0 1 1 1 0 1 1 0 1 1 0 1 
1 1 1 1 0 0 1 0 1 1 0 1 1 0 1 1 0 0 0 1 
0 0 0 1 0 0 1 1 1 0 1 1 0 0 0 1 0 1 1 1 
0 0 0 1 0 0 1 1 0 0 1 1 1 0 1 1 1 1 0 0 
1 1 1 1 1 1 0 1 1 1 1 1 0 0 0 0 1 1 1 0 
0 1 0 0 1 1 1 1 0 1 1 0 0 1 0 1 1 0 1 0 
0 0 1 1 0 1 0 0 1 1 0 0 0 0 0 1 1 1 1 0 
0 1 1 1 0 0 1 1 0 0 1 1 1 0 1 0 1 1 0 1 
1 0 1 0 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 1 
1 1 0 0 0 0 0 1 0 1 0 0 0 0 1 1 1 0 0 1 
0 0 0 0 1 1 0 0 0 1 1 1 1 0 1 1 0 0 1 0 
0 1 0 0 1 0 0 1 1 1 1 1 1 0 0 1 0 1 0 0 
1 0 1 1 1 1 0 1 0 1 1 0 1 0 0 1 1 0 1 1 
20 150
1 0 0 0 1 1 1 1 1 1 0 1 0 1 1 0 0 1 0 1 
1 1 0 0 0 0 0 1 1 0 0 0 1 0 1 1 1 0 1 0 
1 1 0 1 1 0 1 1 0 0 1 0 1 0 0 1 1 0 1 1 
0 1 0 1 0 1 1 1 1 0 0 1 1 1 0 1 1 0 1 1 
1 1 0 1 1 1 1 0 0 0 0 1 1 1 1 0 0 1 1 0 
1 1 0 0 1 0 1 0 0 1 0 0 1 0 0 1 0 0 0 1 
0 0 1 1 1 0 0 0 0 0 1 0 1 0 1 0 0 0 0 0 
0 0 0 0 0 1 0 0 0 1 0 0 1 1 1 1 1 1 1 1 
0 0 0 1 0 1 1 0 0 1 1 0 1 1 0 1 1 1 1 1 
0 1 1 1 1 0 1 1 1 0 1 0 1 0 0 1 0 1 0 1 
1 0 0 1 0 0 0 0 1 0 1 0 0 0 0 1 1 1 0 0 
0 1 1 0 0 0 1 0 1 0 1 1 1 0 0 1 1 1 0 1 
1 1 1 0 0 0 1 1 0 0 1 0 1 0 0 0 1 0 0 0 
1 0 0 0 1 1 1 0 0 0 1 0 1 0 1 0 0 1 0 1 
1 1 0 0 0 0 1 0 1 1 1 1 1 0 0 0 0 1 0 1 
0 1 1 1 0 0 0 1 0 0 0 0 1 1 0 0 0 1 0 0 
0 0 0 0 0 1 0 0 1 1 0 1 1 1 0 0 1 0 1 0 
1 1 0 1 1 0 1 1 1 0 0 1 0 0 0 0 1 1 1 0 
1 0 0 1 0 1 0 1 1 0 0 0 1 1 0 1 0 1 1 1 
1 1 1 1 1 0 0 1 1 0 0 1 1 1 1 1 1 0 0 1 
20 200
0 0 1 1 1 1 0 0 1 0 0 1 0 0 0 1 0 0 0 0 
0 0 0 0 0 1 0 1 1 0 1 1 1 0 1 1 1 1 0 1 
1 0 1 1 1 0 1 0 0 0 1 0 0 1 0 1 1 0 0 0 
0 1 1 0 1 1 1 1 0 1 0 0 0 0 0 1 1 0 0 0 
1 0 1 0 0 1 0 0 1 1 0 0 0 1 1 1 0 1 0 1 
1 1 1 0 0 0 0 0 1 1 1 1 0 1 0 0 1 0 1 0 
0 0 1 1 0 0 0 0 0 0 1 0 0 0 0 1 1 0 0 1 
1 1 0 1 1 0 1 0 0 0 0 1 1 0 1 1 0 1 0 0 
0 0 1 1 0 0 0 0 1 1 0 0 1 0 0 0 1 0 0 0 
0 1 1 0 1 1 1 1 1 0 1 1 1 1 1 0 1 0 0 1 
1 1 0 0 1 1 1 1 0 0 1 1 0 1 1 0 1 1 1 0 
0 0 1 1 0 0 1 1 1 0 0 0 1 0 0 1 0 1 1 0 
1 0 0 0 0 0 1 0 1 1 0 0 0 0 0 1 0 1 1 0 
1 0 1 0 1 0 1 0 0 0 1 1 1 0 0 0 0 0 1 1 
1 1 0 1 1 0 1 0 0 1 0 0 0 1 0 1 0 0 0 0 
0 0 1 0 1 1 1 1 1 0 1 0 1 0 0 1 0 1 0 0 
0 0 1 0 0 0 0 0 0 1 1 1 1 0 0 0 1 0 0 0 
0 0 0 0 1 0 1 1 1 1 0 0 0 1 0 1 1 1 0 1 
0 1 0 1 1 1 0 0 0 1 0 0 0 1 0 0 0 1 1 0 
1 0 1 0 0 0 1 1 1 0 1 0 1 0 0 0 0 0 1 0 

#1 1
#2 1
#3 1
#4 1
#5 1
#6 3
#7 1
#8 4
#9 4
#10 1
#11 1
#12 1
#13 1
#14 1
#15 1
#16 1
#17 1
#18 1
#19 2
#20 1
#21 1
#22 1
#23 1
#24 1
#25 1
#26 2
#27 1
#28 1
#29 1
#30 2
#31 1
#32 1
#33 1
#34 1
#35 1
#36 1
#37 1
#38 1
#39 1
#40 1
#41 1
#42 1
#43 1
#44 1
#45 1
#46 1
#47 1
#48 1
#49 1
#50 1