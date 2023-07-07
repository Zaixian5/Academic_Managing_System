#include <stdio.h>
#include <stdbool.h>

void newStudent(void);
void changeStudent(void);
void showStudent(void);
void searchStudent(void);

void forFaculty(void)
{
  int mode = 0;
  char con = 0;

  printf("\n-----Managing System For Faculty-----\n");

  do
  {
    printf("Mode:\n\
      1. Register new students' informations\n\
      2. Change students' informations\n\
      3. Show all students\n\
      4. Search students' informations by ID, Phone number, E-mail address\n");

    printf("Select Mode: ");
    scanf("%d", &mode);

    switch(mode)
    {
      case 1:
  	    newStudent();
	    break;

      case 2:
	    changeStudent();
	    break;

      case 3:
	    showStudent();
	    break;

      case 4:
	    searchStudent();
	    break;

      default:
	    printf("Wrong Input. Try Again\n");
    }

	printf("\ncontinue faculty mode?(y/n): ");
	scanf(" %c", &con);

  }while(con == 'y');
}
