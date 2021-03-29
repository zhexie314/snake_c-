// #include <iostream>

// using namespace std;

// const int ft2in = 12;
// const float in2m = 0.0254;
// const float p2kg = 2.2;
// int main()
// {
// 	int feet,inche,weight_p;
// 	cout << "enter your feet :___\b\b\b";
// 	cin >> feet;
// 	cout << "enter your inches :___\b\b\b";
// 	cin >> inche;
// 	cout << "enter your weight :___\b\b\b";
// 	cin >> weight_p;
// 	float m;
// 	double weight_k;
// 	m = inche * in2m;
// 	weight_k = weight_p / p2kg;
// 	cout << "your bmi is:" << weight_k / (m * m) << endl;
// 	return 0;
// }



// #include <iostream>
// using namespace std;

// int a;

// int main(int argc, char const *argv[])
// {
// 	int size = 4;
// 	int * ptr = new int [size];
// 	for (int i = 0; i < size; i++)
// 	{
// 		cout << "make a number:" << endl;
// 		cin >> ptr[i];
// 	}
// 	delete [] ptr;
// 	cout << ptr << endl;
// 	return 0;
// }


#include <iostream>
using namespace std;

int a;

int main(int argc, char const *argv[])
{
	string str = "meihao";
	str.insert(0,2,'a');

	cout<<str<<endl;
	// cout<<(str == sstr) <<endl;

	return 0;
}