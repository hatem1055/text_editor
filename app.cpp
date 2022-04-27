#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>

using namespace std;
fstream filestream;
vector<string> filecontent;
string name = "";
vector<string> split(const string &s, char delim) {
    vector<string> elems;
    stringstream ss(s);
    string number;
    while(getline(ss, number, delim)) {
        elems.push_back(number);
    }
    return elems;
}
void upper_string(string& s){
    string new_str {""};
    for(char c : s){
        new_str += toupper(c);
    }
    s = new_str;
}
void lower_string(string& s){
    string new_str {""};
    for(char c : s){
        new_str += tolower(c);
    }
    s = new_str;
}
void set_file(){
    cout << "Please Enter File Name : ";
    cin >> name;
    filestream.open(name,std::fstream::in);
    if(filestream.is_open()){
        string line {""};
        while(getline(filestream,line)){
            filecontent.push_back(line);
        }
        cout << "File Opened Successfully \n";
    }

}
void append_text(){
    cout << "Enter Line :- \n";
    string new_line {""};
    cin.clear();
    getline(cin >> ws,new_line);
    filecontent.push_back(new_line);    
}
void display_content(){
    for(string line : filecontent){
        cout << line << "\n";
    }
}
void clear(){
    filecontent = {};
}
void encrypt(){
    for(int i {0};i < filecontent.size();i++){
        string new_line {""};
        for(char c : filecontent[i]){
            new_line += c + 1;
        }
        filecontent[i] = new_line;
    }

}
void decrypt(){
    for(int i {0};i < filecontent.size();i++){
        string new_line {""};
        for(char c : filecontent[i]){
            new_line += c - 1;
        }
        filecontent[i] = new_line;
    }
}
void merge(){
    fstream filestream2;
    string name_2{""};
    cout << "Please Enter File Name : ";
    cin >> name_2;
    filestream2.open(name_2,std::fstream::in);
    if(filestream2.is_open()){
        string line {""};
        while(getline(filestream2,line)){
            cout << line << '\n';
            filecontent.push_back(line);
        }
        filestream2.close();
    }
}
void count_words(){
    int counter {0};
    for(string line : filecontent){
        counter += split(line,' ').size();
    }
    cout << "There is " << counter << " words \n";
}
void count_chars(){
    int counter {0};
    for(string line : filecontent){
        counter += line.size();
    }
    cout << "There is " << counter << " chars \n";
}
void count_lines(){
    cout << "There is " << filecontent.size() << " Lines \n";
}
void search_word(){
    string word_desired{""};
    cout << "Please Enter the word you want to get : ";
    cin >> word_desired;
    lower_string(word_desired);
    for(string line : filecontent){
        for(string word : split(line,' ')){
            lower_string(word);
            if (word_desired == word){
                cout << "Word Found \n";
                return;
            }
        }
    }
    cout << "Word Not Found \n";
}
void count_word(){
    string word_desired{""};
    cout << "Please Enter the word you want to count : "; 
    int counter {};
    cin >> word_desired;
    lower_string(word_desired);
    for(string line : filecontent){
        for(string word : split(line,' ')){
            lower_string(word);
            if (word_desired == word){
                counter += 1;
            }
        }
    }
    cout << "The Word " << word_desired << " Was Found " << counter << "times \n";
}
void to_upper(){
    for(int i {0};i < filecontent.size();i++){
        upper_string(filecontent[i]);
    }
}
void to_lower(){
    for(int i {0};i < filecontent.size();i++){
        lower_string(filecontent[i]);
    }
}
void capltize(){
    for(int i {0};i < filecontent.size();i++){
        string new_line {""};
        for(string word : split(filecontent[i],' ')){
            for(int j {0};j < word.size();j++){
                new_line += j == 0 ? toupper(word[j]) : word[j];
            }
            new_line += ' ';
        }
        filecontent[i] = new_line;
    }
}
void save_file(){
    filestream.close();
    ofstream editfilestream;
    editfilestream.open(name,ios :: out);
    for(string line : filecontent){
        editfilestream << line << "\n";
    }
    editfilestream.close();
    filecontent = {};
    cout << "File Saved \n";
    set_file();
}
int main(){
    cout << "welcome to our text editor \n"; 
    set_file();
    string msg = "1. Add new text to the end of the file \n 2. Display the content of the file \n 3. Empty the file \n 4. Encrypt the file content \n 5. Decrypt the file content \n 6. Merge another file \n 7. Count the number of words in the file. \n 8. Count the number of characters in the file \n 9. Count the number of lines in the file \n 10. Search for a word in the file \n 11. Count the number of times a word exists in the file \n 12. Turn the file content to upper case. \n 13. Turn the file content to lower case. \n 14. Turn file content to 1st caps (1st char of each word is capital)  \n 15. Save \n 16. Exit \n";
    int command {0};
    while(command != 16){
        cout << msg;
        cout << "Enter your command : ";
        cin >> command;
        switch (command)
        {
        case 1:
            append_text();
            break;
        case 2:
            display_content();
            break;
        case 3:
            clear();
            break;
        case 4:
            encrypt();
            break;
        case 5:
            decrypt();
            break;
        case 6:
            merge();
            break;
        case 7:
            count_words();
            break;
        case 8:
            count_chars();
            break;
        case 9:
            count_lines();
            break;
        case 10:
            search_word();
            break;
        case 11:
            count_word();
            break;
        case 12:
            to_upper();
            break;
        case 13:
            to_lower();
            break;
        case 14:
            capltize();
            break;
        case 15:
            save_file();
            break;
        case 16:
            break;
            break;
        
        default:
            cout << "Invalid Command \n";
        }
    }
    return 0;
}