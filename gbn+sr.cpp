#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>
int n,r;
struct frame{
		char ack;
		int data;
}frm[10];
int sender(void);
void recvack(void);
void resend_sr(void);
void resend_gbn(void);
void GoBackN(void);
void SelectiveRepeat(void);
int main(){
	int c;
	do
	{
		printf("\n\n1. Selective Repeat\n2. Go Back N\n3. Exit");
		printf("\n Slecet Option:");
		scanf("%d",&c);
		switch(c)
		{
			case 1: SelectiveRepeat();
			break;
			case 2: GoBackN();
			break;
			case 3: exit(0);
			break;
		}
	}while(c>=4);
}
void GoBackN()
{
	sender();
	recvack();
	resend_gbn();
	printf("\n All frames sent Successfully using Go Back N\n");
}
void SelectiveRepeat()
{
		sender();
	recvack();
	resend_sr();
	printf("\n All frames sent Successfully using Selective Repeat\n");
}
int sender()
{
	int i;
	printf("\n Number of frames to be sent:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("\n Enter data for frames [%d]: ",i);
		scanf("%d",&frm[i].data);
		frm[i].ack = 'Y';
	}
	return 0;
}
void recvack()
{
	int i;
	rand();
	r = rand()%n;
	frm[r].ack = 'N';
	for(i=1;i<=n;i++)
	{
		if(frm[i].ack=='N')
		{
			printf("\n The Frame no %d is not Received\n", r);
		}
	}
}
void resend_sr()
{
	printf("\n Resending Frame %d",r);
	sleep(2);
	frm[r].ack= 'Y';
	printf("\n The Received frame is %d", frm[r].data);
}
void resend_gbn()
{
	int i;
	printf("\n Resending from Frame no. %d",r);
	for(i=r;i<=n;i++)
	{
		sleep(2);
		frm[i].ack= 'Y';
		printf("\n Received data from frame %d",i,frm[i].data); 
	 } 
}
