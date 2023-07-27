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
    @since 07.27.2023
    */
    enum menuDeleteNodeOptions{

        OPT_DELETE_FIRST,
        OPT_DELETE_LAST,
        OPT_DELETE_CERTATIN_POSITION,
        OPT_EXIT_ADD
    };
/*
Ideas:

In every menu there is a few lines that shows a message for the menu, this can be separated in one function.
-The switch of the mainmenu can be extracted in another function since is too long
-Show the list, print the list whenever the user interacts with the list

*/
    /*
    @since 07.27.2023
    */
    void deleteLastNode(){

        if(header->next == NULL){
            deleteFirstNode();
        }else{
            Node *previous;
            Node *current = header;
            while(current->next != NULL){
                previous = current;
                current = current -> next;
            }
            previous -> next = NULL;
            tail = previous;
            delete current;
    }
    size --;
    }

    /*
    @since 07.27.2023
    */
    void deleteFirstNode(){

        Node *temp = header;
        header = header -> next;
        delete temp;
        size--;
    }
    /*
    @since 07.27.2023
    */
    void menuDeleteNode(){
        int optionMenu;
        do{
            cout << "---------DELETE NODE MENU----------" << endl
                 << "Please select an option:"<<endl
                 << OPT_DELETE_FIRST << ") Delete first node." << endl
                 << OPT_DELETE_LAST << ") Delete last node." << endl
                 << OPT_DELETE_CERTATIN_POSITION << ")Delete node at an specific position." << endl;
                 cin >> optionDeleteNode;
        } while (optionDeleteNode != 0);

            switch (optionDeleteNode){

            case OPT_DELETE_FIRST:
                deleteFirstNode();
                break;
            case OPT_DELETE_LAST:
                break;
            case OPT_DELETE_CERTATIN_POSITION:
                break;
            default;
                break;
        }
    }

    /*
    @since 07.26.2023
    */
    void addNodeCertainPosition(int position, int data){

        Node *node = new Node(data);
        Node *previous;
        Node *current = header;

        //Case 1: If the user inserts an invalid position, a message will be shown.
        if(position < 1 || position > size + 1){
            cout << "Invalid position, please try again."<<endl;
        }
        /*
        Case 2: If the user inserts position 1, it means that wants to add a node at the beginning of the list.
        instead of executing the process again, it is better to call the prepend method.
        */
        else if(position == 1){
            prependMethod();
        }
        /*
        Case 3: If the user inserts as position the size of the list plus 1, that means that the user wants to insert
        a node at the end of the list, call append method.
        */
        else if (position == size + 1){
            appendMethod();
        /*
        Case 4: If the user inserts a valid position between the first and the last node.
            Step 1: Create a new node and assign the information the user inserted.
            Step 2: Create a new node called previous.
            Step 3: Create a new node called current that points to the node header is pointing.
            Step 4: Run a cycle to go through all the elements of the list, this cycle stop at the position the user inserted.
                    While this is happening, previous will point to the node that current is pointing, and current will point to
                    its next node.
            Step 5: When the cycle stops, previous will be one position BEFORE the position the user inserted, and CURRENT will
                    at the EXACT position the user inserted.
                    Then, the next element of previous is the new node the user created and the next element of the new node is
                    the node that current is pointing.
        */
        } else {
            for (int i = 1; i < position; i++){
                previous = current;
                current = current ->next;
            }
            previous -> next = node;
            node -> next = current;
        }
        //Increment the size
        size ++;
    }

    /*
    @since 07.26.2023
    */
    void menuOptionAddNodeCertainPosition(){

         int data, position;

         do{
             cout<<"Please insert the position you want to insert the node in:"<<endl;
             cin >> position;
             cout<<"Please insert the data you want to be within the node (an integer):"<<endl;
             cin >> data;
         }while(position < 1 || position > size + 1);
         addNodeCertainPosition(position, data);
    }

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
     menuAddOptionEnding is a void function with the only purpose to show a message that indicates the user to insert an
     integer, store it in a variable, and then send that information as a parameter to prependMethod() function.
     @author Anette Larios
     @since 07.26.2023
     */

    void menuOptionAddNodeAtBeggining(){
        int data;
        cout << "Please insert the data you want to insert within the node (an integer):"<<endl;
        cin >> data;
        prependMethod(data);
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

        int optionMenu;
        int data;
        do{
            cout<<"-------ADD NODE MENU------"<<endl
                <<"Please select an option: "<<endl
                <<OPT_ADD_BEGINNING<<") Add a node at the beginning of the list."<<endl
                <<OPT_ADD_ENDING<<") Add a node at the end of the list."<<endl
                <<OPT_ADD_CERTAIN_POSITION<<") Adddd  a node at a certain position within the linked list."<<endl
                <<OPT_EXIT_ADD<<")Exit from add node menu."<<endl;
                cin >> optionAddNodeMenu;

                switch(optionAddNodeMenu){

                    case OPT_ADD_BEGINNING:
                        menuOptionAddNodeAtBeggining();
                        break;
                    case OPT_ADD_ENDING:
                        menuOptionAddNodeAtEnding();
                        break;
                    case OPT_ADD_CERTAIN_POSITION:
                        menuOptionAddNodeCertainPosition();
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

        int optionMenu;

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
                    if(header != NULL){
                    menuDeleteNode();
                    } else
                    cout << "The list is empty, you can delete any elements." <<endl;
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
