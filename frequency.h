#ifndef CPP_TASK1_FREQUENCY_H
#define CPP_TASK1_FREQUENCY_H

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>

using namespace std;

extern map<string, int> frequency;

struct comp
{
    bool operator()(string a, string b)
    {
        return frequency[b] > frequency[a];
    }
};

int phrases(istream &input, ostream & output, int n, int m);

#endif //CPP_TASK1_FREQUENCY_H
