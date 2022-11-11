// this is a project to keep trace of all the   visiting the historical  monuments
#include<stdio.h>
#include<conio.h>
#include<unistd.h>

int check = -1; // to keep the pointer in structure
// defining the structure to keep record of all  the visitors
struct profile{

char name[50];
char Address[10000];
char gender[44];
int mobile_number;
int status_code;
// status code 301 means visitor has checked in and has not checked out
// status code 103 means visitor has checked out
};

struct profile visitor[100];


// welcome screen
void welcome(){
printf("\
           *********************************************************************\n\
           *                                                                   *\n\
           *                                                                   *\n\
           *              ****    { WELCOME }  < USER/ >  ****                 *\n\
           *                                                                   *\n\
           *                                                                   *\n\
           *             ^^^ TO ^^^   -> ( VISITOR  TRACKING SYSTEM ) => {     *\n\
           *                                                                   *\n\
           *                                                                   *\n\
           *   - GET RECORD OF TOTAL VISITOR IN A DAY                          *\n\
           *                                                                   *\n\
           *   - GET TO KNOW NO. OF VISITOR CURRENTLY ATTENDING                *\n\
           *                                                                   *\n\
           *   - SEARCH FOR A PARTICULAR PERSON IF HE HAS VISITED              *\n\
           *                                                                   *\n\
           *   SOURCECODE  ON  GITHUB  UNDER     Apache-2.0 license            *\n\
           ********************************************************************* ");
           printf("\n\n\n\n    ");

           printf("Project Developed by Divyansh , Liza , Sargam ");
           printf("\n\n");
           config(900000);


}
// configuration function

void config(int seconds){

    printf("\n \n \n       ");
    printf("configuring");

    for(int i= 20 ; i<=40;i++){

            usleep(seconds);
            printf(".");
    }

    }

    // border line function to  create a separating line

void borderline(){
printf("\n\n\n ");
    for(int i=1;i<=50;i++){
        printf("*");
    }
    printf("\n\n");

}
// welcome page
void welcome_page(){
 borderline();
    printf("ENTER 1  - > NEW ENTRY \n\n\n ENTER 2 -> SEARCH FOR VISITOR \n\n\n ENTER 3 -> GET VISITOR'S STATS \n\n\n 4 -> LOGOUT \n\n");
    int ch;
    scanf("%d" , &ch);

    if(ch == 1){
        borderline();
        usleep(20000);
        NEW_ENTRY();
    }else if(ch == 2){
        borderline();
        usleep(20000);
        SEARCH_VISITOR();

    }
    else if(ch ==3){
        borderline();
        usleep(20000);
        VISITOR_STATS();
    }else if(ch==4){
        borderline();
        usleep(20000);
        logout_user();
    }

}

//  function to search for particular visitor
void  SEARCH_VISITOR(){

if(check < 0){
    printf("Sorry no visitors have checked in so far ! \n\n");
    welcome_page();
}
int output;
printf("ENTER THE NAME OF THE VISITOR ");
char search_name[50];
scanf("%s" , &search_name);
int flag=-1;
for(int i =0;i<=check;i++){
    if(strcmp(search_name , visitor[i].name ) == 0){
            output = i;
            break;
    }else{
        output =-1;
    }
}
// code for checking and operations on output variable
if(output!=-1){

    printf("\n\n\n  NAME : %s \t ADDRESS : %s \n\n MOBILE-NUMBER : %d \t GENDER : %s " , visitor[output].name , visitor[output].Address , visitor[output].mobile_number , visitor[output].gender);
    printf("\n\n\n");
    for(int k = 0;k<=30;k++){
        printf("*");
    }

}else{
    printf("No such user has checked in so far ! \n\n");
    welcome_page();
}
    printf("\n\n\n");
welcome_page();
}

//CHECKOUT FUNCTION

void check_out(){
//  this fucntion to  update the session code
// so first we need to search for the user


}

// LOGOUT USER FUNCTION

void logout_user(){
 printf("\n\n LOGGED  OUT ! \n\n ");
 printf("\n\n");
 login_admin();

}
// function to get the stats of all the visitors
void VISITOR_STATS() {
    printf("\n\n");
borderline();

printf("\n\n ");

printf("TOTAL NUMBER OF VISITOR'S  VISITED SO FAR : %d " ,  check+1 );
printf("\n\n ");

if(check< 0){
    printf("NO USER HAVE CHECKED IN SO FAR \n\n\n");
    welcome_page();
}
int mcounter = 0;
int fcounter = 0;
int ocounter = 0;
for(int i = 0; i<=check ;i++){
    if(strcmp(visitor[i].gender , "M") == 0){

        ++mcounter;
    }else if(strcmp(visitor[i].gender , "F")== 0){
        ++fcounter;
    }else{
        ocounter++;
    }
}
printf("TOTAL NUMBER OF MALE VISITOR'S  VISITED SO FAR : %d " ,  mcounter );
printf("\n\n ");
printf("TOTAL NUMBER OF FEMALE VISITOR'S  VISITED SO FAR : %d " ,  fcounter );
printf("\n\n ");
printf("TOTAL NUMBER OF 'NOT SPECIFIED' VISITOR'S  VISITED SO FAR : %d " ,  ocounter);
printf("\n\n ");
welcome_page();
}
// NEW ENTRY VISITOR FUCNTION

// code for admin login
void login_admin(){
    printf("\n\n PLEASE  ENTER THE ADMIN PASSWORD TO ACCESS SOFTWARE");
    char passcode[20];
    scanf("%s" , &passcode);

    if(strcmp(passcode , "123ABC" ) == 0){
        printf("\n\n\n PASSWORD VERIFICATION COMPLETED SUCCESSFULLY \n\n\n ");
        printf("\n\n\n");
        welcome_page();
    }
    else{
        printf("\n\n INCORRECT PASSWORD RETRY ! \n\n\n");
        login_admin();
    }
}


// code for user login
void NEW_ENTRY(){
check++;
printf("\n\n\n\n   ENTER VISITOR'S  NAME ");
scanf("%s" , &visitor[check].name);
printf("\n\n\n\n   ENTER VISITOR'S  ADDRESS ");
scanf("%s" , &visitor[check].Address);
printf("\n\n\n\n   ENTER VISITOR'S  MOBILE NUMBER ");
scanf("%s" , &visitor[check].mobile_number);
printf("\n\n\n\n   ENTER VISITOR'S  gender  ");
printf("please  note  : INPUT  'M' FOR MALE 'F' FOR FEMALE 'O' FOR NOT SPECIFING ");
scanf("%s" , &visitor[check].gender);
visitor[check].status_code = 301;  // 301 means  visitor has checked in successfully

printf("\n\n saving data .. \n");
for(int i = 0;i<=20;i++){
    printf("...");
}
printf("\n\n");

welcome_page();
}
// drivers code
void main(){
    // welcome function to greet our visitors

    welcome();
    login_admin();
}
