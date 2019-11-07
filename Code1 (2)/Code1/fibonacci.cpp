#include <iostream>

using namespace std;


long long fibonacci(int n) //recursive function
{
    if (n == 0 || n == 1)
        return n;

    long long res = fibonacci(n-1) + fibonacci(n-2); //recursive function calls

    return res;
}


//long long fibonacci(int n) //iterative function
//{
//    if (n == 0 || n == 1)
//        return n;
//    else
//    {
//        long long before_last = 0;
//        long long last = 1;
//        long long current;
//
//        for(int i = 2; i <= n; i++)
//        {
//            current = before_last + last;
//            before_last = last;
//            last = current;
//        }
//
//        return current;
//
//    }
//}




int main()
{
	int n;

	cout << "Enter n: ";

	while (cin >> n && n >= 0)
    {
        cout << "\nfibonacci(" << n << ") = "
             << fibonacci(n) << endl << endl;

        cout << "Enter n: ";
    }

    return 0;
}
