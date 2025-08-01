#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int>numsInCols(n*n+1, 0);
	vector<int>numsInRows(n*n+1, 0);

	for(int row = 0; row < n; row++){
		for(int col = 0; col < n; col++){
			int c;
			cin >> c;
			numsInCols[c] = col;
			numsInRows[c] = row;
		}
	}
	vector<int>maxPerCol(n+1, 0);
	vector<int>maxPerRow(n+1, 0);
	int mx = -1;
	for(int c = n*n; c >= 1; c--){
		int col = numsInCols[c];
		int row = numsInRows[c];
		int newMaxPerCol = maxPerRow[row]+1;
		int newMaxPerRow = maxPerCol[col]+1;
		maxPerCol[col] = max(newMaxPerCol, maxPerCol[col]);
		maxPerRow[row] = max(newMaxPerRow, maxPerRow[row]);
		mx = max(maxPerCol[col], max(maxPerRow[row], mx));
	}

	cout << mx << endl;
	return 0;

}
