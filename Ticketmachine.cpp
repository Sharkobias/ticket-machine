#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
string input;
string moneygiven;

int main()
{
    int norm = 480;
    int redu = 320;
    int timshour = 650;
    int timsdob = 2250;
    int twengr = 20;
    int fifgr = 50;
    int onezl = 100;
    int twozl = 200;
    int fivzl = 500;
    int tenzl = 1000;
    int twenzl = 2000;
    int fiftzl = 5000;
    int ticket_cost;
    double ticket_cost_zl;


    cout << "Hello!" << endl;
    cout << "Select language:" << endl;
    cout << "[1]English" << endl << "[2]Polski" << endl << "[3]українська" << endl << "[4]Deutsch" << endl;
    cin >> input;
    if (input == "1")
    {
        cout << "What kind of ticket do you want to purchase?:" << endl;
        cout << "[1]Normal Ticket" << endl << "[2]Reduced Ticket" << endl << "[3]Time ticket" << endl;
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
        ticket_cost_zl = ticket_cost / 100.0;
        cout << "Choose type of payment:" << endl;
        cout << "[1]Card" << endl << "[2]blik" << endl << "[3]cash" << endl;
        cin >> input;
        if (input == "1")
        {
            cout << "cost:" <<ticket_cost_zl<< endl;
            cout << "Please insert card" << endl;
            cout << "[a]ccept" << endl << "[d]ecline" << endl;
            cin >> input;
            if (input == "a")
            {
                cout << "Please wait..." << endl;
                cout << " " << endl;
                cout << "authorization completed" << endl;
                cout << "Thanks for using our services!" << endl;

            }
            else if (input == "d")
            {
                cout << "authorization canceled" << endl;
            }

        }
        else if (input == "2")
        {
            cout << "cost:" << ticket_cost_zl<< endl;
            cout << "Please, enter the blik code:" << endl;
            cin >> input;
            cout << "Please wait..." << endl;
            cout << " " << endl;
            cout << "authorisation completed" << endl;
            cout << "Thanks for using our services!" << endl;
        }
        else if (input == "3")
        {
            cout << "cost:"<<ticket_cost_zl<<endl;
            do
            {
                cout << "insert coins or cash" << endl;
                cout << "Insert:" << endl;
                cout << "[20gr]" << endl << "[50gr]" << endl;
                cout << "[1zl]" << endl << "[2zl]" << endl << "[5zl]" << endl << "[10zl]" << endl << "[20zl]" << endl << "[50zl]" << endl;
                cin >> moneygiven;

                if (moneygiven == "20gr")
                {
                    float diff = ticket_cost - twengr;
                    cout << "Money left to pay:" << diff << "zl" << endl;
                }
                else if (moneygiven == "50gr")
                {
                    float diff = ticket_cost - fifgr;
                    cout << "Money left to pay:" << diff << "zl" << endl;
                }
                else if (moneygiven == "1zl")
                {
                    float diff = norm - onezl;
                    cout << "Money left to pay:" << diff << "zl" << endl;
                }
                else if (moneygiven == "2zl")
                {
                    float diff = norm - twozl;
                    cout << "Money left to pay:" << diff << "zl" << endl;
                }
                else if (moneygiven == "5zl")
                {
                    float diff = norm - fivzl;
                    cout << "Your change:" << diff << "zl" << endl;
                    cout << "20gr" << endl;
                }
                else if (moneygiven == "10zl")
                {
                    float diff = norm - tenzl;
                    cout << "Your change:" << diff << "zl" << endl;
                    cout << "5zl" << endl;
                    cout << "20gr" << endl;
                }
                else if (moneygiven == "20zl")
                {
                    float diff = norm - twenzl;
                    cout << "Your change:" << diff << "zl" << endl;
                }
                else if (moneygiven == "50zl")
                {
                    float diff = norm - fiftzl;
                    cout << "Your change:" << diff << "zl" << endl;
                    cout << "2*20zl" << endl;
                    cout << "5zl" << endl;
                    cout << "20gr" << endl;
                    cout << "Thanks for using our services!" << endl;
                    abort();
                }

            } while (norm > 0);
        }
    }
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
