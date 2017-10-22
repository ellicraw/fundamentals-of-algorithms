#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

string getWordToAdd(string raw_word, int &max_chars);
void sendToOutput(string line, int);

ifstream instream;
ofstream outstream;

int main() {
int margins, size_of_word;
int max_chars;
string word, temp_line, temp_word;
instream.open("infile.txt");
outstream.open("DAT1.txt");
cout << "Enter the maximum amount of characters in one line: ";
cin >> max_chars;
margins = 30;
if (margins > 0) {
max_chars = max_chars - margins;
while (instream >> temp_word)
{
size_of_word = temp_word.size();
if (size_of_word < max_chars) {
word = getWordToAdd(temp_word, max_chars);
temp_line = temp_line + word;
}
else {
sendToOutput(temp_line, margins);
temp_line = getWordToAdd(temp_word, max_chars);
max_chars = 80 - margins - temp_line.size();
}
}
sendToOutput(temp_line, margins);
}
outstream.close();
instream.close();
return 0;
}
string getWordToAdd(string raw_word, int &max_chars)
{
string word;
char a = raw_word.back();
if (a == '.' || a == '?' || a == '!') {
word = raw_word + " ";
max_chars = max_chars - (word.size());
}
else {
word = raw_word + " ";
max_chars = max_chars - (word.size());
}
return word;
}

void sendToOutput(string line, int margins) {
// put margins and print it to console
margins = margins/2;
string left_margin(margins,' ');
cout << left_margin << line << endl;
// print it to output file
outstream << left_margin << line << endl;
}