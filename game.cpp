#include <iostream>
#include <cstdarg>
#include <stdlib.h>

using namespace std;

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
                sleep(1);
                cout << "You wait." << endl;
                sleep(1);
                cout << "And wait." << endl;
                sleep(1);
                cout << "This might be a while. " << endl;
                for(int i =0; i < 10; i++){
                sleep(1);
                cout << ".";
                }
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
        }
    }
}
void sceneTwo(){
}
