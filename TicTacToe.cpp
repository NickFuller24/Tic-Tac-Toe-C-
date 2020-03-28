//
//
//

#include <iostream>
using namespace std;

struct box
{
  bool m_filled;
  char m_char;
  short m_val;
};

ostream& operator<<(ostream& o, const box & b)
{
  o << b.m_char;
  return o;
}

void reset_boxes(box arr[]);
void reset_totals(short arr[]);
void disp_board(const box arr[]);
bool check_choice(const short val, const box arr[]);
void find_totals(const box boxes[], short totals[]);

//Global Constants
const short TOTAL_BOX = 9;
const short CHOICE_1 = 1;
const short CHOICE_2 = 2;
const short CHOICE_3 = 3;
const short CHOICE_4 = 4;
const short MAX_CHOICE = 4;
const short MIN_CHOICE = 1;
const short MAX_BOX = 9;
const short MIN_BOX = 1;
const short WIN_TOTAL_1 = 15; //Need to change this value
const short WIN_TOTAL_2 = 9; //Need to change this value
const short TOTAL_SIZE = 8;

int main()
{ 
  //Declarations
  
  short user_choice;
  short play_count = 1;
  short user_1;
  short user_2;
  bool valid;
  bool winner = false;
  bool quit = false;
  
  //boxes
  box box_arr[9];
  reset_boxes(box_arr);

  //Array of totals
  short total_arr[8];
  reset_totals(total_arr);

  //Greeting
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  cout << " Welcome to my Tic Tac Toe Game :) " << endl;
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

  do
  {
    do
    {
      cout << "1. If you want to play a game by yourself, choose option 1." << endl;
      cout << "2. To play a two person game, choose option 2." << endl;
      cout << "3. For a list of rules, choose option 3." << endl;
      cout << "4. To quit the game, choose option 4." << endl << endl;

      cout << "Enter your choice: ";
      cin >> user_choice;

      //Validate user_choice
      if(user_choice > MAX_CHOICE || user_choice < MIN_CHOICE)
      {
        cout << "**********************************************" << endl;
        cout << "Invalid Choice! Please pick option 1,2,3, or 4" << endl;
        cout << "**********************************************" << endl;
      }
    }while(user_choice > MAX_CHOICE || user_choice < MIN_CHOICE);

    switch(user_choice)
    {
      case CHOICE_1:
      {
        cout << "This feature hasn't been created yet." << endl;
        break;
      }

      case CHOICE_2:
      {
        do
        {
          //Display board and validate choice
          do
          {
            disp_board(box_arr);
            if(play_count % 2 == 0)
            {
              cout << "User 2(O's), enter your choice: ";
              cin >> user_2;
              valid = check_choice(user_2,box_arr);
              if(valid)
              {
                box_arr[user_2-1].m_filled = true;
                box_arr[user_2-1].m_val = 3;
                box_arr[user_2-1].m_char = 'O';
              }
            }
            else
            {
              cout << "User 1(X's), enter your choice: ";
              cin >> user_1;
              valid = check_choice(user_1,box_arr);
              if(valid)
              {
                box_arr[user_1-1].m_filled = true;
                box_arr[user_1-1].m_val = 5;
                box_arr[user_1-1].m_char = 'X';
              }
            }
          }while(valid == false);
        
          play_count++;                      //Controls whose turn it is

          //Once there have been 6 turns(someone can win)
          if(play_count >= 6)
          {
            find_totals(box_arr, total_arr);
          
            //check totals for winner
            for(int i = 0; i < TOTAL_SIZE; i++)
            {
              if(total_arr[i] == WIN_TOTAL_1)
              {
                disp_board(box_arr);
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                cout << "Player one wins!!! Congrats :)" << endl;
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                winner = true;
              }
              else if(total_arr[i] == WIN_TOTAL_2)
              {
                disp_board(box_arr);
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                cout << "Player two wins!!! Congrats :)" << endl;
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                winner = true;
              }
              else if(play_count == 9)
              {
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                cout << "Cat Game! No one wins... or everyone wins..." << endl;
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                winner = true;
              }
            }
          }
        }while(!winner);

        //reset everything
        reset_boxes(box_arr);
        reset_totals(total_arr);
        winner = false;
        play_count = 1;

        break;
      }

      case CHOICE_3:
      {
        cout << "It's tic tac toe... it's pretty self explanatory" << endl;
        cout << "More rules to be added later" << endl;
        break;
      }

      case CHOICE_4:
      {
        quit = true;
        break;
      }
    }
  }while(!quit);

  return 0;
}

void reset_boxes(box arr[])
{
  for(int i = 0; i < TOTAL_BOX; i++)
  {
    arr[i].m_filled = false;
    arr[i].m_val = 0;
  }
  arr[0].m_char = '1';
  arr[1].m_char = '2';
  arr[2].m_char = '3';
  arr[3].m_char = '4';
  arr[4].m_char = '5';
  arr[5].m_char = '6';
  arr[6].m_char = '7';
  arr[7].m_char = '8';
  arr[8].m_char = '9';
  return;
}

void reset_totals(short arr[])
{
  for(int i = 0; i < TOTAL_SIZE; i++)
  {
    arr[i] = 0;
  }
  return;
}

void disp_board(const box arr[])
{
  cout << endl;
  cout << " " << arr[0] << " | " << arr[1] << " | " << arr[2] << " " << endl;
  cout << "----------" << endl;
  cout << " " << arr[3] << " | " << arr[4] << " | " << arr[5] << " " << endl;
  cout << "----------" << endl;
  cout << " " << arr[6] << " | " << arr[7] << " | " << arr[8] << " " << endl;
  cout << endl;
  return;
}

bool check_choice(const short val, const box arr[])
{
  bool valid;
  if(val < MIN_BOX || val > MAX_BOX)
  {
    cout << "******************************" << endl;
    cout << "Invalid Choice! Pick a Box 1-9" << endl;
    cout << "******************************" << endl;
    valid = false;
  }
  else if(arr[val-1].m_filled)
  {
    cout << "***********************************" << endl;
    cout << "Invalid Choice! This box is filled!" << endl;
    cout << "***********************************" << endl;
    valid = false;
  }
  else
  {
    valid = true;
  }
  
  return valid;
}

void find_totals(const box boxes[], short totals[])
{
  //total0 across1
  totals[0] = boxes[0].m_val + boxes[1].m_val + boxes[2].m_val;
  //total1 across2
  totals[1] = boxes[3].m_val + boxes[4].m_val + boxes[5].m_val;
  //total2 across3
  totals[2] = boxes[6].m_val + boxes[7].m_val + boxes[8].m_val;
  //total3 down1
  totals[3] = boxes[0].m_val + boxes[3].m_val + boxes[6].m_val;
  //total4 down2
  totals[4] = boxes[1].m_val + boxes[4].m_val + boxes[7].m_val;
  //total5 down3
  totals[5] = boxes[2].m_val + boxes[5].m_val + boxes[8].m_val;
  //total6 diag1
  totals[6] = boxes[0].m_val + boxes[4].m_val + boxes[7].m_val;
  //total7 diag2
  totals[7] = boxes[2].m_val + boxes[4].m_val + boxes[6].m_val;
  return;
}