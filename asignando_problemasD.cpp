#include<bits/stdc++.h>

using namespace std;

// k*C[i] asumiendo que hay 1e14 problemas y cada competencia
// necesita solo un problema
const int MAX = 1e15;


int main(){
	int k;
	cin >> k;
	vector<int> requisitos(k);

	for(auto& i: requisitos){
		cin >> i;
	}
	vector<int> problemas(k);
	for(auto& p: problemas){
		cin >> p;
	}

	long long left = 0;
	long long right = MAX;
	long long cantidadDeCompetencias = 0;

	while(left <= right){
		long long mid = 1ll*(right-left)/2 + left;


		bool isPossible = true;
		long long resto = 0;
		for(int i = 0; i < k; i++){
			if(((1ll*problemas[i]+1ll*resto)/(1ll*requisitos[i])) < (1ll*mid)){
				isPossible = false;
				break;
			}
			resto = (1ll*problemas[i]+1ll*resto - 1ll*mid*requisitos[i]);
		}

		if(isPossible){
			cantidadDeCompetencias = mid;
			left = mid+1;
		}else{
			right = mid-1;
		}

	}

	cout << cantidadDeCompetencias << endl;




	return 0;
}
