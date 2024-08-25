#include<iostream>
using namespace std;

int n;
int door[3][3];
int seat[60];
int result;
int	checkRight(int i){
	int dis=0;
	int l,r;
	l=r=door[i][0];
	int passengers=door[i][1];
	while(passengers>0){
		if(seat[r]==-1 && passengers > 0){
			seat[r]=i;
			passengers--;
			dis += (r-door[i][0]+1);
		}
		if(seat[l]==-1 && passengers > 0){
			seat[l]=i;
			passengers--;
			dis += (door[i][0]-l+1);
		}
		if(l>0) l--;
		if(r<n-1) r++;
	}
	return dis;
}
int checkLeft(int i){
	int dis=0;
	int l,r;
	l=r=door[i][0];
	int passengers=door[i][1];
	while(passengers>0){
		if(seat[l]==-1 && passengers > 0){
			seat[l]=i;
			passengers--;
			dis += (door[i][0]-l+1);
			
		}
		if(seat[r]==-1 && passengers > 0){
			seat[r]=i;
			passengers--;
			dis += (r-door[i][0]+1);
		}
		if(l>0) l--;
		if(r<n-1) r++;
	}
	return dis;
}
void unset(int x){
	for(int i=0; i<=n; i++){
		if(seat[i]==x) seat[i]=-1;
	}
}
void backtrack(int index, int dis){
	if(index==3){
		result=min(result,dis);
		return;
	}
	for(int i=0; i<3; i++){
		if(door[i][2]==0){
			door[i][2]=1;
			backtrack(index+1,dis+checkRight(i));
			unset(i);
			backtrack(index+1,dis+checkLeft(i));
			unset(i);
			door[i][2]=0;
		}
		
	}
}
int main(){
	freopen("Text.txt","r",stdin);
	int T;cin>>T;
	for(int t=0; t<T; t++){
		cin>>n;
		for(int i=0; i<=n; i++) seat[i]=-1;
		for(int i=0; i<3; i++){
			cin>>door[i][0];
			door[i][0]-=1;
			cin>>door[i][1];
			door[i][2]=0;
		}
		result=5000;
		backtrack(0,0);
		cout<<"Case #"<<t+1<<endl<<result<<endl;
	}
	return 0;
}
50
10
4 5
6 2
10 2
10
8 5
9 1
10 2
24
15 3
20 4
23 7
39
17 8
30 5
31 9
60
57 12
31 19
38 16
10
2 2
8 3
5 2
10
9 3
3 3
5 2
10
8 8
2 1
6 1
10
2 2
5 2
3 2
10
2 2
5 2
4 2
20
12 5
19 6
10 2
20
16 4
15 3
4 4
20
14 2
5 6
2 5
20
8 4
5 4
3 2
20
4 5
2 5
10 6
20
11 5
3 5
9 3
20
5 4
9 3
7 4
20
11 4
7 3
2 4
20
4 1
5 3
15 5
20
17 1
12 4
9 3
30
14 9
18 3
29 10
30
12 10
4 9
6 5
30
1 4
28 7
27 2
30
6 1
15 10
23 8
30
4 7
28 1
13 2
30
7 6
6 5
18 2
30
23 2
21 5
11 7
30
11 8
28 8
12 8
30
18 10
4 10
6 9
30
12 7
19 7
3 1
40
14 1
9 4
21 5
40
11 11
40 8
25 10
40
36 11
2 12
3 17
40
15 2
21 9
37 20
40
29 3
5 2
2 11
40
19 6
21 13
29 11
40
14 11
9 4
4 11
40
18 10
14 12
35 8
40
12 10
1 6
10 10
40
24 8
25 6
9 1
50
3 6
46 8
36 12
50
38 9
15 1
4 3
50
19 15
31 2
47 6
50
49 9
10 7
8 11
50
43 15
39 10
30 7
60
12 17
16 12
29 3
60
55 20
33 20
16 20
60
27 10
36 3
54 5
60
37 20
42 20
19 20
60
60 13
18 10
37 16