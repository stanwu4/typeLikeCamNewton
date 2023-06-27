#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

// hash table to convert
unordered_map<char, string> myTable = {
    {'A', "Ä"},
    {'B', "ß"},
    {'C', "C"},
    {'D', "D"},
    {'E', "£Ē"},
    {'F', "F"},
    {'G', "G"},
    {'H', "H"},
    {'I', "ÎÏĮ1"},
    {'J', "J"},
    {'K', "K"},
    {'L', "Ł"},
    {'M', "M"},
    {'N', "Ń"},
    {'O', "Ø"},
    {'P', "₽"},
    {'Q', "Q"},
    {'R', "R"},
    {'S', "§"},
    {'T', "T"},
    {'U', "Ü"},
    {'V', "V"},
    {'W', "₩"},
    {'X', "X"},
    {'Y', "¥Ÿ"},
    {'Z', "Ž"},
    {'a', "á"},
    {'b', "b"},
    {'c', "č"},
    {'d', "d"},
    {'e', "ē"},
    {'f', "f"},
    {'g', "g"},
    {'h', "h"},
    {'i', "ï"},
    {'j', "j"},
    {'k', "k"},
    {'l', "ł"},
    {'m', "m"},
    {'n', "ñ"},
    {'o', "ø"},
    {'p', "p"},
    {'q', "q"},
    {'r', "r"},
    {'s', "š"},
    {'t', "t"},
    {'u', "ū"},
    {'v', "v"},
    {'w', "w"},
    {'x', "x"},
    {'y', "ÿ"},
    {'z', "ż"},

};

string convert(int iType, int yType, string input)
{
    string output = "";
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] >= 65 && input[i] <= 90 || input[i] >= 97 && input[i] <= 122)
        {
            if (input[i] == 'I')
            {
                output += myTable[input[i]][iType];
            }
            if (input[i] == 'I')
            {
                output += myTable[input[i]][yType];
            }
            output += myTable[input[i]];
        }
        else
        {
            output += input[i];
        }
    }
    return output;
}

int main()
{
    string input;
    string output;
    int iType;
    int yType;
    bool validInput = false;
    // generating what types of I and Y's the user wants to use within their text, also error checking for valid input
    while (!validInput)
    {
        cout << "Which type of I do you want in your text? (select by entering number corresponding to the order)"
             << " Î Ï Į 1" << endl;
        cin >> iType;
        if (iType > 0 && iType <= 4)
        {
            validInput = true;
        }
        else
        {
            cout << "Try again with a number 1-4" << endl;
            cin.clear();
        }
    }
    while (!validInput)
    {
        cout << "Which type of Y do you want in your text? (select by entering number corresponding to the order)"
             << " ¥ Ÿ" << endl;
        cin >> yType;
        if (yType > 0 && yType <= 2)
        {
            validInput = true;
        }
        else
        {
            cout << "Try again with a number 1-2" << endl;
            cin.clear();
        }
    }
    // indexing for array
    iType--;
    yType--;
    cout << "Enter the text you want to convert:" << endl;
    cin >> input;
    output = convert(iType, yType, input);
    cout << "This is how Cam Newton would type your message: " << endl;
    cout << output << endl;
    return 0;
}