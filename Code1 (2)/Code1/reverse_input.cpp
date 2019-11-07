#include <iostream>

using namespace std;

//recursive function
void reverse_input( )
{
    char ch;

    //read next character
	cin.get(ch);

	if (cin && ch != '\n') //base case
    {
        reverse_input();  //recursive call
        cout << ch; //display
    }
}



int main()
{
    cout <<"Please enter a line" << endl;
	reverse_input();

	return 0;
}

