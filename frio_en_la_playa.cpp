#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int a, b, tx, ty;
	cin >> a >> b >> tx >> ty;
	vector<long long> azul(n);
	vector<long long> rojo(n);



	for(auto& a: azul){
		int x, y;
		cin >> x >> y;
		long long dist = 1ll*(abs(tx-x)*abs(tx-x)) + 1ll*(abs(ty-y)*abs(ty-y));

		a = dist;
	}
	for(auto& a: rojo){
		int x, y;
		cin >> x >> y;
		long long dist = 1ll*(abs(tx-x)*abs(tx-x)) + 1ll*(abs(ty-y)*abs(ty-y));
		a = dist;
	}

	sort(azul.begin(), azul.end());
	sort(rojo.begin(), rojo.end());

	if(azul[0] < rojo[0]){
		int count = 0;
		for(int i = 0; i < n; i++){
			if(azul[i] > rojo[0]) break;
			count++;
		}

		cout << "A " << count << endl;

	}else{
		int count = 0;
		for(int i = 0; i < n; i++){
			if(rojo[i] > azul[0]) break;
			count++;
		}

		cout << "R " << count << endl;
	}




	return 0;
}
