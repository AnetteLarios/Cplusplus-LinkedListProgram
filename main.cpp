#include <iostream>

using namespace std;

/*
Class node simulates the node object that contains the data and a pointer.
@author Anette Larios
@since 07.25.2023
*/
class Node{

    public:
        int data;
        //This is a node object called next, it is a pointer that will point to the next element.
        Node *next;


        //Class Constructor
        Node(int data){
            //assign the data received to the node
            this->data = data;
            //the pointer will point to null
            next = NULL;
        }
};

class LinkedList{

    private:
        Node *header;
        Node *tail;
        int size;
    public:
        //Class constructor
        LinkedList(){
          header = NULL;
          tail = NULL;
          size = 0;
        }
    /*
    @since 07.21.2023
    */
    enum mainmenuOptions{

        OPT_EXIT,
        OPT_ADD_NODE,
        OPT_DELETE_NODE,
        OPT_DELETE_ALL,
        OPT_SEARCH_NODE,
        OPT_SHOW_LIST

    };

    /*
    @since 07.21.2023
    */
    enum menuAddNodeOptions{

        OPT_ADD_BEGINNING,
        OPT_ADD_ENDING,
        OPT_ADD_CERTAIN_POSITION,
        OPT_EXIT_ADD
    };

    /*
    @since 07.26.2023
    */
     void prependMethod(int data){
        Node *node = new Node(data);
       //Case 1: If the list is not empty the new node is the only element, header and tail have to point to this new node.
        if(header == NULL){
            header = node;
            tail = node;
        /* Case 2 : If the list is not empty, then is necessary to have a pointer where will be saved the node that header
        is pointing, then the new node becomes the one header is pointing and this new header, will have as next element the
        node that temp is pointing.
        */
        } else {
          Node *temp = header;
          header = node;
          node-> next = temp;
        }
        //In both cases it is necessary to increment the size as we are adding a new node.
        size ++;
     }



    /*
    @since 07.25.2023
    */
    void appendMethod(int data){

        Node *node = new Node(data);

        //If the list is empty, header and tail are going to point to the only element on the list
        if(header == NULL){
           header = node;
           tail = node;
        }
        else{
           // Tail contains the last node of the list, so the new node, will be the next node
           tail->next = node;
           //And now tail is pointing to this new node that became the last node within the linked list.
           tail = node;
        }
        size++;
    }

    void menuOptionAddNodeAtEnding(){

        int data;
         cout<<"Please insert the data you want to be within the node (an integer):"<<endl;
         cin>>data;
         appendMethod(data);
    }

    void menuAddNode(){

        int optionAddNodeMenu;
        int data;
        do{
            cout<<"-------ADD NODE MENU------"<<endl
                <<"Please select an option: "<<endl
                <<OPT_ADD_BEGINNING<<") Add a node at the beginning of the list."<<endl
                <<OPT_ADD_ENDING<<") Add a node at the end of the list."<<endl
                <<OPT_ADD_CERTAIN_POSITION<<") Add a node at a certain position within the linked list."<<endl
                <<OPT_EXIT_ADD<<")Exit from add node menu."<<endl;
                cin >> optionAddNodeMenu;

                switch(optionAddNodeMenu){

                    case OPT_ADD_BEGINNING:
                        //add to the beginning
                        break;
                    case OPT_ADD_ENDING:
                        menuOptionAddNodeAtEnding();
                        break;
                    case OPT_ADD_CERTAIN_POSITION:
                        //add a certain position function.
                        break;
                    default:
                        break;
                }
        } while (optionAddNodeMenu != 0);
    }

    /*
    @since 07.21.2023
    */
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
                    menuAddNode();
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
                    cout << "Invalid option, please try again."<<endl;
                    break;
             }

        }while( option != 0);
    }
};

/*
@since 07.21.2023
*/
int main(){
    LinkedList().mainMenu();
}
