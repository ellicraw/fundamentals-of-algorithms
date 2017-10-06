#include <iostream>
#include <string>
#include <map>

using namespace std;

void findPairs(int[], int, int);
void findHashPairs(int[], int, int);
int indToNum(string);
string numToInd(int);

int main () {
    int A[]={1, 21, 4, 12, 18, 10};
    int target = 22; 
    int arraySize = sizeof(A)/sizeof(A[0]);
    int num, n;
    string s, str;
    
    cout << endl;
    //testing part 1a
    // findPairs(A, arraySize, target);

    //testing part 1b 
    // findHashPairs(A, arraySize, target);

    // //tesing part 2
    // s = "AH";
    // num = indToNum(s);
    // cout << "The column given, "<< s<< ", would be the number: " << num << ", in excel."<< endl;
    
    //testing part 3
    // n = 26;
    // str = numToInd(n);
    // cout << "The number given, "<< n<< ", would be column: " << str << ", in excel."<< endl;


    return 0;
}

// part 1a Naive Approach
void findPairs(int A[] , int arraySize, int target)
{
  for (int i = 0; i < arraySize; i++)
  {
    for (int j = i; j < arraySize; j++)
    {
      if (A[i] + A[j] == target)
        cout << "(" << A[i] << ", " << A[j] << ") ";
    }
  }
  cout << endl;
} 

// part 1b Use Hashmap/ dictionary
void findHashPairs(int A[], int length, int target)
{
   map<int, int> element;
   for (int i=0; i< length; ++i)
   {
      element.insert( pair<int, int>(A[i], 1));
      if(element.count(target - A[i]) )
        cout << "(" << A[i] << ", " << target - A[i] << ") ";
   }
   cout << endl;
}
 
// part 2 Given the index of Excel spreadsheet, return the equivalent column number
int indToNum(string s) {
  int a = 0;
  for (int i = 0; i < s.length(); i ++) {
      a = a * 26 + s[i] - 64;
  }
  return a;
}


// part 3 
string numToInd(int n) {
  string a = "";
  while (n > 0) {
      a = (char)(65 + (n - 1) % 26) + a;
      n = (n - 1) / 26;
  }
  return a;
}