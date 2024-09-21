//Bushra Shafqat 2461
// DSA Project (30,dec,2021)

#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
using namespace std;

// Node to store words in data part
class Node
{
    public:
        string word;
        char Alphabet;
        Node *right;
        Node *down;
        Node(string w = NULL, char a = 0, Node *r = NULL, Node *d = NULL)
        {
            word = w;
            Alphabet = a;
            right = r;
            down = d;
        }
};

class Dictionary
{
public:
    Node *Head;
    int NumberOfWords=0;
    // constructor initially pointing head node to NULL(empty dictionary)
    Dictionary()
    {
        Head = NULL;
    }
    // destructor delete all nodes(empty dictionary)
    ~Dictionary()
    {
        Node *Current = Head;
        Node *nextWord = NULL;
        while (Current != 0)
        {
            nextWord = Current->right;
            delete Current;
            Current = nextWord;
        }
 
    }

    
    
       //insert all Alphabets in the new linked list from dictionary
    void Insert_Alphabets(string word)
    {
        Node *CurrentWord = Head;
                char str[NumberOfWords];
                int i=0;
                while(CurrentWord!= NULL){
                    if(i<NumberOfWords)
                    str[i]=CurrentWord->word.at(0);
                    i++;
                    CurrentWord=CurrentWord->right;
                }
                char temp;

                for( int i = 0; i < NumberOfWords; ++i)
                {
                    if(str[i] > str[i+1])
                    {
                        temp = str[i];
                        str[i] = str[i+1];
                        str[i+1] = temp;
                    }
                }
                CurrentWord = Head;
                    int x=0;
                  while(CurrentWord!= NULL){
                      if(i<NumberOfWords)
                   CurrentWord->Alphabet=str[x];
                   x++;
                    CurrentWord=CurrentWord->down;
                }
        
    }


    //insert all words in the new linked list from dictionary
    void Insert_Words(string word)
    {
        // inserting new word in the node
        Node *NewWord = new Node(word);

        // inserting word in Alphabetical order ( comparing ASCII value of first letter of each word)
        if (Head == NULL)
            Head = NewWord;
        else
        {
            Node *Current = Head;
            // bool repeat = false ;
            while(Current!=NULL){
                if(Current->word == word){
                    break;
                }
                Current=Current->right;
            }
            if(Current==NULL)
            NewWord->right = Head;
            Head = NewWord;
        }
    }

//replace new word with old one 
void Update_Word(string existing , string newWord){
     Node *Current = Head;
        //Case 1 : No word in the dictionary
        if(Current==NULL){
            cout << " Dictionary is empty "<< "\"" << existing << "\" Not found"<< endl ;
        }else if(Current->word==existing){     // case 2 : word is at head
            Current->word=newWord;
        }else {
            Current= Head ;
            while(Current!=NULL && Current->word!=existing){
                Current=Current->right;
            }
            if (Current){
            Current->word=newWord;
            cout << "\"" << existing << "\" is replaced with \""<< newWord<<"\"" << endl ;
            }else{
                 cout << "word \"" << existing << "\" can't be replaced as ,it is not available in the dictionary." << endl ;
            }
        }
}
// search and display the location of word being searched
 void Search_Word(string word){
         Node *Current = Head;
        //Case 1 : No word in the dictionary
        if(Current==NULL){
            cout << " Dictionary is empty "<< "\"" << word << "\" Not found"<< endl ;
        }else if(Current->word==word){     // case 2 : word is at head
                 cout << "\"" << word << "\" found in the dictionary at number 1." << endl ;

        }else {
            Current= Head ;
            int wordNumber =1 ;
            while(Current!=NULL && Current->word!=word){
                Current=Current->right;
                wordNumber++;
            }
            if (Current){
                cout << "\"" << word << "\" found in the dictionary at number "<< wordNumber << endl ;
            }else{
                 cout << "\"" << word << "\" Not found in the dictionary." << endl ;
            }
        }
 }
// sort and display all words in alphabetical order
void Sort_Words()
{
    Node *Current=Head ;
    Node *Temp = NULL ;
    string stemp ;
    int i;
    if(Head==NULL)
    return ;
    else {
        while(Current!=NULL){
            Temp=Current->right;
             while(Temp!=NULL){
                if(Current->word.at(0) > Temp->word.at(0)){
                    stemp=Current->word;
                    Current->word= Temp->word;
                    Current->Alphabet= Temp->Alphabet;
                    Temp->word=stemp;
                    Temp->Alphabet=stemp.at(0);
                }
                Temp=Temp->right;
             }
             Current=Current->right;
        }
    }
    Current=Head;
    cout << " All words in the dictionary are : (Alphabetical order)"<< endl;
    while (Current!=NULL){
        cout << Current->word << "      " ;
        Current->Alphabet=Current->word.at(0);
        Current=Current->right;
    }
        cout << endl ;
}




