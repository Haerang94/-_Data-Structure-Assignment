#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;
string input = "";
vector<string> arr;
int n = 0;


void print_gray(string binary)
{
	string shift = "0", gray = "";
	shift += binary;
	for (int i = 0; i< binary.length(); i++)
		if (binary[i] != shift[i])
			gray += "1";
		else
			gray += "0";
	
	arr.push_back(gray);
	
	
}





void bitString(int x, string prefix)
{
	
	if (x == 0) {
		
		print_gray(prefix);
		
	}

	else
	{
		bitString(x - 1, (prefix + "0"));
		bitString(x - 1, (prefix + "1"));
	}


	
}

void print() {
	int k;

	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == input) {
			k = i;
			break;
		}
	}

	if (k == 0) {
		for (int i = 0; i < arr.size(); i++)
		{
			cout << arr[i] << endl;
		}
	}
	else if (k == arr.size() - 1) {
		cout << arr[k] << endl;
		for (int i = 0; i < arr.size() - 1; i++)
		{
			cout << arr[i] << endl;
		}
	}
	else {
		for (int i = k; i < arr.size(); i++)
		{
			cout << arr[i] << endl;
		}
		for (int i = 0; i < k; i++)
		{
			cout << arr[i] << endl;
		}

	}
}


int main()
{
	
	cin >> n >> input;
	
	clock_t startTime, endTime;
	startTime = clock();
	bitString(n, "");
	print();
	endTime = clock();
	printf("수행 시간 : %f\n", ((double)(endTime - startTime) / (double)CLOCKS_PER_SEC));
	return 0;
}