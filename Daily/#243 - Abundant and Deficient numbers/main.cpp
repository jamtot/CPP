#include <iostream>
using namespace std;

void numberIs(int n){
	int divsum=0;
	for (int i = 1; i < n+1; i++){
		if (n%i==0) divsum+=i;
	}
	int dn = n*2;
	cout << n << ": ";
	if (divsum > dn) cout << "Abundant by " << divsum-dn << endl;
	else if (divsum < dn) cout << "Deficient"<<endl;// by " << dn-divsum << endl;
	else cout << "~~neither~~ Perfect number" << endl;
}

int main(){
	int nums [] = {12, 28, 18, 21, 9, 6, 111, 112, 220, 69, 134, 85};
	for (unsigned int i = 0; i < sizeof(nums)/4; i++){
		// using sizeof()/4 because ints are 4 bytes each
		// kind of hacky
		numberIs(nums[i]);
	}
}
