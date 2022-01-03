#include "ScoreManager.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <string>

using namespace std;

class ScoreManagerTest
{
    ScoreManager sm;

public:
    void setUp()
    {
        sm = ScoreManager();
    }

    bool testWithTestCase(string input, string output)
    {
        bool res = true;
        setUp();
        auto rollPinsString = stringSplit(input, " ");
        auto frameScoresString = stringSplit(output, " ");

        for (size_t index = 0; index < rollPinsString.size(); index++)
        {
            auto rollPins = rollPinsString[index];
            int pins = stoi(rollPins);
            sm.roll(pins);
        }
        sm.score();
        for (int frame = 1; frame < 11; frame++)
        {
            cout << "Expected: " << stoi(frameScoresString[frame - 1]) << "---";
            cout << "Actual: " << sm.frameScores[frame];
            if (sm.frameScores[frame] != stoi(frameScoresString[frame - 1]))
            {
                res = false;
                cout << " XXXXXXXXXXXX";
            }

            cout << endl;
        }

        return res;
    }

private:
    void rollMany(int n, int pins)
    {
        for (int i = 0; i < n; i++)
            sm.roll(pins);
    }

    vector<string> stringSplit(string input, string delimiter)
    {
        vector<string> res;
        size_t pos = 0;
        std::string token;
        while ((pos = input.find(delimiter)) != std::string::npos)
        {
            token = input.substr(0, pos);
            res.push_back(token);
            input.erase(0, pos + delimiter.length());
        }
        res.push_back(input);

        return res;
    }
};

void getTestCases(vector<string> &inputs, vector<string> &outputs);

int main(int argc, char const *argv[])
{
    ScoreManagerTest test;
    vector<string> inputs;
    vector<string> outputs;
    getTestCases(inputs, outputs);
    bool res;
    for (size_t i = 0; i < inputs.size(); i++)
    {
        string input = inputs[i];
        string output = outputs[i];
        cout << "Input " << (i + 1) << ": " << input << endl;
        cout << "Output " << (i + 1) << ": " << output << endl;
        res = test.testWithTestCase(input, output);
        if (res)
        {
            cout << "Pass";
        }
        else 
        {
            cout << "Failed";
        }
        cout << endl;
        }

    return 0;
}

void getTestCases(vector<string> &inputs, vector<string> &outputs)
{
    ifstream ifs;
    ifs.open("TestCases.txt", ios::in);
    char ch;
    string s = "";
    bool isInput = true;
    while (ifs >> noskipws >> ch)
    {
        if (ch == '\n')
        {
            if (isInput)
                inputs.push_back(s);
            else
                outputs.push_back(s);
            s = "";
            isInput = !isInput;
        }
        else
        {
            s += ch;
        }
    }
    ifs.close();
}
