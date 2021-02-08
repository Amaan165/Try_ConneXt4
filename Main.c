
/*
  This file is the Starting point for the Project ConneXt4,
  Connecting other files to itself,
  And calling the Required Functions as needed.
*/
// Importing the necessary Files in Main
#include <stdio.h>
#include <string.h>
// Hoi- I did Stuff here.

// I again Did some Stuff...
// Tring to check editing in Atom.
#include "display.c"
#include "funcs.h"
/*File Opening, if previously not presnet, then creation;*/
void init(){
  FILE *f;
  f = fopen("user.txt","a");
  fclose(f);
  f = fopen("setting.txt", "a");
  if (f)
	{
		fseek (f, 0, SEEK_END);
		int size = ftell(f);
	//	printf("Size of the file in bytes: %d\n", size);
    //sleep(5);
    if(size ==0){
      fprintf(f,"SaveSett 0\nDiff 0\n");
    }
	}
  fclose(f);
  f =fopen("saveState.txt","a");
  fclose(f);

}


int main(int argc, char const *argv[]) {
  init();
  init_users();
  // Now call the display fuctions to print stuff(pending.)
  display_Start();
  return 0;
}

// Amaan Changed here!

// I am updating here.

