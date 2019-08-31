#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

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

 *
 */

/**
 * Name: isKeyword()
 * Purpose: Finds whether the string parameter 'buffer' is Keyword in CPP or not
 * @param:  char[] buffer
 * @return: short int, returns '1' if string is a CPP Keyword else '0'
 */
short int isKeyword(char buffer[]) {
    // List of Keywords in CPP
    // Reference: 'https://en.cppreference.com/w/cpp/keyword' true and false as literals
    char keywordsCPP[101][20] = {
        "alignas","alignof","and","and_eq","asm","atomic_cancel","atomic_commit","atomic_noexcept","auto",
        "bitand","bitor","bool","break","case","catch","char","char8_t","char16_t","char32_t","class","compl",
        "concept","const","consteval","constexpr","const_cast","continue","co_await","co_return","co_yield",
        "decltype","default","delete","do","double","dynamic_cast","else","enum","explicit","export","extern",
        "float","for","friend","goto","if","inline","int","long","mutable","namespace","new","noexcept",
        "not","not_eq","nullptr","operator","or","or_eq","private","protected","public", "return", "reflexpr","register",
        "reinterpret_cast","requires","return","short","signed","sizeof","static","static_assert","static_cast",
        "struct","switch","synchronized","template","this","thread_local","throw","try","typedef","typeid",
        "typename","union","unsigned","using","virtual","void","volatile","wchar_t","while","xor","xor_eq","<<",">>","cout","cin", "printf", "scanf"
    };
    // Linear Search to find
    int i;
    for(i=0; i<99; i++)
        if( strcmp(keywordsCPP[i], buffer) == 0 )
            return 1;
    // If buffer is not a Keyword in CPP Language
    return 0;
}

/**
 * Name = isOperator()
 * Purpose: Finds whether the parameter 'buffer[]' is a operator, if yes returns 1 else 0
 * @param: char[] buffer
 * @return: short int, returns
 */
short int isOperator(char buffer[]) {
    // Basic set of arithmetic operators
    char operatorsCPP[15][3] = { "+", "-", "*", "/", "=", ">", "<", ">=", "<=", "++", "--", "+=", "-=", "*=", "/=" };
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
    int i;
    for(i=0; i<6; i++)
        if(strcmp(seperatorsCPP[i],buffer)==0 )
            return 1;
    // if buffer is not a seperator in CPP language
    return 0;
}

/**
 * Name = isLiteralNum()
 * Purpose: Finds whether the parameter 'buffer' is a Numeric Literal
 * @param: char[] buffer
 * @return: short int, , if yes returns 1 else 0
 */
short int isLiteralNum(char buffer[]) {
    // check is buffer[]. contains only 0 or numeric digit
    if(buffer[0]=='0' || atof(buffer) )
        return 1;
    return 0;
}

/**
 * Name = isLiteralChar()
 * Purpose: Finds whether the parameter 'buffer' is a Char Literal ex. 'A'
 * @param: char[] buffer
 * @return: short int, if yes returns 1 else 0
 */
short int isLiteralChar(char buffer[]) {
    if(strlen(buffer)>2) {
        // if 1st and second char is "'" i.e. ascii 39
        short int a = buffer[0];
        short int b = buffer[2];
        if( a==39 && b==39 )
            return 1;
    }
    return 0;
}

/**
 * Name = isLiteralBool()
 * Purpose: Finds whether the parameter 'buffer' is a Boolean Literal
 * @param: char[] buffer
 * @return: short int, , if yes returns 1 else 0
 */
short int isLiteralBool(char buffer[]) {
    if(strcmp(buffer, "true")==0 || strcmp(buffer, "false")==0)
        return 1;
    return 0;
}

/**
 * Name = isLiteralString()
 * Purpose: Finds whether the parameter 'buffer' is a String Literal
 * @param: char[] buffer
 * @return: short int, , if yes returns 1 else 0
 */
short int isLiteralString( char buffer[]) {
    int i=0;
    while(buffer[i]!='\0')
        i++;
    // check if literal is string i.e. begins and ends with '"'
    if(buffer[0]=='"' || buffer[i]=='"')
        return 1;
    return 0;
}

/**
 * Name: isLiteral(), ex. true, false, 3523, 23.09832, 'A', 'Hello World';
 * Purpose: Checks wheather the string is literal or not
 * @param char[], buffer[]
 * @return short int, is it is literal returns 1, else 0
 */
short int isLiteral(char buffer[]) {
    if(isLiteralChar(buffer) || isLiteralBool(buffer) || isLiteralNum(buffer) || isLiteralString(buffer))
        return 1;
    return 0;
}

int main() {
    char ch, buffer[20];
    unsigned short int j=0;
    // Taking 'program.txt' file as i/p
    FILE *fp;
    fp = fopen("program.txt","r");
    // Checking if the sample program open successfully
    if(fp == NULL) {
        printf("Error while opening the file\n");
        exit(0);
    }
    // Loop to iterate char by char in file
    // extract space separated letters or words
    while( (ch = fgetc(fp)) != EOF ){

        if((ch==' ' || ch=='\n') && j!=0) {
            buffer[j] = '\0';
            j=0;
            if(isSeperator(buffer))
                printf("\n%s : Seperator", buffer);
            else if( isOperator(buffer) )
                printf("\n%s : Operator", buffer);
            else if( isKeyword(buffer) )
                printf("\n%s : Keyword", buffer);
            else if(isLiteral(buffer))
                printf("\n%s : Literal", buffer);
            else
                printf("\n%s : Identifier", buffer);
        }else if(ch!=' ' && ch!='\n')
            buffer[j++]=ch;
    }
    // Closing file after operation is complete
    fclose(fp);
    return 0;
}
