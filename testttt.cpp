#include <iostream>
int aaa(int a)
{
	return a + 2;
}


int main(int argc, char const *argv[])
{
	int b = 5;
	b = aaa(b);
	std::cout << b << std::endl;
	return b;
}
