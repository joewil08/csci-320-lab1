#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab1.h"
/*
 * readString - reads a line from a file given by
 * fileName and returns it as a c-string.  The line
 * return is removed from the string.
 * 
 * fileName is c-string representing the file to read.
 * 
 */
char* readString(char* fileName){

    FILE* fptr = fopen(fileName, "r");
    if (fptr == NULL){
        perror("Unable to open file.");
        return NULL;
    }
    char* strPtr = (char*)malloc(MAX_LINE_LEN * sizeof(char));
    fgets(strPtr, MAX_LINE_LEN, fptr);
    fclose(fptr);
    strPtr[strcspn(strPtr, "\n")] = 0;
    return strPtr;
}

/*
 * mysteryExplode - takes a string of characters and explodes it
 * as follows:
 * 
 * A non-empty string such as "Code" is turned into "CCoCodCode".
 *
 *   Return a new string similar to the string given above.
 *
 *  Example:
 *   mysteryExplosion("Code") --> "CCoCodCode"
 *   mysteryExplosion("abc") --> "aababc"
 *   mysteryExplosion(":)") --> "::)"
 * 
 */
char* mysteryExplode(const char* str){
    
    char* resultPtr = (char*)malloc(strlen(str) * strlen(str) * sizeof(char));
    resultPtr[0] = 0;
    for (int i = 0; i < strlen(str) + 1; i++) {
        strncat(resultPtr, str, i);
    }
    return resultPtr;
}
