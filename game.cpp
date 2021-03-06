#include <iostream>
#include <cstdarg>
#include <stdlib.h>

#include <thread>
#include <chrono>
#include <random>

#include <map>
#include <sstream>
#include <fstream>

using namespace std;

map<string,bool> items;

void sceneOne();
void sceneTwo();
void sceneThree();
void sceneFour();
void sceneFive();
void sceneSix();
void sceneSeven();
void sceneEight();


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
    char response = '?';
    while(response != 'y' && response != 'n') {
        cout << "\n>>>";
        if(cin.fail()) {
            cin.clear();
            cin.ignore();
        }
        cin >> response;
    }
    return response == 'y';
}

void printPirateDialogue() {

    string result = "invalid string";

    stringstream d;
    string line;
    ifstream dfile("pirate_dialogue.txt");
    int itr = 0;
    double res = 1.0;
    while(getline(dfile,line)) {
        if(line.compare("-----") == 0){
            itr++;
            res = (double)1/itr;
            if((double)rand()/RAND_MAX <= res) {
                result = d.str();
            }
            d.str("");
            //cout << "Debug " << res << endl; 
        } else {
            d << line << "\n";
        }
    }
    cout << result << endl;
}

void sleep(int seconds) {
    this_thread::sleep_for(chrono::seconds(seconds));
}

int main(int argc, char** argv) {

    srand(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
    //printPirateDialogue();

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
                    cout << "You do absolutly nothing. Being the completly chad genius you are, \nyou realize the best opportunity is when the pirates least expect it." << endl;
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
        case 1: {
            cout << "You climb up the creaky stairs, and approach the door.\n"
                 << "The smell of salty sea air fills your nostrils when you get to the top.\n";
            bool response = getYesNo("The main deck must be through here. Do you want to open the door?\n");
            if (response){
                cout << "You open the door and gaze upon the main deck." << endl;
                sceneThree();
            }
            else{
                cout << "You decide not to step on the potentially pirate ridden main deck." << endl;
                cout << "So you turn around and head back downstairs, avoiding any possible pirate gang bang that may have awaited you." << endl;
                sceneFour();
            }
            break;
        }
        case 2:
            cout << "You walk up to the map, and look at it closely in the dim light.\n"
                 << "You can tell that this boat is en route to the PIRATE ISLAND.\n"
                 << "The creativity in a name like that is overwelming.\n";
                 sceneTwo();
            break;
    }

}
void sceneThree(){
    cout << "The light of the moon illuminates the deck of the ship.\n"
         << "It seems most of the pirates are below deck, as their voices echo from the entrance to the brig.\n"
         << "As you look for a way off the ship, two pirates emerge from a door across the deck.\n"
         << "They seem to both be drunk. They have not noticed you yet.\n";
         int response = getChoice(3,"Eavesdrop on their conversation","Try to sneak by them","Wait until they leave");
        switch(response) {
            case 1: {
            /*cout << "You listen in on their conversation.\n"
                 << "\"Oy! Ya Wee Slag Clubber! Ya Be Cuffin Ma Main Squeeze Ain't Ya!\"\n"
                 << "\"Yu Barnicle Brain! Iv'e Never Even Met Ya Girl! Ya Blastfamous Bahooka!\"\n"
                 << "\"";*/
            printPirateDialogue();
            sceneThree();
            }
            case 2: {
                        cout << "You attempt to sneak by the pirates to the other side of the ship.\n"
                             << "One of the pirates spots you.\n";
                        sleep(1);
                        cout << "OI YOU! WHAT ARRRRRR YA DOIN HERE?\n";
                        if(items["Name of Captain"]) {
                            int response2 = getChoice(2,"Surrender","Tell them your name is Amanda");
                            if(response2 == 1) {
                                cout << "You surrender to the pirates\n";
                                sceneOne();
                            } else {
                                cout << "You tell the pirates that you are Amanda.\n"
                                     << "A look of shock and terror dawns on them, and they apologize before walking away.\n";
                                sleep(2);
                                cout << "You are very confused.\n";
                                sceneSeven();
                            }
                        } else {
                            cout << "You have no choice but to surrender to the pirates.\n";
                            sceneOne();
                        }
            }
            case 3: {
                cout << "You wait for the pirates to leave.\n";
                sleep(2);
                for(int i = 0; i < 3; ++i) {
                    cout << ".";
                    cout.flush();
                    sleep(1);
                }
                cout << "\nOk you don't wait that long until the pirates leave.\n"
                     << "The pirates go back down into the lower decks, muttering something about termites in peg legs\n"
                     << "The deck is wide and open.\n";
                if(!items["lantern"]) {
                    cout << "There is a lantern above you.\n";
                    items["lantern"] = getYesNo("Take it?");
                }
                int response2 = getChoice(3,"Follow the pirates","Turn back to the stairs","Explore the deck");
                switch(response2) {
   	                case 1: 
			               	cout << "You follow the pirates below deck, making sure to keep\n";
			              	cout << "a Safe Distance at all times.\n";
			        	    sleep(2);
			        	    cout << "After tailing the pirates for far too long a time,\n";
			        	    cout << "(do THEY even know where their going!?) You arrive at what\n";
			        	    cout << "seems to be the barracks. It's brimming with pirate activity.\n";
                            sceneSix();
                            break;
                    case 2: sceneFour();
                            break;
                    case 3: sceneSeven();
                            break;
                }
                break;
            }
        }
}

