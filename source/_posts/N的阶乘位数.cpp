#include <stdio.h>
#include <math.h>

typedef struct node
{
    unsigned int data;
    struct node *next;
};
int main(void){

	struct node *node2;
	node2->data = 1;
	
	printf("%d\n",node2->data);
	
	return 0;
}