/* Author Jonathan Morris
https://www.hackerearth.com/practice/machine-learning/prerequisites-of-machine-learning/basic-probability-models-and-rules/tutorial/

TEST YOUR UNDERSTANDING
Basic probability rules and models

SAMPLE INPUT
0.2 (Pmb)
0.2 (Pab)
0.5 (P1)
*/

#include <iostream>
#include <iomanip>   
using namespace std;

int main()
{
	double Pmb,Pab,P1,Prs;
	cin >> Pmb;//prob that Mike will take the bus
	cin >> Pab;//prob that Alic will take bus
	cin >> P1;//prob of rain this weekend
	// prob of rain independant of mike and alice's travel plans
	// P = (P1 AND ((Pmb AND not Pab) OR (not Pmb AND Pab))
	// P = (P1 * ((Pmb * (1-Pab)) + ((1-Pmb) * Pab)))

	Prs = P1 * ((Pmb * (1 - Pab)) + ((1 - Pmb) * Pab));
	printf("%.6f", Prs);
}