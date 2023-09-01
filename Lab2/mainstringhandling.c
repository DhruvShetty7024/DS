#include<stdio.h>
#include<stdlib.h>
void main()
{ int o;
int flag;
flag =3;
do
{
    char str1[100];
    char str2[100];
    printf("\nEnter 1 for length of string\nEnter 2 for string concatination\nEnter 3 for string comparism\nEnter 4 to insert substring\nEnter 5 to delete substring\nEnter 6 to exit");
    printf("\nenter option:");
    scanf("%d",&o);
    fflush(stdin);
    if(o==1||o==5)
    {
    printf("enter string 1:");
    gets(str1);
    }
    else if(o==6)
    {
        exit (0);
    }
    else if(o==2||o==3||o==4)
    {
    printf("enter string 1:");
    gets(str1);
    printf("enter string 2:");
    gets(str2);
    }
    else
        {
        printf("Wrong option entered");
        exit(0);
        }
    switch(o)
    { case 1:printf("Length of string is %d",strlen(str1));
      break;
      case 2:
      puts(strcon(str1,str2));
      break;
      case 3:
          flag=strcomp(str1,str2);
          if(flag==0)
    {
        printf("string 1 is greater than string 2");
    }
    else if(flag==1)
    {
        printf("string 2 is greater than string 1");
    }
    else if(flag==2)
    {
        printf("string 1 is equal to string2");
    }
      break;
      case 4:puts(strsub(str1,str2));
      break;
      case 5:puts(strdel(str1));
      break;
      case 6:exit (0);
      default:printf("Wrong option entered");
    }}while(1);
    return 0;}


int strlen(char str1[100])
{
    int len=0,i,j;
    for(i=0;str1[i]!='\0';i++)
    {
        len++;
    }
    return len;
}
int strcon(char s1[100],char s2[100])
{
    int i,j;
    for( i=0;s1[i]!='\0';i++);
        for( j=0;s2[j]!='\0';)
        {
            s1[i]=s2[j];
            j++;
            i++;
        }
        s1[i]='\0';
        printf("the concatenated string is %s",s1);
return 0;

}
int strcomp(char s1[100],char s2[100])
{int flag;
    for(int i=0;s1[i]!='\0';i++)
    {
        if(s1[i]>s2[i])
        {
            return 0;
        }
        else if(s1[i]<s2[i])
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    }
    int strsub(char s1[100],char s2[100])
    {
    int p,l1,l2;
    printf("enter the position of insertion:");
    scanf("%d",&p);
    l1= strlen(s1);
    l2= strlen(s2);
    for(int i=p;i<l1;i++)
    {
        s1[i+l2]=s1[i];
    }
    for(int i=0;i<l2;i++)
    {
        s1[p+i]=s2[i];
    }

    printf("after insertion the string is %s",s1);
    return 0;
    }

    int strdel(char s1[100])
    {
        char word[100];
 int i, j, ls, lw, temp, c=0;
   printf("Enter a Word: ");
   gets(word);
   ls = strlen(s1);
   lw = strlen(word);
   for(i=0; i<ls; i++)
   {
      temp = i;
      for(j=0; j<lw; j++)
      {
         if(s1[i]==word[j])
            i++;
      }
      c = i-temp;
      if(c==lw)
      {
         i = temp;
         for(j=i; j<(ls-lw); j++)
            s1[j] = s1[j+lw];
         ls = ls-lw;
         s1[j]='\0';
      }
   }
   printf("After deletion= %s", s1);
   return 0;
    }


