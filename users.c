/*
  This file contains all the functions
  Related to User Management
  */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcs.h"

// User Related Functions below;
/*
To make data of file(users)
acessible by storing it in a Struct Array.
*/
void extractUsers(){
  FILE *f;
  f = fopen("user.txt","r");
  char dta[30];
  int usr_no =0;
  while(fgets(dta,40,f))
  {
    char nm[20];
    char sc[10];
    int i=0;

    while(dta[i]!=' '){
      nm[i] = dta[i];
      i++;
    }
    nm[i] = '\0';

    i++;
    int j=0;

    while(dta[i]!='\n'){

      sc[j] = dta[i];
      j++;i++;
    }
    sc[j] = '\0';

    users[usr_no].score = atoi(sc);
    strcpy(users[usr_no].name,nm);
    usr_no++;
  }
  fclose(f);
  len = countUsers();
}
/*
  To count the Number of Users Registered.
*/
int countUsers(){
  FILE *f;
  f = fopen("user.txt", "r");
  int count =0;
  char chek[40];
  while(fgets(chek,40,f)){
    count++;
  }
  return count;
}
/*
 To Update the User List into the file along with scores.
*/
void saveUsers(){
  FILE *f;

  f = fopen("user.txt","w");

  for(int i=0;i<len;i++){
    fprintf(f,"%s %d\n",users[i].name,users[i].score);
  }
  fclose(f);

}
/*
  To print the Users
*/
void printUsers()
{
  for(int i=0;i<len;i++){
    //extractUsers();
    display_Align();
    printf("%s %d\n",users[i].name,users[i].score);
    //printf("\n");
  }
}
/*
  Adds a user if limit is not reached
  return values:
  1: User Added
  0: User Limit Exeded, so user not added.
*/
int AddUser(char nm[]){

  if(len == 10){
    return 0;
   }
  strcpy(users[len].name,nm);
  users[len].score = 0;
  len++;
  saveUsers();
  return 1;


}
/*
  To delete an user from the list if found
  return values:
  1: Element found and Deleted
  0: Element Not found
*/
int DelUser(char nm[]){
  int chk =0;
  for(int i=0;i<len;i++){
    if(strcmp(users[i].name,nm)==0){
      chk =1;

      for(int j=i;j<len-1;j++){
        char temp[20];
        strcpy(temp,users[j].name);
        strcpy(users[j].name,users[j+1].name);
        strcpy(users[j+1].name,temp);
        int t=0;
        t = users[j].score;
        users[j].score = users[j+1].score;
        users[j+1].score = t;
      }
      break;
    }
  }

  if(chk){
    len--;
    saveUsers();
  }
  return  chk;
}
// User FUncs End

// Basic Settings Start ;

/* Save State Check */
void loadSettings(){
  FILE *f;
  f = fopen("setting.txt","r");
  for(int i=0;i<2;i++){
    fscanf(f,"%s %d",&settings[i].setting, &settings[i].value);
  }
  fclose(f);
}
void saveSettings(){
  FILE *f;
  f = fopen("setting.txt","w");
  for(int i=0;i<2;i++){
    fprintf(f,"%s %d\n",settings[i].setting, settings[i].value);
  }
  fclose(f);
}
/*
  checks the value of SaveSett setting
  which allows user to be able to save their in game progress
*/
int checkSave(){
  return settings[0].value;
}
/*
 Changes the value of SaveSet settings
 n shold be 0 or 1, make sure.
*/
void ammendSave(int n){
  settings[0].value = n;
  saveSettings();
}
/*
  Checks the difficulty Level of game
*/
int checkDiff(){
  return settings[1].value;
}
/*
  Ammends the difficulty Level of Game
*/
void ammendDiff(int n){
  settings[1].value = n;
  saveSettings();
}

// Basic settings Functions End;

void init_users(){
  extractUsers();
  loadSettings();
}


//void main(){
  //extractUsers();
  //printUsers();
//}
