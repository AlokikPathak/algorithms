#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
using namespace std;

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
 * Purpose: Finds whether the parameter 'ch' is a operator of not
 * @param: char 'ch'
 * @return: short int, returns
 */
short int isOperator(char buffer[]) {
    // Basic set of arithmetic operators
    char operatorsCPP[4][2] = { "+", "-", "*", "/" };
    // Linear Search
    for(int i=0; i<6; i++)
        if( strcmp(operatorsCPP[i], buffer) == 0)
            return 1;
    // if ch is not a operator in CPP language
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
            // 1. If the string is Operator
            if( isOperator(buffer) )
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
