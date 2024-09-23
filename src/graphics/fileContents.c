#include "fileContents.h"
#include <stdio.h>
#include <stdlib.h>

//**************************** File Contents *********************************
FileContents* initFileContents(){
	FileContents* contents = (FileContents*) malloc(sizeof(FileContents));
	return contents;
}


