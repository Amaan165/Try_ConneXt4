

/*
  This File ontains functions related to displaying the game elements
  On The Command Prompt.
  It will Display the screens.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "users.c"
#include "funcs.h"

void display_savestate(){
  system("cls");
  int a;
  printf(" \t\t\t\t\t\t\tCONECTX4");
  printf("\n\n");
  display_Align();
  printf("Allows User to save the current state of game\n");
  display_Align();
  printf("So that it can be loaded when opening the game again.\n\n");
  display_Align();
  if(checkSave()){
    printf("Currently Selected: Setting Enabled\n\n");
  }
  else{
    printf("Currently Selected: Setting Disabled\n\n");
  }
  display_Align();
  printf("1. Disable\n");
  display_Align();
  printf("2. Enable\n");
  display_Align();
  printf("3. Go Back\n");
  display_Align();
  scanf("%d",&a);
  if(a<1 || a>3){
    printf("Not Valid Choice");
    display_savestate();
  }
  if(a==1||a==2){
    ammendSave(a-1);
    display_savestate();
  }
  display_setting();


}
void display_setting()
  {
  system("cls");
  int a;
  printf(" \t\t\t\t\t\t\tCONECTX4");
  printf("\n\n");
  display_Align();
  printf("1. Save Game Progress In-Game\n");
  display_Align();
  printf("2. Toggle Difficulty\n");
  display_Align();
  printf("3. Go Back\n");
  scanf("%d",&a);
  if(a<1 || a>3){
    printf("Not Valid Choice");
    display_setting();
  }

  switch(a){
    case 1:{
      display_savestate();
    }

    case 2:{

    }
    case 3:{
      display_options();
    }
  }
}


/*
  Start Screen
  will give options to user.
  and different Screens Will be printed.by calling different Functions
*/
void display_Align(){
  printf("\t\t\t\t\t\t\t");
}



void display_users()
{
  system("cls");
  printf(" \t\t\t\t\t\t\tCONECTX4");
  printf("\n\n");
  printUsers();
  printf("\n");
  display_Align();
  printf("1. add user");
  printf("\n");
  display_Align();
  printf("2. delete user");
  printf("\n");
  display_Align();
  printf("3.Go Back\n");
  display_Align();

  int choice ;
  scanf("%d",&choice);
  switch(choice){
    case 1:
    {char nm[20];
      printf("Enter UserName: ");
      char n[1];
      gets(n);
      gets(nm);
      int chk = AddUser(nm);
      if(chk){
        printf("User Added Successfully.");
        sleep(2);
        display_users();
      }
      else{
        printf("User Limit Exceeded, Delete an user to add another one.");
        sleep(2);
        display_users();
      }
      break;
    }

  case 2:{
  char nm[20];
  printf("Enter UserName: ");
  char n[1];
  gets(n);
  gets(nm);
  int chk = DelUser(nm);
  if(chk){
    printf("User Deleted Successfully.");
    sleep(2);
    display_users();
  }
  else{
    printf("User Not Found.");
    sleep(2);
    display_users();
  }}

  case 3:
   display_options();
}


}
void display_options(){//settings sub menu
  system("cls");
   int i;
   printf(" \t\t\t\t\t\t\tCONECTX4");
   printf("\n\n");
   printf("\t\t\t\t\t\t\t1.users\n");
   printf("\t\t\t\t\t\t\t2.settings\n");
   printf("\t\t\t\t\t\t\t3.go back\n");
   //display_Align();
   scanf("%d",&i);
   switch(i){
   case 1:
   display_users();
   break;
   case 2:
   display_setting();
   break;
   case 3:
   display_Start();
   break;
 }
}
void display_exit()
{
  system("cls");
  printf(" \t\t\t\t\t\t\tCONECTX4");
  printf("\n\n");
  display_Align();
  printf("--------");
    exit(0);
}
void display_play()//play options menu
{
  system("cls");
  printf(" \t\t\t\t\t\t\tCONECTX4");
  printf("\n\n");
  int z;
  printf("\t\t\t\t\t\t\t1.singlemode\n");
  printf("\t\t\t\t\t\t\t2.multiplayer\n");
  printf("\t\t\t\t\t\t\t3.go back\n");
  scanf("%d",&z);
  switch(z){
  case 1:
  //display_single();
  break;
  case 2:
  //display_multi();
  break;
  case 3:
  display_Start();
  break;
}
}
void display_Start(){
  system("cls");
  int input;
  printf(" \t\t\t\t\t\t\tCONECTX4");
  printf("\n\n");
  printf("\t\t\t\t\t\t\t1.play\n");
  printf("\t\t\t\t\t\t\t2.options\n");
  printf("\t\t\t\t\t\t\t3.exit\n");
  display_Align();
  scanf("%d",&input);
  if (input==1){
    display_play();

  }
  else if(input==2){

    display_options();
  }

  else if(input==3){
    display_exit();
  }
}
