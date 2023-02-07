#include "Dictionary.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

string Dictionary::TakeOutWord(string s) {
    string word = "";
    int i = 0;
    while (s[i] != ' ') i++;
    i++;
    while (i < size(s)) {
        word += s[i];
        i++;
    }
    return word;
}

void Dictionary::ChangingTheCase() {
    ifstream input("input.txt");
    if (input.is_open())
    {
        ofstream out;          // поток для записи
        out.open("output.txt");

        if (out.is_open())
        {
            string str;
            while (!input.eof())
            {
                str = "";
                getline(input, str);

                for (int i = 0; i < size(str); i++)
                {
                    if ((int(str[i]) >= 65 && int(str[i]) <= 90) || (int(str[i]) >= 97 && int(str[i]) <= 122) || (int(str[i]) >= 48 && int(str[i]) <= 57)|| str[i]==' '|| int(str[i])==39) {
                        if (int(str[i]) >= 65 && int(str[i]) <= 90)
                            out << char(int(str[i]) + 32);
                        else out << str[i];
                        
                    }
                    
                }
                out << endl;
            }
        }
        out.close();
        input.close();
    }
    else cout << "File not found" << endl;
}

string Dictionary::Find(string s, int& count) {
    count = 0;
    string flag = "*";
    ifstream f("Dictionary.txt");
    if (f.is_open())
    {
        string str;
        while (!f.eof() && flag == "*")
        {
            count++;
            str = "";
            getline(f, str);
            if (str != "") {
                string word = "";
                int i = 0;
                while (str[i] != ' ')
                    i++;
                i++;
                while (i < size(str)) {
                    word += str[i];
                    i++;
                }
               // cout << word << " " << s << endl;
                if (word == s) flag = str;
            }
        }
        f.close();
    }
    else cout << "File not found" << endl;
    return flag;
}

void Dictionary::AddCount(string s, int count) {
    int k = 0;
    ifstream input("Dictionary.txt");

    if (input.is_open())
    {
        ofstream out;          // поток для записи
        out.open("NewDictionary.txt");

        if (out.is_open())
        {
            while (!input.eof())
            {
                k++;
                if (k == count) {
                    int N;
                    input >> N;
                    N++;
                    string str;
                    input >> str;
                    str = to_string(N) + ' ' + str;
                    out << str;
                }
                else {
                    string str;
                    str = "";
                    getline(input, str);
                    if (str != " ")
                        out << str;
                }
                out << endl;
            }
        }
        out.close();
        input.close();

        input.open("NewDictionary.txt");
        out.open("Dictionary.txt");
        if (out.is_open())
        {
            string str;
            while (!input.eof())
            {
                str = "";
                getline(input, str);
                //cout << "*"<<str<<endl;
                if (str != "") out << str << endl;
            }
        }
        out.close();
        input.close();
        remove("NewDictionary.txt");
    }
    else cout << "File not found" << endl;
}

int Dictionary::FindAddWord(string s) {
    int ans = 0;
    int j = 0;
    bool flag2 = 0;
    ifstream f("Dictionary.txt");
    if (f.is_open())
    {
        while (!f.eof()) {
            do {
                string str;
                getline(f, str);
                if (str == "") flag2 = 1;
                if (str != "") {
                    str = TakeOutWord(str);
                    int i_str = 0;
                    int i_s = 0;
                    bool flag = 0;
                    //cout << "s=" << s << " str=" << str <<" ans=";

                    while (flag == 0 && (i_s < size(s) || i_str < size(str))) {
                        while (i_s < size(s) && i_str < size(str) && char(s[i_s]) == char(str[i_str])) {
                            i_s++;
                            i_str++;
                        }
                        if (i_s < size(s) && i_str == size(str)) {
                            ans = j+1;
                            flag = 1;
                        }
                        if (i_s < size(s) && i_str < size(str))
                            if (char(s[i_s]) > char(str[i_str])) {
                                ans = j + 1;
                                flag = 1;
                            }
                            else flag=1;

                        i_s++;
                        i_str++;
                    }
                    //cout << ans << endl;
                    j++;
                }
              
            } while (ans != 0 && flag2==0);
        }
        f.close();
    }
    else cout << "File not found" << endl;
   // cout << "ans="<<ans << endl;
    return ans;

}

void Dictionary::AddWord(string word, int count) {
    int k = 0;
    ifstream input("Dictionary.txt");

    if (input.is_open())
    {
        ofstream out;          // поток для записи
        out.open("NewDictionary.txt");

        if (out.is_open())
        {
            while (!input.eof())
            {
                k++;
                if (k == count && word!="")
                    out << "1 " + word << endl;

                string str;
                getline(input, str);
                if (str != "")
                    out << str << endl;
            }
        }
        out.close();
        input.close();

        input.open("NewDictionary.txt");
        out.open("Dictionary.txt");
        if (out.is_open())
        {
            string str;
            while (!input.eof())
            {
                str = "";
                getline(input, str);
                //cout << "*" << str << endl;
                if (str != "") out << str << endl;
            }
        }
        out.close();
        input.close();
        remove("NewDictionary.txt");
    }
    else cout << "File not found" << endl;
}

void Dictionary::PrintDictionary() {
    cout << endl << "-----Словарь-----" << endl;
    ifstream f("Dictionary.txt");
    if (f.is_open())
    {
        string str;
        while (!f.eof())
        {
            str = "";
            getline(f, str);
            cout << str << endl;
            
        }
        f.close();
    }
    else cout << "File not found" << endl;
    cout << "-----------------------" << endl;
}


void Dictionary::Create() {
    ChangingTheCase();
    ifstream f("output.txt");
    if (f.is_open())
    {
        while (!f.eof())
        {
            string str;
            getline(f, str);

            int i = 0;
            string word = "";
            while (i < size(str)) {
                if (str[i] != ' ') word += str[i];
                else {
                    int count = 0;
                    string s = Find(word, count);
                    if (s != "*") AddCount(s, count);
                    if (s == "*") {
                        int pos = FindAddWord(word);
                        AddWord(word, pos + 1);
                    }
                    word = "";
                }
                i++;
            }
            word = "";
            if (str != "") {
                i = size(str) - 1;
                while (str[i] != ' ') {
                    word = str[i] + word;
                    i--;
                }
            
            }
            int count = 0;
            string s = Find(word, count);
            //cout << "Слово: " << word << endl;
            //cout << "- " << s<<endl;
            //cout << " word=" << word << endl;
            if (s != "*") AddCount(s, count);
            if (s == "*") {
                //cout << "word=" << word << endl;
                int pos = FindAddWord(word);
                //cout << word << " pos=" << pos << endl;
                
                AddWord(word, pos + 1);
            }
        }
        f.close();
    }
    else cout << "File not found" << endl;
    remove("output.txt");
}