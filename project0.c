// Counts Unicode Characters and sorts them by highest to lowest.
  
#include <stdio.h>
#include <stdlib.h> 
#include <wchar.h>
#include <locale.h>
#define MAX_FILE_NAME 100 
//Structure dab that holds a char array and interger for the number of times that Unicode character appear.
struct charaVal
{
        unsigned char *a;
        int b;
};  
int main() 
{ 
    //printf("Here");
    //Intializing variables
    FILE* fp = stdin; 
    int count = 0;
    int k = 0;
    int m = -1;
    int o;
    int p;
    int j;
    int l;
    int y = 0;
    int x = 1;
    int z = 0;
    struct charaVal *text = malloc(1114112 * sizeof(struct charaVal));
    for(int i = 0; i < 1114112; i++)
    {
        text[i].b = 0;
        //text[i].a = malloc(4 * sizeof(char));
        // *text[i].a = 'a';
        //printf("%ls", text[i].a);
    }
    unsigned char c;
    unsigned char one;
    unsigned char two;
    unsigned char three;
    unsigned char four;
  //Recieving Unicode Characters from local
    setlocale(LC_CTYPE, "");
  //Input file
    fp = stdin;  
    // Extract characters from file and store in c, compares with text array values for matching or new characters. 
    for (c = getc(fp); c != EOF; c = getc(fp)) 
    {
	//Beginning of loop goes through if statements to see how many bytes the current character is
        k = 0;
        if(c < 0x0080)
        {
		one = c;
        }
 	else if(c < 0x00E0)
        {
                one = c;
                c = getc(fp);
                two = c;
        }
        else if(c < 0x00F0)
        {
                //printf("Check Three");
                one = c;
                c = getc(fp);
                two = c;
                c = getc(fp);
                three = c;
        }
        else if(c < 0x00F8)
        {
                //printf("Check Four");
                one = c;
                c = getc(fp);
                two = c;
                c = getc(fp);
                three = c;
                c = getc(fp);
                four = c;
        }
        else
        {
                one = c;
        }
      //Duplicate Loop to check for repeating characters in the file, first compares by character byte, than by character itself
        for(o = 0; o < count; o++)
        {
                /*if(*text[o].a == c && k == 0)
                {
                        //printf("Here2");
                        text[o].b = text[o].b + 1;
                        k = 1;

                }*/
		if(one < 0x0080)
                {
                	if(*text[o].a == one  && k == 0 && x == 0)
                        {
                        	//printf("Here1");
                                text[o].b = text[o].b + 1;
                                k = 1;
                        }
                }
		else if(one < 0x00E0)
                {
                        if(*text[o].a == one && *(text[o].a + 1)== two && k == 0 && x == 0)
                        {
                                 //printf("Here2");
                                 text[o].b = text[o].b + 1;
                                 k = 1;
                        }
                }
                else if(one  < 0x00F0)
                {
                	if(*text[o].a == one && *(text[o].a + 1)== two && *(text[o].a + 2) == three && k == 0 && x == 0)
                	{
                        	//printf("Here3");
                        	text[o].b = text[o].b + 1;
                        	k = 1;
                        }
                }
                else if(one < 0x00F8)
                {
                        if(*text[o].a == one && *(text[o].a + 1)== two && *(text[o].a + 2) == three && *(text[o].a + 3) == four && k == 0 && x == 0)
                        {
                                //printf("Here4");
                                text[o].b = text[o].b + 1;
                                k = 1;
                        }
                }
        }
      //Loop to place new character in proper position. A new character position will be the next avalible place in the array that does not equal 0
        if(k == 0)
        {
                //printf("Here1");
                for(p = 0; p < count + 1; p++)
                {
                        if(text[p].b == 0 && k == 0)
                        {
                                text[p].a = malloc(4 * sizeof(char));
                                *text[p].a = 'a';
                                count = count + 1;
                                //printf("%s ", c);
                                if(one < 0x0080)
                                {
                                        *text[p].a = one;
                                        //printf("Byte:1");
                                        text[p].b = text[p].b + 1;//printf("Byte:1");
                                }
                                else if(one < 0x00E0)
                                {
                                        *(text[p].a) = one;
                                        *(text[p].a + 1)  = two;
                                        text[p].b = text[p].b + 1;
                                }
                                else if(one < 0x00F0)
                                {
                                        *text[p].a = one;
                                        *(text[p].a + 1)  = two;
                                        *(text[p].a + 2)  = three;
                                        text[p].b = text[p].b + 1;
                                }
                                else if(one < 0x00F8)
                                {
                                        *text[p].a = one;
                                        *(text[p].a + 1)  = two;
                                        *(text[p].a + 2)  = three;
                                        *(text[p].a + 3)  = four;
                                        text[p].b = text[p].b + 1;
                                }
                                else
                                {
                                        //printf("Breakdown");
                                        y = 1;
                                }
                                k = 1;
                                x = 0;
                        }
                } 
        }
        if(y == 1)
        {
                break;
        }
}  
    // While loop to sort arrays from highest to lowest
    k = 0;
    while(k == 0)
    { 
        k = 1;
        for(l = 0; l < count; l++)
        {
                if(text[l].b != 0)
                {
                        k = 0;
                }
        }
         for(j = 0; j < count; j++)
         {
                if(text[j].b > m)
                {
                        m = text[j].b;
                        z = j;
                }
                if(j == count - 1)
                {
                        text[z].b = 0;
                }
         }
        if(k == 0)
        {
                printf("%s->%d\n", text[z].a, m);
        }
        m = -1;
    }
    // Close the file  
    fclose(fp);
    // Print the count of characters 
    return 0; 
}  