void sceneFour(){
    cout << "While walking back down the stairs, you notice there is a hole in the ceiling.\n"
         << "It is entirely unlit, and you can swear you hear rats scurrying about in it.\n";
    bool response = getYesNo("Do you enter the hole rather than continuing back down to the room?");
    if(response) {
        cout << "You climb up into the ceiling hole, and begin feeling your way around.\n";
        sceneFive();
    } else {
        sceneTwo();
    }
}

void sceneFive() {
    if(items["lantern"]) {
        cout << "You are in a dark tunnel. You can't see shit\n";
        bool response = getYesNo("Take out your lantern?");
        if(response) {
            cout << "You see an inscription in the tunnel. It says...\n";
            sleep(2);
            cout << "It says";
            for(int i = 0; i < 2; ++i) {
                cout << ".";
                cout.flush();
                sleep(3);
            }
            cout << "\nIt's really hard to read...\n";
            sleep(2);
            cout << "\"Amanda\"\n";
            sleep(1);
            cout << "It just says \"Amanda\".\n";
            sleep(2);
            cout << "Well then. You turn around.\n";
            items["Name of Captain"] = true;
            sceneFour();
        } else {        
            response = getYesNo("You can't move forward. Turn back?");
            if(response) {
                sceneFour();
            } else {
                sceneFive();
            }
        }
    } else {
        cout << "You are in a dark tunnel. You can't see shit.\n";
        bool response = getYesNo("You can't move forward. Turn back?");
        if(response) {
            sceneFour();
        } else {
            sceneFive();
        }
    }
}

void sceneSix() {
    int response = getChoice(3, "Return to the main deck","Examine the barracks","Challange the pirates");
    switch (response){
        case 1: 
                cout << "You return to the main deck.";
                sceneSeven();
                break;
        
        case 2: 
                cout << "You examine the barracks.\n";
                cout << "The disguisting room is filled with several scurvy ridden pirates, each half dead\n";
                cout << "from the several diseases they gather from their lack of general hygene. Mold grows\n";
                cout << "Along the walls, likely drawn to the noxious odor. \n";
                sleep(3);
                cout << "Yup, it's a barracks alright.\n";
                sceneSix();
                break;

        
        case 3: 
                sceneEight();
                break;
    }
}

//empty deck
void sceneSeven() {
    cout << "Now that you are alone on the deck, you take a careful look around.\n"
         << "The deck is about 70 feet long, and has two masts. Near the back of the boat are the captain's quarters, and stairs down to the holds.\n"
         << "Above the captain's quarters is the poop deck.\n"
         << "The stairs you came out of are in the middle of the deck.\n"
         << "Towards the front of the boat are several barrels, and a giant cannon.\n";
    int response = getChoice(4,"Go back down the stairs","Approach the captain's quarters","Go to the poop deck","Go to the front of the boat");
    switch(response) {
        case 1:
            sceneTwo();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
    }
}
void sceneEight() {
    cout << "Not done yet...\n";
}
