#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;
//Function that creates the hashmap from the standard out output from the mapping program
void get_map(std::unordered_map<string, int>& hash, istream& cin){
    while (cin){
    string line;
    getline(cin, line, '\n');
    if (line != "" || line != " "){
        if (hash[line] == 0){
                hash[line] = 1;
            }else{
                hash[line]++;
            }
        }
    }        
}
int main(int argc, char* argv[]){
    unordered_map<string, int> hash;
    get_map(hash, cin);
    for (auto it = hash.cbegin(); it != hash.cend(); it++){
        cout << it->first << "\t" << it->second << "\n";
    }
}