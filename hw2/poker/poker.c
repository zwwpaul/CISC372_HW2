#include<stdlib.h>
#include <stdbool.h>
#include<stdio.h>
#include<string.h>

#define MAX 5
#define BUFFERSIZE 128

typedef enum suit_s {DIAMONDS, CLUBS, HEARTS, SPADES} Suit;

typedef struct card_s
{
	int rank;
	Suit suit;
} *Card;

typedef struct hand_s
{
	Card h[MAX];
} *Hand;

//This is a function to create a new card
Card create(){
	Card card;
	int rank_upper=13;
	int rank_lower=1;
	int suit_lower=1;
	int suit_upper=4;
	int suit_index=(rand()%(suit_upper+1 - suit_lower))+suit_lower;
	card=(Card)malloc(sizeof(struct card_s));
	card->rank=(rand()%(rank_upper + 1 - rank_lower))+rank_lower;
	switch(suit_index){
		case 1:
			card->suit=DIAMONDS;
			break;
		case 2:
			card->suit=CLUBS;
			break;
		case 3:
                        card->suit=HEARTS;
                        break;
		case 4:
                        card->suit=SPADES;
                        break;

	}
	return card;

}
//This is a function to print rank and suit of a card
void printcard(Card c){
	switch(c->suit){
                case DIAMONDS:
                        printf("This card is a diamond %d!\n ",c->rank);
                        break;
                case CLUBS:
                        printf("This card is a club %d!\n ",c->rank);
                        break;
                case HEARTS:
                        printf("This card is a heart %d!\n ",c->rank);
                        break;
                case SPADES:
                        printf("This card is a spade %d! \n",c->rank);
                        break;
        }

}

//This is a function to free the memory.
void destroy(Card card1){
	free(card1);
}

//This is a function to determine whether two cards are equal.
bool isequal(Card c1,Card c2){
	bool flag=false;
	if(c1->rank==c2->rank){
		if(c1->suit==c2->suit){
			flag=true;
		}
	}
	return flag;
}
//This is a function to create a hand by recursively using create().
Hand createHand(){
	Hand hand;
	hand=(Hand)malloc(sizeof(struct hand_s));
	for(int i=0;i<MAX;i++){
		hand->h[i]=create();
		for(int j=0;j<i;j++){
			while(isequal(hand->h[i],hand->h[j])){
				destroy(hand->h[i]);
				hand->h[i]=create();
			}
		}
	}
	return hand;
}

//This is a function to print a hand by recursively using printcard(Card c).
void printHand(Hand h){
	for(int i=0;i<MAX;i++){
		printcard(h->h[i]);
	}
}

//This is a function to free the memory of a hand.
void destroyHand(Hand h){
	for(int i=0;i<MAX;i++){
   		free(h->h[i]);
        }
	free(h);
}

//This is a function to determine whether your hand is a straight flush
bool isSameSuit(Hand hand){
	bool flag=false;
	for(int i=0;i<MAX;i++){
		if(hand->h[i]->suit==hand->h[0]->suit){
			flag=true;
		}else{
			flag=false;
		}
	}
	return flag;
}

bool isStraight(Hand hand){
	bool flag=false;
	int temp=0;
	int cardlist[MAX];
	//Put all card in a list
	for(int i=0;i<MAX;i++){
		if(hand->h[i]->rank==1){
			cardlist[i]=14;
		}else{
			cardlist[i]=hand->h[i]->rank;
		}
	}
	//Sort them in acsending order
	for(int i=0;i<MAX;i++){
		if((i+1)!=MAX){
			temp=hand->h[i]->rank;
			if(temp>hand->h[i+1]->rank){
				hand->h[i]->rank=hand->h[i+1]->rank;
			       	hand->h[i+1]->rank=temp;
			}
		}
	}
	//Determine whether it is a staright
	for(int i=0;i<MAX-1;i++){
		if(hand->h[i+1]->rank - hand->h[i]->rank == 1){
			flag=true;
		}else{
			flag=false;
		}
	}
	return flag;
}

bool isSF(Hand hand){
	return isSameSuit(hand)&&isStraight(hand);
}
int main(){
	int count=0;
	char* times;
	int len,time; 
	times=malloc(BUFFERSIZE);
	printf("How many hands do you want to create.\n");
        if(fgets (times, BUFFERSIZE, stdin)!=NULL){
		        len=strlen(times);
                        times[len-1]='\0';
         	}else{
                        printf("How many hands do you want to create.\n");
                }
	time=atoi(times);

	for(int i=0;i<time;i++){
		Hand h1;
		h1=(Hand)malloc(sizeof(struct hand_s));
		h1=createHand();
		//printHand(h1);
		if(isSF(h1)){
			//printf("Your hand is a straight flush!\n");
			count++;
		}
		destroyHand(h1);
		//printf("\n");
	}
	printf("Total number of straight flushes encountered: %d \n",count);
	printf("The fraction is: %2.6f \n",(double)count/time);
	return 0;
}
