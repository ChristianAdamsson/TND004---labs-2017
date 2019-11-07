#include <iostream>
#include <vector>

using namespace std;

// A divide-and-conquer based function to count number of occurrences
// for each element in the array
void findFrequency(int arr[], int low, int high, vector<int>& freq)
{

	// Base case: all items from low to high are the same
	if (arr[low] == arr[high])
	{
		freq[arr[low]] += high - low + 1;
	}
	else
	{
		// Same as (low + high)/2, but avoids overflow for
		// large low and high
		int mid = low + (high - low) / 2;

		findFrequency(arr, low, mid, freq);
		findFrequency(arr, mid + 1, high, freq);
	}
}

int main()
{
    //The sorted sequence
	int arr[] = { 1, 1, 1, 2, 3, 3, 5, 5, 8, 8, 8, 9, 9, 10 };
	int n = 14;

	vector<int> freq(arr[n - 1] + 1, 0);

	// Fill the vector with frequency
	findFrequency(arr, 0, n - 1, freq);

	// Display the frequencies
	for (int i = 0; i <= arr[n - 1]; i++)
    {
        if (freq[i] != 0)
			cout << "Item " << i << " occurs "
                 << freq[i] << " times" << endl;
    }

	return 0;
}
