#include <iostream>
#include <cstdarg>

using namespace std;

int getChoice(int numChoices, ...) {
    va_list args;
    va_start(args,numChoices); //numChoices is last named parameter
   
    int response = -1;
    while(response < 1 || response > numChoices ) {
   	    cout << "Will you...\n";
   	    for(int i = 1; i <= numChoices; ++i) {
   	        cout << i << ". " << va_arg(args,char*) << endl;
   	    }
   	    cout << ">>>";
   	    cin >> response;
    }
    return response;
}

int main(int argc, char** argv) {

    cout << "Avast! You've been abducted by pirates!\n"
         << "You are in a dark room, tied to a chair.\n"
         << "What do you do?\n";
    int response = getChoice(3,"Do nothing","Shake chair vigorously","Kill yourself");
    if(response == 3) {
        cout << "You are dead\n";
    } else {
        cout << "You are not dead\n";
    }

    return 0;
}
