#include <iostream>

using namespace std;

int fun(int *k) {
	*k += 4;
	return 3 * (*k) - 1;
}

int main() {
	int i = 10, j = 10, sum1, sum2;

	//En cada ejecución de sum debido a que se pasa una dirección de memoria en *k += 4, la varianble aumenta en 4

        //sum1 = 46 = (10/2)+41
	sum1 = (i / 2) + fun(&i);

	//sum2 = 48 = 41 + (14/2)
	sum2 = fun(&j) + (j / 2);

	cout << "SUM 1: " << sum1 << endl;
	cout << "SUM 2: " << sum2 << endl;
}
