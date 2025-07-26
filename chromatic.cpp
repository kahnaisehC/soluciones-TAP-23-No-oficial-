#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> red(n);
	vector<int> blue(n);

	for(auto& r: red){
		cin >> r;
	}
	for(auto& b: blue){
		cin >> b;
	}

	sort(blue.begin(), blue.end());
	sort(red.rbegin(), red.rend());

	


	int mn = INT_MAX;
	int mx = INT_MIN;
	for(int i = 0; i < n; i++){
		mn = min(mn, blue[i]+red[i]);
		mx = max(mx, blue[i]+red[i]);
	}
	cout << mx - mn << endl;




	return 0;

}


