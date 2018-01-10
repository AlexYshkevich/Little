#pragma once
#include "Algorithm.h"

using namespace std;

class LittleAlgorithm : public Algorithm
{
public:
	LittleAlgorithm();
	LittleAlgorithm(vector<vector<int>>);
	LittleAlgorithm(char*);
	virtual void Run();
private:
	vector<pair<int,int>> result;
	enum check{Row, Col};
	int getMin(vector<vector<int>>, int, check);
	void matrixProcedure(vector<vector<int>>);
	int getResultSum();
	const int aver_speed = 6;
	virtual bool validateData();
};

