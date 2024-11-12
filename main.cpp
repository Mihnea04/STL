#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream inFile("input.txt");

    int no_problems, no_doctors;
    string name, speciality;
    vector<string> specialitate, nume;
    
    inFile >> no_problems;

    for (int i = 0; i < no_problems; i++)
    {
        inFile >> name;
        inFile >> speciality;
        specialitate.emplace_back(speciality);
        nume.emplace_back(name);
        //cout << name << ' ' << speciality << '\n';
    }

    inFile >> no_doctors;

    for (int i = 0; i < no_doctors; i++)
    {
        inFile >> name;
        inFile >> speciality;
       
        for (auto k = begin(specialitate); k != end(specialitate); k++)
        {
            if (*k == speciality)
            {
                int d = distance(begin(specialitate), k);
                specialitate[d] = "Acceptat";
            }
        }
        //cout << name << ' ' << speciality << '\n';
    }
    for (auto k = begin(specialitate); k != end(specialitate); k++)
    {
        int d = distance(begin(specialitate), k);
        if (*k == "Acceptat")
        {
            cout << nume[d] << " " << *k << endl;
        }
        else {
            cout << nume[d] << " " << "Respins" << endl;
        }
    }

    return 0;
}