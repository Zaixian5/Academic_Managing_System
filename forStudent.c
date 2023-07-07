#include <stdio.h>

#include "school_system.h"

extern FILE* fp;

void forStudent(void)
{
  int own_id = 0;
  char isChange = 0;
  STUDENT rec = { 0 };

  printf("\n-----Managing System For Student-----\n");
  printf("You can search and change your own informations\n");
  printf("Enter your ID: ");
  scanf("%d", &own_id);

  fseek(fp, (own_id - STARTID)*(long)sizeof(rec), SEEK_SET);
  if((fread(&rec, sizeof(rec), 1, fp) > 0) && (rec.id != 0))
  {
    printf("%d %s %s %s %s %s %d %s %s\n", rec.id, rec.name, rec.phone, rec.email,
				rec.addr, rec.major, rec.scholar, rec.multimajor, rec.state);

	printf("\nYou can only change your phone number, email, address.\n");
	printf("Do you want to change your informations?(y/n): ");
	scanf(" %c", &isChange);

	if(isChange == 'y')
	{
      printf("\nEnter your new phone number: ");
	  scanf("%s", rec.phone);
      
	  printf("\nEnter your new e-mail: ");
	  scanf("%s", rec.email);

	  printf("\nEnter your new address: ");
	  scanf("%s", rec.addr);

	  fseek(fp, -(long)sizeof(rec), SEEK_CUR);
	  fwrite(&rec, sizeof(rec), 1, fp);
	}
  }
  else
  {
    printf("Not Exist\n");
  } 
}
