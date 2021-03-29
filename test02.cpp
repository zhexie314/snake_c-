#include <iostream>
using namespace std;

int* getnext(char* pname);


int main(int argc, char const *argv[])

{
	char obj [10] = "abaa";
	char * pstr = & obj;
	getnext(pstr);
	return 0;
}

int* getnext(char * pstr)
{

	int * p1 = new int [strlen(*pstr)]
	p1[0] = -1;
	p1[1] = 0;
	int n;
	int len = strlen(*pstr)
	for (int i =3; i < len; i++) 
	{
		string s1,s2;
		for (int j = 1,j < i,j++)
		{
			strncopy(s1,pstr,i);
			strncopy(s2,(pstr - j),i);
			if (s1 == s2)
			{
				n = j + 1;
				break;
			}
		}
		p1[i] = n;
		s1.clear();
		s2.clear();
	}
cout << p1[0] << endl;
cout << p1[1] << endl;
cout << p1[2] << endl;
cout << p1[3] << endl;
}


