/**************************************************************************
**       Title: 
**    $RCSfile: $
**   $Revision: $$Name:  $
**       $Date: $
**   Copyright: GPL $Author: $
** Description:
**
**    
**
**-------------------------------------------------------------------------
**
**  $Log: $
**
**
**************************************************************************/

#include <iostream>
#include <string>

#include <GlobalState.hh>
#include <Team.hh>
#include <Character.hh>
#include <fstream>

void newGame()
{
  std::ifstream file( "Fanmerc_Char.txt");
  
  fanmerc::GlobalState globalstate;
  
  globalstate.read( file);
}

void loadGame()
{}

int main( int argv, char** argc)
{
  std::cout << "Welcome to FANtasy MERCenaries\n\n";

  bool inputIsBad=true;
  std::string input; 
  while( inputIsBad)
  {
    std::cout << "(N)ew Game, (L)oad Game or (Q)uit?\n";
    std::cin >> input;
  
    if( input == "N" || input == "n")
    {
      newGame();
      inputIsBad = false;
      break;
    }
    else if( input == "L" || input == "l")
    {
      loadGame();
      inputIsBad = false;
      break;
    }
    else if( input == "Q" || input == "q")
    {
      std::cout << "Exiting...\n";
      return 0;
    }
    else
    {
      std::cout << "Please check your input...\n\n";
    }
  }
    
  return 0;
}
