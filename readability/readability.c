#include<stdio.h>
#include"../cs50/cs50.h"
#include<ctype.h>
#include<string.h>
#include<math.h>
#define LEVELS 16
#define W_WORDS 100.0
// Prototypes
float Letters_count(string const sentence_letter);
float Sentence_count(string const sentence_letter);

int main(void)
{
    string text;
    text=get_string("text: ");
    float L=Letters_count(text);
    float S=Sentence_count(text);
    float index=(0.0588 * L)-(0.296*S)-15.8;
    int int_index=round(index);
    if (int_index <= 1)
        printf("Before Grade 1\n");
    else if (int_index >= 16)
        printf( "Grade 16+\n");
        else
            printf("Grade %i", int_index);
        return 0;
}
// Functions
float Letters_count(string const sentence_letter)
{
    float letter_count=0.0;
    // for the last word
    float word_count=1.0;
    float L=0.0;
    for(int i=0,n=strlen(sentence_letter);i<n;i++)
    {
        if(isalpha(sentence_letter[i]))
        letter_count++;
        
        if(sentence_letter[i]==' ')
        word_count++;
    }
    L=(letter_count/word_count)*W_WORDS;
    return L;
}
float Sentence_count(string const sentence_letter)
{
    float sentence=0.0;
    // for the last word
    float word_count=1.0;
    float S=0.0;
    for(int i=0,n=strlen(sentence_letter);i<n;i++)
    {   
        if(sentence_letter[i]==' ')
        word_count++;

        if(sentence_letter[i]=='.'|| sentence_letter[i]=='?'|| sentence_letter[i]=='!')
        sentence++;
    }
    S=(sentence/word_count)*W_WORDS;
    return S;
}
