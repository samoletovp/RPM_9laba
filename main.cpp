/**
* @file main.cpp
* @author Samoletov Petr <samoletovp@gmail.com>
* @brief Главный исполняемый файл(Поиск и вывод строк с двузначным числом)
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include "getline.h"

using namespace std;

int main()
{
    vector<string> matr;
    string tmp;
    ifstream fin("input.txt");
    while(!fin.eof())
    {
        char* r;
        r = getline(fin,0);
        if(r==NULL)
        {
            break;
        }
        tmp=r;
        matr.push_back(tmp);
    }
    for(size_t i = 0; i < matr.size(); ++i)
    {
        tmp = matr[i];
        bool flag = false;
        istringstream ist(matr[i]);
        while(ist >> matr[i])
            if (matr[i].length() == 2)
            {
                string c;
                c = matr[i];
                istringstream ss(c);
                int a;
                ss>>a;
                if(a!=0)
                {
                    flag = true;
                }
            }
        if(flag)
        {
            char* r;
            stringstream a(tmp);
            r = getline(a,1);
            cout << r <<" ";
        }
    }
    return 0;
}
