#include <iostream>
#include <stdlib.h>
#include "LittleAlgorithm.h"

using namespace std;

int main(int argc, char *argv[])
{
	
	if (argc == 1 || argc > 3)
	{
		cout << "Sorry, must have command files as the first and second arguments!" << endl;
		system("pause");
		return 1;
	}
	
	Algorithm* method = new LittleAlgorithm();

	if (argc == 3)
		method->setOut(argv[2]);
	
	method->LoadData(argv[1]);	
	system("pause");
	return 0;
}

