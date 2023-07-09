#include <stdio.h>

#include "school_system.h"

extern FILE* fp;

void showStudent(void)
{
  STUDENT rec = { 0 };

  printf("\n-----All Students-----\n");
  
  rewind(fp);
  while(fread(&rec, sizeof(rec), 1, fp) > 0)
  {
    if(rec.id == 0)
	  {
      continue;
	  }

	  printf("%d %s %s %s %s %s %d %s %s\n", rec.id, rec.name, rec.phone, rec.email,
			rec.addr, rec.major, rec.scholar, rec.multimajor, rec.state);
  }
}
