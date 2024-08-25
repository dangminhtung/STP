#include<iostream>
#include<stdio.h>
using namespace std;


struct edge
{
	int start,end;
	double kc;
};
int n,a,b,c,slg;
double ans;
edge array[2000];
int visited[100];

double cal(double mid){
	return a * mid * mid * mid + b * mid * mid + c;
}
double findH(double kc){
	double l = 0, r =  kc, mid = 0;
		while(r - l > 0.000001) {
			mid = (l+r) / 2;
			double temp = cal(mid);
			if(kc - temp > 0.0000001) l = mid;
			else if(kc - temp < -0.0000001) r = mid;
			else break;
		}
		return mid;
}
void sapxep(){
	for(int i=0;i<slg-1; i++){
		for(int j=i+1; j<slg; j++){
			if(array[i].kc>array[j].kc){
				double temp = array[i].kc;
				array[i].kc = array[j].kc;
				array[j].kc = temp;

				int temp1 = array[i].start;
				array[i].start = array[j].start;
				array[j].start = temp1;

				temp1 = array[i].end;
				array[i].end = array[j].end;
				array[j].end = temp1;
			}
		}
	}
}
void prim(){
	while(true) {
			int check = true;
			for (int i = 0; i < slg; i++) {
				if ((visited[array[i].start]  && !visited[array[i].end]) || (!visited[array[i].start]  && visited[array[i].end])) {

					visited[array[i].start] = true;
					visited[array[i].end] = true;
					ans += findH(array[i].kc);
					check = false;
					break;
				}
			}
			if(check) return;	
		}
}
int main(){
	//freopen("Text.txt","r",stdin);
	int test;cin>>test;
	for(int t=0; t<test; t++){
		cin>>n>>a>>b>>c;
		slg=0;
		for(int i=0 ; i<n; i++){
			double x;
			visited[i]=0;
			for(int j=0; j<n; j++){
				cin>>x;
				if(i<j){
					array[slg].start=i;
					array[slg].end=j;
					array[slg++].kc=x;
				}
			}
		}
		sapxep();
		ans=0;
		visited[0]=1;
		prim();
		cout<<"#"<<t+1<<" ";
		printf("%.3f",ans);
		cout<<endl;
	}

	return 0;
}
50
3
3 2 1
0 100 100
100 0 100
100 100 0
4
10 1 4
0 452 995 613 
452 0 302 173 
995 302 0 309 
613 173 309 0 
4
9 6 2
0 351 912 720 
351 0 251 107 
912 251 0 941 
720 107 941 0 
7
1 9 9
0 604 571 668 261 511 546 
604 0 435 979 223 356 602 
571 435 0 842 482 759 109 
668 979 842 0 972 306 438 
261 223 482 972 0 988 468 
511 356 759 306 988 0 601 
546 602 109 438 468 601 0 
7
6 6 4
0 766 956 661 962 422 999 
766 0 203 784 105 890 887 
956 203 0 157 409 329 460 
661 784 157 0 928 733 707 
962 105 409 928 0 315 817 
422 890 329 733 315 0 467 
999 887 460 707 817 467 0

[Output]
#1 6.000
#2 9.119
#3 8.060
#4 26.371
#5 18.983