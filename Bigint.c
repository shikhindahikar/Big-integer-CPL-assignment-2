#include<stdio.h>
#include<stdlib.h>

typedef struct node_type {
	int data;
	struct node_type * next;
}node;

typedef struct bigInt_type {
	node * tail;
	node* start;
}bigInt;

void Init(bigInt * num){
	num->tail=num->start=NULL;//Initialize a null node num
}

node * makenode(node * num,int n){
	num=(node*)malloc(sizeof(node));//allocate node a memory block and insert a data
	num->next=NULL;
	num->data=n;
	return num;
}
void createInt(bigInt * num1){
	printf("please enter number\n");
	int n,i=0;                          //creating a complete list using Init() and makenode functions
	char s[310];
	node * num;
	Init(num1);
	scanf("%s",s);
	while(s[i]!='\0'){
		n=(int)s[i]-48;                 //first big number is taken as a string and then type casted into integers and inserted into a linked list
		num=makenode(num,n);
		if(num1->start==NULL){
			num1->start=num1->tail=num;
		}
		else{
			num->next=num1->start;
			num1->start=num;
		}
		i++;
	}

}
void printnode(node * num){
	node * temp= num;
	if(temp!=NULL){
		printnode(temp->next);
		printf("%d",temp->data);
	}
}
void print(bigInt * num1){
	node*num=num1->start;
	printnode(num);
	printf("\n");
}
void add(bigInt *l1, bigInt *l2,bigInt *b)
{
	Init(b);
	int sum,carry=0;
	node *num,*p1,*p2;
	p1=l1->start;
	p2=l2->start;
	while(p1!=NULL && p2!=NULL)
	{
		sum=p1->data+p2->data+carry;
		carry=sum/10;
		sum=sum%10;
		num=makenode(num,sum);
		if(b->start==NULL){
			b->start=b->tail=num;
		}
		else{
			(b->tail)->next=num;
			b->tail=num;
		}
		p1=p1->next;
		p2=p2->next;
	}
	if(p1!=NULL)
	{
		while(p1!=NULL)
		{
			sum=p1->data+carry;
			carry=sum/10;
			sum=sum%10;
			num=makenode(num,sum);
			if(b->start==NULL){
				b->start=b->tail=num;
			}
			else{
				(b->tail)->next=num;
				b->tail=num;
			}
			p1=p1->next;
		}
	}
	if(p2!=NULL)
	{
		while(p2!=NULL)
		{
			sum=p2->data+carry;
			carry=sum/10;
			sum=sum%10;
			num=makenode(num,sum);
			if(b->start==NULL){
				b->start=b->tail=num;
			}
			else{
				(b->tail)->next=num;
				b->tail=num;
			}
			p2=p2->next;

		}
	}
	if(carry!=0)
	{
		num=makenode(num,sum);
		(b->tail)->next=num;
		b->tail=num;
	}
	print(b);


}
void subtract(bigInt *l1, bigInt *l2,bigInt *b)
{
	Init(b);
	bigInt d;
	int sub,brw=0;
	node *num,*p1,*p2;
	p1=l1->start;
	p2=l2->start;
	while(p1!=NULL && p2!=NULL)
	{
		sub=p1->data-p2->data-brw;
		brw=(sub<0)?1:0;
		sub=(brw==1)?(10+sub):sub;
		num=makenode(num,sub);
        if(b->start==NULL){
            b->start=b->tail=num;
        }
        else{
            (b->tail)->next=num;
            b->tail=num;
        }
		p1=p1->next;
		p2=p2->next;
	}
	if(p1!=NULL )
	{
		while(p1!=NULL)
		{
			sub=p1->data-brw;
			brw=(sub<0)?1:0;
			sub=(brw==1)?(10+sub):sub;
			num=makenode(num,sub);
			if(b->start==NULL){
				b->start=b->tail=num;
			}
			else{
				(b->tail)->next=num;
				b->tail=num;
			}
			p1=p1->next;
		}
	}
	if(brw==1 || p2!=NULL)
	{
		printf("-");
		subtract(l2,l1,&d);

	}
	else if(brw==0)
	{
		print(b);
	}
	printf("\n");
}
void multiplication(bigInt *l1, bigInt *l2,bigInt *b)
{
	Init(b);
	int m,carry=0,d;
	node *num,*p1,*p2,*p,*t;
	p1=l1->start;
	p=b->tail;
	while(p1!=NULL)
	{
		d=p1->data;
		p2=l2->start;
		carry=0;
		while(p2!=NULL)
		{
			if(p==NULL){
				num=makenode(num,0);
				if(b->start==NULL){
					t=p=b->start=b->tail=num;
				}
				else{
					(b->tail)->next=num;
					p=b->tail=num;
					if(t==NULL)
					{
						t=p;
					}
				}
			}
			m=d*(p2->data)+carry+p->data;
			carry=m/10;
			m=m%10;
			p->data=m;
			p=p->next;
			p2=p2->next;
		}
		if(carry!=0)
		{
				num=makenode(num,carry);
				if(b->start==NULL){
					p=b->start=b->tail=num;
				}
				else{
					(b->tail)->next=num;
					p=b->tail=num;
				}
		}
		p1=p1->next;
		p=t=t->next;
	}
	printf("\n");
	print(b);
	printf("\n");
}

int main()
{
	int e=1;
	while(e==1)
	{
		int a,b,c;
		printf("Enter operation to perform-\n1.Addition\n2.Subtraction\n3.Multiplication\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1 :
				{
					bigInt a,b,c;
					createInt(&a);
					createInt(&b);
					printf("addition is:\n");
					add(&a,&b,&c);
				}	break;
			case 2 :
				{
					bigInt a,b,c;
					createInt(&a);
					createInt(&b);
					printf("subtraction is:\n");
					subtract(&a,&b,&c);
				}	break;
			case 3 :
				{
					bigInt a,b,c;
					createInt(&a);
					createInt(&b);
					printf("multiplication  is:\n");
					multiplication(&a,&b,&c);
				}	break;
			default  : 	printf("Enter correct option\n");
					break;
		}
		printf("press 0 to exit\npress 1 to continue\n");
		scanf("%d",&e);
	}
	return 0;
}


