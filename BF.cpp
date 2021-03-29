#include <iostream>
using namespace std;

char s_target[100];
char s_format[100];
int size00;
int size01;



void Brute_Force(char * target, char * format);


int main(int argc, char const *argv[])
{
cout << "make a target:" << endl;
cin.getline(s_target, 100);
cout << "make a format:" << endl;
cin.getline(s_format, 100);

size00 = strlen(s_target);
size01 = strlen(s_format);


char * p_tar = s_target;
char * p_for = s_format;
Brute_Force(p_tar,p_for);

	return 0;
}



void Brute_Force(char * target, char * format)
{
	int n = 0;
	for(int i = 0;i < size00;i++)
	{
		int j;
		if(j == size01)
		{
			n = i - size01;
			cout << "find = " << n << endl;
			return;
		}
		if (*(target + i) != *(format + j))
		{
			j = 0;
		}
		else
		{
			j++;
		}
		cout << i << endl;
		cout << j << endl;
		cout << "*************" << endl;
	}
}