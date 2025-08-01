#include<bits/stdc++.h>

using namespace std;

map<int, pair<int, int>>hashes = {
	{2, {2, 1}},
	 {3, {1,3}},
	{8, {4,2}},
	{12, {3, 4}}
};

int main(){
	int n;
	cin >> n;
	vector<int> modulos(5,0);
	for(int i = 0; i < n; i++){
		int c;
		cin >> c;
		modulos[c%5]++;
	}
	int amountOfGroups = 0;
	amountOfGroups+=modulos[0];
	modulos[0] = 0;

	int amountOf1_4 = min(modulos[1], modulos[4]);
	modulos[1]-=amountOf1_4;
	modulos[4]-=amountOf1_4;
	amountOfGroups+=amountOf1_4;

	int amountOf2_3= min(modulos[2], modulos[3]);
	modulos[2]-=amountOf2_3;
	modulos[3]-=amountOf2_3;
	amountOfGroups+=amountOf2_3;
	
	int hash = 1;
	for(int i = 0; i < 5; i++){
	if(modulos[i] != 0){
		hash*=i;
	}
	}
	int key1 = hashes[hash].first;
	int key2 = hashes[hash].second;


	while(modulos[key1] > 0 && modulos[key2] > 0){
		if(modulos[key1] >= modulos[key2]){
			if(modulos[key1] < 2)break;
			modulos[key1]-=2;
			modulos[key2]--;
			amountOfGroups++;
		}else{
			if(modulos[key2] < 3)break;
			modulos[key1]--;
			modulos[key2]-=3;
			amountOfGroups++;
		}
	}
	for(int i = 0; i < 5; i++){
		amountOfGroups += modulos[i]/5;

	}

	cout << amountOfGroups << endl;



	return 0;
}
