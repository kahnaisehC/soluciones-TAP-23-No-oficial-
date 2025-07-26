#include<bits/stdc++.h>

using namespace std;

int main(){
	long long a, s, l ,r;
	cin >> a >> s >> l >> r;


	long long i = l;
	long long j = l;

	while(s != 0 && j <= r){
		if(s > 0){
			s -= j;
			j++;
		}else{
			s+= i;
			i++;
		}
	}


	if(s != 0){
		cout << 0 << endl;
	}

	// si la progresion tiene una cantidad impar de terminos
	int cantidadDeRangos = 0;
	int posicionA = 1ll*a-l;
	if((i-j)&1){
		long long posicionA = 1ll*a-l;
		long long medio = 1ll*(l-r)/2;

	// si la progresoin tiene cantidad par de terminos
	}else{
	}



	return 0;
}

