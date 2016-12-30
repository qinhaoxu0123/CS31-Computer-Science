#include<iostream>
#include <string>

using namespace std;

bool isWellFormedCommandstring (string commands);
bool crossedOriginOnItsPath(string commands);

int main ()
{
    string commands = "e";
    cout << isWellFormedCommandstring(commands)<< endl;
    cout << crossedOriginOnItsPath(commands)<< endl;
    
}

bool isWellFormedCommandstring (string commands)
{
    if(commands.length()!=0 && !isalpha(commands[0]) && isalpha(commands[commands.length()-1]) );//check the front and the end of the input string
    else
        return false;
    
    for(int i= 0; i < commands.length(); i++)
    {
        switch(commands[i])// input other than the following cases will return false;
        {
            case '1':case '2':
            case '3':case '4':
            case '5':case '6':
            case '7':case '8':
            case '9':case '0':
            case '+':case '-':
            case 'E':case 'e':
            case 'W':case 'w':
            case 'N':case 'n':
            case 'S':case 's':
                break;
            default:
                return false;
                break;
        }
    }
    
    
    for(int i= 0; i < commands.length(); i++)
    {
    // if the string starts with digits
        if (isdigit(commands[i]))
        {
            if (commands[i]=='0')
                return false;
            else if (i+1< commands.length())// check to see if the string has next position/
            {
                if (commands[i+1]=='+'|| commands[i+1]=='-')
                    return false;
                else if (isdigit(commands[i+1]) )
                {
                   if(i+2 < commands.length())
                   {
                       if (commands[i+2]=='+'|| commands[i+2]=='-')
                           return false;
                       else if (isdigit(commands[i+2]) )
                        {
                            if(i+3 < commands.length())
                            {
                                if (commands[i+3]=='+'|| commands[i+3]=='-'|| isdigit(commands[i+3]))
                                        return false;
                            }
                            i++;// we want the complier to jump into another string of number 
                        }
                    }
                    i++;
                 }
             }
        }
        // if it starts with + and -
        else if (commands[i]=='+'|| commands[i]== '-')
        {
            if (i+1< commands.length())
            {
                if (!isdigit(commands[i+1])) return false;
            }
            
        }
        //if it starts with alpha
        else
        {
            if (i+1< commands.length() && isalpha(commands[i+1]))
            {
                switch (commands[i])
                {
                    case 'N':case 'n':
                    case 'S':case 's':
                        break;
                    default:
                        return false;
                        break;
                }
                switch (commands[i+1])
                {
                    case 'W':case 'w':
                    case 'E':case 'e':
                        break;
                    default:
                        return false;
                        break;
                }
                i++;
            }
            if (i+1 < commands.length())
            {
                if(isalpha(commands[i+1]))
                   return false;
            }
            
        }

    }
    return true;
}

bool crossedOriginOnItsPath(string commands)
{
    int x=0;
    int y=0;
    int result=0;
    string number;
    int sign = 1;// using for string that has + or -.
    
    for(int step=0; step<commands.length(); step++)
    {
        if(commands[step]=='-')
        {
            sign = -1; // implenment negative sign into the following function if it start with "-" sign
        }
        else if(isdigit(commands[step]))
          {
           number=(commands[step]);
              if (step+1 <commands.length())
             {
                if(isdigit(commands[step+1]))
                {
                   step++;
                   number+=commands[step];
                  if (step+1 < commands.length())
                  {
                      if(isdigit(commands[step+1]))
                      {
                        step++;
                        number +=commands[step];
                      }
                
                   }
                }
             }
              result = atoi(number.c_str());
           }
          else if(isalpha(commands[step]))
          {
                  switch(commands[step])
                  {
                          case 'E':case'e':
                          x+= sign * result;
                          break;
                          case 'W':case'w':
                          x-= sign * result;
                          break;
                          case'S':case's':
                          y-= sign * result;
                          break;
                          case'N':case'n':
                          y+= sign * result;
                          break;
                          default:
                          break;
                  }
                  if(step+1< commands.length())
                  {
                      if(isalpha(commands[step+1]))
                      {
                              switch (commands[step+1])
                              {
                                  case 'E':case 'e':
                                      x+= sign * result;
                                      break;
                                  case 'W':case 'w':
                                      x-= sign * result;
                                      break;
                                  default:
                                      break;
                              }
                          step++;
                       }
                      sign = 1; //return back to "+" sign
                      
                  }
        
          }
    
    
    }
if(x!=0 || y!=0) return false;// if x and y do not equal to 0 return false
else return true;
}
