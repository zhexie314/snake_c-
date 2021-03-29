#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{

	string s0,s1,s2;

	cout << "make a string:";
	cin >> s0;
	int len = s0.length() + 1;



	int i ,k ,n; 
	for (i = 3; i < len; i++)
	{

		k = 2;
		do
		{
			if (k < i)
			{
				s1 = s0.substr(0, i - k);
				cout << s1 << endl;
				s2 = s0.substr(k - 1, i - k);
				cout << s2 << endl;
				k++;
			}
			else break;

		}
		while (s1 != s2);

		n = i - k;
		cout << "-------" << n << endl;


		cout << "######################" << endl;
	}

	return 0;
}


