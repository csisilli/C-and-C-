// Sisilli_Lab2.cpp 
//Name: Caitlin Sisilli
//Project: Lab 2
#include <iostream>
#include <cfenv>
#include <float.h>
using namespace std;
void TurnOnFloatingExceptions()
{
    unsigned int cw;

    cw = _control87(0, 0) & MCW_EM;
    cw &= ~(_EM_INVALID | _EM_ZERODIVIDE | _EM_OVERFLOW);
    _control87(cw, MCW_EM);

}
int main()
{
    TurnOnFloatingExceptions();
    float x = 0;
    float y = 0;
    float sum = x / y;
       
     return 0;
}

 