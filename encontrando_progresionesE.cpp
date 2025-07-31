#include<bits/stdc++.h>

using namespace std;

int main(){
	long long a, sum, left, right;
	cin >> a >> sum >> left >> right;

	a*=2;
	sum*=2;
	left*=2;
	right*=2;

	vector<long long> evenMids;
	vector<long long> oddMids;
	for(long long mid = left; mid <= right; mid++){
		if(mid > sum)break;
		if(sum%mid!=0)continue;
		long long progSize = sum/mid;
		if(progSize == 1)continue;
		if(progSize%2 == 1){
			long long amountPerSide = progSize/2;
			if(mid-amountPerSide < left){
				continue;
			}
			if(mid+amountPerSide > right){
				continue;
			}
			oddMids.push_back(mid);
		}else{
			long long amountPerSide = progSize/2-1;
			if(mid-amountPerSide < left){
				continue;
			}
			if(mid+amountPerSide > right){
				continue;
			}
			evenMids.push_back(mid);
		}
	}

	int amountOfProgressions = 0;
	if(a >= left && right >= a && a == sum)amountOfProgressions++;
	for(long long k = 2; k <= right-left; k+=2){

		for(auto& mid: oddMids){
			long long progSize = sum/mid;
			long long amountPerSide = progSize/2;
			long long firstValue = mid-amountPerSide*k;
			long long lastValue = mid+amountPerSide*k;
			if(firstValue < left){
				continue;
			}
			if(lastValue > right){
				continue;
			}
			if(firstValue > a){
				continue;
			}
			if(lastValue < a){
				continue;
			}
			if(mid%k != a%k){
				continue;
			}
			amountOfProgressions++;
		}
		for(auto& mid: evenMids){
			long long progSize = sum/mid;
			long long amountPerSide = progSize/2;
			long long firstValue = mid-amountPerSide*k + k/2;
			long long lastValue = mid+amountPerSide*k - k/2;
			if(firstValue < left){
				continue;
			}
			if(lastValue > right){
				continue;
			}
			if(firstValue > a){
				continue;
			}
			if(lastValue < a){
				continue;
			}
			if((mid+k/2)%k != a%k){
				continue;
			}
			amountOfProgressions++;
		}
	}
	cout << amountOfProgressions << endl;



	return 0;
}

