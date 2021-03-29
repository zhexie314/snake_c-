#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{

	string s0,s1,s2;

	cout << "make a string:";
	cin >> s0;
	int len = s0.length() + 1;



	int i ,k ,n; 
	int * p_next = new int [len - 1];
	p_next[0] = -1;
	p_next[1] = 0;
	for (i = 3; i < len; i++)
	{

		for (k = 2; k < i; k++)
		{
			s1 = s0.substr(0, i - k);
			cout << s1 << endl;
			s2 = s0.substr(k - 1, i - k);
			cout << s2 << endl;
			if (s1 == s2)
				{
				n = i - k;
				break;
				}
			else 
				{
					n = 0;
				};
		}
		cout << "-------" << n << endl;
		p_next[i - 1] = n;
		cout << "######################" << endl;
	}
	for(int i = 0;i < len - 1;i++)
	{
	 cout << "next array [" << i << "] is " << p_next[i] << endl;
	}

	delete []p_next;
	return 0;
}






















