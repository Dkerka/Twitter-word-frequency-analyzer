#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

//Function to get the contents of the tweet
string get_tweet(std::istream& cin){
    string line; 
    getline(cin, line, '\n');
    if (line != "" && line.size() > 100){
        int pos = line.find("e</a>");
        string parsedl = line.substr(pos + 8);
        int pos2 = parsedl.find("\",");
        string finalparse = parsedl.substr(0, pos2);
        return finalparse;
    }
    return "";
}
//Function to remove punctuation from words from the tweets
void rm_punctuation(vector<string>& strs, string parse, int gramlength){
    string check = parse;	
    bool done = false;
    bool nopush = false;
        while (done == false){
		    if(check.find("!") != string::npos){
                check.erase(std::remove(check.begin(), check.end(), '!'), check.end());
		    }else if (check.find("?") != string::npos){
                check.erase(std::remove(check.begin(), check.end(), '?'), check.end());
            }else if (check.find(39) != string::npos){
                check.erase(std::remove(check.begin(), check.end(), 39), check.end());
            }else if (check.find(44) != string::npos){
                int pos = check.find(44);
                //cout << "String length: " << parse.length() << endl;
                //cout << "Comma position: " << pos << endl;
                if (pos == parse.length() - 1){
                    check.erase(std::remove(check.begin(), check.end(), 44), check.end());
                }else{
                    string ret1 = check.substr(0, pos-1);
                    string ret2 = check.substr(pos+1);
                    nopush = true;
                    strs.push_back(ret1);
                    if (ret2 != ""){
                        strs.push_back(ret2);
                    }
                    break;
                }
             }
            else if (check.find(";") != string::npos){
                check.erase(std::remove(check.begin(), check.end(), ';'), check.end());
            }else if (check.find(":") != string::npos){
                check.erase(std::remove(check.begin(), check.end(), ':'), check.end());
            }else if (check.find("\"") != string::npos){
                check.erase(std::remove(check.begin(), check.end(), 34), check.end());
            } else if (check.find(".") != string::npos){
                check.erase(std::remove(check.begin(), check.end(), '.'), check.end());
            }else{
                done = true;
            }
        }
        if (nopush == false){
            strs.push_back(check);
        }
    }

//Function to parse words out of the tweet
void parse_tweet(string tweet, vector<string>& strs, int gramlength){
    string check;
    string parsed;
    bool end = false;
    check = tweet;
    while (end != true){
        int whitespace = check.find(" ");
        parsed = check.substr(0, whitespace);
        if (parsed.find("https://") == string::npos && parsed.find("#") == string::npos && parsed != ":" && whitespace > 0){
            rm_punctuation(strs, parsed, gramlength);
            //strs.push_back(parsed);
            check = check.substr(whitespace+1);
        }else{
            check = check.substr(whitespace+1);
        }
            if (whitespace == -1){end = true;} 
    }   
}
int main(int argc, char* argv[]){
    int gramlength;
    string line;
    vector<string> words; 
    //ngram length
    gramlength = atoi(argv[1]);  
    //Discarding the first line
    getline(cin, line, '\n');
    string tweet;
    while(!cin.eof()){
        tweet = get_tweet(cin);
        if (tweet != ""){
            string ngram;
            parse_tweet(tweet, words, gramlength);
        }
    }
    //Printing all of the words as n-grams in the tweet to standard out for the reducer to handle
    string gram;
    for (int i = 0; i < words.size(); i+=gramlength){
        gram = "";
        //Loop that creates the n-grams
        for (int j = 0; j < gramlength; j++){
            if (i + j < words.size()){
                gram += words[i + j];
                gram += " ";
            }
        }
        cout << gram << endl;
    }
}

