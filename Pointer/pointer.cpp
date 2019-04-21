#include <iostream>
#include <string>
using namespace std;

const std::string SORT_DECREASE = "Decreasing";
const std::string SORT_INCREASE = "Increasing";


/* -------------- Advanced implementation ----------------------------
Description: To check whether the input string is only included the numeric only
Result: - Return True if yes
		- Return False if not
*/
inline bool isNumber(std::string sValue)
{
	for (auto& var : sValue)
	{
		if (var < '0' || var > '9')
		{
			return false;
		}
	}
	return true;
}

/* -------------- Advanced implementation ----------------------------
Description: This function is to check whether we want to increasing sort or descresing sort.
Result: - in case iFirstValue > iSecondValue: we want to wrap those 2 values -> It means we wanted the sort type will be increasing
		- another case, that is decreasing sort.
*/
inline std::string SortType(int iFirstValue, int iSecondValue)
{
	return iFirstValue > iSecondValue ? SORT_INCREASE : SORT_DECREASE;
}


// Hoan doi gia tri hai bien
void Swap(int *num1, int *num2)
{
	//your code here
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

// In mang
void PrintArray(int *arr, int n)
{
	//your code here
	for (int iOut = 0; iOut < n; ++iOut)
	{
		std::cout << *(arr + iOut) << " ";
	}
}

// Thuat toan sap xep noi bot
void BubbleSort(int *arr, int n, const std::string& sSortType)
{
	int i, j;
	int iCount1 = 1;
	//
	if (n < 2) return;	



	for (i = 1; i < n; ++i)
	{
		std::cout << "\n----- Thuc hien sap xep buoc " << i << " -------------" <<std::endl;
		for (j = 0; j < n - i; ++j)
		{
			//your code here
			if (SortType(*(arr + j), * (arr + j + 1)) == sSortType)
			{				
				Swap((arr + j), (arr + j + 1));
				// Print the steps
				std::cout << "Step " << i << "." << iCount1 << ": Mang sau khi thuc hien" << std::endl;
				PrintArray(arr, n);
				++iCount1;
				std::cout << endl;
			}
		}
		iCount1 = 1;
	}
}

// Thuat toan sap xep chon
void SelectionSort(int *arr, int n, const std::string& sSortType)
{
	int *i, *j;
	int *end = NULL;
	int iCount1 = 1;

	if (n < 2 || arr == NULL)
		return;

	end = arr + n - 1;
	
	for (i = arr; i < end; i++)
	{
		//your code here		
		// Step 1: Find the Minimum value in the array
		int *temp = i;
		for (j = i+1; j <= end; ++j)
		{
			//minTemp = *minTemp > * j ? j : minTemp;
			if (sSortType == SORT_INCREASE) // Find the minimum value
			{
				temp = *temp > * j ? j : temp;
			}
			else if (sSortType == SORT_DECREASE) // Find the maximum value
			{
				temp = *temp < * j ? j : temp;
			}
			
		}
		// Step 2: Swap the position of min value and i value
		//if (*temp < *i) Swap(i, temp);		
		if (SortType(*i, *temp) == sSortType)
		{
			Swap(i, temp);
		}
		
		std::cout << "Step " << iCount1++ << ": Mang sau khi thuc hien" << std::endl;	
		PrintArray(arr, n);
		std::cout << std::endl;
	}
}

int main()
{
	//int arr[10]; // Mang dau vao
	int *arr; // Mang dau vao
	int i;
	int n; // Kich thuoc mang
	int menu_option;

	cout << "Kich thuoc mang: ";
	//your code here
	cin >> n;
	arr = new int[n]; // Cap phat bo nho dong cho mang

	cout << endl << "Nhap mang dau vao: " << endl;
	//your code here
	std::string sTempValueCheck{ NULL };
	for (int iValue = 0; iValue < n; ++iValue)
	{
		do
		{
			std::cout << "arr[" << iValue << "] = ";			
			std::cin >> sTempValueCheck;

			// DEBUG			
			//std::cout << "sTempValueCheck = " << sTempValueCheck << std::endl;
			
			if (isNumber(sTempValueCheck))
			{
				*(arr + iValue) = std::stoi(sTempValueCheck);
				// DEBUG
				//std::cout << "*(arr + iValue) = " << *(arr + iValue) << std::endl;
			}	
			else
			{
				std::cout << "\n!!! Gia tri nhap vao '" << sTempValueCheck <<  "' khong phai la so nguyen" << "\n";
				std::cout << "!!! Moi nhap lai gia tri nay" << "\n";
			}
		} while (!isNumber(sTempValueCheck));
	}

	cout << endl << "Mang truoc khi sap xep: " << endl;
	//your code here
	PrintArray(arr, n);
	cout << endl;

	do {
		//your code here
		cout << "\n";
		std::cout << "Vui long chon thuat toan sap xep" << std::endl;
		std::cout << " 1. Thuat toan noi bot (Buddle sort) - Tang dan" << std::endl;
		std::cout << " 2. Thuat toan noi bot (Buddle sort) - Giam dan" << std::endl;
		std::cout << " 3. Thuat toan chon (Selection sort) - Tang dan" << std::endl;
		std::cout << " 4. Thuat toan chon (Selection sort) - Giam dan" << std::endl;
		cin >> menu_option;
	} while (menu_option != 1 && menu_option != 2 && menu_option != 3 && menu_option != 4);


	switch (menu_option) {
		case 1:
			//your code here
			BubbleSort(arr, n, SORT_INCREASE);
			break;
		case 2:
			//your code here
			BubbleSort(arr, n, SORT_DECREASE);
			break;
		case 3:
			//your code here
			SelectionSort(arr, n, SORT_INCREASE);
			break;
		case 4:
			//your code here
			SelectionSort(arr, n, SORT_DECREASE);
			break;

	}

	cout << endl << "Mang sau khi sap xep: " << endl;
	//your code here
	PrintArray(arr, n);
	cout << "\n";
	system("pause");
	delete[] arr;
	return 0;
}