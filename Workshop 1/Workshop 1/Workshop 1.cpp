// Workshop 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    /*
    // Task 1.1
    cout << "Task 1.1\n--------\n\n";
    cout << "Enter the number of stars: ";
    int stars;
    cin >> stars;

    for (int x = 0; x < stars; x++) {
        for (int i = 0; i < (x+1); i++) {
            cout << "*";
        }
        cout << endl;
    }

    string aMap[5][5];
    for (int x = 0; x < 5; x++) {
        for (int i = 0; i < 5; i++) {
            string boolValue = "";
            if (x == 0 || x == 4) {
                boolValue = "-";
            }
            else if ((rand() % 2) == 1) {
                if (i == 0 || i == 4) {
                    boolValue = "|";
                }
                else {
                    boolValue = "*";
                }
            }
            else {
                boolValue = " ";
            }
            aMap[x][i] = boolValue;
        }
    }

    for (int x = 0; x < 5; x++) {
        for (int i = 0; i < 5; i++) {
            cout << aMap[x][i];
        }
        cout << endl;
    }
    */


    /*
    // Task 1.2

    string s1 = "";
    string s2 = "";
    string conclusion = "";

    cout << "Task 1.2";

    cout << endl << "Enter the first string: ";
    cin >> s1;
    cout << endl << "Enter the Second string: ";
    cin >> s2;
   
    for (int i = 0; i < (s1.length()); i++) {
        string newS1 = "";
        int xPos = 0;
        for (int x = 0; x < (s1.length()); x++) {
            if (x != i) {
                newS1.insert(xPos, 1, s1[x]);
            }
            else {
                xPos -= 1;
            }
            xPos++;
        }
        if (newS1 == s2) {
            conclusion = "True";
            break;
        }
        else if (i == s1.length()-1) {
            conclusion = "False";
        }
    }
    cout << endl << s1 << " - " << s2 << "       returns " << conclusion;
    */

    // Task 1.3

    string diceInput = "";
    cout << "Enter your dice numbers"
}
































































// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
