#include <string>
#include <iostream>
#include <vector>

using namespace std;
int main() {
    int amountOfNames;
    string temp;
    cout << "How many names would you like to sort? ";
    cin >> amountOfNames;
    
    vector<string> names(amountOfNames);
    
    for (int i=0; i < amountOfNames; i++){
        cout << "Enter the names: ";
        cin >> names[i];
    }
    
    cout << "**** Printing unsorted array ****" << endl;
    for (int i=0; i < amountOfNames; i++){
        cout << names[i] << " ";
    }
    cout << endl;

    for (int i=0; i < amountOfNames; i++){
        for (int j=0; j < amountOfNames-1; j++) {
            if (names[j] > names[j+1]){
                temp = names[j];
                names[j] = names[j+1];
                names[j+1] = temp;
            }
        }
    }
    
    cout <<  "**** printing sorted array ****" << endl;
    for (int i=0; i < amountOfNames; i++) {
        cout << names[i] << " ";
    }
    cout << endl;
    
    return 0;
}

