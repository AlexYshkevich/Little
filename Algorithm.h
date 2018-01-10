#pragma once
#include <string>
#include <vector>
#include <iostream>

class Algorithm
{
public:
	const char* name = "Algorithm";
	Algorithm();
	Algorithm(std::vector<std::vector<int>>);
	Algorithm(char*);
	void showMatrix(std::vector<std::vector<int>>);
	bool setOut(char*);
	bool LoadData(std::vector<std::vector<int>>);
	bool LoadData(char*);
	virtual void Run();
protected:
	std::vector<std::vector<int>> data;
	int GetStrCount();
	int GetColCount();
	int rows, cols;
	virtual bool validateData();
	std::ostream *sout;
	const std::string dcmds[4] = {"size", "line", "start", "show"};
};

