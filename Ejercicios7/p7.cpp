#include<iostream>

using namespace std;

int foo() {
	cout << "Esto va segundo" << endl;
	return 0;
}

int bar() {
	cout << "Esto va segundo" << endl;
	return 0;
}

int foobar(int x, int y)
{
	cout << "Esto va tercero" << endl;
	return 0;
}

int main()
{
	foobar(foo(), bar());	
}

