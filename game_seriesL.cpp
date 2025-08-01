#include<iostream>

using namespace std;
int p3;
int a3;

#define wins 2
#define flase 0
#define maybe 1


#define piwinsye wins 
#define pilosenoooo flase
#define duraw maybe

int main(){
	int a1, p1;
	int a2, p2;
	cin >> a1 >> p1 >> a2 >> p2;

	int p3 = p2+(a2^a2^p1);
	int a3 = a2+(a1^a1^a1);

	switch (int(!(a3>p3)+!(a3>=p3))){
		case piwinsye:{
			printf("%c\n", 'P');
			return 0;
		}
		case pilosenoooo:{
			printf("%c\n", 'A');
			return 0;
		}
		case duraw:{
			printf("%c\n", 'D');
			return 0;
		}
	}

	return 0;

}
