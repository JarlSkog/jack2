/**Anders Skog
   CS150-01
   Jack-o-Lantern 2**/
#include <iostream>
#include <windows.h> //Needed to display colors
using namespace std;

void displayMenu();     //Prototypes
int getChoice();
void makeJack0Lantern();

const int QUIT = 6, MAX_CHOICE = 6; //Global constants

int main()
{
    int colorChoice;
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE); //Get the handle to standard output device (the console)

    do
    {   SetConsoleTextAttribute(screen, 7); //Set to white on black for menu display
        displayMenu();
        colorChoice = getChoice();

        if (colorChoice != QUIT)
        {   SetConsoleTextAttribute(screen, colorChoice + 9);
            makeJack0Lantern();
        }
    } while (colorChoice != QUIT);
    return 0;
}

/**                 displayMenu
This function disp[lays the menu of color choices.**/
void displayMenu()
{   system("cls");      //Clear the screen
    cout << "I will draw a Jack-o-lantern. What color should it be?\n\n"
         << "Enter 1 for Green  2 for Blue  3 for Red \n"
         << "   4 for Purple    5 for yellow    6 to quit: ";
}

/**                         getChoice
This function inputs, validates, and returns the user's menu choice**/
int getChoice()
{
    int choice;

    cin >> choice;
    while (choice < 1 || choice > MAX_CHOICE)
    {   cout << "\nThe only valid choices are 1-" << MAX_CHOICE
             << ". Please ree-enter. ";
        cin >> choice;
    }
    return choice;
}
/**                         makeJack0Lantern
This function draws a Jack-o-lantern in whatever color the user selected**/
void makeJack0Lantern()
{
    cout << "\n\n";
    cout << "                   ^   ^   \n";
    cout << "                     *     \n";
    cout << "                   \\___/    " << endl;
    cout << "\n\n      Press ENTER to return to the menu.";
    cin.get();          //Clear the previous \n out of the input buffer
    cin.get();          //Wait for the user to press ENTER
}
