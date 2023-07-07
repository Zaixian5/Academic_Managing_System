#include <stdio.h>

#include "school_system.h"

extern FILE* fp;

void changeStudent(void)
{
  int change_id = 0;
  STUDENT rec = { 0 };

  printf("\n-----Enter Student ID to change informations-----\n");
  scanf("%d", &change_id);
  
  fseek(fp, (change_id - STARTID)*(long)sizeof(rec), SEEK_SET);
  if((fread(&rec, sizeof(rec), 1, fp) > 0) && (rec.id != 0))
  {
    printf("%d %s %s %s %s %s %d %s %s\n", rec.id, rec.name, rec.phone, rec.email,
			rec.addr, rec.major, rec.scholar, rec.multimajor, rec.state);
	printf("\nEnter changed informations.\nEnter the same, if the information has nothing to change.\n");

	scanf("%d %s %s %s %s %s %d %s %s", &rec.id, rec.name, rec.phone, rec.email,
			rec.addr, rec.major, &rec.scholar, rec.multimajor, rec.state);

	fseek(fp, -(long)sizeof(rec), SEEK_CUR);
	fwrite(&rec, sizeof(rec), 1, fp);
  }
  else
  {
    printf("Not Exist\n");
  }
}
