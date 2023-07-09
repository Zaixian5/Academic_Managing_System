#include <stdio.h>
#include <stdlib.h>

void forFaculty(void);
void forStudent(void);

FILE* fp = NULL;

int main(int argc, char* argv[])
{
  int mode = 0;
  char con = 0;
	
  if(argc != 2)
  {
    fprintf(stderr, "format: ./student (file_name)\n");
	  exit(1);
  }

  if ((fp = fopen(argv[1], "rb+")) == NULL)
  {
    fprintf(stderr, "file open failed\n");
    exit(2);
  }

  printf("-----School Affairs Managing Program-----\n\n");

  do
  {
    printf("Mode: 1. for faculty, 2. for student\n");
    printf("Select Mode: ");
    scanf("%d", &mode);

    switch(mode)
    {
      case 1:
	      forFaculty();
	      break;
    
      case 2:
	      forStudent();
	      break;

      default:
	      printf("Wrong Input. Try Again\n");
    }

	printf("\nChange Mode?(y/n): ");
	scanf(" %c", &con);

  }while(con == 'y');

  fclose(fp);

  return 0;
}
