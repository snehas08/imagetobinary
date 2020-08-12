#include<stdio.h>
#include<conio.h>

void main()
{
  clrscr();
  FILE *fptr;
  FILE *txt;
  int c;

  fptr=fopen("D:\\aa.bmp","r");
  txt=fopen("D:\\test1.txt","w");

  if(fptr==NULL)
  {
    printf("NOTHING In FILE");
    fclose(fptr);
  }
  else
  {
    printf("success");

    do
    {
      c=fgetc(fptr);
      for(int i=0;i<=7;i++)
      {
        if(c&(1<<(7-i)))
        {
          fputc('1',txt);
        }
        else
        {
          fputc('0',txt);
        }
      }
      // fprintf(txt,"\t");
    }while(c!=EOF);

  }

  fclose(fptr);
  fclose(txt);

  printf("writing over");
  getch();
}
2. Here is the code to convert the resulting text file to image file full of binary characters, i.e. a text file with only ones and zeroes.

#include<stdio.h>
#include<conio.h>


\\The following function converts the ones and zeroes in the text file into a character. 
\\For example the text file may have the 8 consecutive characters '1','0','0','0','1','0','0','0'. 
\\This converts it into the character equivalent of the binary \\value 10001000

char bytefromtext(char* text) 
{
  char result=0;
  for(int i=0;i<8;i++)
  {
    if(text[i]=='1')
    {
      result |= (1<< (7-i) );
    }
  }
  return result;
}

void main()
{
  clrscr();
  FILE *pfile;
  FILE *image;
  char buf[8];
  char c;
  int j=0;

  image=fopen("D:\\aa2.bmp","w"); //open an empty .bmp file to
                                  //write characters from the source image file
  pfile=fopen("D:\\test1.txt","r");

  if(pfile==NULL)
    printf("error");
  else
  {
    c=fgetc(pfile);

    while(c!=EOF)
    {
      buf[j++]=c;
      if(j==8)
      {
        fputc(bytefromtext(buf),image);
        j=0;
      }
      c=fgetc(pfile);

    }

    fclose(pfile);
    fclose(image);
  }

  getch();
}