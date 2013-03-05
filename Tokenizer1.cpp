//============================================================================
// Name        : helloworld.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "string.h"
using namespace std;

#define MAX_TOKEN_VAL	1000
#define MAX_TOKEN_ARRAY	20

typedef struct TOKEN_CONTAINER {
	char	tokenArray[MAX_TOKEN_VAL];
} t_TOKEN_CONTAINER;

void tokenizeBuffer(char buffer[], t_TOKEN_CONTAINER* tokenContainer, int& totalTokenCount);

int main() {
    char buffer[200]="";
    char *bufferjunk = "\"Sanjay\",\"Sajwan\", \"100 ,200\", \"Test , function\"";
    memcpy(buffer, bufferjunk, strlen(bufferjunk));
    //char *buffer = "\"Sanjay\",\"Sajwan\", \"100 ,200\", \"Test , function" ;
    //char *buffer = "'Sanjay','Sajwan', '100 ,200', 'Test , function'";
    int	totalTokenCount = 0;

    t_TOKEN_CONTAINER tokenContainer[MAX_TOKEN_ARRAY];
    memset(&tokenContainer, 0, sizeof(TOKEN_CONTAINER)); //Reset token container before usage
    tokenizeBuffer(buffer, &tokenContainer[0], totalTokenCount);

    //#ifdef DEBUG
    int tempCount = 0;
    while(tempCount <= totalTokenCount)
    {
    	cout << "Token Information: " << endl;
    	cout << "Token[" << tempCount << "]" << ":" << tokenContainer[tempCount].tokenArray << endl;
    	tempCount++;
    }
    //#endif

	return 0;
}

void tokenizeBuffer(char buffer[], t_TOKEN_CONTAINER* tokenContainer, int& totalTokenCount)
{
    int tokenCount = 0;
    int bufferCount = 0;
    char tempToken[MAX_TOKEN_VAL];

    while(buffer[bufferCount] != 0)
    {
        if(buffer[bufferCount]== '"')// && bstartQuote==false) && bendQuote==false)
        {
            tempToken[tokenCount]= buffer[++bufferCount]; //Skip storage of " in the token

            //Keep filling the buffer till end quote is found
            while(buffer[bufferCount] != '"')
            {
            	tempToken[++tokenCount] = buffer[++bufferCount];
            }
            tempToken[tokenCount] = '\0';

            //Store the retrieved token in a token container array
            strcpy(tokenContainer[totalTokenCount].tokenArray, tempToken);
            totalTokenCount++;
            strcpy(tempToken, ""); //Reset current token
            tokenCount = 0; //Reset token count for the creation of next token
            ++bufferCount;
        }
        else
        {
        	++bufferCount;
        }//End
    }//End while
}//End tokenizeBuffer

