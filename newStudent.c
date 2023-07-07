#include <stdio.h>
#include <stdbool.h>

#include "school_system.h"

extern FILE* fp;

void newStudent(void)
{
  STUDENT rec = { 0 };
  int info_num = 1;
  char con = 0;

  printf("\n-----Register New Students's Informations-----\n");
  printf("Enter 9 informaions separating by space.\n\
1. Student_ID 2. Name 3. Phone_number 4. E-mail\n\
5. address 6. Major 7. Scholoarship_total\n\
8. Multimajor(if not, enter N) 9. registration_state(registered/graduated/leave_of_absence)\n\n");

  while(true)
  {
     printf("No.%d: ", info_num++);

     if (scanf("%d %s %s %s %s %s %d %s %s", &rec.id, rec.name, rec.phone, rec.email,
         rec.addr, rec.major, &rec.scholar, rec.multimajor, rec.state) != 9)
     {
         break;
     }

    fseek(fp, (rec.id - STARTID)*(long)sizeof(rec), SEEK_SET);
	fwrite(&rec, sizeof(rec), 1, fp);

	printf("\ncontinue registering?(y/n): ");
	scanf(" %c", &con);

	if(con == 'n')
	{
      break;
	}
  }
}
