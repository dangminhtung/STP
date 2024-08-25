#include<stdio.h>
int n,m,max;
int arr[15][15];
bool visit[15][15];
int dx[6]={0,1,1,1,0,1};
int dy[6]={1,-1,0,1,-1,-1};
int dx2[6]={-1,0,1,0,-1,-1};
int dy2[6]={1,1,0,-1,-1,0};
int map[4][2];
void backTrack(int k,int x,int y,int sum){
  if(k==3){
    sum+=arr[x][y];
    if(sum>max)
      max=sum;
    return;
  }
  sum+=arr[x][y];
  map[k][0]=x;
  map[k][1]=y;
  visit[x][y]=true;
  for(int j=0;j<=k;j++){
    if(map[j][1]%2==1){
      for(int i=0;i<6;i++){
        int xx=map[j][0]+dx[i];
        int yy=map[j][1]+dy[i];
        if(xx>=0&&xx<n&&yy>=0&&yy<m&&!visit[xx][yy]){
          backTrack(k+1,xx,yy,sum);
        }
      }
    }
    else{
      for(int i=0;i<6;i++){
        int xx=map[j][0]+dx2[i];
        int yy=map[j][1]+dy2[i];
        if(xx>=0&&xx<n&&yy>=0&&yy<m&&!visit[xx][yy]){
          backTrack(k+1,xx,yy,sum);
        }
      }
    }
  }
  visit[x][y]=false;

}
int main(){
//  freopen("text.txt","r",stdin);
  int test;
  scanf("%d",&test);
  for(int t=1;t<=test;t++){
    scanf("%d%d",&m,&n);
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++){
        scanf("%d",&arr[i][j]);       
        visit[i][j]=false;
      }
      max=0;
      for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
          backTrack(0,i,j,0);
      long long maxx=max*max;
      printf("Case #%d\n%lld\n",t,maxx);
  }
  return 0;
}
3
5 3

300 410 150 55 370

120 185 440 190 450

165 70 95 420 50

5 5

356 55 41 453 12

401 506 274 506 379

360 281 421 311 489

425 74 276 371 164

138 528 461 477 470
13 3
197 51 443 274 47 552 160 96 501 102 469 318 308 
516 128 506 471 381 418 328 517 380 78 569 58 90 
113 238 179 444 541 27 444 62 264 93 245 353 37 