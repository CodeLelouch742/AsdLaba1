#include "Utils.h"

bool DEBUG = false;

string fileInput(string inputFileName)
{
    ifstream input_file;

    input_file.open(inputFileName.c_str());
    if (!input_file.is_open()) {
        if(DEBUG) {
            cout << "Не удалось открыть указанный файл, проверьте существует ли он" << endl;
        }
        return "NULL";
    }

    string text;
    getline(input_file, text, '\0');
    input_file.close();

    return text;
}

void fileOutput(string outputFileName, string text)
{
    ofstream output_file;

    output_file.open(outputFileName.c_str());
    if (!output_file.is_open()) {
        if(DEBUG) {
            cout << "Не удалось открыть указанный файл" << endl;
        }
    }

    output_file << text;
    output_file.close();
}

string inputString(string info)
{
    string input_string;
    cout << info << ": ";

    getline(cin >> ws, input_string);
    return input_string;
}

int inputInt(string info)
{
    return stoi(inputString(info));
}

double inputDouble(string info)
{
    return atof(inputString(info).c_str());
}

void printBreakLine()
{
    cout << "------------------------------------------------------------------" << endl;
}
