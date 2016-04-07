#include <iostream>
#include <math.h>

int getTri(int n){
	for (int i = n-1; i > 0; i--){
		n+=i;
	}
	return n;
}

int getDivs(int tri){
	int divs = 0;
	for (int i = 1; i < ceil(sqrt(tri))+1; i++){
		if (tri%i==0) divs+=2;
		if (i*i==tri) divs--;
	}
	return divs;
}

int main(){
	int i = 0;
	int divs = -1;
	while (divs<500)
	{
		i++;
		divs = getDivs(getTri(i));
	}
	std::cout << "The first triangle number is the " << i << "th, "<<
	getTri(i) << " with " << divs << " divisors." << std::endl;
}
