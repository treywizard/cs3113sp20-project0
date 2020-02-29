// Counts Unicode Characters and sorts them by highest to lowest.
  
#include <stdio.h>
#include <stdlib.h> 
#include <wchar.h>
#include <locale.h>
#define MAX_FILE_NAME 100 
//Structure dab that holds a char array and interger for the number of times that Unicode character appear.
struct dab
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
    int z = 0;
    struct dab *dabbing = malloc(1114112 * sizeof(struct dab));
    for(int i = 0; i < 1114112; i++)
    {
        dabbing[i].b = 0;
        //dabbing[i].a = malloc(4 * sizeof(char));
        // *dabbing[i].a = 'a';
        //printf("%ls", dabbing[i].a);
    }
    unsigned char c;
  //Recieving Unicode Characters from local
    setlocale(LC_CTYPE, "");
  //Input file
    fp = stdin;  
    int y = 0;
    int x = 1;
    // Extract characters from file and store in c, compares with dabbing array values for matching or new characters. 
    for (c = getc(fp); c != EOF; c = getc(fp)) 
    {
        k = 0;
      //Duplicate Loop to check for repeating characters
        for(int o = 0; o < count; o++)
        {
                if(*dabbing[o].a == c && k == 0 && x == 0)
                {
                        //printf("Here2");
                        dabbing[o].b = dabbing[o].b + 1;
                        k = 1;

                }
        }
      //Loop to place new character in proper position
        if(k == 0)
        {
                //printf("Here1");
                for(int p = 0; p < 1114112; p++)
                {
                        if(dabbing[p].b == 0 && k == 0)
                        {
                                dabbing[p].a = malloc(4 * sizeof(char));
                                *dabbing[p].a = 'a';
                                count = count + 1;
                                //printf("%d ", d);
                                if(c < 0x0080)
                                {
                                        *dabbing[p].a = c;
                                        //printf("Byte:1");
                                        dabbing[p].b = dabbing[p].b + 1;//printf("Byte:1");
                                }
                                else if(c < 0x00E0)
                                {
                                        *(dabbing[p].a) = c;
                                        c = getc(fp);
                                        *(dabbing[p].a + 1)  = c;
                                        //printf("Byte:2");
                                        dabbing[p].b = dabbing[p].b + 1;
                                }
                                else if(c < 0x00F0)
                                {
                                        *dabbing[p].a = c;
                                        c = getc(fp);
                                        *(dabbing[p].a + 1)  = c;
                                        c = getc(fp);
                                        *(dabbing[p].a + 2)  = c;
                                        //printf("Byte:3");
                                        dabbing[p].b = dabbing[p].b + 1;
                                }
                                else if(c < 0x00F8)
                                {
                                        *dabbing[p].a = c;
                                        c = getc(fp);
                                        *(dabbing[p].a + 1)  = c;
                                        c = getc(fp);
                                        *(dabbing[p].a + 2)  = c;
                                        c = getc(fp);
                                        *(dabbing[p].a + 3)  = c;
                                        //printf("Byte:4");
                                        dabbing[p].b = dabbing[p].b + 1;
                                }
                                else
                                {
                                        //printf("Breakdown");
                                        y = 1;
                                }
                                //*dabbing[p].a =  c;
                                //printf("%s", dabbing[p].a);
                                //dabbing[p].b = dabbing[p].b + 1;
                                k = 1;
                                x = 0;
                        }
                } 
        }
        //counting[characterNum] = counting[characterNum] + 1;
        if(y == 1)
        {
                break;
        }
}  
    // While loop to sort arrays from highest to lowest
    k = 0;
    //printf("%s->%d\n", dabbing[0].a, dabbing[0].b);
    while(k == 0)
    { 
        k = 1;
        for(int l = 0; l < count; l++)
        {
                if(dabbing[l].b != 0)
                {
                        k = 0;
                }
        }
         for(int j = 0; j < count; j++)
         {
                //printf("%s", dabbing[j].a);
                if(dabbing[j].b > m)
                {
                        m = dabbing[j].b;
                        //printf("%c->%d\n", n, m);
                        z = j;
                        //printf("%d", dabbing[j].b);
                }
                if(j == count - 1)
                {
                        dabbing[z].b = 0;
                }
         }
        if(k == 0)
        {
                printf("%s->%d\n", dabbing[z].a, m);
        }
        m = -1;
    }
    // Close the file  
    fclose(fp);
    // Print the count of characters 
    return 0; 
}  
