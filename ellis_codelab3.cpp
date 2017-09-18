#include <iostream>
#include <string>

using namespace std;

string numOutLoud(int);
void randArray(); //declare random array function
void mergeSort(string list[], int lowerBound, int upperBound);
void merge(string list[], int lowerBound, int upperBound, int mid);

int randNumArr[10]; // declare array for ranndom numbers

int main() {
    randArray();
    string comboArr[10]; // declare array for the combo of random numbers and number outloudz
    // for loop to combine random number array and numbers out loud
    for (int i = 0; i < 10; i++) {
        string temp;
        temp = numOutLoud(randNumArr[i]);
        comboArr[i] = temp;
    }
    cout << "** unsorted array **" << endl;
    
    for (int i = 0; i < 10; i++) {
        cout<< comboArr[i] << " ";
    }
    cout << endl;
    cout << endl;
    int sizeOfArray = sizeof( comboArr ) / sizeof( comboArr[ 0 ] );
    
    mergeSort(comboArr, 0, sizeOfArray);
    
    
    cout << "**sorted array**" <<endl;
    
        for (int i = 0; i < 10; i++) {
            cout<< comboArr[i] << " ";
        }
    cout << endl;
    return 0;
}

// function that takes a number and prints out how its said out loud (?)
string numOutLoud(int n) {
    if(n<1) return "";
    string ret = "1";
    for(int i=2; i<=n; i++) {
        string temp = "";
        int count = 1;
        char prev = ret[0];
        for(int j=1; j<ret.size(); j++) {
            if(ret[j]==prev)
                count++;
            else {
                temp += to_string(count);
                temp.push_back(prev);
                count = 1;
                prev = ret[j];
            }
        }
        temp += to_string(count);
        temp.push_back(prev);
        ret = temp;
    }
    return ret;
}

// function that populates randNumArr with random numbers from 5 (inclusively) to 15 (exclusively)
void randArray() {
    srand ( time(NULL) );
    for (int i = 0; i < 10; i++) {
        randNumArr[i] = rand() % 10 + 5;
        // cout << rand() % 10 + 5 << " ";
    }

}

void mergeSort(string comboArr[], int lowerBound, int upperBound)
{
    int mid;
    
    if (upperBound > lowerBound)
    {
        mid = ( lowerBound + upperBound) / 2;
        mergeSort(comboArr, lowerBound, mid);
        mergeSort(comboArr, mid + 1, upperBound);
        merge(comboArr, lowerBound, mid, upperBound);
    }
}
void merge(string comboArr[], int lowerBound, int mid, int upperBound)
{
    string* leftArray = NULL;
    string* rightArray = NULL;
    int i, j, k;
    int n1 = mid - lowerBound + 1;
    int n2 = upperBound - mid;
    leftArray = new string[n1];
    rightArray = new string[n2];
    for (i = 0; i < n1; i++){
        leftArray[i] = comboArr[lowerBound + i];
    }
    for (j = 0; j < n2; j++){
        rightArray[j] = comboArr[mid + 1 + j];
    }
    i = 0;
    j = 0;
    k = lowerBound;
    
    while (i < n1 && j < n2)
    {
        if (leftArray[i].length() < rightArray[j].length())
        {
            comboArr[k] = leftArray[i];
            i++;
        }
        else if (leftArray[i] <= rightArray[j])
        {
            comboArr[k] = leftArray[i];
            i++;
        }
        else
        {
            comboArr[k] = rightArray[j];
            j++;
        }
        
        k++;
    }
    
    while (i < n1)
    {
        comboArr[k] = leftArray[i];
        i++;
        k++;
    }
    
    while (j < n2)
    {
        comboArr[k] = rightArray[j];
        j++;
        k++;
    }
    
    delete [] leftArray;
    delete [] rightArray;
}
