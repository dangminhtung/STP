#include<stdio.h>
int n,m,sr,sc;
int arr[16][16],arrC[60][2],arrKc[16][16];
bool visit[16][16];
int queueDC[5000][2];
int head,bot,slC,max;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void resetVS(){
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      visit[i][j]=false;
}

void resetArr(){
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      arr[i][j]=300;
}

void bfsDC(){
  while(head<=bot){
    int x=queueDC[head][0];
    int y=queueDC[head++][1];
    for(int i=0;i<4;i++){
      int xx=x+dx[i];
      int yy=y+dy[i];
      if(xx>0&&xx<=n&&yy>0&&yy<=m&&!visit[xx][yy]&&arr[xx][yy]!=-1){
        arr[xx][yy]=arr[x][y]+1;
        queueDC[++bot][0]=xx;
        queueDC[bot][1]=yy;
        visit[xx][yy]=true;
      }
    }
  }
}

bool checkCong(int x,int y){
  for(int i=0;i<slC;i++)
      if(arrC[i][0]==x&&arrC[i][1]==y)
        return true;
  return false;
}

void backTrack(int x,int y,int count,int sb){
  if((x==1||x==n||y==1||y==m)&&count>max&&checkCong(x,y)){
      max=count;
  }
  visit[x][y]=true;
  for(int i=0;i<4;i++){
      int xx=x+dx[i];
      int yy=y+dy[i];
      int b;
      
      if(xx>0&&xx<=n&&yy>0&&yy<=m&&!visit[xx][yy]){
        if(arr[xx][yy]==-1){
          backTrack(xx,yy,count+arrKc[xx][yy],sb+2);
         
        }
        else if(arr[xx][yy]>sb+1)
          backTrack(xx,yy,count+arrKc[xx][yy],sb+1);
      }
  }
  visit[x][y]=false;
  
}

void solution(int t){
  bfsDC();
  resetVS();
  max=-1;
  backTrack(sr,sc,arrKc[sr][sc],0);
  if(max==-1)
    printf("Case #%d\n-1\n",t);
  else
    printf("Case #%d\n%d\n",t,max);
}
int main(){
//  freopen("text.txt","r",stdin);
  int test;
  scanf("%d",&test);
  for(int t=1;t<=test;t++){
    scanf("%d%d%d%d",&n,&m,&sr,&sc);
    int k,x,y;
    head=0;bot=-1;
    resetArr();
    resetVS();

    scanf("%d",&k);
    for(int i=0;i<k;i++){
      scanf("%d%d",&x,&y);
      queueDC[++bot][0]=x;
      queueDC[bot][1]=y;
      arr[x][y]=0;
      visit[x][y]=true;
    }

    scanf("%d",&k);
    for(int i=0;i<k;i++){
      scanf("%d%d",&x,&y);
      arr[x][y]=-1;
    }

    scanf("%d",&slC);
    for(int i=0;i<slC;i++)
      scanf("%d%d",&arrC[i][0],&arrC[i][1]);

    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        scanf("%d",&arrKc[i][j]);

    solution(t);
  }
  return 0;
}