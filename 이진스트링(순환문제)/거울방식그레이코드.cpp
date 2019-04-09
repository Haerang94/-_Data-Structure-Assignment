// C++ program to generate n-bit Gray codes 
#include <iostream> 
#include <string> 
#include <vector> 
#include <time.h>

using namespace std;

vector<string> arr = { "0","1" };
vector<int>::iterator iter;
int n;
string input;



void generateGrayarr()
{
	
	if (n <= 0)
		return;

	
	int i, j,k;
	for (i = 2; i < (1 << n); i <<= 1)
	{
		
		for (j = i - 1; j >= 0; j--) {
			arr.push_back(arr[j]);
		}

	 
		for (j = 0; j < i; j++)
			arr[j] = "0" + arr[j];

		 
		for (j = i; j < (i<<1); j++)
			arr[j] = "1" + arr[j];
	}

	
	for (i = 0; i < (1 << n); i++) {
		if (arr[i] == input) {
			k = i;
			break;
		}
	}
	
	//rotate(arr.begin(), arr.begin() + k, arr.end());

	
		
		for (i = k; i < (1 << n); i++)
		{
			cout << arr[i] << endl;
		}
		if (k == 0) return;
		for ( i = 0; i < k; i++)
		{
			cout << arr[i] << endl;
		}
		

	//for (auto i: arr)
	//	cout << i << endl;
		
	

	


}

int main()
{

	
	cin >> n >> input;
	

	generateGrayarr();

	



	return 0;
}