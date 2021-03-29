#include <iostream>
// #include <array>
using namespace std;


string s_target;
string s_format;
int size00;
int size01;
int n = 0;
int * _next;



int Brute_Force(string target, string format);
void result(int n);
void get_next(string format, int size01);



int main(int argc, char const *argv[])
{

	cout << "make a target:" << endl;
	getline(cin,s_target);
	cout << "make a format:" << endl;
	getline(cin,s_format);

	size00 = s_target.size();
	size01 = s_format.size();
	_next = new int [size01];

	get_next(s_format, size01);
	n = Brute_Force(s_target,s_format);
	result(n);

	delete [] _next;
	return 0;
}



int Brute_Force(string target, string format)
{
	int n = 0;
	for(int i = 0;i < size00;i++)
	{
		int j;
		if(j == size01)
		{
			n = i - size01;
			// cout << "find = " << n << endl;
			return n;
		}
		if (target [i] != format [j])
		{
			j = _next[j];
			// cout << "j = "<< j << endl;
		}
		else
		{
			j++;
		}
		// cout << i << endl;
		// cout << j << endl;
		// cout << "*************" << endl;
	}
	return n;
}



void result(int n)
{
	if (n!= 0)
	{
		string ss_target = s_target.insert(n, 1,'\'');
		ss_target.insert((n + size01 + 1),1,'\'');
		cout << ss_target << endl;
	}
	else
	{
		cout << "find nothing" << endl;
	}
}





void get_next(string format, int size01)
{

	string s0,s1,s2;

	s0 = format;

	int len = size01 + 1;



	int i ,k ,n; 
	// int * p_next = new int [len - 1];
	_next[0] = 0;
	_next[1] = 0;
	for (i = 3; i < len; i++)
	{

		for (k = 2; k < i; k++)
		{
			s1 = s0.substr(0, i - k);
			// cout << s1 << endl;
			s2 = s0.substr(k - 1, i - k);
			// cout << s2 << endl;
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
		// cout << "-------" << n << endl;
		_next[i - 1] = n;
		// cout << "######################" << endl;
	}
	// for(int i = 0;i < len - 1;i++)
	// {
	//  cout << "next array [" << i << "] is " << _next[i] << endl;
	// }
}

