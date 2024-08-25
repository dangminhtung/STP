
#include<iostream>
using namespace std;
int n,m,k,head,bot;
long long min_c;
long long int map[1001],arrCP[16][16];
int arrS[15];
int arr[1001][1001][2],queue[1000000];
bool visit[1001];
void resetArr(){
  for(int i=1;i<=n;i++)
      arr[i][0][0]=0;
}
void resetVS(){
  for(int i=1;i<=1000;i++){
    visit[i]=false;    
  }
}
void resetMap(){
  for(int i=1;i<=n;i++)
    map[i]=99999999;
}
void bfs(int index){
  head=0;
  bot=-1;
  queue[++bot]=index;
  map[index]=0;
  while(head<=bot){
    index=queue[head++];
    visit[index]=false;
    for(int i=1;i<=arr[index][0][0];i++){
      if(map[arr[index][i][0]]>map[index]+arr[index][i][1]){
        map[arr[index][i][0]]=map[index]+arr[index][i][1];
        if(!visit[arr[index][i][0]])
          queue[++bot]=arr[index][i][0];
        visit[arr[index][i][0]]=true;
      }
    }
  }
}

void backTrack(long long sum,int index,int c){
  if(sum+arrCP[index][0]>=min_c)
    return;
  if(c==k){
    min_c=sum+arrCP[index][0];
    return;
  }
  visit[index]=true;
  
    for(int i=1;i<=k;i++){
      if(!visit[i]&&arrCP[index][i]!=0)
        backTrack(sum+arrCP[index][i],i,c+1);
    }
  visit[index]=false;
}
void solution(int t){
  for(int i=0;i<=k;i++){
    resetMap();
    bfs(arrS[i]);
    for(int j=0;j<=k;j++){
      arrCP[i][j]=map[arrS[j]];
      if(arrCP[i][j]==99999999)
        arrCP[i][j]=0;
    }
  }
  min_c=9000000;
  backTrack(0,0,0);
  if(min_c==9000000)
      cout << "Case #" << t << endl <<"-1"<<endl<<endl;
  
  else

     cout << "Case #" << t << endl <<min_c<<endl<<endl;
}
int main(){
 // freopen("Text.txt","r",stdin);
  int test;
  resetVS();
    cin >> test;
  
  for(int t=1;t<=test;t++){
      cin >> n >> m >> k;
    for(int i=1;i<=k;i++)
        cin >> arrS[i];
     
    arrS[0]=1;
    int x,y,c;
    resetArr();
    for(int i=0;i<m;i++){
     
        cin >> x >> y >> c;
      arr[x][0][0]++;
      arr[x][arr[x][0][0]][0]=y;
      arr[x][arr[x][0][0]][1]=c;
    }
    solution(t);
  }
  return 0;
}
1

6 8 2

2 5

1 2 4

2 4 2

4 3 3

3 1 4

4 1 5

3 5 5

5 3 1

5 6 7