#include <sstream>
#include "frequency.h"

map<string, int> frequency;

int phrases(istream &input, ostream &output, int n, int m)
{
    vector<string> phrase_Arr(n);
    vector<string> suitable;


    string initial_St;
    for (int i = 0; i < n; i++)
    {
        input >> phrase_Arr[i];
        if (!input.good())
            return 0;

        initial_St += phrase_Arr[i] + " ";

        if (++frequency[initial_St] == m)
            suitable.push_back(initial_St);
    }


    string word;
    while (input >> word)
    {
        phrase_Arr.erase(phrase_Arr.begin());
        phrase_Arr.push_back(word);

        string phrase_St;
        for (int i = 0; i < n; i++)
        {
            phrase_St += phrase_Arr[i] + " ";
        }

        if (++frequency[phrase_St] == m)
            suitable.push_back(phrase_St);
    }

    std::sort(suitable.begin(), suitable.end(), comp());

    while (!suitable.empty())
    {
        output << suitable.back() << "(" << frequency[suitable.back()] << ")" << endl;
        suitable.pop_back();
    }

    return 0;
}