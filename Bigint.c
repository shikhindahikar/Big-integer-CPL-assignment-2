#include<stdio.h>
#include<stdlib.h>

typedef struct NodeType{
	int data;
	struct NodeType* next;
    struct NodeType* tail;
	struct NodeType* start;
}node,BigInt;

void Init(BigInt* num){
	num->tail=num->start=NULL;//Initialize a null node num
}

node * MakeNode(node * num,int n){
	num=(node*)malloc(sizeof(node));//allocate node a memory block and insert a data
	num->next=NULL;
	num->data=n;
	return num;
}
void Create(BigInt* num1){
	printf("please enter number\n");
	int n,i=0;                          //creating a complete list using Init() and MakeNode functions
	char s[310];
	node * num;
	Init(num1);
	scanf("%s",s);
	while(s[i]!='\0'){
		n=(int)s[i]-48;                 //first big number is taken as a string and then type casted into integers and inserted into a linked list
		num=MakeNode(num,n);
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
void PrintNode(node * num){
	node * temp= num;
	if(temp!=NULL){             //prints nodes data if it is not the end of the list
		PrintNode(temp->next);
		printf("%d",temp->data);
	}
}
void print(BigInt * num1){
	node* num=num1->start;
	PrintNode(num);
	printf("\n");
}
void add(BigInt *l1, BigInt *l2,BigInt *b)
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
		num=MakeNode(num,sum);
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
			num=MakeNode(num,sum);
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
			num=MakeNode(num,sum);
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
		num=MakeNode(num,sum);
		(b->tail)->next=num;
		b->tail=num;
	}
	print(b);


}
void subtract(BigInt *l1, BigInt *l2,BigInt *b)
{
	Init(b);
	BigInt d;
	int sub,brw=0;
	node *num,*p1,*p2;
	p1=l1->start;
	p2=l2->start;
	while(p1!=NULL && p2!=NULL)
	{
		sub=p1->data-p2->data-brw;
		brw=(sub<0)?1:0;
		sub=(brw==1)?(10+sub):sub;
		num=MakeNode(num,sub);
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
			num=MakeNode(num,sub);
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
void Mult(BigInt *l1, BigInt *l2,BigInt *b)
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
				num=MakeNode(num,0);
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
				num=MakeNode(num,carry);
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
		printf("Enter operation to perform-\n1.Addition\n2.Subtraction\n3.Mult\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1 :
				{
					BigInt a,b,c;
					Create(&a);
					Create(&b);
					printf("addition is:\n");
					add(&a,&b,&c);
				}	break;
			case 2 :
				{
					BigInt a,b,c;
					Create(&a);
					Create(&b);
					printf("subtraction is:\n");
					subtract(&a,&b,&c);
				}	break;
			case 3 :
				{
					BigInt a,b,c;
					Create(&a);
					Create(&b);
					printf("Mult  is:\n");
					Mult(&a,&b,&c);
				}	break;
			default  : 	printf("Enter correct option\n");
					break;
		}
		printf("press 0 to exit\npress 1 to continue\n");
		scanf("%d",&e);
	}
	return 0;
}


