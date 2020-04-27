/**
 * @file getline.h
 * @author Samoletov Petr <samoletovp@gmail.com>
 * @brief Чтение предложений из файла
 */

#include <iostream>
#include <cstring>

using namespace std;

char* getline(std::istream& _in, int q)
{
    char   c;
    size_t i, n  = 3;
    char*  t, *s = NULL;
    for(i = 0; _in.get(c) && !_in.fail(); )
    {
        if((c == '.')||(c==';')||(c=='?')||(c=='!')||(c=='\n'))
        {
            if(q==0)
            {
                s[i++] = ' ';
                s[i++] = c;
                break;
            }
            else
            {
                s[i-1] = c;
                break;
            }
        }
        if(s == NULL)
        {
            s = new (std::nothrow) char[n];
            if(s == NULL)
            {
                return NULL;
            }
        }
        else if((i + 1) >= n)
        {
            t = new (std::nothrow) char[i * 3 / 2];
            if(t == NULL)
                break;
            std::memcpy(t, s, n * sizeof(char));
            delete[] s;
            s = t;
            n = i * 3 / 2;
        }
        s[i++] = c;
    }
    if(s!= NULL)
    {
        s[i++] = '\0';
    }
    return s;
}