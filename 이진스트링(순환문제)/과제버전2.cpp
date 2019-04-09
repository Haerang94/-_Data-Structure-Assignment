#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;
string input = "";
vector<string> arr;
int n = 0, i = 0, p = 0;


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

	p++;
	if (p == arr.size()) {
		int k;
		for ( i = 0; i < (1<<n); i++) {
			if (arr[i] == input) {
				k = i;
				break;
			}
		}

		for (auto a : arr)
			cout << a << endl;

	}
	
}




int main()
{
	
	cin >> n >> input;
	
	clock_t startTime, endTime;
	startTime = clock();
	bitString(n, "");

	endTime = clock();
	printf("수행 시간 : %f\n", ((double)(endTime - startTime) / (double)CLOCKS_PER_SEC));
	return 0;
}