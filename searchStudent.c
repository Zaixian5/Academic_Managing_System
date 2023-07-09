#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "school_system.h"

extern FILE* fp;

void searchStudent(void)
{
  int search_id = 0;
  char search_name[MAXSIZE] = { 0 };
  char search_phone[MAXSIZE] = { 0 };
  char search_email[MAXSIZE] = { 0 };
  char mode = 0;

  bool name_exist = false;
  bool phone_exist = false;
  bool email_exist = false;

  STUDENT rec = { 0 };

  printf("\n-----You can search student by ID(i), Name(n), Phone number(p), e-mail(e)-----\n");
  printf("select mode(i/n/p/e): ");
  scanf(" %c", &mode);

  switch(mode)
  {
    case 'i':
      printf("\n-----Enter Student_ID to search-----\n");
      printf("Enter here: ");
      scanf("%d", &search_id);

      fseek(fp, (search_id - STARTID)*(long)sizeof(rec), SEEK_SET);
      if((fread(&rec, sizeof(rec), 1, fp) > 0) && (rec.id != 0))
      {
        printf("%d %s %s %s %s %s %d %s %s\n", rec.id, rec.name, rec.phone, rec.email,
				rec.addr, rec.major, rec.scholar, rec.multimajor, rec.state);
      }
      else
      {
        printf("Not Exist\n");
      }
	  	break;

		case 'n':
	  	printf("\n-----Enter Name to search-----\n");
      printf("Enter here: ");
	  	scanf("%s", search_name);
	  
	  	rewind(fp);
	  	while(fread(&rec, sizeof(rec), 1, fp) > 0)
	  	{
				if(rec.id == 0)
				{
        	continue;
				}

      	if(strncmp(rec.name, search_name, strlen(rec.name)) == 0)
				{
		  		printf("%d %s %s %s %s %s %d %s %s\n", rec.id, rec.name, rec.phone, rec.email,
				  	rec.addr, rec.major, rec.scholar, rec.multimajor, rec.state);

		  		name_exist = true;
				}
				else
				{
		  		continue;
				}
	  	}

	  	if (!name_exist)
	  	{
		  	printf("Not Exist\n");
	  	}

	  	break;

		case 'p':
	  	printf("\n-----Enter Phone number to search-----\n");
      printf("Enter here: ");
	  	scanf("%s", search_phone);
	  
	  	rewind(fp);
	  	while(fread(&rec, sizeof(rec), 1, fp) > 0)
	  	{
				if(rec.id == 0)
				{
          continue;
				}

				if(strncmp(rec.phone, search_phone, strlen(rec.phone)) == 0)
				{
		  		printf("%d %s %s %s %s %s %d %s %s\n", rec.id, rec.name, rec.phone, rec.email,
				  	rec.addr, rec.major, rec.scholar, rec.multimajor, rec.state);

		  		phone_exist = true;
				}
				else
				{
  		  	continue;
				}
	  	}

	  	if (!phone_exist)
	  	{
		  	printf("Not Exist\n");
	  	}

	  	break;

		case 'e':
	  	printf("\n-----Enter e-mail to search-----\n");
      printf("Enter here: ");
	  	scanf("%s", search_email);
	  
	  	rewind(fp);
	  	while(fread(&rec, sizeof(rec), 1, fp) > 0)
	  	{
				if(rec.id == 0)
				{
          continue;
				}

        if(strncmp(rec.email, search_email, strlen(rec.email)) == 0)
				{
		  		printf("%d %s %s %s %s %s %d %s %s\n", rec.id, rec.name, rec.phone, rec.email,
				  	rec.addr, rec.major, rec.scholar, rec.multimajor, rec.state);

		  		email_exist = true;
				}
				else
				{
  		  	continue;
				}
	  	}

	  	if (!email_exist)
	  	{
		  	printf("Not Exist\n");
	  	}

	  	break;
  }
}