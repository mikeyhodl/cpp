#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>

#define FAIL -1
/*Random formula now should work properly for all cases 1-100
 *Converted if-else to try/catch 
 * Put better wording in error statement
 */
int main()
{
    srand(time(NULL));
    int tries = 0, myNum = 0, min = 1, max = 100;
    int findNum;
    puts("Welcome to Ace's Guessing Game!");
    puts("In this version, the computer tries to guess your number.");
    std::cout<<"Enter a number between 1 and 100 (Warning: Bad input causes program to terminate!): ";
    std::cin>>myNum;
    
    try{
        if(std::cin.fail() || std::cin.bad() || myNum < min || myNum > max)
            throw FAIL;
        do //now that all error cases have been handled, time for the fun 
        {
            //max = (max == 100) ? max + 1 : max;
            findNum = rand() % (max + 1 - min) + min;
                    
            std::cout << "\nComputer's guess: " << findNum << std::endl;
            ++tries;
        
            if(myNum > findNum)
            {
               std::cout << "Too low!\n";
               min = findNum + 1;
            }else if(myNum < findNum)
            {
               std::cout << "Too high!\n";
               max = findNum - 1;
            }else
                std::cout << "Computer found the number in " << tries << " tries.";
        }while(myNum != findNum);
    }catch(...)
    {
        puts("\n\nAn error occured. Input must be an integer between 1 and 100. Quitting.");    
    }
    return 0;
}
