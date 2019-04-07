#include <iostream>
#include <cstdarg>
#include <stdlib.h>

#include <thread>
#include <chrono>

#include <map>

using namespace std;

map<string,bool> items;

void sceneOne();
void sceneTwo();

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

bool getYesNo(const string & text) {
    cout << text << endl
         << "(y/n)";
    string response = "?";
    while(response.compare("y") != 0 || response.compare("n") != 0) {
        cout << "\n>>>";
        if(cin.fail()) {
            cin.clear();
            cin.ignore();
        }
        cin >> response;
    }
    if(response.compare("y") == 0) {
        return true;
    }
    return false;
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
            cout << "You shake the chair vigorously. The rope falls to your feet." << endl;
            cout << "Obviously these pirates were knot prepared to tie somebody up!" << endl;
            cout << "You examine the room." << endl;
            sceneTwo();
            break;
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
void sceneTwo(){

    cout << "The room is small and dark, lit only by cracks in the walls.\n"
         << "There is a map on the far wall.\n"
         << "There is a staircase leading up to a door.\n";
    int response = getChoice(2,"Go to the door","Look at the map");
    switch(response) {
        case 1:
            cout << "You climb up the creaky stairs, and approach the door.\n"
                 << "The smell of salty sea air fills your nostrils when you get to the top.\n";
            bool response = getYesNo("The main deck must be through here. Do you want to open the door?\n");
            if (response == 1){
                cout << "You open the door and gaze upon the main deck." << endl;
                sceneThree();
            }
            else{
                cout << "You decide not to step on the potentially pirate ridden main deck." << endl;
                cout << "So you turn around and head back downstairs, avoiding any possible pirate gang bange that may have await you." << endl;
                sceneFour();
            }
            break;
        case 2:
            cout << "You walk up to the map, and look at it closely in the dim light.\n"
                 << "You can tell that this boat is en route to the PIRATE ISLAND.\n";
                 sceneTwo();
            break;
    }

}
void sceneThree(){
}
void sceneFour(){
}
