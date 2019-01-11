// This program accepts user input to a vector of a length determined by the user, 
// sorts the numbers from least to greatest using the Quicksort algorithm, then
// displays the results to the user.

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

// quickSort function prototype
vector<int> quickSort(vector<int> x, int low, int high);

int main()
{
	// vector declaration
	vector<int> x;
	int vectorLength;

	// get user input
	cout << "\n     Enter the number of integers your list: ";
	cin >> vectorLength;
	cout << "\n     *** NOTE: ONLY ENTER INTEGER VALUES -- NO DECIMALS ***";
	x.resize(vectorLength);
	for (int i = 0; i < vectorLength; i++)
	{
		cout << "\n     (" << i+1 << ") Enter number: ";
		cin >> x[i];
	}

	if (vectorLength > 0)
	{
		// perform the Quicksort on the vector x
		x = quickSort(x, 0, vectorLength - 1);


		// display the newly sorted vector x, from element 0 to element vectorLength-1
		cout << "\n\n     QUICKSORTED RESULT:\n\n";
		for (int i = 0; i < vectorLength; i++)
		{
			cout << "                 " << x[i] << "\n";
		}
	}
	else
	{
		cout << "\n\n     ERROR: There must be at least 1 number in your list. Program terminated.\n";
	}

	cin.ignore(); cin.ignore();

	return 0;
}


vector<int> quickSort(vector<int> x, int low, int high)
// takes the vector x, performs a quickSort, and returns the sorted vector
{

	vector<int> localVector;
	int partitionIndex;
	int a, b;

	// copy the vector x to the vector localVector
	localVector.resize(x.size());
	for (int i = 0; i < x.size(); i++) { localVector[i] = x[i]; }

		if (low < high)
		{

			a = low - 1;

			for (b = low; b <= high - 1; b++)
			{
				if (localVector[b] <= x[high])
				{
					a++;
					// swap elements a and b
					if (a != b)
					{
						localVector[a] = localVector[a] + localVector[b];
						localVector[b] = localVector[a] - localVector[b];
						localVector[a] = localVector[a] - localVector[b];
					}
				}
			}
			// swap elements a+1 and high
			if (a + 1 != high)
			{
				localVector[a + 1] = localVector[a + 1] + localVector[high];
				localVector[high] = localVector[a + 1] - localVector[high];
				localVector[a + 1] = localVector[a + 1] - localVector[high];
			}

			partitionIndex = a + 1;
			localVector = quickSort(localVector, low, partitionIndex - 1);
			localVector = quickSort(localVector, partitionIndex + 1, high);
		}

	return localVector;
}