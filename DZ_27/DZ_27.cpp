#include <iostream>
#include <array>
#include <stdlib.h>

using namespace std;

void NewArray(int** parr, int** parr1, int s1, int s2)
{
    for (int i = 0; i < s2; i++) {
        for (int j = 0; j < s1; j++) {
            parr1[i][j] = parr[j][i];
        }
    }
}

int main()
{
    //1
    int m1, m2;
    cout << "Rows: ";
    cin >> m1;
    cout << "Cells: ";
    cin >> m2;
    int** pArr = new int* [m1];

    for (int i = 0; i < m1; i++) 
        pArr[i] = new int[m2];

    int c = 0;
    for (int j = 0; j < m1; j++) {
        for (int k = 0; k < m2; k++)
        {
            pArr[j][k] = c;
            c++;
            cout << pArr[j][k] <<" ";
        }
        cout << endl;
    }
    cout << endl;
    int** pArr1 = new int* [m2];
    for (int i = 0; i < m2; i++)
        pArr1[i] = new int[m1];
    NewArray(pArr, pArr1, m1, m2);
    for (int n = 0; n < m2; n++) {
        for (int l = 0; l < m1; l++) {
            cout << pArr1[n][l] << " ";
        }
        cout << endl;
    }
    
    //2
    int size1 = 2, size2 = 20, size3 = 200;
    char*** pBook = new char** [size1];
    for (int i = 0; i < size1; i++) {
        pBook[i] = new char* [size2];
        for (int d = 0; d < size2; d++)
            pBook[i][d] = new char[size3];
    }
    enum Action { FindNumber = 1, FindName, Enter, Edit, Quit };
    int UserChoice;
    char UserNum[200];
    char UserName[200];
    do {
        cout << "Your choice:\n";
        cout << "1 - find number\n";
        cout << "2 - find name\n";
        cout << "3 - enter data\n";
        cout << "4 - edit data\n";
        cout << "5 - quit\n";
        cin >> UserChoice;
        switch (UserChoice)
        {
        case FindNumber:
        {
            cout << "Enter phone number: ";
            scanf("%*c");
            fgets(UserNum, 200, stdin);
            int t = 0;
            for (int j = 0; j < size2; j++) {
                if (pBook[1][j] == UserNum) {
                    cout << "Name: " << pBook[0][j] << endl;
                    cout << "Number: " << pBook[1][j] << endl;
                    t++;
                }
            }
            if (t == 0)
                cout << "Nothing found!" << endl;
            break;
        }
        case FindName:
        {
            int t = 0;
            cout << "Enter name: ";
            scanf("%*c");
            fgets(UserName, 200, stdin);
            for (int j = 0; j < size2; j++) {
                if (pBook[0][j] == UserName) {
                    cout << "Name: " << pBook[0][j] << endl;
                    cout << "Number: " << pBook[1][j] << endl;
                    t++;
                }
            }
            if (t == 0)
                cout << "Nothing found!" << endl;
            break;
        }
        case Enter:
        {
            int t = 0;
            for(int k = 0; k < size2; k++)
                if (strlen(pBook[0][k])-204 == 0) {
                    cout << "Enter the name: ";
                    scanf("%*c");
                    fgets(UserName, 200, stdin);
                    pBook[0][k] = UserName;
                    cout << "Enter phone number: ";
                    scanf("%*c");
                    fgets(UserNum, 200, stdin);
                    pBook[1][k] = UserNum;
                    t++;
                    break;                    
                }
            if (t == 0)
                cout << "There is no place!" << endl;
            break;
        }
        case Edit:
        {
            int ch;
            cout << "1 - edit number\n";
            cout << "2 - edit name\n";
            cin >> ch;
            if (ch == 1) {
                cout << "Enter old phone number: ";
                scanf("%*c");
                fgets(UserNum, 200, stdin);
                for (int j = 0; j < size2; j++) {
                    if (pBook[1][j] == UserNum) {
                        cout << "Enter new phone number: ";
                        scanf("%*c");
                        fgets(UserNum, 200, stdin);
                        pBook[1][j] = UserNum;
                        break;
                    }
                }
            }
            else if (ch == 2) {
                
                cout << "Enter old name: ";
                scanf("%*c");
                fgets(UserName, 200, stdin);
                for (int j = 0; j < size2; j++) {
                    if (pBook[0][j] == UserName) {
                        cout << "Enter new name: ";
                        scanf("%*c");
                        fgets(UserName, 200, stdin);
                        pBook[0][j] = UserName;
                        cout << UserName << endl;
                        break;
                    }
                }
            }
            break;
        }
        case Quit:
        {
            cout << "See you!";
            break;
        }
        default:
            cout << "Invalid command!";
        }
    } while (UserChoice != 5);
    return 0;
}
