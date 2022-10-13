#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string> 

using namespace std;

/*Prototype Funtions*/
void TranslatePick(int flag_who, char selection, char pick[5]);
char ComputerSelectRPSLK(char pick[5]);
int versus(char userPick, char computerPick,char pick[5]);
void whoWon(int WinState, char pick[5]);

/* Main */

int main()
{

  //declare array 
  char pick[5];
  pick[0]='R';
  pick[1]='P';
  pick[2]='S';
  pick[3]='L';
  pick[4]='K';
  
// declare variables
  char userPick='A';              //users selection for the game
  bool valid_pick = false;    // flage controlled while loop for obtaining user input
  char computerPick;          //randomly selected computer selection for the game
  int WinState;
  
  srand(time(NULL));
  //Display rules of the game

  cout << "It's time to play Rock, Paper, Scissors, Lizard, Spock!" << endl;
  cout << "Use R (for Rock), P (for Paper), S (for Scissors)," << endl;
  cout << "L (for Lizard), and K (for Spock)." <<endl;

  // Obtain userPick. Prompt until vaild selection is made.

  while (valid_pick == false)
  {
    cout << "You chose: ";
    cin >> userPick;

    for (int i=0; i < 5; i++)
    {
    if (userPick == pick[i])
    {
      valid_pick = true;
    }  
    
   else if(!valid_pick && i==4)
      cout << "Invalid Selection. Try again." << endl;
    }
  }
  // Repaet selection back to user 
  TranslatePick (0, userPick, pick);
  computerPick = ComputerSelectRPSLK( pick);
TranslatePick(1, computerPick, pick); // Inform user of computers selection
  WinState = versus(userPick, computerPick, pick);
 
whoWon(WinState, pick);
  return 0;
}
void TranslatePick(int flag_who, char selection, char pick[5])
{
//declare local funation variables
string who_text;
  // identify which statements to insert into output below 
if (flag_who == 0)
  who_text = "You";
else
  who_text = "The Computer";
//display output where the char selection is translated into words 
if (selection == pick[0])
  cout << who_text << " selected Rock."<< endl;
else if (selection == pick[1])
  cout << who_text <<" selected Paper."<<endl;
else if (selection == pick[2])
  cout << who_text <<" selected Scissors."<<endl;
else if (selection == pick[3])
  cout << who_text <<" selected Lizard."<<endl;
else if (selection == pick[4])
  cout << who_text <<" selected Spock."<<endl;
else // somthing is wrong
  cout << "Check code for errors. Message from TranslatePick fcn."<< endl;
}
char ComputerSelectRPSLK(char pick[5])
{
  //declare local function variables
  char randPickChar;
  int randPick;
  // Pick a random number from 0 to 4
  srand (time(NULL)); // initialize random seed.
  randPick = rand()% 5; // gives us 0 to 4
  //cout< randPick; // uncomment to debug

  //assiagn random number to letter
  switch (randPick)
    {
      case 0:
          randPickChar = pick[0];
          break;
      case 1:
          randPickChar =pick[1];
          break; 
      case 2:
          randPickChar =pick[2];
          break;
      case 3:
          randPickChar =pick[3];
          break;
      case 4:
          randPickChar =pick[4];
          break;
      default:
        cout << "error in the function ComputerSelectRPSLK."<< endl;
    }
  return randPickChar;
}

