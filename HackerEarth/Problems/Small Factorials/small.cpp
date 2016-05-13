#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> bignum;

bignum inttobignum(int n)
{
    bignum bn;
    for(; n != 0; n /= 10)
    {
        bn.push_back(n % 10);
    }
    return bn;
}

void printbn(bignum bn)
{
    bignum::reverse_iterator rit = bn.rbegin();
    for (; rit != bn.rend(); ++rit)
    {      
        cout << *rit;
    }
    cout << endl;
}

bignum multiply(bignum bn, int n)
{
    int carry = 0;
    bignum::iterator it = bn.begin();
    for (; it != bn.end(); ++it)
    {      
        int newnum = (*it * n)+carry;
        //cout << newnum << endl;
        *it = newnum%10;
        carry = newnum/10;
    }

    for(; carry != 0; carry /= 10)
    {
        bn.push_back(carry % 10);
    }
    return bn;
    
}

void fac(int n)
{
    bignum b = inttobignum(n);
    for (int i = n-1; i > 0; i--)
    {
        b = multiply(b, i);
    }
    printbn(b);
}

void smallfacs(int T)
{
	int n;
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		fac(n);
	}
	
}

int main()
{
    int T;
    cin >> T;
    smallfacs(T);
    return 0;
}

