#include <iostream>
using namespace std;

string s_target;
string s_format;
int size00;
int size01;




int Brute_Force(string target, string format);


int main(int argc, char const *argv[])
{
cout << "make a target:" << endl;
getline(cin,s_target);
cout << "make a format:" << endl;
getline(cin,s_format);

size00 = s_target.size();
size01 = s_format.size();


// char * p_tar = s_target;
// char * p_for = s_format;

int n = Brute_Force(s_target,s_format);

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
			j = 0;
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