    // searching and removing word from the dictionary ( by deleting node containing that word)
    void Delete_Word(string word){
        Node *Current = Head;
        //Case 1 : No word in the dictionary
        if(Current==NULL){
            cout << " Dictionary is empty"<< endl ;
        }else if(Current->word==word){     // case 2 : word is at head
                Head = Head->right;
                delete Current ;
             cout << "\"" << word << "\" deleted from the dictionary!" << endl ;
        }else { // Case 3 : word exist anywhere in the list
            Node *previous = NULL ;
            Current= Head;
            while(Current!=NULL && Current->word!=word){
                previous = Current;
                Current=Current->right;
            }
            // word found then delete
            if (Current){
                previous->right=Current->right;
                Current->right=NULL;
                delete Current;
             cout << "\"" << word << "\" deleted from the dictionary!" << endl ;
            }else{ // word not found in the dictionary
                 cout << "\"" << word << "\" does Not exist in the dictionary. "<< endl ;
            }
        }
    }


    // traversing and displaying all words of a specific from the text file
    void Display_Words(char ch)
    {
        Node *CurrentWord = Head;
        string str[NumberOfWords];
        int i=0;
        while(CurrentWord!= NULL){
            if(i<NumberOfWords)
            str[i]=CurrentWord->word;
            i++;
            CurrentWord=CurrentWord->right;
        }
        string temp;
        for(int i = 0; i < NumberOfWords-1; ++i)
        for( int j = i+1; j < NumberOfWords; ++j)
        {
            if(str[i] > str[j])
            {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
        bool present=false;
            cout << endl;
            // cout << " All words present in the dictionary with starting letter \""<< ch << "\" : "<< endl ;
            for(int i = 0; i < NumberOfWords; ++i)
            {
                if(str[i].at(0)==ch){
                    present=true;
                    cout << str[i] << "      ";
                }
            }
            cout << endl  << endl ;
            if(present==false)
            cout << "No word starting with \""<< ch <<"\" is Available in the dictionary."<<endl;
    }


    // traversing and displaying all nodes containing Alphabets from the text file
    void Display_Alphabet(){
        Node *Current = Head ;
        Node *Temp = Head ;
        // if dictionary is empty
        if(Current==NULL){
            cout << " No Alphabet available yet!"<< endl ;
        }else{  // data available 
        cout << " Words with following letters are available in the Dictionary(In Sorted order) : "<< endl ;
        Current=Head->right;
            while(Current->right!=NULL){
                if(Current->Alphabet==Current->right->Alphabet){

                }else
                cout << Current->Alphabet << "      " ;
                Current= Current->right;
            }

            cout << endl ;
        }
    }
    
    void readFile()
    {
        ifstream file;
        file.open("Dictionary.txt");
        // file.open("D.txt");
        if (!file.is_open())
            return;

        string word;
        while (file >> word)
        {
            NumberOfWords++;
            Insert_Words(word);
            Insert_Alphabets(word);
        }
    }
};
int main()
{
    Dictionary obj;
    cout << " Press 1 : To Insert All Words and Alphabet in Dictionary" << endl
         << " Press 2 : To Display All words in Aplhabetical order " << endl
         << " Press 3 : To Display All words starting with a letter of user's choice" << endl
         << " Press 4 : To Display Starting Letter of each word entered Yet!" << endl
         << " Press 5 : To Search a word in the dictionary" << endl
         << " Press 6 : To take a word from user and insert in the Dictionary. " << endl
         << " Press 7 : To delete a word from the Dictionary. " << endl
         << " Press 8 : To update a word in the Dictionary. " << endl
         << " Press 0 : To Exit " << endl;
    int choice;
    // opening the text file containing all words
    do
    {
        string word, str, replace;

        // option user will select
        cout << " Enter your choice " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            obj.readFile();
            cout << "All Words and Alphabets inserted in the Dictionary." << endl;
        break;
        case 2 :
            obj.Sort_Words();
        break;
        case 3:
            char Alphabet ;
            cout << " Enter an alphabet : "<< endl ;
            cin >> Alphabet;
            obj.Display_Words(Alphabet);
        break;
        case 4 :
            obj.Display_Alphabet();
        break ;
        case 5 :
            cout<<"Enter The word you want to search: " << endl;
            cin>>word;
            obj.Search_Word(word);
        break ;
        case 6 :
            cout<<"Enter The word you want to add in the dictionary: " << endl ;
            cin>>word;
            cout << "\"" << word << "\" inserted in the dictionary! "<< endl ;
            obj.Insert_Words(word);
        break ;
        case 7 :
            cout<<"Enter The word you want to delete from the dictionary: "<< endl ;
            cin>>word;
            obj.Delete_Word(word);
        break ;
        case 8 :
            cout<<"Enter The word you want to replace in the dictionary: "<< endl ;
            cin>>word;
            cout<<"Enter The word you want to replace with \""<< word << "\"." << endl;
            cin>>replace;
            obj.Update_Word(word,replace);
        break ;
        case 0 :
               cout << endl << endl << " \t\t\t\tProgram Ended!"<< endl << endl <<endl;
        break ;
        default:
            cout << " Invalid option selected! " << endl;
        break;
        }
    } while (choice != 0);
    return 0;
}