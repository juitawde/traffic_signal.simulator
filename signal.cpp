#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

// ANSI color codes
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

// Countdown function using real seconds
void countdown(int seconds)
{
    for(int i = seconds; i >= 1; i--)
    {
        cout << i << " " << flush;
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout << endl;
}

// Function to show a signal with countdown
void showSignal(const string &color, const string &name, const string &emoji, int duration)
{
    cout << color << "Signal: " << name << " " << emoji << RESET << endl;
    cout << "Next signal in seconds: ";
    countdown(duration);
    cout << endl;
}

int main()
{
    int choice;
    bool running = false;

    do
    {
        cout << CYAN << "\n==============================\n";
        cout << " SMART TRAFFIC SIGNAL SYSTEM\n";
        cout << "==============================\n" << RESET;

        cout << "1. Start Signal\n";
        cout << "2. Stop Signal\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                running = true;
                cout << GREEN << "\nStarting Simulation...\n" << RESET;

                while(running)
                {
                    showSignal(GREEN, "GREEN", "🟢", 30);   // GREEN 30 sec
                    showSignal(YELLOW, "YELLOW", "🟡", 5);  // YELLOW 5 sec
                    showSignal(RED, "RED", "🔴", 30);       // RED 30 sec

                    int cont;
                    cout << "Enter 0 to STOP or 1 to CONTINUE: ";
                    cin >> cont;
                    if(cont == 0)
                        running = false;
                }

                cout << RED << "\nSimulation Stopped.\n" << RESET;
                break;

            case 2:
                running = false;
                cout << RED << "\nSignal Already Stopped.\n" << RESET;
                break;

            case 3:
                cout << CYAN << "\nExiting Program!\n" << RESET;
                break;

            default:
                cout << RED << "\nInvalid Choice!\n" << RESET;
        }

    } while(choice != 3);

    return 0;
}