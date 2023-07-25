#include <iostream>

using namespace std;

enum mainmenuOptions{

    OPT_EXIT,
    OPT_ADD_NODE,
    OPT_DELETE_NODE,
    OPT_DELETE_ALL,
    OPT_SEARCH_NODE,
    OPT_SHOW_LIST

};


void mainMenu(){

    int option;

    do{
    cout << "-----------------LINKED LIST MAIN MENU--------------"<<endl
         << "Please select an option:" <<endl
         << OPT_ADD_NODE << ") ADD NODE." <<endl
         << OPT_DELETE_NODE << ") DELETE NODE AT A SPECIFIC POSITION" <<endl
         << OPT_DELETE_ALL << ") DELETE LINKED LIST"  <<endl
         << OPT_SEARCH_NODE << ") SEARCH NODE" <<endl
         << OPT_SHOW_LIST << ") SHOW LIST" <<endl
         << OPT_EXIT << ") EXIT";
         cin >> option;

         switch(option){

            case OPT_ADD_NODE:
                break;
            case OPT_DELETE_NODE:
                break;
            case OPT_DELETE_ALL:
                break;
            case OPT_SEARCH_NODE:
                break;
            case OPT_SHOW_LIST:
                break;
            case OPT_EXIT:
                break;
            default:
                break;
         }



    }while( option != 0);
}


int main()
{
    mainMenu();
    return 0;
}
