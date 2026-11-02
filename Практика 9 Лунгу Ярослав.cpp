#include <iostream>
#include <fstream>
using namespace std;

void task1() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    
    if (!fin) {
        cout << "Cannot open input.txt" << endl;
        return;
    }
    
    char c;
    char letters[] = "useragreementUSERAGREEMENT";
    
    while (fin.get(c)) {
        bool found = false;
        for (int j = 0; letters[j] != '\0'; j++) {
            if (c == letters[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            fout << c;
        }
    }
    
    fin.close();
    fout.close();
    cout << "Task 1 completed" << endl;
}

void task2() {
    ifstream fin1("input1.txt");
    ifstream fin2("input2.txt");
    ofstream fout("output.txt");
    
    if (!fin1 || !fin2) {
        cout << "Cannot open input files" << endl;
        return;
    }
    
    char x[10001], y[10001];
    int lenX = 0, lenY = 0;
    char c;
    
    while (fin1.get(c)) {
        x[lenX++] = c;
    }
    x[lenX] = '\0';
    
    while (fin2.get(c)) {
        y[lenY++] = c;
    }
    y[lenY] = '\0';
    
    bool found = false;
    if (lenY <= lenX) {
        for (int i = 0; i <= lenX - lenY; i++) {
            bool match = true;
            for (int j = 0; j < lenY; j++) {
                if (x[i + j] != y[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                found = true;
                break;
            }
        }
    }
    
    if (found) {
        fout << "yes";
    } else {
        fout << "no";
    }
    
    fin1.close();
    fin2.close();
    fout.close();
    cout << "Task 2 completed" << endl;
}

void task3() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    
    if (!fin) {
        cout << "Cannot open input.txt" << endl;
        return;
    }
    
    char s[256];
    int len = 0;
    char c;
    
    while (fin.get(c)) {
        s[len++] = c;
    }
    s[len] = '\0';
    
    int i = 0;
    while (i < len) {
        if (s[i] >= '0' && s[i] <= '9') {
            long long num = 0;
            while (i < len && s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            
            if (num == 0) {
                fout << "0";
            } else {
                char bin[100];
                int idx = 0;
                long long temp = num;
                while (temp > 0) {
                    bin[idx++] = '0' + temp % 2;
                    temp /= 2;
                }
                for (int j = idx - 1; j >= 0; j--) {
                    fout << bin[j];
                }
            }
        } else {
            fout << s[i];
            i++;
        }
    }
    
    fin.close();
    fout.close();
    cout << "Task 3 completed" << endl;
}

int main() {
    int choice;
    cout << "1 - Task 1" << endl;
    cout << "2 - Task 2" << endl;
    cout << "3 - Task 3" << endl;
    cout << "Choice: ";
    cin >> choice;
    
    if (choice == 1) {
        task1();
    } else if (choice == 2) {
        task2();
    } else if (choice == 3) {
        task3();
    } else {
        cout << "Invalid choice" << endl;
    }
    
    return 0;
}