// function for part A
int versus(char userPick, char computerPick, char pick[5])
{
  if (userPick== pick[0])//user picks rock
  {
    if( computerPick == pick[0]){
      //cout << "Tie. Please try again."<< endl;
      return 0;
    }
    else if (computerPick == pick[1]) 
    {
      cout << "Paper beats Rock!"<< endl;
      return -1;
    }
    else if (computerPick ==pick[4])
    {
      cout<< "Spock beats Rock!" << endl;
      return -1;
      }
        
    else if (computerPick == pick[2])
    {
     cout << "Rocks beats Scissors!"<< endl;
      return 1;
    }
    else if (computerPick == pick[3])
    {
      cout << "Rock beats Lizard!"<< endl;
      return 1;
    }
  }

  if (userPick == pick[2])//user picks scissors
  {
    if( computerPick == pick[2]){
      //cout << "Tie. Please try again."<< endl;
      return 0;
    }
    else if (computerPick == pick[0]) 
    {
      cout << "Rock beats Scissors!"<< endl;
      return -1;
    }
    else if (computerPick ==pick[4])
    {
      cout<< "Spock beats Scissors!" << endl;
      return -1;
      }
        
    else if (computerPick == pick[1])
    {
     cout << "Scissors beats Paper!"<< endl;
      return 1;
    }
    else if (computerPick == pick[3])
    {
      cout << "Scissors beats Lizard!"<< endl;
      return 1;
    }
  }

if (userPick == pick[2])//user picks scissors
  {
    if( computerPick == pick[2]){
      //cout << "Tie. Please try again."<< endl;
      return 0;
    }
    else if (computerPick == pick[0]) 
    {
      cout << "Rock beats Scissors!"<< endl;
      return -1;
    }
    else if (computerPick ==pick[4])
    {
      cout<< "Spock beats Scissors!" << endl;
      return -1;
      }
        
    else if (computerPick == pick[1])
    {
     cout << "Scissors beats Paper!"<< endl;
      return 1;
    }
    else if (computerPick == pick[3])
    {
      cout << "Scissors beats Lizard!"<< endl;
      return 1;
    }
  }

if (userPick == pick[1])//user picks Paper
  {
    if( computerPick == pick[1]){
      //cout << "Tie. Please try again."<< endl;
      return 0;
    }
    else if (computerPick == pick[2]) 
    {
      cout << "Scissors beats Paper!"<< endl;
      return -1;
    }
    else if (computerPick ==pick[3])
    {
      cout<< "Lizard beats Paper!" << endl;
      return -1;
      }
        
    else if (computerPick == pick[4])
    {
     cout << "Paper beats Spock!"<< endl;
      return 1;
    }
    else if (computerPick == pick[0])
    {
      cout << "Paper beats Rock!"<< endl;
      return 1;
    }
  }
  
if (userPick == pick[3])//user picks Paper
  {
    if( computerPick == pick[3]){
      //cout << "Tie. Please try again."<< endl;
      return 0;
    }
    else if (computerPick == pick[0]) 
    {
      cout << "Rock beats Lizard!"<< endl;
      return -1;
    }
    else if (computerPick ==pick[2])
    {
      cout<< "Scissors beats Lizard!" << endl;
      return -1;
      }
        
    else if (computerPick == pick[4])
    {
     cout << "Lizard beats Spock!"<< endl;
      return 1;
    }
    else if (computerPick == pick[1])
    {
      cout << "Lizard beats Paper!"<< endl;
      return 1;
    }
  }

  if (userPick == pick[4])//user picks Spock
  {
    if( computerPick == pick[4]){
      //cout << "Tie. Please try again.<< endl;
      return 0;
    }
    else if (computerPick == pick[3]) 
    {
      cout << "Lizard beats Spock!"<< endl;
      return -1;
    }
    else if (computerPick ==pick[1])
    {
      cout<< "Paper beats Spock!" << endl;
      return -1;
      }
        
    else if (computerPick == pick[2])
    {
     cout << "Spock beats Scissors!"<< endl;
      return 1;
    }
    else if (computerPick == pick[0])
    {
      cout << "Spock beats Rock!"<< endl;
      return 1;
    }
  }  
}

void whoWon(int WinState, char pick[5])
{
  if (WinState == 0)
  {
    cout<<"It is a Tie!"<<endl;
  }
  else if (WinState == -1)
  {
    cout << "You Lose!"<< endl;
  }
  else if (WinState == 1)
  {
    cout << "You Win!"<< endl;
  }  
}
