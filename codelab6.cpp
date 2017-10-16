#include <iostream>
#include <fstream>
#include <iomanip>
#include <locale>
#include <string>
using namespace std;

string get_word_to_add(string raw_word, int &max_chars);
void send_to_output(string line, int);

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
margins = 20;
if (margins > 0) {
max_chars = max_chars - margins;
while (instream >> temp_word)
{
size_of_word = temp_word.size();
if (size_of_word < max_chars) {
word = get_word_to_add(temp_word, max_chars);
temp_line = temp_line + word;
}
else {
send_to_output(temp_line, margins);
temp_line = get_word_to_add(temp_word, max_chars);
max_chars = 80 - margins - temp_line.size();
}
}
send_to_output(temp_line, margins);
}
outstream.close();
instream.close();
return 0;
}
string get_word_to_add(string raw_word, int &max_chars)
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

void send_to_output(string line, int margins) {
// put margins and print it to console
margins = margins/2;
string left_margin(margins,' ');
cout << left_margin << line << endl;
// print it to output file
outstream << left_margin << line << endl;
}