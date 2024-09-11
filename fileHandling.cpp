// Online C++ compiler to run C++ program online
#include <iostream>
#include <fstream>

using namespace std;

class users {
    public:
        void createUser(string name, string email, string password) {
            fstream fout;
            
            fout.open("users.csv", ios::out | ios::app);
            
            fout << name << ", "
                << email << ", "
                << password << ", "
                << "/n";
        }
        
        void login(string email, string password) {
            fstream fin;
            
            fin.open("users.csv", ios::in);
            
            vector<string> row;
            string line, word, temp;
            
            while(fin >> temp) {
                row.clear();
                
                getline(fin, line);
                
                stringstream s(line);

                while (getline(s, word, ','))
                {
                    row.push_back(word);
                }
                if(email == row[1] && password == row[2]) {
                    cout << "Welcome " << row[0] << endl;
                    break;
                }
            }
        }
}

int main() {
    
    
    
    return 0;
}
