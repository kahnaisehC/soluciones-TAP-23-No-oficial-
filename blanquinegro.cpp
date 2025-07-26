#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<vector<bool>> tablero(n, vector<bool> (n));

	string st;

	for(int i = 0; i < n; i++){
		cin >> st;
		for(int j = 0; j < n; j++){
			tablero[i][j] = st[j] == 'B';
		}
	}


	int cantidad = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n-1; j++){
			if(!tablero[i][j] && !tablero[i][j+1]){
				tablero[i][j+1] = true;
				tablero[i][j] = true;
				cantidad ++;
			}
		}
	}

	cout << cantidad << endl;



	return 0;
}
