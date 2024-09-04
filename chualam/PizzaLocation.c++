    #include <iostream>
#include <time.h>
using namespace std;

int oo = 2000000000;

int T, k, r, result; 
int m, mp[21][2], vs[21];
int n, pos[101][3], check[101];
int people[21][101];


int calcPeople(int located, int space){
	int ans = 0;
	int x1 = mp[located][0], y1 = mp[located][1];
	int x2 = pos[space][0], y2 = pos[space][1], p = pos[space][2];

	if((x1- x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= (r * r)) ans += p;
	return ans;
}


void backtrack(int index, int from, int sum){
	if(index == k){
		if(sum > result){
			result = sum;
		}
		return;
	}

	for(int i = from; i <= m - k + index; i++){
		if(!vs[i]){
			vs[i]++;

			int total = 0;
			for(int j = 0; j < n; j++){
				if(people[i][j] > 0){
					if(!check[j]) total += people[i][j];
					check[j]++;
				}
			}

			backtrack(index+1, i+1,  sum + total);

			for(int j = 0; j < n; j++){
				if(people[i][j] > 0) check[j]--;
			}

			vs[i]--;
		}
	}
}



int main(){

	//freopen("input.txt", "r", stdin);

	// Calc clock
	clock_t time_start, time_end; 
	time_start = clock(); 
	
	cin >> T;
	for(int tc = 1; tc <= T; tc++){
		// Initial && Input
		result = 0;
		cin >> k >> r;
		cin >> m;
		for(int i = 0; i < m; i++){
			vs[i] = 0;
			cin >> mp[i][0] >> mp[i][1];
		}

		cin >> n;
		for(int i = 0; i < n; i++){
			check[i] = 0;
			cin >> pos[i][0] >> pos[i][1] >> pos[i][2];
		}

		// Solve Problem
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				people[i][j] = calcPeople(i, j);
			}
		}
		backtrack(0, 0, 0);
		
		// Output
		cout << "#" << tc << " " << result << endl;
	}

	// Calc Time
	time_end = clock();
	cout.setf(ios::fixed);
	cout.precision(9);
	cout << "Time: " << double (time_end - time_start) / double (CLOCKS_PER_SEC) << " s." << endl;
	
	return 0;
 }