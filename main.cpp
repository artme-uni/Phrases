#include "frequency.h"

int main(int argc, char *argv[])
{
    int m = 2;
    int n = 2;
    string text = "-";

    vector<string> line;

    for (int i = 1; i < argc; i++)
    {
        line.emplace_back(argv[i]);
    }

    for (int i = 0; i < argc - 1; i++)
    {
        if (line[i] == "-n")
        {
            n = stoi(line[i+1]);
            i++;
        }
        else if (line[i] == "-m")
        {
            m = stoi(line[i+1]);
            i++;
        }
        else
        {
            text = line[i];
        }
    }

    stringstream output;

    if (text == "-")
        phrases(cin, output, n, m);
    else
    {
        ifstream input(text);
        phrases(input, output, n, m);
        input.close();
    }

    cout << output.str();

    return 0;
}