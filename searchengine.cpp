#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
using namespace std;
#define FILES 10
char arr[FILES][12];
class hash
 {
   public :
     class listrecord
      {
       public :
       int doc;
       listrecord* next;
       listrecord(int d)
        {
         doc=d;
        } 
      }*l; 
   hash* h[26];
   hash();
   void display();
   void Insert(int d);    
 };     


void printfile(char str[])
 {
    FILE * pfile;
    char c;
    cout<<"\n---------------------------------------------------------------------\n";
    pfile=fopen(str,"r");
    while(1)
     {
       if(feof(pfile))
         break; 
       c=fgetc(pfile);
       cout<<c;
     }
    fclose(pfile); 
    cout<<"\n---------------------------------------------------------------------\n";
 }     


hash::hash()
 {
   l=NULL;
   int i;
   for(i=0;i<26;i++)
     h[i]=NULL;
 }    


void hash::display()
 {
   listrecord* temp=l;
   cout<<"\n\n";
   while(temp!=NULL)
     {
      cout<<"\n\nDocument number  :  "<<temp->doc<<" \n\n   ";
      printfile(arr[temp->doc-1]);
      temp=temp->next;
      cout<<"\n\n";
     } 
   cout<<"\n\n";
 }     


void hash::Insert(int d)
 {
   listrecord* temp=l;
   listrecord* newnode;
   if(l==NULL)
    {
     l=new listrecord(d);
     l->next=NULL;
    }
   else 
    {
     while(1)
     {
      if(temp->next==NULL)
       break;
      temp=temp->next;
     }
     if(temp->doc==d)
       return; 
     newnode=new listrecord(d);
     temp->next=newnode;
     newnode->next=NULL;
    } 
 }    


void write(char str[],int k)
 {
   str[0]='f';
   str[1]='i';
   str[2]='l';
   str[3]='e';
   if(k<10)
    {
      str[4]=(char)(k+48);
      str[5]='.';
      str[6]='t';
      str[7]='x';
      str[8]='t';
      str[9]='\0';
    }  
   else
    {
      str[4]=(char)(k/10+48);
      str[5]=(char)(k%10+48);
      str[6]='.';
      str[7]='t';
      str[8]='x';
      str[9]='t';
      str[10]='\0';
    }
 }    


int main()
 {
   FILE * pfile;
   int flag;
   int k;
   for(k=0;k<FILES;k++)
      write(arr[k],k+1);
   hash* head;
   head=new hash;
   char c,str[30];
   int i,len,ic,ic1,j;
   hash* temp=head;
   hash* temp1;
   char files[FILES][1500];
   for(j=0;j<FILES;j++)
    {
     temp=head;
     pfile=fopen(arr[j],"r");
     while(1)
      {
        c=fgetc(pfile);
        if(feof(pfile))
          break;
        ic=(int)c;
        if(!((ic>=65&&ic<=90)||(ic>=97&&ic<=122)))
         {
           temp->Insert(j+1);
           temp=head;
           continue;
         }  
        if(ic>=65&&ic<=90)
          ic=ic-65;
        else  
          ic=ic-97;  
        if(temp->h[ic]==NULL)
          {
           temp->h[ic]=new hash;
           temp=temp->h[ic];
          }
        else
          temp=temp->h[ic];    
      }
//     ic1=(int)files[j][len-1]; 
//     if((ic1>=65&&ic1<=90)||(ic1>=97&&ic1<=122)) 
//       temp->Insert(j+1);
     fclose(pfile);  
    }    
   cout<<"\nEnter a string to search. . .";
   cin>>str;
   len=strlen(str);
   temp1=temp;
   temp=head;
   flag=0;   
   for(i=0;i<len;i++)
    {
      c=str[i];
      if((int)c>=65&&(int)c<=90)
        ic=(int)c-65;
      else
        ic=(int)c-97;
      if(temp->h[ic]==NULL)
       {
        flag=1;
        break;
       }   
      temp=temp->h[ic];
    }
   if(flag)
     cout<<"\nNo result found. . .\n\n"; 
   else
     {
       cout<<"\nThe given string is present in the following documents. . .\n\n";
       temp->display();        
     }         
   getch(); 
   return 0; 
 }   

