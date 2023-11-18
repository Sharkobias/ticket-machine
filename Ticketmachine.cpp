#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <map>

using namespace std;
string input;
string moneygiven;

int main()
{
    map<int, string> english = {
        {1, "What kind of ticket do you want to purchase?:"},
        {2, "[1]Normal Ticket"},
        {3, "[2]Reduced Ticket"},
        {4, "[3]Time Ticket"},
        {5, "Choose type of payment:"},
        {6, "[1]Card"},
        {7, "[2]Blik"},
        {8, "[3]Cash"},
        {9, "cost:"},
        {10, "Please insert card"},
        {11, "Please wait..." },
        {12, "authorization completed"},
        {13, "authorization canceled"},
        {14, "Thanks for using our services!"},
        {15,  "Please, enter the blik code:" },
        {16,  "insert coins or cash" },
        {17, "insert:"},
        {18,  "Money left to pay:" },
        {19, "Your Change:"},
        {20, "!Unrecognizable type of ticket!"},
        {21, "try again"},
        {22, "!Unsupported type of payment!"}
    };

    map<int, string> polish = {
        {1, "Wybierz typ biletu:"},
        {2, "[1]Normalny"},
        {3, "[2]Ulgowy"},
        {4, "[3]Okresowy"},
        {5, "Wybierz typ platnosci:"},
        {6, "[1]Karta"},
        {7, "[2]Blik"},
        {8, "[3]Gotowka"},
        {9, "koszt:"},
        {10, "Prosimy o wprowadzenie karty"},
        {11, "Prosimy czekac... "},
        {12, "autoryzacja ukonczona"},
        {13, "autoryzacja odrzucona"},
        {14, "dziekujemy za skorzystanie z naszego serwisu!"},
        {15, "Prosimy o wpisanie kodu Blik:"},
        {16, "wloz monety"},
        {17, "wprowadz:"},
        {18, "Pozostalo do zaplaty:"},
        {19, "reszta:"},
        {20, "!nieznany typ biletu!"},
        {21, "sprobuj ponownie"},
        {22, "!Nieobslugujemy tego typu platnosci!"}
    };

    map<int, string> lang;

    map<string, int> coin_values = {
        {"50zl", 5000},
        {"20zl", 2000},
        {"10zl", 1000},
        {"5zl", 500 },
        {"2zl", 200},
        {"1zl", 100 },
        {"50gr", 50},
        {"20gr", 20},
        {"10gr", 10}
    };
    int norm = 480;
    int redu = 320;
    int timshour = 650;
    int timsdob = 2250;
    int ticket_cost;
    double ticket_cost_zl;
    int remaining_cost;
    int true_rest;


    cout << "Hello!" << endl;
    cout << "Select language:" << endl;
    cout << "[1]English" << endl << "[2]Polski" << endl;
    cin >> input;
    if (input == "1")
    {
        lang = english;
    }
    else if (input == "2")
    {
        lang = polish;
    }
    else 
    {
        cout << "!unsupported language! deafulting to english" << endl;
        lang = english;
    }
    
    cout <<lang[1]<< endl;
    cout <<lang[2]<< endl<<lang[3]<<endl<<lang[4]<< endl;
    cin >> input;
    if (input == "1") {
        ticket_cost = norm;
    }
    else if (input == "2") {
        ticket_cost = redu;
    }
    else if (input == "3") {
        ticket_cost = timsdob;
    }
    else
    {
        cout << lang[20] << endl << lang[21] << endl;
        return 0;
    }
    ticket_cost_zl = ticket_cost / 100.0;
    cout <<lang[5]<< endl;
    cout << lang[6]<< endl <<lang[7]<< endl <<lang[8]<< endl;
    cin >> input;
    if (input == "1")
    {
        cout <<lang[9]<<ticket_cost_zl<< endl;
        cout <<lang[10]<< endl;
        cout << "[a]ccept" << endl << "[d]ecline" << endl;
        cin >> input;
        if (input == "a")
        {
            cout <<lang[11]<< endl;
            cout << " " << endl;
            cout <<lang[12] << endl;
            cout <<lang[14]<< endl;

        }
        else if (input == "d")
        {
            cout <<lang[13]<< endl;
        }
        else 
        {
            cout << lang[21] << endl;
        }
    }
    else if (input == "2")
    {
        cout <<lang[9]<< ticket_cost_zl<< endl;
        cout <<lang[15]<< endl;
        cin >> input;
        cout <<lang[11]<< endl;
        cout << " " << endl;
        cout <<lang[12]<< endl;
        cout <<lang[14]<< endl;
    }
    else if (input == "3")
    {
        cout <<lang[9]<<ticket_cost_zl<<endl;
        remaining_cost = ticket_cost;
        do
        {
            cout <<lang[16]<< endl;
            cout <<lang[17]<< endl;
            cout << "[10gr]" <<endl << "[20gr]" << endl << "[50gr]" << endl;
            cout << "[1zl]" << endl << "[2zl]" << endl << "[5zl]" << endl << "[10zl]" << endl << "[20zl]" << endl << "[50zl]" << endl;
            cin >> moneygiven;
            remaining_cost -= coin_values[moneygiven];
            if (remaining_cost > 0)
            {
                cout << lang[18] << remaining_cost / 100.0 << "zl" << endl;
            }
        } while (remaining_cost > 0);
        if (remaining_cost < 0) 
        {
            true_rest = remaining_cost * (-1);
            do
            {
                for (auto coin : coin_values) {
                    if (true_rest - coin.second >= 0) {
                        cout <<lang[19]<< coin.first << endl;
                        true_rest -= coin.second;
                    }
                }
            } while (true_rest > 0);
        }
        cout << lang[11] << endl;
        cout << " " << endl;
        cout << lang[14] << endl;
    }
    else 
    {
        cout << lang[22] << endl;
        return 0;
    }

    return 0;
}