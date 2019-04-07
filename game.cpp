#include <iostream>
#include <cstdarg>
#include <stdlib.h>

#include <thread>
#include <chrono>

#include <map>

using namespace std;

map<string,bool> items;

void sceneOne();
void sleep(int seconds);

int getChoice(int numChoices, ...) {
    va_list args;
    va_start(args,numChoices); //numChoices is last named parameter

    int response = -1;
    cout << "Will you...";
    for(int i = 1; i <= numChoices; ++i) {
        cout << endl << i << ". " << va_arg(args,char*);
    }
    while(response < 1 || response > numChoices ) {
        cout << "\n>>>";
        if(cin.fail()) {
            cin.clear();
            cin.ignore();
        }
        cin >> response;
    }

    return response;
}

void sleep(int seconds) {
    this_thread::sleep_for(chrono::seconds(seconds));
}

int main(int argc, char** argv) {

    sceneOne();

    return 0;
}

void sceneOne(){
    cout << "Avast! You've been abducted by pirates!\n"
        << "You are in a dark room, tied to a chair.\n"
        << "What do you do?\n";
    int response = getChoice(3,"Do nothing","Shake chair vigorously","Kill yourself");
    switch (response) {
        case 1: {
                    cout << "You do absolutly nothing. Being the completly chad genius you are, \nyou realize the best oppertunity is when the pirates least expect it." << endl;
                    sleep(2);
                    cout << "You wait." << endl;
                    sleep(2);
                    cout << "And wait." << endl;
                    sleep(2);
                    cout << "This might be a while. " << endl;
                    for(int i = 0; i < 10; i++){
                        cout << ".";
                        sleep(2);
                        cout.flush();
                    }
                    cout << "This is taking too long. Start over.\n";
                    cout << endl;
                    sceneOne();
                    break;
                }
        case 2: {

                }
        case 3: {
                    switch(rand()%3) {
                        case 0:
                            cout << "You toaster neck\n";
                            break;
                        case 1:
                            cout << "You commit not alive\n";
                            break;
                        case 2:
                            cout << "You uninstall life\n";
                            break;
                    }
                    cout << "You are dead. Start over!\n\n";
                    sceneOne();
                    break;
                }
    }
}
