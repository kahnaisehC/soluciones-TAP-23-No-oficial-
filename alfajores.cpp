#include<bits/stdc++.h>

using namespace std;



int main(){
	int n, m;
	cin >> n >> m;
	vector<int> alfajores(n);
	for(auto& a: alfajores){
		cin >> a;
	}
	vector<int> oficinas;
	int mn = -1e9-4;
	for(int i = 0; i < m; i++){
		int o;
		cin >> o;
		if(-o > mn){
			mn = -o;
			oficinas.push_back(mn);
		}
	}



	for(int i = 0; i < alfajores.size(); i++){
		int a = alfajores[i];
		int it = 0;
		while(a>=-oficinas[oficinas.size()-1]){

			int sigOfic = lower_bound(oficinas.begin(), oficinas.end(), -a) - oficinas.begin();

			if(sigOfic == oficinas.size())break;
			int o = -oficinas[sigOfic];
			a = (a%o);
		}
		cout << a << " ";
	}
	cout << endl;



	return 0;
}
