#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;
string input = "";
vector<string> arr;
int n = 0;
int i = 0,p=0,k;

void print_gray(string binary)
{
	string shift = "0", gray = "";
	shift += binary;
	for (i = 0; i< binary.length(); i++)
		if (binary[i] != shift[i])
			gray += "1";
		else
			gray += "0";

	arr.push_back(gray);

	
	if (gray == input) k = p;

	p++;

	if (p == (1 << n)) {

		rotate(arr.begin(), arr.begin() + k, arr.end());


		for (i = 0; i < (1 << n); i++)
			cout << arr[i] << endl;
			
	}




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



int main()
{

	cin >> n>>input;

	bitString(n, "");
	
	return 0;
}