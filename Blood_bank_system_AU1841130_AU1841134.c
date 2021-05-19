//**********************************************************
//   ROLLNO     |    NAME        |      EMAILID             |
//-----------------------------------------------------------
// AU1841130    | HARSH MANGE    |  harsh.m2@ahduni.edu.in  |                                   |
//AU1841134     | SHARVIL PATEL  |  sharvil.p@ahduni.edu.in |
//***********************************************************




//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>                  
#include<ctype.h>                   
#include<dos.h>                     
#include<time.h>

//***************************************************************
//      global declaration of functions
//****************************************************************


void donormenu(void);
void patientmenu(void);
void viewmenu();
void patientview();
void donorview();
void donationview();
void mainmenu();
void add_donor(void);
void update_donor();
void delete_donor();
void add_patient(void);
void update_patient();
void delete_patient();
void add_bagdetail(int);
void pat_doc();
void view_allpatient();
void view_patientid();
void view_donorid();
void view_alldonor();
void box();
void patientpattern(void); 
void donorpattern(void);
void boxoldvalue(void);
void loader();
void adddonation();
void deletedonation();
void donation(void);
void bmsbox();
int check_password();
void passbox();
void loginpattern(void);

COORD coord = {0, 0};
void gotoxy (int x, int y)
{
coord.X = x; coord.Y = y; // X and Y coordinates
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


//***************************************************************
//                   STRUCTURES TO BE USED IN PROJECT
//****************************************************************



struct donor
{
	char name[20],gender[8],bgp[4];
	int age,weight,donorid;
} d;

struct patient
{
	char name[20],gender[8],docname[20],bgp[4];
	int age,patientid,noofbag,weight;
	//struct dosdate_t Date;
   int amount;
} p;

 struct bagdetail
  {
    int pid;
    int bid;
 }bg;
 
 struct doctor
 {
    int ptid;
    char docname[30];
    char clinic_name[30];
 } dct;

struct blood_stock
 {
	char bg[4];
	int nobag;

 }   bldstk;
 
 //STRUCTURES END HERE


//***************************************************************
//      global declaration for file pointers
//****************************************************************


FILE *fd,*fp,*ft,*fdd;
int i;
char ch;
int main()
{     int flag,name;
	
	HWND hWnd;
   SetConsoleTitle("test");
   hWnd = FindWindow(NULL, "test");
   HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
   COORD maxXY = GetLargestConsoleWindowSize(hOut);
  // printf("Maximum x and y coordinate in the window = %d %d",maxXY.X,maxXY.Y );
 
   SetConsoleScreenBufferSize(hOut, maxXY);
 
   ShowWindow(hWnd, SW_MAXIMIZE);
   	
   		pass:
   	flag = check_password();
     
   	if (flag==1)
   	   {
		printf("\n\n\nLogin successful."); //write program logic here
      
      	 system("cls");    
					
				   bmsbox();
				   gotoxy(32,13);
				   printf("\xcd\xcd\xcd\xcd\xcdWELCOME TO\xcd\xcd\xcd\xcd\xcd");
				   sleep(1);
				   gotoxy(52,19);
				   printf(" \xcd\xcd\xcd\xcd BLOOD BANK\xcd\xcd\xcd\xcd");  
				   sleep(1);
      			   gotoxy(72,25);
				   printf("\xcd\xcd\xcd\xcd\xcdMANAGEMENT\xcd\xcd\xcd\xcd\xcd");
				   sleep(1);
				   gotoxy(92,31);
				   printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcdSYSTEM\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
        	loader();
         mainmenu();
       }
       
	else
        gotoxy(54,70); 	
         
                  for(i=0; i<3; i++)
			            {
						           
	   	                     printf("Login failed,PLEASE RE-ENTER PASSWORD.");               
                             Sleep(500);
                        system("cls");
                        Sleep(500);
                         }
                         
                         ch=getch();
                     passbox();
                     system("cls");
				goto pass;


	return 0;
}
void mainmenu()
{
		
		       system("color 03"); 
 	             system("cls");
 	              gotoxy(50,9);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 [MAIN MENU]\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
				    gotoxy(50,12);             
printf("\xDB\xDB:::::::::::::::\xB2\xB2   <<<[1]>>>  DONOR       \xB2\xB2:::::::::::::::\xDB\xDB");
	               gotoxy(50,15);
printf("\xDB\xDB:::::::::::::::\xB2\xB2   <<<[2]>>>  PATIENT     \xB2\xB2:::::::::::::::\xDB\xDB");                                      
				gotoxy(50,18) ; 
printf("\xDB\xDB:::::::::::::::\xB2\xB2   <<<[3]>>>  VIEW        \xB2\xB2:::::::::::::::\xDB\xDB");
				gotoxy(50,21); 
printf("\xDB\xDB:::::::::::::::\xB2\xB2   <<<[4]>>> DONATION     \xB2\xB2:::::::::::::::\xDB\xDB");
		        gotoxy(50,24);
printf("\xDB\xDB:::::::::::::::\xB2\xB2   <<<[5]>>> BLOOD STOCK  \xB2\xB2:::::::::::::::\xDB\xDB");
		        gotoxy(50,27);
printf("\xDB\xDB:::::::::::::::\xB2\xB2   <<<[0]>>>   EXIT       \xB2\xB2:::::::::::::::\xDB\xDB");
				gotoxy(50,30);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
				      
				      
	gotoxy(20,36);
	printf("Enter your choice:");
	
	time_t t;
	time(&t);
	gotoxy(53,32);
	printf("%s",ctime(&t));
		switch(getch())
		{
			case '1':
				{
					system("cls");
					donormenu();
					break;
				}
			case '2':
			{
				system("cls");
				patientmenu();
				break;
			}
			case '3':
			{
				system("cls");
	    	      viewmenu();
					break;
			}
				case '4':
			{
				system("cls");
				donation();
					break;
			}	
				case '5':
			{
				system("cls");
			    bloodstock();
					break;
			}	
				case '0':
			{
				system("cls");
				gotoxy(50,50);
				
	printf("\n::::::::::::::::::::::::::::::::::::::::");
	printf("\n::::::::::::::::::::::::::::::::::::::::");
	printf("\n::                 THIS               ::");
	printf("\n::                 PROJECT            ::");
	printf("\n::                   IS               ::");
	printf("\n::                BROUGHT TO U        ::");
	printf("\n::                   BY               ::");
	printf("\n::            SHARVIL AND HARSH.      ::");
	printf("\n::::::::::::::::::::::::::::::::::::::::");
	printf("\n::::::::::::::::::::::::::::::::::::::::");
	
	gotoxy(50,65);
   printf("\n\n\n::::::::::::::::::::::::::::::::::::::::::::::");
	   printf("\n::::::::::::::::::::::::::::::::::::::::::::::");
       printf("\n::       UNDER GUIDANCE OF                  ::");
   	   printf("\n::       PROF.KUNTAL PATEL,                 ::");
       printf("\n::      PROF.ADITYA PATEL,                  ::");
       printf("\n::      AND RESPECTED TA'S.                 ::");
       printf("\n::::::::::::::::::::::::::::::::::::::::::::::");
       printf("\n::::::::::::::::::::::::::::::::::::::::::::::");
				ch=getch();
				exit(1);
					break;
			}
			default:
			{
                    
				 for(i=0; i<5; i++)
                      {
			          
					  printf("\nPlease enter between 0 to 5 only\n");
                      Sleep(500);
                      system("cls");
                      Sleep(500);
                     }
				
				mainmenu();
			}		
	}
}
	
void donormenu(void)
{
system("color 03"); 
 loader();
 system("cls");
gotoxy(50,14);	
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 [DONOR MENU]\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(50,17);
printf("\xDB\xDB:::::::::::::::\xB2\xB2    <<<[1]>>>   For adding donor  \xB2\xB2:::::::::::::::\xDB\xDB ");
gotoxy(50,20);
printf("\xDB\xDB:::::::::::::::\xB2\xB2    <<<[2]>>>   For update donor   \xB2\xB2:::::::::::::::\xDB\xDB");
gotoxy(50,23);
printf("\xDB\xDB:::::::::::::::\xB2\xB2    <<<[3]>>>   For delete donor   \xB2\xB2:::::::::::::::\xDB\xDB");
gotoxy(50,26);
printf("\xDB\xDB:::::::::::::::\xB2\xB2    <<<[0]>>>   EXIT               \xB2\xB2:::::::::::::::\xDB\xDB");
gotoxy(50,29);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");	
		gotoxy(50,32);
		printf("Enter your choice:");

		switch(getch())
		{
			case '1':
				{
					system("cls");
					add_donor();
					break;
				}
			case '2':
			{
				system("cls");
				update_donor();
				break;
			}
			case '3':
			{
				system("cls");
				delete_donor();
					break;
			}
				case '0':
			{
				system("cls");
				mainmenu();
					break;
			}
			default:
			{
				for(i=0; i<5; i++)
                     
					  {
			          
					  printf("\nPlease enter between 0 to 3 only\n");
                      Sleep(500);
                      system("cls");
                      Sleep(500);
                     }

             
			 				
				donormenu();
				break;
			}		
	}
}

void patientmenu(void)
{
system("color 03"); 
loader();
system("cls");
gotoxy(50,14);	
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 [PATIENT MENU]\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(50,17);
printf("\xDB\xDB:::::::::::::::\xB2\xB2    <<<[1]>>>   For adding patient   \xB2\xB2:::::::::::::::\xDB\xDB ");
gotoxy(50,20);
printf("\xDB\xDB:::::::::::::::\xB2\xB2    <<<[2]>>>   For update patient   \xB2\xB2:::::::::::::::\xDB\xDB");
gotoxy(50,23);
printf("\xDB\xDB:::::::::::::::\xB2\xB2    <<<[3]>>>   For delete patient   \xB2\xB2:::::::::::::::\xDB\xDB");
gotoxy(50,26);
printf("\xDB\xDB:::::::::::::::\xB2\xB2    <<<[0]>>>   MAIN MENU            \xB2\xB2:::::::::::::::\xDB\xDB");
gotoxy(50,29);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");	
		gotoxy(50,32);
		printf("Enter your choice:");
	
		switch(getch())
		{
			case '1':
				{
					system("cls");

					add_patient();
					break;
				}
			case '2':
			   {
				system("cls");
				update_patient();
				break;
		       }
			case '3':
			  {
				system("cls");
				delete_patient();
					break;
			  }
			case '0':
			 {
				system("cls");
				mainmenu();
					break;
			 }
			default:
			{
				for(i=0; i<5; i++)
                     
					  {
			          
					  printf("\nPlease enter between 0 to 3 only\n");
                      Sleep(500);
                      system("cls");
                      Sleep(500);
                     }

				patientmenu();
				break;
			}		
	}
}
void viewmenu(void)
{
	system("color 03"); 
loader();
system("cls");
	gotoxy(50,14);	
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 [VIEW MENU]\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(50,17);
printf("\xDB\xDB:::::::::::::::\xB2\xB2    <<<[1]>>>  VIEW DONOR     \xB2\xB2:::::::::::::::\xDB\xDB");
gotoxy(50,20);
printf("\xDB\xDB:::::::::::::::\xB2\xB2    <<<[2]>>>  VIEW PATIENT   \xB2\xB2:::::::::::::::\xDB\xDB");
gotoxy(50,23);
printf("\xDB\xDB:::::::::::::::\xB2\xB2    <<<[3]>>>  VIEW DONATION  \xB2\xB2:::::::::::::::\xDB\xDB");
gotoxy(50,26);
printf("\xDB\xDB:::::::::::::::\xB2\xB2    <<<[0]>>>  MAIN MENU      \xB2\xB2:::::::::::::::\xDB\xDB");
gotoxy(50,29);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");	
		gotoxy(50,32);
		printf("Enter your choice:");

	
	
                 
		switch(getch())
		{
			case '1':
				{
					system("cls");
					  donorview();
					break;
				}
				
			case '2':
			{
				system("cls");
				patientview();
				break;
			}
			case '3':
			{
				system("cls");
	               bloodstock();			
					break;
			}
			case '0':
			{
				system("cls");
				mainmenu();
					break;
			}
			default:
			{
				for(i=0; i<5; i++)
                     
					  {
			          
					  printf("\nPlease enter between 0 to 3 only\n");
                      Sleep(500);
                      system("cls");
                      Sleep(500);
                     }

				viewmenu();
				break;
			}		
	}
}



void patientview()
{
	system("color 03"); 
	loader();
	system("cls");
	gotoxy(50,14);	
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 [PATIENT VIEW]\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(50,17);
printf("\xDB\xDB:::::::::::::::\xB2\xB2    <<<[1]>>>   VIEW USING PATIENT ID               \xB2\xB2:::::::::::::::\xDB\xDB");
gotoxy(50,20);
printf("\xDB\xDB:::::::::::::::\xB2\xB2    <<<[2]>>>   VIEW DOCTOR INFO BY PATIENT ID      \xB2\xB2:::::::::::::::\xDB\xDB");
gotoxy(50,23);
printf("\xDB\xDB:::::::::::::::\xB2\xB2    <<<[3]>>>   VIEW ALL PATIENT                    \xB2\xB2:::::::::::::::\xDB\xDB");
gotoxy(50,26);
printf("\xDB\xDB:::::::::::::::\xB2\xB2    <<<[0]>>>    EXIT                               \xB2\xB2:::::::::::::::\xDB\xDB");
gotoxy(50,29);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");	
		gotoxy(50,32);
		printf("Enter your choice:");

    
		switch(getch())
		{
			case '1':
				{
					system("cls");
				 view_patientid();
					 break;
				}
			case '2':
			{
				system("cls");
			   pat_doc();
				break;
			}
			case '3':
			{
				system("cls");
				view_allpatient();
					break;
			}
			case '0':
			{
				system("cls");
				viewmenu();
					break;
			}
			default:
			{
				for(i=0; i<5; i++)
                     
					  {
			          
					  printf("\nPlease enter between 0 to 3 only\n");
                      Sleep(500);
                      system("cls");
                      Sleep(500);
                     }

			    patientview();
				break;
			}		
	}
}	                 
	            
void donorview()
{
	system("color 03"); 
	loader();
	system("cls");
	  	gotoxy(50,14);	
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 [DONOR VIEW]\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(50,17);
printf("\xDB\xDB:::::::::::::::\xB2\xB2    <<<[1]>>>   VIEW USING DONOR ID        \xB2\xB2:::::::::::::::\xDB\xDB ");
gotoxy(50,20);
printf("\xDB\xDB:::::::::::::::\xB2\xB2    <<<[2]>>>   VIEW ALL DONOR             \xB2\xB2:::::::::::::::\xDB\xDB");
gotoxy(50,23);
printf("\xDB\xDB:::::::::::::::\xB2\xB2    <<<[0]>>>    EXIT                      \xB2\xB2:::::::::::::::\xDB\xDB");
gotoxy(50,26);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");	
		gotoxy(50,29);
		printf("Enter your choice:");

	       	
		switch(getch())
		{
			case '1':
				{
					system("cls");
					 view_donorid();
					 break;
				}
			case '2':
			{
				system("cls");
				view_alldonor();
				break;
			}
		
			case '0':
			{
				system("cls");
				viewmenu();
					break;
			}
			default:
			{
				for(i=0; i<5; i++)
                     
					  {
			          
					  printf("\nPlease enter between 0 to 2 only\n");
                      Sleep(500);
                      system("cls");
                      Sleep(500);
                     }

			    donorview();
				break;
			}		
	}

}

void donation(void)
{
	system("color 03"); 
	loader();
	system("cls");
	  	gotoxy(50,14);	
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 [DONATION MENU]\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(50,17);
printf("\xDB\xDB:::::::::::::::\xB2\xB2    <<<[1]>>>   ADD DONATION               \xB2\xB2:::::::::::::::\xDB\xDB ");
gotoxy(50,20);
printf("\xDB\xDB:::::::::::::::\xB2\xB2    <<<[2]>>>   DELETE DONATION             \xB2\xB2:::::::::::::::\xDB\xDB");
gotoxy(50,23);
printf("\xDB\xDB:::::::::::::::\xB2\xB2    <<<[0]>>>    EXIT                      \xB2\xB2:::::::::::::::\xDB\xDB");
gotoxy(50,26);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");	
		gotoxy(50,29);
		printf("Enter your choice:");

	switch(getch())
	{
		case '1':
			{
				adddonation();
				break;
			}
		case '2':
		    {
			    deletedonation();
			    break;
			}
		case '0':
		{
			mainmenu();
			break;
		}
		default:
		{
			for(i=0; i<5; i++)
                     
					  {
			          
					 printf("Please select between 0 to 2 only");
                      Sleep(500);
                      system("cls");
                      Sleep(500);
                     }

			
			donation();
			break;
		}	
	}
}

int checkid_donor(int checkdonorid)  //check whether the donor is exist or not
{	
   rewind(fd);
    while(fread(&d,sizeof(d),1,fd)==1)

   {
     if(d.donorid==checkdonorid)
     {
      return 0;  //returns 0 if donor exists
     }
   }
     return 1; //return 1 if it not
}

int getdata_donor()
{	
     
	donorpattern();
	
	box();
	int checkdonorid,flag;
     gotoxy(54,13);
	 printf(" ID:");
   //  scanf("%d",&checkdonorid);
            checkdonorid=getintonly();
			if(checkid_donor(checkdonorid) == 0)
               {
               	gotoxy(52,30);
                 for(i=0; i<5; i++)
                      {
			        
					  printf("\aThe donor id already exists");
                      Sleep(500);
                      system("cls");
                      Sleep(500);
                     }

                 getch();
                 system("cls");
                 mainmenu();
                 return 0;
               }
           d.donorid=checkdonorid;
        gotoxy(54,14);
		printf(" Enter your name:");
        scanf("%s",d.name);
      
      donorgender:
     redgender:
      gotoxy(54,15);     
	 printf(" Enter your gender:");
     scanf("%s",&d.gender);
      strlwr(d.gender);
   if(strcmp(d.gender,"male")!=0 && strcmp(d.gender,"female")!=0)
   {
           gotoxy(52,30); 	
   	   for(i=0; i<5; i++)
                      {
			        
					   	printf("\a Gender should be male or female only!! please re-enter gender");
                      Sleep(500);
                      system("cls");
                      Sleep(500);
                     }

      box();
   	goto redgender;
   }
    fflush(stdin);
   redbgp:
   gotoxy(54,16);
    printf(" Enter blood-group:");
   scanf("%s",&d.bgp);
   strupr(d.bgp);
   if(strcmp(d.bgp,"A")!=0 && strcmp(d.bgp,"A+")!=0 && strcmp(d.bgp,"A-")!=0 && strcmp(d.bgp,"B")!=0 && strcmp(d.bgp,"B+")!=0 && strcmp(d.bgp,"B-")!=0 && strcmp(d.bgp,"O")!=0 && strcmp(d.bgp,"O+")!=0 && strcmp(d.bgp,"O-")!=0 && strcmp(d.bgp,"AB")!=0 && strcmp(d.bgp,"AB+")!=0 && strcmp(d.bgp,"AB-")!=0)
    {     
                  gotoxy(54,32);
                  for(i=0; i<3; i++)
			            {
						           
	   	                printf("Please enter valid blood-group");
                             Sleep(500);
                        system("cls");
                        Sleep(500);
                         }
                         
     box();
	 goto redbgp;
	}
   fflush(stdin);
      gotoxy(54,17);
  printf(" Enter your age:");
    	  // scanf("\n %d",&d.age);
    	  d.age=getintonly();
   gotoxy(54,18);
    printf(" Enter your weight:");
     	  // scanf("%d",&d.weight);
     	  d.weight=getintonly();

  if(d.weight<50 || d.age<18)
   {  
                  gotoxy(54,30);
                  for(i=0; i<5; i++)
			            {
						           
	   	                
       printf("Invalid donor!! Minimum age:18 and Minimum weight:50");
                               Sleep(500);
                        system("cls");
                        Sleep(500);
                        }
                        donormenu();

       }

  /*else
             gotoxy(54,25);
             	for(i=0; i<5; i++)
                      {
			          
                          printf("\n YOU ARE NOT A VALID DONOR");
                      Sleep(500);
                      system("cls");
                      Sleep(500);
                     }
  */
   
   
   return 1;
   
  /*flag= valid_donor( d);
   if(flag==2){
return 2;
}
else if(flag==3)
{
	printf("\nDonor is not applicable\n");
	mainmenu();
}*/
}



void add_donor()
{
   system("cls");
   int flag;   
    fd=fopen("donor(1).dat","ab+");
   if(getdata_donor()==1)
   {
   	
   	 fseek(fd,0,SEEK_END);
     fwrite(&d,sizeof(d),1,fd);  
     fclose(fd);
	 system("cls");
	 donormenu();
	}
  printf("\nThe record is sucessfully saved\n");
  
  getch();
}



void update_donor()
{
	system("cls");
	 char ch;
	 int donorid2,flag=0;
	 fd=fopen("donor.dat","rb+");
	 if(fd==NULL)
	 	printf("\n File cannot be opened");

     	printf("\n ENTER id :");
     //	scanf("%d",&donorid2);
	 	donorid2=getintonly();
	while(fread(&d,sizeof(d),1,fd)==1)
	  {
	 		if(donorid2==d.donorid)
	 		 { 
	                 printf("\nDonor data is available\n");
					 boxoldvalue();   
					 gotoxy(42,8);
	                 printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcdOLD VALUES\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
	                gotoxy(27,16);
                	printf("Name   \xcd \xcd : %s",d.name);
	                gotoxy(27,18); 
					printf(" Id    \xcd \xcd:%d",d.donorid);
	                gotoxy(27,20);
					printf("Age     \xcd \xcd: %d",d.age);
	                gotoxy(27,22);
					printf("Gender   \xcd \xcd : %s",d.gender);
                     gotoxy(27,24);
				   printf("Bloodgroup \xcd \xcd : %s",d.bgp);    
	            gotoxy(27,26);
				printf("  Weight  \xcd \xcd  : %d",d.weight);   
		      gotoxy(27,30);
		      printf("Do you want to update(Y/N):");
		        fflush(stdin);
               ch=getch();
				fflush(stdin);
				fflush(stdin);
		        
				if(ch=='y'||ch=='Y')
		          {
		          	      
		          	      system("cls");
		          	     box();
		          	     gotoxy(52,8);
		                printf("<<<<<<<<<<<<<<<<<<<<<<<<<Enter Information>>>>>>>>>>>>>>>>>>>");
		          
		                gotoxy(52,14);
		  	   		   printf("Name:");
		            scanf("%s",&d.name);
                     	redupgender: 		    
					  gotoxy(52,16);
		          	
		              printf("Gender:");
					scanf("%s",&d.gender);
					 strlwr(d.gender);
   if(strcmp(d.gender,"male")!=0 && strcmp(d.gender,"female")!=0)
   {
   	   gotoxy(54,32);
    	              for(i=0; i<3; i++)
			            {
						
   	   	               	printf("\aGender should be male or female only!! please re-enter gender");
								          
					      Sleep(500);
                        system("cls");
                        Sleep(500);
                         }
     box();
   	goto redupgender;
   }    
                 redupbgp:
					 gotoxy(52,18);
			        
					printf("Blood Group:");
					scanf("%s",&d.bgp);
					  strupr(d.bgp); 
					 if(strcmp(d.bgp,"A")!=0 && strcmp(d.bgp,"A+")!=0 && strcmp(d.bgp,"A-")!=0 && strcmp(d.bgp,"B")!=0 && strcmp(d.bgp,"B+")!=0 && strcmp(d.bgp,"B-")!=0 && strcmp(d.bgp,"O")!=0 && strcmp(d.bgp,"O+")!=0 && strcmp(d.bgp,"O-")!=0 && strcmp(d.bgp,"AB")!=0 && strcmp(d.bgp,"AB+")!=0 && strcmp(d.bgp,"AB-")!=0)
                 {
    	              gotoxy(54,32);
    	              for(i=0; i<3; i++)
			            {
						
   	   	                printf("Please enter valid blood-group");
                             Sleep(500);
                        system("cls");
                        Sleep(500);
                         }
              box();
             goto redupbgp;
                  	}
					strupr(d.bgp);
					invalidupdate:
					 gotoxy(52,20);
					 
					 	 printf("Age:");
				   // scanf("%d",&d.age);
				   d.age=getintonly();
				   	 gotoxy(52,22);
					printf("Enter your weight:");
     		   		//scanf("%d",&d.weight); 
     		   		d.weight=getintonly();
     		   		if(d.weight<50 || d.age<18)
   {  
                 for(i=0; i<5; i++)
			            {
						           
	   	gotoxy(52,40);
         printf("Invalid !! Minimum age:18 and Minimum weight:50 , Please re-enter age and weight!!");                
        
        Sleep(500);
        system("cls");
        Sleep(500);
    }
       box();
       goto invalidupdate;
   }
   
       		fseek(fd,-sizeof(struct donor),SEEK_CUR);
     //	fseek(fd,ftell(fd)-sizeof(d),0);
						fwrite(&d,sizeof(d),1,fd);
						
						for(i=0; i<5; i++)
			            {
						  gotoxy(52,40) ;        
	   	                printf(" Record is updated");
                         Sleep(500);
                        system("cls");
                        Sleep(500);
                         }
		 
						
						flag=1;
						break;
						system("cls");
						donormenu();
			     getch();
	 		  }     
	    } 
	}
	
    	
		if(flag==0)
		{
			for(i=0; i<5; i++)
                      {
			          
					  printf("Donor data is not available");
                      Sleep(500);
                      system("cls");
                      Sleep(500);
                     }

			
		}
		    fclose(fd);
		    getch();
		    system("cls");
		    donormenu();
		}


void delete_donor()    
{
system("cls");
int deletedonorid;
char finddonor;

system("cls");
printf("Enter the donor ID to  delete:");
//scanf("%d",&deletedonorid);
deletedonorid=getintonly();
fd=fopen("donor.dat","rb+");

     while(fread(&d,sizeof(d),1,fd)==1) 
      {
     if(d.donorid==deletedonorid)
        {
      printf("The donor record is available\n");
       printf("Donor name is %s\n",d.name);
    finddonor='a';
        }
    
     }


if(finddonor!='a')
  {
  	for(i=0; i<5; i++)
        {
			          
		printf("No record is found...\n");
        Sleep(500);
        system("cls");
        Sleep(500);
        }
    system("cls");
     donormenu();
  }
if(finddonor=='a' )
{
   printf("Do you want to delete it?(Y/N):");  
      if(getch()=='y'|| getch()=='Y')
   {
       ft=fopen("temporary.dat","wb+");  //temporary file for delete
      rewind(fd);
      while(fread(&d,sizeof(d),1,fd)==1)
     {
       if(d.donorid!=deletedonorid)
        {
      fseek(ft,0,SEEK_CUR);
     fwrite(&d,sizeof(d),1,ft);
       }                              
    } 
    fclose(ft);
    fclose(fd);
    remove("donor.dat");
    rename("temporary.dat","donor.dat"); 
     fd=fopen("donor.dat","r+"); 
    if(finddonor=='a')
     {
     	gotoxy(54,32); 
		 	for(i=0; i<5; i++)
			{
		 				           
	   	printf("The record is sucessfully deleted");
        Sleep(500);
        system("cls");
        Sleep(500);
        }
       // break ;
        getch();
    donormenu();
     }
         
		    }
//break;		     

getch();
system("cls");
donormenu();


       }
  }
	
	
	
	
	int checkid_patient(int checkpatientid)  //check whether the patient is exist or not
{
  
rewind(fp);
while(fread(&p,sizeof(p),1,fp)==1)
{
    if(p.patientid==checkpatientid)
     {   
	   return 0;
	 }
}
return 1; //return 1 if it not
}

 void add_doctor(struct patient p)
 {
     system("cls");
     ft=fopen("doctor.dat","ab+");
     if(ft==NULL)
       {
	 printf("\nFile cannot be opened");
       }
     else
      {
	   dct.ptid= p.patientid;
	   strcpy(dct.docname,p.docname);
	   printf("\n Enter clinic name:");
	   	   scanf("%s",&dct.clinic_name);
	     fwrite(&dct,sizeof(dct),1,ft);
	      printf("\n Patient-Doctor Record is written:");
	   }
	   fclose(ft);
	   system("cls");
	   donormenu();
  }



int getdata_patient()
{
    //  void add_bagdetail(int,int);
      //void add_doctor(int);
	  
	patientpattern();
	box();
	int checkpatientid,patientid;
        gotoxy(54,13); 
		printf("ID:");
    // scanf("%d",&checkpatientid);
    checkpatientid=getintonly();
      if(checkid_patient(checkpatientid) == 0)
{
     gotoxy(52,30);
     //sleep(3000);
	 for(i=0; i<5; i++)
        {
			            
	    printf("\aThe patient id already exists");
        Sleep(500);
        system("cls");
        Sleep(500);
        }
	 
      getch();
      system("cls");
      patientmenu(); 
      return 0;
}
    p.patientid=checkpatientid;
     gotoxy(54,14);
	printf("Enter your name:");
    scanf("%s",&p.name);
    
	gotoxy(54,15);
      printf("Enter your age:");
   //scanf("%d",&p.age);
    p.age=getintonly();
	repgender:   
	gotoxy(54,16);
	
    
	printf("Enter your gender:");
    scanf("%s",&p.gender);
     strlwr(p.gender);
   if(strcmp(p.gender,"male")!=0 && strcmp(p.gender,"female")!=0)
   {
   	  gotoxy(54,32); 
    
                  for(i=0; i<3; i++)
			            {
						           
	   	               printf("\aGender should be male or female only!! please re-enter gender");
                             Sleep(500);
                        system("cls");
                        Sleep(500);
                         } 
   	box();
   	goto repgender;
   }
    repbgp: 
	gotoxy(54,17);
   
   printf("Blood Group:");
   fflush(stdin);
	scanf("%s",&p.bgp);
	strupr(p.bgp);
	 if(strcmp(p.bgp,"A")!=0 && strcmp(p.bgp,"A+")!=0 && strcmp(p.bgp,"A-")!=0 && strcmp(p.bgp,"B")!=0 && strcmp(p.bgp,"B+")!=0 && strcmp(p.bgp,"B-")!=0 && strcmp(p.bgp,"O")!=0 && strcmp(p.bgp,"O+")!=0 && strcmp(p.bgp,"O-")!=0 && strcmp(p.bgp,"AB")!=0 && strcmp(p.bgp,"AB+")!=0 && strcmp(p.bgp,"AB-")!=0)
    {
       gotoxy(54,32); 
    
                  for(i=0; i<3; i++)
			            {
						           
	   	                printf("Please enter valid blood-group");
                             Sleep(500);
                        system("cls");
                        Sleep(500);
                         } 
       
       box();
       goto repbgp;
	}
	   fflush(stdin);
    
	gotoxy(54,18);
     printf("Doctor Name:");
		scanf("%s",&p.docname);		   
	
			 gotoxy(54,19);
           printf("no of bags :");
			scanf("%d",&p.noofbag);
			//_dos_getdate(&p.Date);
      p.amount = p.noofbag*900;
    //add_bagdetail(p.patientid);
     add_doctor(p);
return 1;
}






void add_patient() // int patientid )
{
 system("cls");
 
  fp=fopen("patient.dat","ab+");
   if(getdata_patient()==1)
   {
   	
   	fseek(fp,0,SEEK_END);
    fwrite(&p,sizeof(p),1,fp);
    fclose(fp);
    system("cls");
    printf("The record is successfully saved\n");
     
	 patientmenu();
      }
	  else
system("cls");
//add_patient();
   }


void add_bagdetail(int patientid)
{
   int bid;
    system("cls");
    fp=fopen("bag.dat","ab+");
     if(fp==NULL)
      {
       printf("\nFile cannot be opened");
      }
 else
 {

  bg.pid= patientid;
  
     printf("\nEnter the bagid for bag ");
        fflush(stdin);
     scanf("%d",&bid);
        fflush(stdin);
      bg.bid=bid;
       fwrite(&bg,sizeof(bg),1,fp);

     printf("\n Patient-blood bag Record is written:");
    fclose(fp);
  }
}
 
void update_patient()
{
	system("cls");
  char ch;
  int ptid2,flag=0;
  fp=fopen("patient.dat","rb+");
   if(fp==NULL)
   printf("File cannot be opened");
     printf("\nEnter id:");
     				fflush(stdin);
     //scanf("%d",&ptid2);
     ptid2=getintonly();
     				fflush(stdin);
     while(fread(&p,sizeof(p),1,fp)==1)
     {
        if(ptid2==p.patientid)
	        {
	        	 boxoldvalue();
	  	  printf("\n Patient data is available\n");
	  	  gotoxy(42,8);
	        printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd OLD VALUES\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
	        
	       
	        gotoxy(27,16);
		   	printf(" Name : %s",d.name);
	        gotoxy(27,18);
		   printf("  Id is:%d",p.patientid);
	       gotoxy(27,20);
		  printf("Age is: %d",p.age);
	       gotoxy(27,22);
		  printf("Gender is: %s",p.gender);
           gotoxy(27,24);
		  printf(" Bloodgroup is : %s",p.bgp);    
     	   gotoxy(27,26);
		   printf("Weight is : %d",p.weight);
            gotoxy(27,28);
			printf("Doctor name: %s",p.docname);   
	   	   gotoxy(27,30);
		     printf(" Do you want to update(Y/N):");
						fflush(stdin);
                 ch=getch();
						fflush(stdin);
		         if(ch=='Y' ||ch=='y')
		            {
		            	system("cls");
		 			    box();
		 			    gotoxy(52,8);
					     printf("<<<<<<<<<<<<<<<<<<<<<<<<<Enter Information>>>>>>>>>>>>>>>>>>>");
		  
		  	 				fflush(stdin);
		   			 gotoxy(52,14);
						printf(" Name:");
		   			 scanf("%s",&p.name);	
							fflush(stdin);	   
					gotoxy(52,16);
					printf(" Age :");
		    	//	scanf("%d",&p.age);
		    	p.age=getintonly();
		    				fflush(stdin);
		   		      repupgender:	
      					   gotoxy(52,18);
					   
					    printf("Gender :");
		    		scanf("%s",&p.gender);
		    			 strlwr(p.gender);
   if(strcmp(p.gender,"male")!=0 && strcmp(p.gender,"female")!=0)
   {  
        gotoxy(54,32); 
    
                  for(i=0; i<3; i++)
			            {
						           
	   	               printf("\aGender should be male or female only!! please re-enter gender");
                             Sleep(500);
                        system("cls");
                        Sleep(500);
                         } 
   
   	    box();
	   goto repupgender;
   }	    		
				  fflush(stdin);
		              repupbgp:      	
					gotoxy(52,20);
				   
					printf("Blood-group :");
		    		scanf("%s",&p.bgp);
		    		strupr(p.bgp);
			if(strcmp(p.bgp,"A")!=0 && strcmp(p.bgp,"A+")!=0 && strcmp(p.bgp,"A-")!=0 && strcmp(p.bgp,"B")!=0 && strcmp(p.bgp,"B+")!=0 && strcmp(p.bgp,"B-")!=0 && strcmp(p.bgp,"O")!=0 && strcmp(p.bgp,"O+")!=0 && strcmp(p.bgp,"O-")!=0 && strcmp(p.bgp,"AB")!=0 && strcmp(p.bgp,"AB+")!=0 && strcmp(p.bgp,"AB-")!=0)
                 {
    	           gotoxy(54,32);
                     for(i=0; i<3; i++)
			            {
						           
	   	                printf("Please enter valid blood-group");
                             Sleep(500);
                        system("cls");
                        Sleep(500);
                         }
                          box();
                        goto repupbgp;
	           }
		    				fflush(stdin);
		   			gotoxy(52,22);
					    printf("Weight :");
				//	scanf("%d",&p.weight);
				p.weight=getintonly();		
							fflush(stdin);		
		  		       gotoxy(52,24);
					 printf(" Doctor Name:");
		    		scanf("%s",&p.docname);		   
			
		   //  printf("\n no of bags :");
			//scanf("%d",&p.noofbag);
		fseek(fp,-sizeof(struct patient),SEEK_CUR);
			 
			//fseek(fp,ftell(fp)-sizeof(p),0);
		 	fwrite(&p,sizeof(p),1,fp);
			 
		 	for(i=0; i<5; i++)
			{
						           
	   	 printf("Record is updated");
        sleep(500);
        system("cls");
        sleep(500);
        }
		 
		     
		    flag=1;
		    break;
		 	getch();
			patientmenu();
           }
           //patientmenu();
       }
	
  }
   if(flag==0)
        {
         for(i=0; i<5; i++)
			{
						          
	    printf("\n Patient data is not available");
        sleep(500);
        system("cls");
        sleep(500);
        }
		 
         system("cls");
   {
         patientmenu();
  }
fclose(fp);
 
}
}

void delete_patient()    //function that delete items from file fp
{
    system("cls");
     FILE *fp,*ft,*fd;
  struct patient p;
    int deletepatientid;
   char another='y',findpatient=0;
    while(another=='y'||another=='Y')  //infinite loop
   {
      system("cls");
      printf("Enter the patient ID to  delete:");
       // scanf("%d",&deletepatientid);
       deletepatientid=getintonly();
         fp=fopen("patient.dat","rb+");
         rewind(fp);
        while(fread(&p,sizeof(p),1,fp)==1)
           {
                 if(p.patientid==deletepatientid)
                   {
						printf("The patient record is available\n");
						printf("Patient name is %s\n",p.name);
					findpatient='b';	
				   }
			}
       if(findpatient!='b')
        {
           printf("No record is found...\n");
            system("cls");
            getch();
			patientmenu();
        } 
           if(findpatient=='b' )
             {
                printf("Do you want to delete it?(Y/N):");
                if(getch()=='y'|| getch()=='Y')
                   {
                         ft=fopen("temporary.dat","w+");  //temporary file for delete
                         rewind(fp);
              while(fread(&p,sizeof(p),1,fp)==1)
                      {
                   if(p.patientid!=deletepatientid)
                        {
                            fseek(ft,0,SEEK_CUR);
                            fwrite(&p,sizeof(p),1,ft);
                         }                              
                      }
                      
		fclose(ft);
       fclose(fp);
       remove("patient.dat");
       rename("temporary.dat","patient.dat"); 
        fp=fopen("patient.dat","r+"); 
    if(findpatient=='b')
     {
     	
		 	for(i=0; i<5; i++)
			{
						           
	   	printf("The record is sucessfully deleted");
        sleep(500);
        system("cls");
        sleep(500);
        }
        getch();
        patientmenu();
     }
         
		    }
break;		     

getch();
system("cls");
patientmenu();


       }
  }
//mainmenu();
}


void view_donorid()
{
	int donorid2,flag=0,i;
  fd=fopen("donor.dat","rb");
   if(fd==NULL)
   {
    printf("File cannot be opened");
   }
   else
   {
   	  system("cls");
   	  
		  
     printf("\n Enter Donor ID that you want to  searh: ");
    // scanf("%d",&donorid2);
     donorid2=getintonly();
     
     while(fread(&d,sizeof(d),1,fd)==1)
     {
      if(donorid2==d.donorid)
      {
	       flag=1;  
	         system("cls");
	          boxoldvalue();   
             gotoxy(42,8);
	        printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd INFORMATION \xcd\xcd\xcd\xcd\xcd\xcd");
	        
	        gotoxy(27,16);
               
     	     printf("ID is:  %d",d.donorid);
     	     gotoxy(27,18);
			  printf("Name is:  %s",d.name);
	         gotoxy(27,20);
			 printf("Age is :  %d",d.age);
	         gotoxy(27,22);
			 printf("Gender is: %s",d.gender);
	         gotoxy(27,24);
			 printf("Blood-group is: %s",d.bgp);
	         gotoxy(27,26);
			 printf("Weight is: %d",d.weight);
	         	    	 	      break;
	    	 }
	    	 
    }  
	 
	 fclose(fd);
	 if(flag==0)
	{
	for(i=0; i<3; i++)
        {
		            
	      printf("\n Donorid doesnot exist");
          sleep(1);
          system("cls");
           sleep(1);
        }
   }
	 
	 	 getch();
	 	 system("cls");
	 donorview();
         
     }
    
}


void view_alldonor()
{
	  char ch;
  fd=fopen("donor.dat","rb+");
   if(fd==NULL)
   {
    printf("File cannot be opened");
   }
   else
   {
   	  system("cls");
   	   printf("	ID	|\tNAME			  |\tAGE	|\tGENDER	|\tBLOOD-GROUP	|\tWEIGHT|\n");
      printf("============================================================================================================================================\n");
      while(fread(&d,sizeof(d),1,fd)==1)
      {
	 	printf("	%1d	|\t%-4s		 	  |\t%3d	|\t%-6s	|\t%-11s	|\t%2d  KG 	|\n",d.donorid,d.name,d.age,d.gender,d.bgp,d.weight);
	 	printf("------------------------------------------------------------------------------------------------------------------------------------\n");
	       
	  }
	  
	     
		 fclose(fd);
		
		 getch();
		 system("cls");
		 donorview();
	}
		 
}
		 
void view_patientid()
{
   int p2id,flag=0;
   
   fp=fopen("patient.dat","rb");
   if(fp==NULL)
   {
    printf("\n File can't be opened");
   }
   else
  {
      system("cls");
      
      printf("\nEnter the patient id that you want to search:");
      fflush(stdin);
      //scanf("%d",&p2id);
      p2id=getintonly();
      
	        fflush(stdin);
   while(fread(&p,sizeof(p),1,fp)==1)
    {
       if(p2id==p.patientid)
        {
	 	 flag=1;
	 	 
	 	 
		  system("cls");
	         boxoldvalue();   
             gotoxy(42,8);
	        printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd INFORMATION \xcd\xcd\xcd\xcd\xcd\xcd");
	        
	        gotoxy(27,16);
	       printf("ID: %d",p.patientid);
	       gotoxy(27,18);
		   printf("Name: %s",p.name);
		  gotoxy(27,20);
		   printf("Gender: %s",p.gender);
			 gotoxy(27,22);
			 printf("Age: %d",p.age);
			gotoxy(27,24);
			printf("Blood-group: %s",p.bgp);
			gotoxy(27,26);
			printf("Weight: %d",p.weight);
			gotoxy(27,28);
				printf("No of blood bags taken  %d",p.noofbag);
				break;
	   }
    }
    fclose(fp);
    if(flag==0)
    for(i=0; i<5; i++)
        {
			            
	      printf("\nPateint id does not exit");
          sleep(1);
          system("cls");
           sleep(1);
        }

	
    
	getch();
	system("cls");
     patientview();
    }
}

void pat_doc()
{ 
  int pid,flag=0;
  
  fp=fopen("doctor.dat","rb");
  if(fp==NULL)
  {
   printf("\n File is not exit");
  }
  else
  {
      system("cls");
      printf("\nEnter the patient id  whose doctor u want to search:");
      scanf("%d",&pid);
      while(fread(&dct,sizeof(dct),1,fp)==1)
      {
	if(dct.ptid==pid)
	 {
	   	  system("cls");
	    boxoldvalue();   
          gotoxy(42,8);
		  printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd INFORMATION \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
	     
		   gotoxy(27,16);
	    printf("patient id :%d",dct.ptid);
	   gotoxy(27,19);
	   printf("Doctor name : %s",dct.docname);
	   	   gotoxy(27,22);
	     	   printf("Clinic name : %s",dct.clinic_name);
	    flag=1;
	 }
      }
   }
   fclose(fp);
   if(flag==0)
    for(i=0; i<5; i++)
        {
			            
	      printf("\nPateint id does not exit");
          sleep(1);
          system("cls");
           sleep(1);
        }

    	getch();
    	system("cls");
    patientview();
    
}



void view_allpatient()
{  

	char ch;
   	fp=fopen("patient.dat","rb");
   	if(fp==NULL)
   	{
    	printf("\n File cannot be opened");
   }
   else
  	{
      system("cls");
      printf("	ID	|\tNAME				|\tAGE	|\tGENDER	|\tBLOOD-GROUP	|\tWEIGHT	|\tNO.OF TAKEN BAGS \n");
     
	  printf("============================================================================================================================================================\n");
      while(fread(&p,sizeof(p),1,fp)==1)
      {
	 	printf("	%1d	|\t%-8s			|\t%4d	|\t%-6s	|\t%-11s	|\t%2d  KG 	|\t%8d	\n",p.patientid,p.name,p.age,p.gender,p.bgp,p.weight,p.noofbag);
	 	printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
		}
		
	} //end of else
    fclose(fp);
    
	getch();
	system("cls");
    patientview();
}	



void adddonation(void)
{
	system("cls");
	
	int flag=0,check_nobag;
	char check_bg[4];
	
	fdd=fopen("donation.dat","rb+");
	
		printf("Enter the blood-group:");
		scanf("%s",&check_bg);
		strupr(check_bg);
		
	while(fread(&bldstk,sizeof(bldstk),1,fdd)==1)
	{
       if(strcmp(check_bg,bldstk.bg)==0)
    {
			printf("\n\n\tBLOOD-GROUP=== %s",bldstk.bg);
			
			printf("\n\n\tNO OF BAGS=== %d\n",bldstk.nobag);
			break;
	}
	}
	{
       if(strcmp(check_bg,bldstk.bg)==0)
		{
			strcpy(bldstk.bg,check_bg);
		//	donorreport(check_bg,check_nobag);
			fflush(stdin);
			printf("\n\n\tEnter the no of blood bags that you want to add of %s blood group===",bldstk.bg);
		//	scanf("%d",&check_nobag);
		check_nobag=getintonly();
			bldstk.nobag=bldstk.nobag+check_nobag;
			//fseek(fdd,0,SEEK_END);
			fseek(fdd,-sizeof(struct blood_stock),SEEK_CUR);
			fwrite(&bldstk,sizeof(bldstk),1,fdd);
			
			printf("\nBlood stock updated\n");
			flag=1;
			getch();
		}
	}
	if(flag==0)
		{   
		// gotoxy(54,32);
                  for(i=0; i<3; i++)
			            {
						           
	   	                printf("Please enter valid blood-group");
                             Sleep(500);
                        system("cls");
                        Sleep(500);
                         }
			getch();
			adddonation();
		}
		    fclose(fdd);
		    system("cls");
		    donation();
}
void deletedonation(void)
{
	system("cls");
	
	int flag=0,check_nobag;
	char check_bg[4];
	
	fdd=fopen("donation.dat","rb+");
		
		printf("Enter the blood-group:");
		scanf("%s",&check_bg);
		
	while(fread(&bldstk,sizeof(bldstk),1,fdd)==1)
	{
       if(strcmp(check_bg,bldstk.bg)==0)
    {
			printf("\nBLOOD-GROUP: %s",bldstk.bg);
			printf("\tNO OF BAGS: %d",bldstk.nobag);
			break;
	}
	}
	{
       if(strcmp(check_bg,bldstk.bg)==0)
		{
			strcpy(bldstk.bg,check_bg);
			printf("\nEnter the no of blood bags that you want to delete of %s blood group:",bldstk.bg);
		//	scanf("%d",&check_nobag);
		check_nobag=getintonly();
			bldstk.nobag=bldstk.nobag - check_nobag;
			// fseek(ft,0,SEEK_CUR);
			fseek(fdd,-sizeof(struct blood_stock),SEEK_CUR);
			fwrite(&bldstk,sizeof(bldstk),1,fdd);
			
			printf("Blood stock updated\n");
			flag=1;
			getch();
		}
	}
	if(flag==0)
		{   
		 //gotoxy(54,32);
                  for(i=0; i<3; i++)
			            {
						           
	   	                printf("Please enter valid blood-group");
                             Sleep(500);
                        system("cls");
                        Sleep(500);
                         }
			
			getch();
			deletedonation();
		}
		    fclose(fdd);
		    system("cls");
		    donation();
}
bloodstock()
{
	fdd=fopen("donation.dat","rb+");
	 if(fdd==NULL)
   {
    printf("File cannot be opened");
   }
   else
   {
   	  system("cls");
   	  
   	  printf("BLOOD GROUP |  NO OF BAG	|\n");
      printf("=================================\n");
	while(fread(&bldstk,sizeof(bldstk),1,fdd)==1)
      {
      	
	 	printf(" %-4s        |    %-6d        |\n",bldstk.bg,bldstk.nobag);
	
	 	printf("---------------------------------\n");
	       
	  }
	fclose(fdd);
}
printf("\n\nPress any key for Main Menu\n");
getch();
system("cls");
mainmenu();
}









//***************************************************************
//          PATTERN,ANIMATION,LOADER FUNCTIONS
//***************************************************************	    


int check_password(){
	
	int i=0,name;
	char ch, temp[20], password[20]={"guest"};
	 

	
	
//	passbox();

   loginpattern();
	
	gotoxy(27,22);
	printf("\xcd\xcd\xcd\xcd\xcd\xcdUSERNAME\xcd\xcd\xcd\xcd\xcd\xcd\xcd");  
	gotoxy(96,22);
	scanf("%s",&name);
	
	gotoxy(27,32);
	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcdPASSWORD\xcd\xcd\xcd\xcd\xcd\xcd");
	 gotoxy(98,32);
	ch = getch();
	while(ch!=13 && i<20)
	{
		printf("*");
		temp[i]=ch;
		ch = getch();
		i++;	
	}
	temp[i]='\0';
	
	if(strcmp(temp, password)==0)
		return 1;
	else
		return 0;
	}



void passbox()
{
     int a,b=21,c,d=31,e,f=21,g,h=31;
	 char ch;
	 int x,y=11;
	 
	    gotoxy(25,10);  //login printed box logic
         for(x=0;x<90;x++)
		 {
		 	printf("%c",178);
		   }  
	
		   for(x=0;x<4;x++)
	{	printf("\n");
		gotoxy(25,y);
		printf("%c%c%87c%c",178,178,178,178);
			y++;}
	printf("\n");
	gotoxy(25,y); 	
 	
 	for(x=0;x<90;x++)
		 {
		 	printf("%c",178);
		   }
		   
    
	 	gotoxy(25,20);
         for(a=0;a<25;a++)
		 {
		 	printf("%c",178);
		   }  
	
		   for(a=0;a<4;a++)
	{	printf("\n");
		gotoxy(25,b);
		printf("%c%c%22c%c",178,178,178,178);
			b++;}
	printf("\n");
	gotoxy(25,b); 	
 	
 	for(a=0;a<25;a++)
		 {
		 	printf("%c",178);
		   }
		   
		   
		
		   	gotoxy(25,30);
         for(c=0;c<25;c++)
		 {
		 	printf("%c",178);
		   }  
	
		   for(c=0;c<4;c++)
	{	printf("\n");
		gotoxy(25,d);
		printf("%c%c%22c%c",178,178,178,178);
			d++;}
	printf("\n");
	gotoxy(25,d); 	

 	for(c=0;c<25;c++)
		 {
		 	printf("%c",178);
		   }  
		   
		   
		   
		   
			 	gotoxy(90,20);
         for(e=0;e<25;e++)
		 {
		 	printf("%c",178);
		   }  
	
		   for(e=0;e<4;e++)
	{	printf("\n");
		gotoxy(90,f);
		printf("%c%c%22c%c",178,178,178,178);
			f++;}
	printf("\n");
	gotoxy(90,f); 	
 	
 	for(e=0;e<25;e++)
		 {
		 	printf("%c",178);
		   }
		      
		   
		     	gotoxy(90,30);
         for(g=0;g<25;g++)
		 {
		 	printf("%c",178);
		   }  
	
		   for(g=0;g<4;g++)
	{	printf("\n");
		gotoxy(90,h);
		printf("%c%c%22c%c",178,178,178,178);
			h++;}
	printf("\n");
	gotoxy(90,h); 	

 	for(g=0;g<25;g++)
		 {
		 	printf("%c",178);
		   }  
		   
		   
		   
		   
}





void loginpattern(void) // patient for patient info
{

system("color F0");
system("cls");
char d[10]="LOGIN";
char ch;
int j;

passbox();
gotoxy(28,12);
for(j=0;j<40;j++)
{
Sleep(50);
printf("<");
}
for(j=0;j<5;j++)
{
Sleep(50);
printf("%c",d[j]);
}
for(j=0;j<40;j++)
{
Sleep(50);
printf(">");
}
}


void bmsbox()
{
	system("color E1");
     int a,b=30,c,d=12,e,f=18,g,h=24;
	 char ch;
	 
	
		   
		
		   	gotoxy(30,11);
         for(c=0;c<25;c++)
		 {
		 	printf("%c",178);
		   }  
	
		   for(c=0;c<4;c++)
	{	printf("\n");
		gotoxy(30,d);
		printf("%c%c%22c%c",178,178,178,178);
			d++;}
	printf("\n");
	gotoxy(30,d); 	

 	for(c=0;c<25;c++)
		 {
		 	printf("%c",178);
	     }  
		
		   sleep(1);
		   
		 	gotoxy(50,17);
         for(e=0;e<25;e++)
		 {
		 	printf("%c",178);
		   }  
	
		   for(e=0;e<4;e++)
	{	printf("\n");
		gotoxy(50,f);
		printf("%c%c%22c%c",178,178,178,178);
			f++;}
	printf("\n");
	gotoxy(50,f); 	
 	
 	
 	for(e=0;e<25;e++)
		 {
		 	printf("%c",178);
	     }
		   
	     sleep(1);
		gotoxy(70,23);
         for(g=0;g<25;g++)
		 {
		 	printf("%c",178);
		 }  
	
		   for(g=0;g<4;g++)
	{	printf("\n");
		gotoxy(70,h);
		printf("%c%c%22c%c",178,178,178,178);
			h++;}
	printf("\n");
	gotoxy(70,h); 	

 	for(g=0;g<25;g++)
		 {
		 	printf("%c",178);
		   }  

     	  sleep(1);

	gotoxy(90,29);
         for(a=0;a<25;a++)
		 {
		 	printf("%c",178);
		   }  
	
		   for(a=0;a<4;a++)
	{	printf("\n");
		gotoxy(90,b);
		printf("%c%c%22c%c",178,178,178,178);
			b++;}
	printf("\n");
	gotoxy(90,b); 	
 	
 	for(a=0;a<25;a++)
		 {
		 	printf("%c",178);
		   }




}
		   
		   
/*
10,7   \xcd\xcd\xcd\xcdWELCOME TO\xcd\xcd\xcd\xcd
30,13  \xcd\xcd\xcdBLOOD BANK\xcd\xcd\xcd
50,19  \xcd\xcd\xcdMANAGEMENT\xcd\xcd\xcd
70,25 \xcd\xcd\xcdSYSTEM\xcd\xcd\xcd


*/

void loader()
{

	int i,j;


	sleep(1);
    
    gotoxy(10,39);
    printf("LOADING.......");
	//printf("\n\n");
	gotoxy(10,40);
	for(i=0;i<30;i++)
	{
			Sleep(15);
		printf("\r");
		printf("[");
		for(j=1;j<=i;j++)
		{
			printf("||");
		}
		printf("]");
	}
	Sleep(1000);
	
	}
	

void box()
{
	system("color 03"); 
	
	int i,j=11;
	char ch;
	
	printf("");
	gotoxy(50,10);
	for(i=0;i<61;i++)
	{
		
		printf("%c",219);
	
		
	}
	

for(i=0;i<15;i++)
	{	printf("\n");
		gotoxy(50,j);
		printf("%c%c%58c%c",219,219,219,219);
			j++;}
	printf("\n");
	gotoxy(50,j);
	for(i=0;i<61;i++)
	{
		printf("%c",219);
	
		
	}

}


void boxoldvalue()
{
	system("color 03"); 
     int i,j=7,l,k=16;
	 char ch;
	 
	    
	 	gotoxy(40,6);
         for(i=0;i<30;i++)
		 {
		 	printf("%c",219);
		   }  
 	
   for(i=0;i<4;i++)
	{	printf("\n");
		gotoxy(40,j);
		printf("%c%c%27c%c",219,219,219,219);
			j++;}
	printf("\n");
	gotoxy(40,j); 	
 	
 	for(i=0;i<30;i++)
		 {
		 	printf("%c",219);
		   }  



      
	    
	 	gotoxy(25,15);
         for(l=0;l<60;l++)
		 {
		 	printf("%c",177);
		   }  
 	
   for(l=0;l<13;l++)
	{	printf("\n");
		gotoxy(25,k);
		printf("%c%c%57c%c",177,177,177,177);
			k++;}
	printf("\n");
	gotoxy(25,k); 	
 	
 	for(l=0;l<60;l++)
		 {
		 	printf("%c",177);
		   } 
}	
	


void donorpattern(void) // pattern for donor info
{
system("color 03"); 
system("cls");
char d[100]="ENTER DONOR INFORMATION";
char ch;
int j;
gotoxy(50,8);
for(j=0;j<20;j++)
{
Sleep(50);
printf("<");
}
for(j=0;j<23;j++)
{
Sleep(50);
printf("%c",d[j]);
}
for(j=0;j<20;j++)
{
Sleep(50);
printf(">");
}
}


void patientpattern(void) // patient for patient info
{
system("color 03"); 
system("cls");
char d[100]="ENTER PATIENT INFORMATION";
char ch;
int j;

gotoxy(50,8);
for(j=0;j<20;j++)
{
Sleep(50);
printf("<");
}
for(j=0;j<25;j++)
{
Sleep(50);
printf("%c",d[j]);
}
for(j=0;j<20;j++)
{
Sleep(50);
printf(">");
}
}
int getintonly()
{
	int no=0,ch;
	
    while(1)
	{
		ch=getch();
		if(ch>=48 && ch<=57)
		{
			printf("%c",ch);
			no=no*10+(ch-48);
			
		}
		if(ch==13)
		break;
	}
	return(no);
}


//***************************************************************
//                      END OF PROJECT
//***************************************************************	    
