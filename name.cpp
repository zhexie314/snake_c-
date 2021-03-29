// #include <iostream>
// using namespace std;

// int main(int argc, char const *argv[])
// {
// 	cout << "enter the world's population: ";
// 	long long int world_population,US_population;
// 	cin >> world_population;
// 	cout << "enter the population of the US: ";
// 	cin >> US_population;
// 	float rate;
// 	rate = (float) US_population/ (float) world_population * 100;
// 	cout << "the population of the US is " << rate << " % of the world population.\n";
// 	return 0;
// }


// #include <iostream>
// using namespace std;

// int main(int argc, char const *argv[])
// {

// 	// int ab = 54;
// 	// int* pad ;
// 	// pad = &ab;
// 	// int * * ppad = &pad;
// 	char * p123 ="1234";


// 	char [5]{'1', '2', '3', '4', '\0'}

// 	cout << p123;

// 	// cout << "pad = " << pad << endl;
// 	// cout << "*pad = " << *pad << endl;
// 	// cout << "**ppad = " << **ppad << endl;
// 	return 0;
// }


// #include <iostream>
// using namespace std;

// int main(int argc, char const *argv[])
// {

// 	char first_name [20];


// 	cout << "what is your first name?";
// 	cin.getline(first_name, 20);
// 	int * size = new int (strlen(first_name) + 1);

// 	cout << * size;

// 	delete size;



// 	return 0;
// }



// #include <iostream>
// using namespace std;

// int main(int argc, char const *argv[])
// {

// 	char * p;


// 	cout << "what is your first name?";
// 	cin.getline(first_name, 20);
// 	int * size = new int (strlen(first_name) + 1);

// 	cout << * size;

// 	delete size;



// 	return 0;
// }




// #include <iostream>
// using namespace std;

// int main(int argc, char const *argv[])
// {
// 	const int size = 20;
// 	char first_name [size];
// 	char last_name [size];
// 	char letter;
// 	int age;

// 	cout << "what is your first name?:";
// 	cin.getline(first_name, size);
// 	cout << "what is your last name?:";
// 	cin.getline(last_name, size);
// 	cout << "what letter grade do you deserve?:";
// 	cin >> letter;
// 	letter = letter + 1;
// 	cout << "what is your age?:";
// 	cin >> age;
// 	cout << "name:" << first_name << " , "<<last_name << endl;
// 	cout << "grade:" << letter << endl;
// 	cout << "age:" << age << endl;
// 	return 0;
// }




// #include <iostream>
// using namespace std;

// int main(int argc, char const *argv[])
// {
// 	char first_name [20];
// 	char last_name [20];
// 	char name [20];

// 	cout << "what is your first name?:";
// 	cin.getline(first_name, 20);
// 	cout << "what is your last name?:";
// 	cin.getline(last_name, 20);

// 	strcpy(first_name + strlen(first_name)," ,");
// 	strcpy(first_name + strlen(first_name),last_name);
// 	cout << "your name is:" << first_name << endl;
// 	return 0;
// }




// #include <iostream>
// using namespace std;

// 	char first_name[20];
// 	char letter;
// 	char* pstr = first_name;
// 	int find_letter();

// int main(int argc, char const *argv[])
// {


// 	cout << "what is your first name?:";
// 	cin.getline(first_name,20);
// 	cout << "what is your letter:";
// 	cin >> letter;
// 	// find_letter();
// 	find_letter();
// 	return 0;
// }



// 	int find_letter()
// 	{
// 		bool find_n = 0;
// 		for(int n = 0; n < strlen(first_name);n++)
// 		{
// 			char find = *(pstr + n);
// 			if (find == letter)
// 			{
// 			cout << n + 1 << endl;
// 			find_n = 1;
// 			}
			
		
// 		}
// 	if (!find_n)
// 	{
// 	cout << "nothing find" << endl;
// 	}
// 	}



#include <iostream>
using namespace std;

void find_letter(char i,const char* pstr);

int main(int argc, char const *argv[])
{
	string first_name;
	char letter;
	const char* pstr = first_name.c_str();


	cout << "what is your first name?:";
	getline(cin,first_name);
	cout << "what is your letter:";
	cin >> letter;
	// find_letter();
	find_letter(letter,pstr);
	return 0;
}



	void find_letter(char i,const char* pstr)
	{
		bool find_n = 0;
		for(int n = 0; n < strlen(pstr);n++)
		{
			if (*(pstr + n) == i)
			{
			cout << n + 1 << endl;
			find_n = 1;
			}
		}
		if (!find_n)
		{
		cout << "nothing find" << endl;
		}
	}







