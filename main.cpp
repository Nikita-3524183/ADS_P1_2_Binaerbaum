/*************************************************
 * ADS Praktikum 1.2
 * main.cpp
 *
 *************************************************/
#define CATCH_CONFIG_RUNNER
#include "Tree.h"
#include "catch.h"
#include <iostream>

using namespace std;

///////////////////////////////////////
// Hilfsmethoden fürs Menü hier:

/***************************
 ** Vorgegebene  Funktion **
 ***************************
   "mainscreen_addTreeCSV" 
 
Importiert CSV Datei in bestehenden Baum.
Bei Aufruf in der main() Methode, muss der Pointer auf den Anker des Baums, als Parameter übergeben werden.
Es wird die im gleichen Verzeichnis liegende Datei "ExportZielanalyse.csv" geladen.
****************************/

void mainscreen_addTreeCSV(Tree*& ref)
{
    char j;
    cout << "+ Moechten Sie die Daten aus der Datei ExportZielanalyse.csv "
            "importieren(j / n) ? >";
    cin >> j;
    if (j == 'j')
    {
        ifstream csvread;
        csvread.open("ExportZielanalyse.csv", ios::in);
        if (!csvread.is_open())
        {
            cout << "Fehler beim Lesen!" << endl;
            return;
        }
        else
        {
            string name, age, postcode, income;

            while (!csvread.eof())
            {
                getline(csvread, name, ';');
                getline(csvread, age, ';');
                getline(csvread, income, ';');
                getline(csvread, postcode, '\n');
                ref->addNode(name, stoi(age), stod(income), stoi(postcode));
            }
            csvread.close();
        }
        cout << "+ Daten wurden dem Baum hinzugefuegt." << endl;
    }
}

void menu(){
    cout << "1. Daten aus CSV-Datei importieren" << endl;
    cout << "2. Daten hinzufuegen, manuell" << endl;
    cout << "3. Daten loeschen" << endl;
    cout << "4. Daten suchen" << endl;
    cout << "5. Daten ausgeben (pre/post/in)" << endl;
    cout << "6. Level Order ausgabe" << endl;
    cout << "7. Programm beenden" << endl;
    cout << "?> ";

}

//
///////////////////////////////////////
int main()
{

    int result =  0;
    result =Catch::Session().run();
    Tree* tree = new Tree();
    int input = 0;
    string name;
    int age;
    double income;
    int postcode;
    int nodeOrderID;


    while (input != 7)
    {
        menu();
        
        cin >> input;
        switch (input)
        {
        case 1:
            mainscreen_addTreeCSV(tree);
            break;
        case 2:           
            cout << "Name ?>";
            cin >> name;
            cout << "Alter ?>";
            cin >> age;
            cout << "Einkommen ?>";
            cin >> income;
            cout << "Postleitzahl ?>";
            cin >> postcode;
            tree->addNode(name, age, income, postcode);
            break;
        case 3:
            cout << "ID ?>";
            cin >> nodeOrderID;
            tree->deleteNode(nodeOrderID);
            break;
        case 4:
            cout << "Name ?>";
            cin >> name;
            if (tree->searchNode(name)){
                cout << "Gefunden" << endl;
                tree->printNode(name);              
            } 
            else cout << "Nicht gefunden" << endl;
            break;
        case 5:
            tree->printAll();
            break;
        case 6:
            tree->levelOrder();
            break;
        case 7:
            break;
        }
    
    }

    system("PAUSE");

    return result;
}
