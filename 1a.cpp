#include <iostream>
#include <cstdlib>
#include <omp.h>

using namespace std;

int main() {
	int th;
	cout << "Enter the number of threads: ";
	cin >> th;
	omp_set_num_threads(th);

	double t = omp_get_wtime();
	double pi=4;
	int n = 10000;
	int den;
	#pragma omp parallel for reduction(+:pi)
	for (int i = 0; i < n; i++) {
		den = i * 2 + 3;
		// (4 - 4/3 + 4/5 -4/7 + 4/9 -......)
		if (i % 2 == 0) {
		    pi = pi - (4.0 / den);
		}
		else {
		    pi = pi + (4.0 / den);
		}
	}

	t = omp_get_wtime() - t;

	cout << "Time: " << t << endl;
	cout << "no. of threads: " << th << endl;
	cout << "no. of trials: " << n << endl;
	cout << "est. of pi: " << pi << endl;
}
