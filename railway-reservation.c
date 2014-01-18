#include<stdio.h>
#include<conio.h>
int count=0;
int count1=0;
int wait=0;
#define N 64
struct Traindetails
 {
  int seat;
  int status;
  int age;
  char *berth;
  char *coach;
  int pnr;
  int w;
  char name[20];
  struct Traindetails* next;
 };
typedef struct Traindetails* Train;

Train q1,q2,q3,c4,c5,c6;
Train findvacancy(Train);
void Delete();
void reform();


void welcome(Train);
void welcome(Train t)
 {
  if(t->status==0)
   {
    clrscr();
    printf("\n\n     CANCELLATION DETAILS\n\n");
    printf("PNR no.  :  %d \n\n",t->pnr);
    printf("Name     :  %s \n\n",t->name);
    printf("Age      :  %d \n\n",t->age);
    printf("Status   :  Cancelled \n\n");
    getch();
   }
  else
   if(t->w==0)
    {
     clrscr();
     printf("\n\n     TICKET DETAILS\n\n");
     printf("PNR no.  :  %d \n\n",t->pnr);
     printf("Name     :  %s \n\n",t->name);
     printf("Age      :  %d \n\n",t->age);
     printf("Coach    :  %s \n\n",t->coach);
     printf("Seat no. :  %d \n\n",t->seat);
     printf("Berth    :  %s \n\n",t->berth);
     printf("Status   :  Booked \n\n");
     getch();

    }
   else
    {
     clrscr();
     printf("\n\n     TICKET DETAILS\n\n");
     printf("PNR no.  :  %d \n\n",t->pnr);
     printf("Name     :  %s \n\n",t->name);
     printf("Age      :  %d \n\n",t->age);
     printf("Status   :  Waiting \n\n");
     getch();
    }

  }



Train Book(Train t,int ag,char nam[])
 {
   int s,d,v;
   Train t2,temp2,new1,temp,new,t1;
   if(t==NULL)
    {
     count++;
     count1++;
     t=(Train)malloc(sizeof(struct Traindetails));
     t->age=ag;
     strcpy(t->name,nam);
     s=count%8;
     t->status=1;
     t->w=0;
     switch(s)
      {
       case 1 : strcpy(t->berth,"L");
		break;
       case 2 : strcpy(t->berth,"M");
		break;
       case 3 : strcpy(t->berth,"U");
		break;
       case 4 : strcpy(t->berth,"L");
		break;
       case 5 : strcpy(t->berth,"M");
		break;
       case 6 : strcpy(t->berth,"U");
		break;
       case 7 : strcpy(t->berth,"SL");
		break;
       case 0 : strcpy(t->berth,"SU");
		break;
      }
     t->pnr=count;
     d=(count-1)/16;
     t->next=NULL;
     switch(d)
      {
       case 0 : strcpy(t->coach,"s1");
		break;
       case 1 : strcpy(t->coach,"s2");
		break;
       case 2 : strcpy(t->coach,"s3");
		break;
       case 3 : strcpy(t->coach,"s4");
		break;
      }
     if(count%16==0)
      t->seat=16;
     else
      t->seat=count%16;

     welcome(t);
    }
   else
    {
     v=checkvacancy(t);
     if(count==N&&v==1)
      {
       clrscr();
       printf("\n\nSORRY NO TICKETS AVAILABLE ! ! !\n\n");
       printf("WAITING LIST ! ! !\n\n\n");
       if(q1==NULL)
	{
	 count1++;
	 wait++;
	 q1=(Train)malloc(sizeof(struct Traindetails));
	 q1->age=ag;
	 strcpy(q1->name,nam);
	 q1->w=wait;
	 q1->next=NULL;
	 q1->pnr=count1;
	 q1->status=1;

	 welcome(q1);
	}
       else
	{
	 temp2=q1;
	 while(temp2->next!=NULL)
	  temp2=temp2->next;
	 new1=(Train)malloc(sizeof(struct Traindetails));
	 temp2->next=new1;
	 new1->age=ag;
	 strcpy(new1->name,nam);
	 wait++;
	 new1->w=wait;
	 new1->status=1;
	 count1++;
	 new1->pnr=count1;
	 new1->next=NULL;
	 welcome(new1);
	}
      }
      else

      if(count<N)
       {
	temp=t;
	while(temp->next!=NULL)
	 temp=temp->next;
	count++;
	count1++;
	new=(Train)malloc(sizeof(struct Traindetails));
	temp->next=new;
	new->next=NULL;
	new->age=ag;
	strcpy(new->name,nam);
	new->status=1;
	s=count%8;
	new->status=1;
	switch(s)
	 {
	  case 1 : strcpy(new->berth,"L");
		   break;
	  case 2 : strcpy(new->berth,"M");
		   break;
	  case 3 : strcpy(new->berth,"U");
		   break;
	  case 4 : strcpy(new->berth,"L");
		   break;
	  case 5 : strcpy(new->berth,"M");
		   break;
	  case 6 : strcpy(new->berth,"U");
		   break;
	  case 7 : strcpy(new->berth,"SL");
		   break;
	  case 0 : strcpy(new->berth,"SU");
		   break;
	 }
	new->pnr=count;
	d=(count-1)/16;
	new->w=0;
	switch(d)
	 {
	  case 0 : strcpy(new->coach,"s1");
		   break;
	  case 1 : strcpy(new->coach,"s2");
		   break;
	  case 2 : strcpy(new->coach,"s3");
		   break;
	  case 3 : strcpy(new->coach,"s4");
		   break;
	 }
	if(count%16==0)
	 new->seat=16;
	else
	 new->seat=count%16;
	welcome(new);
       }
/*      else
       if(v==0)
	{
	  if(q1==NULL)
	  {
	   t1=(Train)findvacancy(t);
	   t1->age=ag;
	   strcpy(t1->name,nam);
	   t1->status=1;
	  }
	  else
	  {
	   t1=(Train)findvacancy(t);
	   t1->age=q1->age;
	   strcpy(t1->name,q1->name);
	   t1->status=1;
	   t1->w=0;
	   q1=(Train)Delete(q1);
	   reform(q1);
	}
   } */

    }

   return t;
 }


