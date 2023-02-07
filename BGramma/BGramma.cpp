#include "Dictionary.h"
#include "BGramma.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

string BGramma::TakeOutWord(string s) {
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


void BGramma::CreateFile() {
    ifstream input("input.txt");
    if (input.is_open())
    {
        ofstream out;          // ����� ��� ������
        out.open("BGmmInput.txt");

        if (out.is_open())
        {
            string str;
            while (!input.eof())
            {
                str = "";
                getline(input, str);

                for (int i = 0; i < size(str); i++)
                {
                    if ((int(str[i]) >= 65 && int(str[i]) <= 90) || (int(str[i]) >= 97 && int(str[i]) <= 122) || (int(str[i]) >= 48 && int(str[i]) <= 57) || str[i] == ' ' || int(str[i]) == 39) {
                        if (int(str[i]) >= 65 && int(str[i]) <= 90)
                            out << char(int(str[i]) + 32);
                        else out << str[i];

                    }
                    else out << "|";

                }
                out << "| ";
            }
        }
        out.close();
        input.close();
    }
    else cout << "File not found" << endl;
}

string BGramma::Find(string s, int& count) {
    count = 0;
    string flag = "*";
    ifstream f("BGramma.txt");
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

void BGramma::AddCount(string s, int count) {
    int k = 0;
    ifstream input("BGramma.txt");

    if (input.is_open())
    {
        ofstream out;          // ����� ��� ������
        out.open("NewBGramma.txt");

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
                    string str2;
                    input >> str2;
                    str += ' ' + str2;
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

        input.open("NewBGramma.txt");
        out.open("BGramma.txt");
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
        remove("NewBGramma.txt");
    }
    else cout << "File not found" << endl;
}

int BGramma::FindAddWord(string s) {
    int ans = 0;
    int j = 0;
    bool flag2 = 0;
    ifstream f("BGramma.txt");
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
                            ans = j + 1;
                            flag = 1;
                        }
                        if (i_s < size(s) && i_str < size(str))
                            if (char(s[i_s]) > char(str[i_str])) {
                                ans = j + 1;
                                flag = 1;
                            }
                            else flag = 1;

                        i_s++;
                        i_str++;
                    }
                    //cout << ans << endl;
                    j++;
                }

            } while (ans != 0 && flag2 == 0);
        }
        f.close();
    }
    else cout << "File not found" << endl;
    // cout << "ans="<<ans << endl;
    return ans;

}

void BGramma::AddWord(string word, int count) {
    int k = 0;
    ifstream input("BGramma.txt");

    if (input.is_open())
    {
        ofstream out;          // ����� ��� ������
        out.open("NewBGramma.txt");

        if (out.is_open())
        {
            while (!input.eof())
            {
                k++;
                if (k == count && word != "")
                    out << "1 " + word << endl;

                string str;
                getline(input, str);
                if (str != "")
                    out << str << endl;
            }
        }
        out.close();
        input.close();

        input.open("NewBGramma.txt");
        out.open("BGramma.txt");
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
        remove("NewBGramma.txt");
    }
    else cout << "File not found" << endl;
}


void BGramma::PrintBGramma() {
    cout << endl << "-----�������-----" << endl;
    ifstream f("BGramma.txt");
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


void BGramma::Create() {
    CreateFile();

    ifstream f("BGmmInput.txt");
    if (f.is_open())
    {
        while (!f.eof())
        {
            string str;
            getline(f, str);

            string word = "";
            //cout << str;
            int k = 0;
            int j = 0;
            for (int i = 0; i < size(str); i++) {
                if (str[i]=='|'&& j==0) {
                    j = 0;
                    word = "";
                    k = 0;
                }else
                    if (str[i] == '|' && j == 1) {
                        if (word[0] != ' ') {
                            int count = 0;
                            string s = Find(word, count);
                            if (s != "*") AddCount(s, count);
                            if (s == "*") {
                                int pos = FindAddWord(word);
                                AddWord(word, pos + 1);
                            }
                            //PrintDictionary();
                        }
                        i -= k+1;
                        k = 0;
                        j = 0;
                        i++;
                        if (word != "") word = "";
                    }
                    else
                        if (str[i] != '|') {
                            if (str[i] == ' ' && j == 0) {
                                word += str[i];
                                j++;
                            }
                            else
                                if (str[i] == ' ' && j == 1) {
                                    if (word[0] != ' ') {
                                        int count = 0;
                                        string s = Find(word, count);
                                        if (s != "*") AddCount(s, count);
                                        if (s == "*") {
                                            int pos = FindAddWord(word);
                                            AddWord(word, pos + 1);
                                        }
                                        //PrintDictionary();
                                    }
                                    
                                    j = 0;
                                    i -= k+1;
                                    k = 0;
                                    if(word!="") word = "";
                                }
                                else
                                    if (str[i] != ' ') {
                                        if (j == 0) word += str[i];
                                        else {
                                            word += str[i];
                                            k++;
                                        }
                                    }
                        }
            }
        }
        f.close();
    }
    else cout << "File not found" << endl;
    remove("BGmmInput.txt");
}


string BGramma::PlusBGramma(string s) {
    int N_ans=0;
    string S_ans=".";
    ifstream f("BGramma.txt");
    if (f.is_open())
    {
        string str;
        while (!f.eof())
        {
            int N;
            string s1, s2;
            f >> N >> s1 >> s2;
            //cout << "N=" << N << " s1=" << s1 << " s2=" << s2 << endl;
            if (s1 == s && N>N_ans){
                N_ans = N;
                S_ans = s2;
            }
        }
        f.close();
    }
    else cout << "File not found" << endl;
    return S_ans;
}
