#include "gapBuffer.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
void printBuffer(GapBuffer* buffer) {
    for (int i = 0; i < buffer->length; i++) {
        if (i == buffer->front) {
            printf("| "); // Indicate the gap position
        }
        printf("%c ", buffer->buffer[i]);
    }
    printf("\n");
}

void testGapBuffer() {
    printf("Testing GapBuffer...\n");
    
    GapBuffer* buffer = initBuffer();
    
    // Insert characters into the buffer
    insert(buffer, 'H');
    insert(buffer, 'e');
    insert(buffer, 'l');
    insert(buffer, 'l');
    insert(buffer, 'o');
    
    printf("Buffer after inserting 'Hello':\n");
    printBuffer(buffer);
    
    // Move the cursor left
    left(buffer);
    printf("Buffer after moving left:\n");
    printBuffer(buffer);
    
    // Insert another character
    insert(buffer, '!');
    printf("Buffer after inserting '!':\n");
    printBuffer(buffer);
    
    // Move right
    right(buffer);
    printf("Buffer after moving right:\n");
    printBuffer(buffer);
    
    // Grow the buffer
    grow(buffer);
    printf("Buffer after growing:\n");
    printBuffer(buffer);
    
    // Free allocated memory
    free(buffer->buffer);
    free(buffer);
}

int main() {
    testGapBuffer();
    return 0;
}
*/

