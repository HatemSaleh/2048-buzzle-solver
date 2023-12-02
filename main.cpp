#include "ArgumentManager.h"
#include "2048.h"

string solve(int level, Matrix &game, string path,ofstream& fileOut)
{
  if(game.isSolved() ) {return path;}

 else  if(level <= 0 || game.impossible()) {return "Impossible";}

  long int longestseq = 99999999999;
  int goodpath = 0;
  string way = path;
  for(int i = 1; i <= 4; i++)
  {
    Matrix temp(game);
    temp.slide(i);
    if(game.getMatrix() != temp.getMatrix())
    {
      string current = solve(level - 1, temp, path,fileOut);
      if(current.length() < longestseq)
      {
        longestseq = current.length();
        goodpath = i;
        way = current;
      }
    }
  }
  
  way = way + to_string(goodpath);
  return way;
}

int main(int argc, char *argv[])
{
  ArgumentManager am(argc, argv);
  string inputName = am.get("input");
  string outputName = am.get("output");
  ofstream fileOut(outputName);
  ifstream fileIn(inputName);
  fileOut << "";

  int size;
  string line;
  getline(fileIn,line,'\n');
  size = stoi(line);
  int row = size;
  int col = size;

  Matrix game;
  game.fillInMatrix(fileIn,row,col);

  string path;
  if(game.isSolved())
  fileOut << "0";
  else 
  {
    path = solve(12,game,"",fileOut);
    if(path.substr(0,10) == "Impossible" || path == "0")
    fileOut << "Impossible";
    else
    {
      stack<char>stk;
      for(int i = 0; i < path.length(); i++)
      {
        stk.push(path.at(i));
      }
      for(int i = 0; i < path.length(); i++)
      {
        path.at(i) = stk.top();
        stk.pop();
      }
      fileOut << path;
    }
  }
}