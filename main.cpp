#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

#include <iomanip>
using std::setw;
using std::left;

#include <fstream>
using std::ifstream;
using std::ofstream; 


struct Track
{
  string webname;
  string password;
  Track* next;
};

void printMenu();
int compareStudents(Track*, Track*);
void removePassword(Track*&, int);
string encode(string);
string decode(string);


int main() 
{
  
  Track* firstTrack = 0, *lastTrack = 0;

  int size = 0;  
  char choice;
  printMenu();
  ifstream fin;
  fin.open("passwords.txt");
  if (fin.good( ))
    {
      while (true)
      {
        string buf;
        getline(fin, buf); 
        if (buf == "EOF") break;

        Track* temp = new Track;

        temp->webname = buf;
        fin >> temp->password; fin.ignore(1000, 10);
        temp->next = 0;
        if (lastTrack) lastTrack->next = temp;
        else firstTrack = temp;
        lastTrack = temp;
        size++;
    }
  }
  fin.close( );

  while (true)
  {
    cin >> choice;

    if (choice == 'A' || choice == 'a')
    {
      Track* temp = new Track;
      string buf;

      cin.ignore(1000, 10);
      cout << "\n***Adding New Password***";
      cout << "\nEnter the name of the website or account associated with the password > ";
      getline(cin, buf);
      temp->webname = buf;

      cout << "\nEnter the password for " << temp->webname << " > ";
      getline(cin, buf);
      temp->password = buf;

      
      Track* p, *prev; 
      for (p = firstTrack, prev = 0; p; prev = p, p = p->next)
        if (compareStudents(temp, p) < 0) break; 

      temp->next = p; 
      if (prev) prev->next = temp; 
      else firstTrack = temp; 
      if (p == 0) lastTrack = temp; 
      
      size++;

      printMenu();
    }

    else if (choice == 'E' || choice == 'e')
    {
      removePassword(firstTrack, size);
      printMenu();

    }

    else if (choice == 'L' || choice == 'l')
    {
      int index = 1;
  

      cout << "\nDisplaying passwords\n" << endl;
      cout << left << setw(3) << " #" << setw(14) << " Account" << setw(8) << "Password" << endl;
      cout << "--- ------------ ------- " << endl;

      for ( Track* p = firstTrack; p; p = p -> next, index++)
      {
        cout << " ";
        cout.width(4);
        cout << index;
        cout.width(14);
        cout << p -> webname;
        cout.width(8);
        cout << encode(p->password);
        cout << endl;
      }
      printMenu();

    }


    else if (choice == 'Q' || choice == 'q')
    {
      ofstream fout;
      fout.open("passwords.txt");

      int index = 1;
      for ( Track* p = firstTrack; p; p = p -> next, index++)
      {
        fout << p -> webname << endl;
        fout << p -> password << endl;       
      }
      fout << "EOF" << endl;
      fout.close();
      break;
    }


  }




}

void printMenu()
{
  // function to print the menu
  cout << "\n***MENU***" << endl;
  cout << "A Add a password" << endl;
  cout << "E Erase a password" << endl;
  cout << "L List all passwords" << endl;
  cout << "Press Q ..Quit"<< endl;
  cout << "Your choice > ";

}


int compareStudents(Track* a, Track* b)
{
  if (a->webname < b->webname) return -1;
  if (a->webname > b->webname) return 1;

  
  if (a->password < b->password) return -1;
  if (a->password > b->password) return 1;


  return 0;
}

void removePassword(Track*& first, int size)
{
  int choice;
  int index = 1;
  string buf;

  if(size)
  {
    cout << "Which password to remove [1-" << size << "]:";
    cin >> buf;
    choice = atoi(buf.c_str());

    Track* p, *prev;
    for(p = first, prev = 0; p; prev = p, p = p->next, index++)
      if(index == choice) break;
      
      if(p)
      {
        if (prev) prev->next = p->next; // skips over the node at p
        else first = p->next; // there's a new head, possibly zero
        delete p;
      }
    else
      cout << "Password " << choice << " not found\n";
  }
  else
    cout << "\n\nInvalid choice, please enter again > ";
    

    size--;

  
}

string encode(string aCppString)
{
  int n = aCppString.length( );
  for (int i = 0; i < n; aCppString[i]++, i++);
  return aCppString;
}

string decode(string aCppString)
{
  int n = aCppString.length( );
  for (int i = 0; i < n; aCppString[i]--, i++);
  return aCppString;
}
