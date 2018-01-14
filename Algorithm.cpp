#include "Algorithm.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

Algorithm::Algorithm() 
{
	cout << "algirtm::algoritm()	";
	data.clear();
}

Algorithm::Algorithm(std::vector<std::vector<int>> Data)
{
	LoadData(Data);
}

Algorithm::Algorithm(char* Path)
{
	LoadData(Path);
}

int Algorithm::GetStrCount()
{
	return rows;
}

int Algorithm::GetColCount()
{
	return cols;
}

bool Algorithm::LoadData(vector<vector<int>> Data)
{
	data = Data;
	return true;
}

bool Algorithm::setOut(char* Path)
{	
	ofstream *file = new ofstream(Path, ios_base::out);
	if (!file->is_open())
		return false;
	sout = file;
	return true;
}

bool Algorithm::LoadData(char* Path)
{
	ifstream file(Path, ios_base::in);
	if (!file.is_open()) throw "Can't open data file";

        if (!file.is_open())                                                                                 
        {                                                                                                    
                cout << "Cannot open the file!" << endl;                                                     
                return 1;                                                                                    
        }                                                                                                    
                                                                                                             
        for (;;)                                                                                             
        {                                                                                                    
                                                                                                             
                if (file.eof())                                                                              
                        break;                                                                               
                                                                                                             
                string line;                                                                                 
                string cmd;                                                                                  
                                                                                                             
                getline(file, line);                                                                         
                istringstream sline = istringstream(line);                                                   
                                                                                                             
                sline >> cmd;                                                                                
                                                                                                             
                if (!sline.fail())                                                                           
                {                                                                                            
                        int cmd_num = 0;                                                                     
                        for (; cmd_num < 4 && dcmds[cmd_num] != cmd; cmd_num++) {}                           
                                                                                                             
                        switch (cmd_num)                                                                     
                        {                                                                                    
                                case 0: //size                                                               
                                        int r, c;                                                            
                                        sline >> r >> c;  
										if (r == 1 && c == 1) return false;
                                        if (!sline.fail())                                                   
                                        {                                                                    
                                                rows = r;                                                    
                                                cols = c;                                                    
                                                data.clear();                                                
                                                data.reserve(r);                                             
                                                for (int j = 0; j < r; j++)                                  
                                                {                                                            
                                                        vector<int> row;                                     
                                                        row.assign(c, 0);                                    
                                                        data.push_back(row);                                 
                                                }                                                            
                                        }                                                                    
                                break;                                                                       
                                case 1:                                                                      
                                        int row_num;                                                         
                                        sline >> row_num;                                                    
                                        row_num--;                                                           
					if (row_num >= data.size())
						continue;
                                        if (!sline.fail())                                                   
                                        {                                                                    
                                                vector<int> row;                                             
                                                row.reserve(cols);                                           
                                                for (int j = 0; j < cols; j++)                               
                                                {                                                            
                                                        int val;                                             
                                                        sline >> val;                                        
                                                        row.push_back(val);                                  
                                                }                                                            
                                                if (!sline.fail())                                           
                                                {                                                            
                                                        data[row_num] = row;                                 
                                                }                                                            
                                        }                                                                    
                                break;                                                                       
                                case 2:                                                                      
					if (data.size() == 0)
						continue;
					else
						if (data[0].size() == 0)
							continue;
					Run();	
                                break;                                                                       
                                case 3:   
					*sout << "Current matrix:" << endl;
					for (int j = 0; j < rows; j++)
					{
						for (int k = 0; k < cols; k++)
						{
							*sout << data[j][k] << "	";
						}
						*sout << endl;
					}
                                break;                                                                       
                                case 4:  
                                break;                                                                       
                                                                                                             
                        }                                                                                    
                }                                                                                           
	}
	return true;
}

void Algorithm::showMatrix(vector<vector<int>> temp)
{
        *sout << endl;
        *sout << "\t";
        for (int i = 0; i < temp[temp.size() - 1].size() - 1; i++) {
              *sout << temp[temp.size() - 1][i] << "\t";
        }
        *sout << endl;
        *sout << "\t";
        for (int i = 0; i < temp[0].size(); i++)
                for (int j = 0; j<6; j++) *sout << "_";
        *sout << endl <<endl;
        for (int i = 0; i < temp.size() - 1; i++) {
                *sout << temp[i][temp.size() - 1] << " | " << "\t";
                for (int j = 0; j < temp[i].size() - 1; j++)
                        if(temp[i][j] != INT32_MAX && j != temp.size() - 1) *sout << temp[i][j] << "\t";
                        else *sout << "inf" << "\t";
                *sout << endl;
        }
        *sout << endl << endl;
}

bool Algorithm::validateData() 
{
	return true;
}

void Algorithm::Run() 
{
	try {
		if (!validateData())
			throw logic_error("Not valid data");
	}
	catch (logic_error) {
		system("pause");
		exit(0);
	}
	*sout << name << ":" << std::endl;
}

