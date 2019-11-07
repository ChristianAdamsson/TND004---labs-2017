#include <iostream>

using namespace std;

//Return n!
//Recursive
long long factorial(int n);

//Return n!
//Iterative
long long factorial2(int n);


int main()
{

	//cout << "Max long in this machine = " << LONG_MAX << endl;

	long x;
	int n;
	cout << "Enter n: ";
	cin >> n;

	cout << "Recursive" << endl;
	cout << "fact(" << n << ")= " << factorial(n) << endl;

	cout << "\nIterative" << endl;
	cout << "fact(" << n << ")= " << factorial2(n) << endl;

	return 0;
}

//Return n!
//Recursive
long long factorial(int n)
{
    if (!n) // base case
        return 1;
    else
        return n * factorial(n-1);
}

//Return n!
//Iterative
long long factorial2(int n)
{
    long long res = 1;

    for(int i = 1; i <= n; ++i)
        res *= i;

    return res;
}



