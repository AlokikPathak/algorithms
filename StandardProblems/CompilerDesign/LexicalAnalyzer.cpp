#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
using namespace std;

/**
 * NOTE:
 * 1. Please keep the text file 'program.txt' as in the same directory where the Program resides
 * 2. For now for this programs, all the segments of Programs( operators, separators, literals, keywords etc ) must be space seperated
 * 3. ex. File: program.txt

        int main ( ) {

            int a = 5 , b = 5 ;
            int c = a + b ;
            return 0 ;
        }

 * 4. It will updated soon, all the above conditions will be taken care.
 */

/**
 * Name: isKeyword()
 * Purpose: Finds whether the string parameter 'buffer' is Keyword in CPP or not
 * @param:  char[] buffer
 * @return: short int, returns '1' if string is a CPP Keyword else '0'
 */
short int isKeyword(char buffer[]) {
    // List of Keywords in CPP
    // Reference: 'https://en.cppreference.com/w/cpp/keyword'
    char keywordsCPP[96][20] = {
        "alignas","alignof","and","and_eq","asm","atomic_cancel","atomic_commit","atomic_noexcept","auto",
        "bitand","bitor","bool","break","case","catch","char","char8_t","char16_t","char32_t","class","compl",
        "concept","const","consteval","constexpr","const_cast","continue","co_await","co_return","co_yield",
        "decltype","default","delete","do","double","dynamic_cast","else","enum","explicit","export","extern",
        "false","float","for","friend","goto","if","inline","int","long","mutable","namespace","new","noexcept",
        "not","not_eq","nullptr","operator","or","or_eq","private","protected","public","reflexpr","register",
        "reinterpret_cast","requires","return","short","signed","sizeof","static","static_assert","static_cast",
        "struct","switch","synchronized","template","this","thread_local","throw","true","try","typedef","typeid",
        "typename","union","unsigned","using","virtual","void","volatile","wchar_t","while","xor","xor_eq"
    };
    // Linear Search to find
    for(int i=0; i<96; i++)
        if( strcmp(keywordsCPP[i], buffer) == 0 )
            return 1;
    // If buffer is not a Keyword in CPP Language
    return 0;
}

/**
 * Name = isOperator()
 * Purpose: Finds whether the parameter 'buffer' is a operator, if yes returns 1 else 0
 * @param: char[] buffer
 * @return: short int, returns
 */
short int isOperator(char buffer[]) {
    // Basic set of arithmetic operators
    char operatorsCPP[5][2] = { "+", "-", "*", "/", "=" };
    // Linear Search
    for(int i=0; i<5; i++)
        if( strcmp(operatorsCPP[i], buffer) == 0)
            return 1;
    // if ch is not a operator in CPP language
    return 0;
}

/**
 * Name = isSeperator()
 * Purpose: Finds whether the parameter 'buffer' is a seperator
 * @param: char[] buffer
 * @return: short int, , if yes returns 1 else 0
 */
short int isSeperator(char buffer[] ) {
    char seperatorsCPP[6][2] = { "(", ")", "{", "}", ";", ","};
    // Linear Search
    for( int i=0; i<6; i++)
        if(strcmp(seperatorsCPP[i], buffer) == 0 )
            return 1;
    // if buffer is not a seperator in CPP language
    return 0;
}


int main() {
    char ch, buffer[20];
    // Taking 'program.txt' file as i/p
    ifstream fin("program.txt");
    int i, j=0;
    // Checking if the sample program open successfully
    if(!fin.is_open()) {
        cout<<"Error while opening the file\n";
        exit(0);
    }
    // Loop to iterate char by char in file
    while(!fin.eof()){
        ch = fin.get();

        if((ch==' ' || ch=='\n') && j!=0) {
            buffer[j] = '\0';
            j=0;
            if(isSeperator(buffer))
                cout<<"\n"<<buffer<<" : Seperator";
            else if( isOperator(buffer) )
                cout<<"\n"<<buffer<<" : Operator";
            else if( isKeyword(buffer) )
                cout<<"\n"<<buffer<<" : Keyword";
            else
                cout<<"\n"<<buffer<<" : Identifier";
        }else
            buffer[j++] = ch;
    }
    fin.close();
}
