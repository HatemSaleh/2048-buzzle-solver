#include "2048.h"
Matrix::Matrix()
{
    for(int i = 0;i < getRow(); i++)
    {
        for(int j = 0; j < getCol(); j++)
        {
            myMatrix.at(i).at(j) = 0;
        }
    }
}

void Matrix::slideLeft()
{
  stack<int>stk;
  for(int i = 0; i < getRow() ; i++)
  {
      bool merged = false;
      for(int j = 0; j < getCol() ; j++)
      {   
        if(myMatrix.at(i).at(j) > 0 && myMatrix.at(i).at(j) != 2048)
        {
          if(stk.empty())
          {
            stk.push(myMatrix.at(i).at(j));
          }
          else if(merged == true)
          {
            stk.push(myMatrix.at(i).at(j));
            merged = false;
          }
          else if(stk.top() == myMatrix.at(i).at(j))
          {
            stk.top() += stk.top();
            merged = true;
          }
          else 
            stk.push(myMatrix.at(i).at(j));
        }
        else if(myMatrix.at(i).at(j) == 2048)
        {
          if (j - stk.size() == 0)
          {
            stk.push(myMatrix.at(i).at(j));
          }
          else
          {
            int n = j - stk.size();
            while(n != 0)
            {
              stk.push(0);
              n--;
            }
            stk.push(myMatrix.at(i).at(j));
          }
        }
      }
      while(stk.size() < getCol())
      {
        stk.push(0);
      }
      for(int k = getCol() - 1; k >= 0; k--)
      {
        myMatrix.at(i).at(k) = stk.top();
        stk.pop();
      }
  }
}

void Matrix::slideRight()
{
  stack<int>stk;
  for(int i = 0; i < getRow() ; i++)
  {
      int pos =0;
      bool merged = false;
      for(int j = getCol() - 1; j >= 0 ; j--)
      {   
        if(myMatrix.at(i).at(j) > 0 && myMatrix.at(i).at(j) != 2048)
        {
          if(stk.empty())
          {
            stk.push(myMatrix.at(i).at(j));
          }
          else if(merged == true)
          {
            stk.push(myMatrix.at(i).at(j));
            merged = false;
          }
          else if(stk.top() == myMatrix.at(i).at(j))
          {
            stk.top() += stk.top();
            merged = true;
          }
          else 
            stk.push(myMatrix.at(i).at(j));
        }
        else if(myMatrix.at(i).at(j) == 2048)
        {
          if (pos - stk.size() == 0)
          {
            stk.push(myMatrix.at(i).at(j));
          }
          else
          {
            int n = pos - stk.size();
            while(n != 0)
            {
              stk.push(0);
              n--;
            }
            stk.push(myMatrix.at(i).at(j));
          }
        }
        pos++;
      }
      while(stk.size() < getCol())
      {
        stk.push(0);
      }
      for(int k = 0; k < getCol(); k++)
      {
        myMatrix.at(i).at(k) = stk.top();
        stk.pop();
      }
  }
}

void Matrix::slideUp()
{
  stack<int>stk;
  for(int i = 0; i < getRow() ; i++)
  {      
      bool merged = false;
      for(int j = 0; j < getCol() ; j++)
      {   
        if(myMatrix.at(j).at(i) > 0 && myMatrix.at(j).at(i) != 2048)
        {
          if(stk.empty())
          {
            stk.push(myMatrix.at(j).at(i));
          }
          else if(merged == true)
          {
            stk.push(myMatrix.at(j).at(i));
            merged = false;
          }
          else if(stk.top() == myMatrix.at(j).at(i))
          {
            stk.top() += stk.top();
            merged = true;
          }
          else 
            stk.push(myMatrix.at(j).at(i));
        }
        else if(myMatrix.at(j).at(i) == 2048)
        {
          if (j - stk.size() == 0)
          {
            stk.push(myMatrix.at(j).at(i));
          }
          else
          {
            int n = j - stk.size();
            while(n != 0)
            {
              stk.push(0);
              n--;
            }
            stk.push(myMatrix.at(j).at(i));
          }
        }
      }
      while(stk.size() < getCol())
      {
        stk.push(0);
      }
      for(int k = getCol() - 1; k >= 0;k --)
      {
        myMatrix.at(k).at(i) = stk.top();
        stk.pop();
      }
  }
}

void Matrix::slideDown()
{
  stack<int>stk;
  for(int i = 0; i < getRow() ; i++)
  {   
      int pos = 0;
      bool merged = false;
      for(int j = getCol() - 1; j >= 0; j--)
      { 
       
        if(myMatrix.at(j).at(i) > 0 && myMatrix.at(j).at(i) != 2048)
        {
          if(stk.empty())
          {
            stk.push(myMatrix.at(j).at(i));
          }
          else if(merged == true)
          {
            stk.push(myMatrix.at(j).at(i));
            merged = false;
          }
          else if(stk.top() == myMatrix.at(j).at(i))
          {
            stk.top() += stk.top();
            merged = true;
          }
          else 
            stk.push(myMatrix.at(j).at(i));
            
        }
        else if(myMatrix.at(j).at(i) == 2048)
        {
          
          if (pos - stk.size() == 0)
          {
            stk.push(myMatrix.at(j).at(i));
          }
          else
          {
            int n = pos - stk.size();
            while(n != 0)
            {
              stk.push(0);
              n--;
            }
            stk.push(myMatrix.at(j).at(i));
          }
        }
        pos++;
      }
      while(stk.size() < getCol())
      {
        stk.push(0);
      }
      for(int k = 0; k < getCol();k ++)
      {
        myMatrix.at(k).at(i) = stk.top();
        stk.pop();
      }
  }
}

bool Matrix::impossible()
{
  double sum = 0;
  for(int i = 0; i< getRow(); i++)
  {
    for(int j = 0; j < getCol(); j++)
    {
        if(myMatrix.at(i).at(j) != 0 && myMatrix.at(i).at(j) != 2048)
        {
          sum += myMatrix.at(i).at(j);
        }
    }
  }  
  for(double i = sum; sum > 2; i)
  {
    sum = sum/2;
  }
  if (sum != 2)
  return true; 
    return false;
}

bool Matrix::isSolved()
{
  int counter = 0;
  for(int i = 0; i < getRow(); i++)
  {
    for (int j = 0; j < getCol(); j++)
    {
      if(myMatrix.at(i).at(j) != 0 && myMatrix.at(i).at(j) != 2048)
      {
        counter++;
      }
    }
  }
  if(counter == 1)
  return true;
    return false;
}

void Matrix :: slide(int move)
{
    if(move == 1)
    {
        slideUp();
    }
    if(move == 2)
    {
        slideRight();
    }
    if(move == 3)
    {
        slideDown();
    }
    if(move == 4)
    {
        slideLeft();
    }
}

void Matrix:: fillInMatrix(ifstream& fileIn,int row,int col)
{
    int value;
    for(int i = 0; i < row; i++)
    {
      vector<int>temp;
      for(int j = 0; j< col; j++)
      {
          fileIn >> value;
          temp.push_back(value);
      }
      myMatrix.push_back(temp);
    }
}

int Matrix:: count()
{
  int counter = 0;
  for(int i = 0; i < getRow(); i++)
  {
    for (int j = 0; j < getCol(); j++)
    {
      if (myMatrix.at(i).at(j) != 0  && myMatrix.at(i).at(j) != 2048)
      counter++;
    }
  }
  return counter;
}