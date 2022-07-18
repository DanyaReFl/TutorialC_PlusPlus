#include <iostream>
#define X_WIN 1
#define O_WIN 2
#define ERROR 3

int win(std::string top,std::string mid,std::string bot)
{
    int countWin(0);
    int  win(0);

    if ( (top[0]==top[1]) && (top[1]==top[2]) )
    {
        if (top[0]=='X') { win=X_WIN; countWin++; }
        else if  (top[0]=='O') { win=O_WIN; countWin++; }
    }
    if ( (mid[0]==mid[1]) && (mid[1]==mid[2]) )
    {
        if (mid[0]=='X') { win=X_WIN; countWin++; }
        else if  (mid[0]=='O') { win=O_WIN; countWin++; }
    }
    if ( (bot[0]==bot[1]) && (bot[1]==bot[2]) )
    {
        if (bot[0]=='X') { win=X_WIN; countWin++; }
        else if  (bot[0]=='O') { win=O_WIN; countWin++; }
    }
    if (countWin>1) return ERROR;
    else
    {
        for (int i(0) ; i<3 ; i++ )
        {
            if ( (top[i]==mid[i]) && (mid[i]==bot[i]) ){
                if (top[i]=='X') { win=X_WIN; countWin++; }
                else if  (top[i]=='O') { win=O_WIN; countWin++; }
            }
        }
    }

    if (countWin>1) return ERROR;
    else
    {
        if ( (top[0]==mid[1]) && (mid[1]==bot[2]) )
        {
            if (top[0] == 'X') {
                win = X_WIN;
                countWin++;
            }
            else if (top[0] == 'O') {
                win = O_WIN;
                countWin++;
            }
        }
        if ( (top[2]==mid[1]) && (mid[1]==bot[0]) )
        {
            if (bot[0] == 'X') {
                win = X_WIN;
                countWin++;
            }
            else if (bot[0] == 'O') {
                win = O_WIN;
                countWin++;
            }
        }
    }
    if (countWin>1) return ERROR;
    else if (countWin) {
        if (win==1) return X_WIN;
        else return O_WIN;
    }
    else return NULL;
}

int  correct(std::string top,std::string mid,std::string bot)
{
    int X(0),O(0);
  for (int i(0) ; i<3 ; i++)
  {
      if ( (top[i]!='.') && (top[i]!='X') && (top[i]!='O') ) return ERROR;
      if ( (mid[i]!='.') && (mid[i]!='X') && (mid[i]!='O') ) return ERROR;
      if ( (bot[i]!='.') && (bot[i]!='X') && (bot[i]!='O') ) return ERROR;
      if (top[i]=='X') X++;
      if (mid[i]=='X') X++;
      if (bot[i]=='X') X++;
      if (top[i]=='O') O++;
      if (mid[i]=='O') O++;
      if (bot[i]=='O') O++;
  }
  int result =win(top,mid,bot);
  if ( (result==NULL) && ( (X==O) || ( (X+1)==O ) || ( (O+1) ==X ) ) ) return NULL;
  else if ( (result==X_WIN) && ( X == O+1 ) ) return X_WIN;
  else if ( (result==O_WIN) && ( X == O ) ) return O_WIN;
  else return ERROR;
}


int main() {

    std::string strTop,strMid,strBot;

    std::cout << "The program is looking for a winner in the tic - tac - toe game ." << std::endl;
    std::cout << "Enter three lines with the characters ('O','X' and '.')." << std::endl;
    std::cin>>strTop;
    std::cin>>strMid;
    std::cin>>strBot;
    int corrected=correct(strTop,strMid,strBot);
    if (corrected==NULL) std::cout<<"Nobody"<<std::endl;
    else if (corrected==X_WIN) std::cout<<"Petya won."<<std::endl;
    else if (corrected==O_WIN) std::cout<<"Vanya won."<<std::endl;
    else std::cout<<"Incorrect."<<std::endl;
    return NULL;
}
