#include <stdio.h>
#include <unistd.h>
#include <iostream>
using namespace std;

int main()
{
	printf("hello world.\n");

	int errNumb = 0;
	int* const curErr = &errNumb;

	if (!errNumb) {
		cerr << "error" << endl;
	}

	sleep(20);

	return 0;
}