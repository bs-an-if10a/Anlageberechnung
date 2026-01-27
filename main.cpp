#include <windows.h>
#include <iomanip>
#include <iostream>
#include <math.h>

using namespace std;

int main() {
    // standart config stuff
    SetConsoleOutputCP(CP_UTF8);
    cout << fixed << setprecision(2);

    // vars
    float fGeld, fErgebnis, fZins = 0;
    int iTage;

    // title
    string title = "A n l a g e b e r e c h n u n g";
    cout << title << endl;
    for (int i = 0; i < title.length(); i++) {
        cout << "=";
    }

    cout << endl << endl;

    // userinput
    do {
        cout << "Geben Sie bitte den anzulegenden Geldbetrag ein: \t";
        cin >> fGeld;

        cout << "Geben Sie die Tage an der Anlage an (30,60,90): \t";
        cin >> iTage;

        if (iTage != 30 && iTage != 60 && iTage != 90) {
            cout << "Bitte korrekte Daten eingeben";
            system("cls");
        }
    } while (iTage != 30 && iTage != 60 && iTage != 90);

    if (fGeld < 100000) {
        switch (iTage) {
            case 30:
                fZins = 3.25;
                break;
            case 60:
                fZins = 3.30;
                break;
            case 90:
                fZins = 3.35;
                break;
        }
    } else {
        switch (iTage) {
            case 30:
                fZins = 3.30;
                break;
            case 60:
                fZins = 3.35;
                break;
            case 90:
                fZins = 3.50;
                break;
        }
    }

    // output
    fErgebnis = ((fGeld * fZins * iTage)/(100 * 365));
    cout << "Die Zinsen betragen bei dieser Anlage " << fErgebnis << " EUR";
    cout << endl << endl;

    system("pause");
    return 0;
}
