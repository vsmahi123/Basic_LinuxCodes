#include "typedef.h"
typedef enum{newline=0,null=1,period=2,space = 3} wordBrk;
typedef enum{success=1,fail=0}stat_t;
wordBrk readWord(word_t word);
stat_t readSentence();
stat_t readParagraph();
document_t readDoucment();

int main()
{
	word_t word=NULL;
	sentence_t sentence=NULL;
fflush(stdin);
	printf("----------------------\n%d\n--------------------------\n",readSentence(sentence));



	return 0;

}
wordBrk readWord(word_t word)
{
	volatile uint8 ch;
	uint16 i=0;
	puts("enter word");
	fflush(stdin);
	while(ch=getchar())
	{
		if(ch=='\n' || ch == '\0' || ch=='.' ||ch == ' ')
			break;

		word=realloc(word,(i+1)*sizeof(uint8));
   		word[i]=ch;
		i++;

	}
		word=realloc(word,(i)*sizeof(uint8));
   		word[i]='\0';


		switch(ch)
		{
			case '\n': return newline; break;
			case '\0':return null;break;
			case '.':return period;break;
			case ' ':return space;break;
				

		}
}

stat_t readSentence(sentence_t sentence)
{
	uint16 i=0;
	word_t word=NULL;
	while(period != readword(word))
	{
	sentence=realloc(sentence,(i+1)*sizeof(sentence));
		sentence[i]=word;
		word=NULL;
		i++;
	}
	return success;

}
