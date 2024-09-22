#include "fileContents.h"
#include <stdio.h>

void testFileContents() {
    FileContents* contents = initFileContents();

    if (contents->capacity != 10 || contents->numOfLines != 1) {
        printf("Initialization failed!\n");
        return;
    }

    initLine(contents, 0);
    if (contents->lines[0] == NULL) {
        printf("Line initialization failed!\n");
        return;
    }

    addToLine(contents, 0, 'A');
    addToLine(contents, 0, 'B');
    addToLine(contents, 0, 'C');

    if (contents->numOfLines != 2) {
        printf("Unexpected number of lines after adding characters!\n");
        return;
    }

    contents->numOfLines = 5; 
    checkForResize(contents);

    if (contents->capacity != 20) {
        printf("Resizing failed! Expected capacity 20, got %d\n", contents->capacity);
        return;
    }

    freeFileContents(contents);
    printf("All tests passed!\n");
}

int main(){
	testFileContents();
	return 0;
}


