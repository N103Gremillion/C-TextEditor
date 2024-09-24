/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gapBuffer.h"

// Function to test fetchText
void testFetchText() {
    printf("Testing fetchText function...\n");

    // Test 1: Fetch text from an empty gap buffer
    GapBuffer* emptyBuffer = initBuffer();
    char* text1 = fetchText(emptyBuffer);
    if (text1 != NULL && strlen(text1) == 0) {
        printf("Test 1 passed: Empty buffer returns empty string.\n");
    } else {
        printf("Test 1 failed: Expected empty string.\n");
    }
    free(text1);
    free(emptyBuffer->buffer);
    free(emptyBuffer);

    // Test 2: Fetch text after inserting characters
    GapBuffer* buffer2 = initBuffer();
    insert(buffer2, 'H');
    insert(buffer2, 'e');
    insert(buffer2, 'l');
    insert(buffer2, 'l');
    insert(buffer2, 'o');
    
    char* text2 = fetchText(buffer2);
    if (text2 != NULL && strcmp(text2, "Hello") == 0) {
        printf("Test 2 passed: Correct text retrieved after inserts.\n");
    } else {
        printf("Test 2 failed: Expected 'Hello', got '%s'.\n", text2);
    }
    free(text2);
    free(buffer2->buffer);
    free(buffer2);

    // Test 3: Insert more characters than initial buffer size
    GapBuffer* buffer3 = initBuffer();
    for (char c = 'A'; c <= 'Z'; c++) {
        insert(buffer3, c);
    }
    
    char* text3 = fetchText(buffer3);
    if (text3 != NULL && strcmp(text3, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") == 0) {
        printf("Test 3 passed: Correct text retrieved after growing buffer.\n");
    } else {
        printf("Test 3 failed: Expected 'ABCDEFGHIJKLMNOPQRSTUVWXYZ', got '%s'.\n", text3);
    }
    free(text3);
    free(buffer3->buffer);
    free(buffer3);
}

// Main function to run tests
int main() {
    testFetchText();
    return 0;
}
*/