Train Cancellist(Train t)
 {
  Train temp=c5,new;
  if(c5==NULL)
   {
    c5=(Train)malloc(sizeof(struct Traindetails));
    c5->pnr=t->pnr;
    c5->age=t->age;
    strcpy(c5->name,t->name);
    c5->next=NULL;
    c5->status=0;
    c5->w=0;
    return c5;
   }
  else
   {
    while(temp->next!=NULL)
       temp=temp->next;
    new=(Train)malloc(sizeof(struct Traindetails));
    temp=new;
    new->age=t->age;
    strcpy(new->name,t->name);
    new->status=0;
    new->w=0;
    new->next=NULL;
    return t;
   }
  }

Train Cancel(Train t,int no)
  {
     Train temp=t,tt=q1;
     int c1=0,c2=0;
     while(temp->pnr!=no&&temp!=NULL)
      temp=temp->next;
      if(temp==NULL)
      {
       c1=1;
       while(tt!=NULL&&tt->pnr!=no)
	tt=tt->next;
      }
     else
      {
       temp->status=0;
       welcome(temp);
      }

      if(tt==NULL)
       c2=1;
      if(c1&&c2)
       {
	printf("Not yet booked ! ! !\n\n\n");
	getch();
       }
      else
       if(c1)
	{
	 tt->status=0;
	 welcome(tt);
	}


     if(q1!=NULL)
      {
       c5=Cancellist(temp);
       temp->status=1;
       temp->age=q1->age;
       strcpy(temp->name,q1->name);
       temp->pnr=q1->pnr;

       Delete();

       reform(q1);
      }
     return t;


  }



void Delete()
 {
  Train t=q1;
  q1=q1->next;
  free(t);

 }

void reform(Train q)
 {
  Train t=q;
  wait--;
  //count1--;
  while(t!=NULL)
   {
    t->w--;
  //  t->pnr--;
    t=t->next;
   }
 }


int checkvacancy(Train t)
 {
  Train temp=t;
  while(temp!=NULL)
    {
     if(temp->status==0)
       return 0;
     temp=temp->next;
    }
  return 1;
 }


Train findvacancy(Train t)
 {
  Train temp=t;
  while(temp!=NULL)
   {
    if(temp->status==0)
     return temp;
    temp=temp->next;
   }
  return temp;

 }

int checkavailable(Train t)
 {
  if(count<N)
   return 1;
  else
   if(!checkvacancy(t))
    return 1;
   else
    return 0;
 }

void Printwait(Train  q)
 {
  Train t=q;
  if(t==NULL)
   {

    clrscr();
    printf("\n\nNO WAITING LIST\n\n");

   }
  while(t!=NULL)
   {
    printf("  %d     %d       %s      %d\n\n",t->pnr,t->age,t->name,t->w);
    t=t->next;
   }
  getch();

 }


void Printchart(Train t)
 {
  Train temp=t;
  clrscr();
  printf("\n\n----------------------------------------\n\n");
  printf(" PNR  SEAT   COACH   AGE   NAME   BERTH\n\n");
  printf("----------------------------------------\n\n");
  while(temp!=NULL)
   {
    if(temp->status==1)
      printf(" %d       %d        %s       %d      %s \t %s \n\n",temp->pnr,temp->seat,temp->coach,temp->age,temp->name,temp->berth);
    else
      printf("         NOT BOOKED    \n\n");
    temp=temp->next;
   }
  printf("----------------------------------------\n\n");
  getch();

 }


