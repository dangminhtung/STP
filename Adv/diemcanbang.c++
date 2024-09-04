#include<iostream>
using namespace std;

int n;
double index[100];
double weight[100];
double caculatorL(int i, double m){
	double result=0;
	for(int j=0; j<=i; j++){
		result=(double)( result +weight[j]/((m-index[j]) * (m-index[j])) );
	}
	return result;

}
double caculatorR(int i, double m){
	double result=0;
	for(int j=n-1; j>=i+1; j--){
		result= (double)(result +weight[j]/((m-index[j]) * (m-index[j])));
	}
	return result;
}
void binary_search(double l , double r , int i){
	double powerL, powerR;
	double m=(double)((r+l)/2);
	if(r-l<= 1e-10){
		printf("%.10f ", r);
		return ;
	}
	powerL=caculatorL(i,m);
	powerR=caculatorR(i,m);

	if(powerL==powerR){
		printf("%.10f ", m);
		return;
	}else if(powerL>powerR){
		binary_search(m,r,i);
	}else if(powerL<powerR){
		binary_search(l,m,i);
	}

}
int main(){
	freopen("Text.txt","r",stdin);
	int q;
	for(int testcase=0; testcase<10 ;testcase++){
		cin>>n;
		for(int i=0; i<n; i++) cin>>index[i];
		for(int i=0; i<n; i++) cin>>weight[i];
		
		cout<<"#"<<testcase+1<<" ";
		for(int i=0; i<n-1; i++)
			binary_search(index[i], index[i+1],i);
		cout<<endl;


	}
	return 0;
}
2
1 2 1 1
2
1 2 1 1000
2
457 468 333 321
3
1 2 3 1 2 1
4
2 3 5 7 3 2 7 5
5
3 11 12 19 29 542 661 450 521 366	
6
42 75 88 94 113 144 669 551 355 344 294 155
7
62 86 279 323 363 516 579 810 749 736 297 136 107 52
8
10 34 64 73 93 97 101 122 466 463 441 373 315 292 225 83
10
9 14 38 39 48 73 179 190 207 302 560 497 640 722 437 259 449 470 709 520