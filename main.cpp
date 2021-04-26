#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>
#include <Windows.h>

using namespace std;

int randRange (int low, int high)
{
    return rand() % (high - low) + low;
}

int main(int argc, char const *argv[])
{
    SetConsoleOutputCP( CP_UTF8 );
    ifstream be;
    be.open("nevsor.txt");
    int db=0;
    string tmp;
    vector<string> nevek;
    while(!be.eof())
    {
        getline (be,tmp);
        nevek.push_back(tmp);
        db++;
    }
    int inp;
    bool ended=0;
    cout<<"0:Exit"<<endl<<"1:Roll"<<endl<<"2:Menu"<<endl;
   while (!ended && cin >> inp) {
        switch (inp) {
            case 0:
                ended = true;
                break;
            case 1:
            default:
                 srand(time(NULL));
                cout<<nevek[randRange(0, db)]<<endl;;
                break;
            case 2:
                cout<<"0:Exit"<<endl<<"1:Roll"<<endl<<"2:Menu"<<endl<<"3:Boros Bálint"<<endl;
                break;
            case 3:
                cout<<"Boros Bálint"<<endl;
                break;
        }
    }
    return 0;
}