void Printcancellist(int no,Train t)
 {
  Train temp=t;
  while(temp!=NULL)
   {
     if(temp->pnr==no)
      {
       clrscr();
       printf("\n\nPNR no.   :  %d\n\n",temp->pnr);
       printf("Name     :  %s\n\n",temp->name);
       printf("Age      :  %d\n\n",temp->age);
       printf("Status   :  Cancelled\n\n\n");
       getch();
      }
     temp=temp->next;
   }
 }

void checkstatus(int no,Train t,Train q)
 {
  Train temp;
  int c=0;
  if(no<=N)
   {
    temp=t;
    while(temp!=NULL)
     {
      if(temp->pnr==no)
	{
	 if(temp->status==1)
	  {
	   clrscr();
	   printf("\n\nPNR number : %d\n\n",temp->pnr);
	   printf("Name       :  %s\n\n",temp->name);
	   printf("Age        :  %d\n\n",temp->age);
	   printf("Seat number : %d\n\n",temp->seat);
	   printf("Coach      : %s \n\n",temp->coach);
	   printf("Berth      : %s\n\n",temp->berth);
	   printf("Status     :  Confirm\n\n");
	   getch();
	  }
	 else
	  {
	   clrscr();
	   printf("\n\nPNR number : %d\n\n",temp->pnr);
	   printf("Name       :  %s\n\n",temp->name);
	   printf("Age        :  %d\n\n",temp->age);
//	   printf("Seat number : %d\n\n",temp->seat);
//	   printf("Coach      : %s \n\n",temp->coach);
	   printf("Status     :  Cancelled\n\n");
	   getch();
	  }

	 c=1;
	 break;
	}
      temp=temp->next;
     }
   }
  else
   {
     temp=q;
     while(temp!=NULL)
      {
       if(temp->pnr==no)

	  {
	   clrscr();
	   printf("\n\nPNR number : %d\n\n",temp->pnr);
	   printf("Name       :  %s\n\n",temp->name);
	   printf("Age        :  %d\n\n",temp->age);
//	   printf("Seat number : %d\n\n",temp->seat);
//	   printf("Coach      : %s \n\n",temp->coach);
	   printf("Status     :  Waiting\n\n");
	   getch();

	  c=1;
	  break;
	 }
       temp=temp->next;
      }

   }
  if(c==0)
   {
    if(no>count1)
     printf("\n\nTicket not yet booked ! ! !\n\n\n");
    else
     Printcancellist(no,c5);
    getch();
   }
 }



void main()
 {
  Train t1,t2,t3;
  int ch,ch1,age,pnr;
  char name[20];
  t1=NULL;
  q1=NULL;
  clrscr();
/*  printf("Select the train number. . .\n\n");
  printf("1 . 2693     Pearl city express\n\n");
  printf("2 . 2679     Pandian express\n\n");
  printf("3 . 2685     Nellai express\n\n");
  scanf("%d",&ch);
  switch(ch)
   {
    case 1 :*/
	 while(1)
	     {
	     clrscr();
//	     printf("Enter your choice. . .\n\n");
	     printf("1 . Book a ticket\n\n");
	     printf("2 . Cancel a ticket\n\n");
	     printf("3 . Check availability\n\n");
	     printf("4 . Check PNR status\n\n");
	     printf("5 . Print the chart of booked tickets\n\n");
	     printf("6 . Print the waiting list\n\n");
	     printf("7 . Exit\n\n");
	     scanf("%d",&ch1);
	     switch(ch1)
	      {
	       case 1 : if(count==N&&checkvacancy(t1))
			  printf("\n\nSorry ! ! Waiting list ! ! !\n\n");
			printf("\nEnter name and age of the person. . .");
			scanf("%s%d",name,&age);
			t1=Book(t1,age,name);
			break;
	       case 2 : printf("Enter the pnr number. . .");
			scanf("%d",&pnr);
			t1=Cancel(t1,pnr);
			break;
	       case 3 : if(checkavailable(t1))
			  printf("\n\nTICKET AVAILABLE\n\n");
			else
			 printf("\n\nNOT AVAILABLE\n\n");
			getch();
			break;
	       case 4 : printf("Enter the PNR number. . .");
			scanf("%d",&pnr);
			checkstatus(pnr,t1,q1);
			break;
	       case 5 : Printchart(t1);
			break;
	       case 6 : Printwait(q1);
			break;
	      }
	   // clrscr();
	    if(ch1==7)
	     break;


   }

 }



