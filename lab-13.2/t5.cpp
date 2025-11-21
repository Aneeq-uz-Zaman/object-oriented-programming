#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ifstream fin("fellows2.txt");
    vector<string> lines;
    string line;
    int count = 1;

    while (getline(fin, line)) {
        string roll = line.substr(0, 12);    
        string name = line.substr(15, 25);    
        string cgpa = line.substr(40, 5); 
        cout << count << " " << name << ", " << roll << "\n";
        cout << "CGPA: " << cgpa << "\n";
        count++;
    }
    fin.close();
    return 0;
}
