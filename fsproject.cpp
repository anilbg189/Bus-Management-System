#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <fstream>

using namespace std;

static int p = 0;

class a

{

  char busn[5], driver[10], depart[10], from[20], to[20] , route[5];

public:

  void install();
  
  void delete1();
  
  void modify();

  void allotment();

  void empty();

  void show();

  void avail();

  void reservations();

};

void vline(char ch)
{
  for (int i=150;i>0;i--)
  cout<<ch;
}

void a::install()
{
  ofstream ofile;
  ofile.open("bus.txt",ios::app);
  
  a bus;
  char buf[100];
  cout<<"Enter bus no: ";

  cin>>bus.busn;

  cout<<"\nEnter Driver's name: ";

  cin>>bus.driver;

  cout<<"\nDeparture: ";

  cin>>bus.depart;

  cout<<"\nFrom: \t\t\t";

  cin>>bus.from;

  cout<<"\nTo: \t\t\t";

  cin>>bus.to;
  
  cout<<"\n Route: \t\t\t";
   
  cin>>bus.route;

  sprintf(buf,"%s|%s|%s|%s|%s|%s|$",bus.busn,bus.driver,bus.depart,bus.from,bus.to,bus.route);
  ofile<<buf;
  ofile.close();
}

void a::allotment()
{
  int seat,rseat,found=0;
  char number[5],name[5],no[5];
  char buf[100],temp[100];
  ifstream ifile;
  ifile.open("reservation.txt",ios::in);
  ofstream ofile;
  ofile.open("reservation.txt",ios::app);
  ifstream bfile;
  bfile.open("bus.txt",ios::in);
  a bus;
  
  cout<<"Bus no: ";

  cin>>number;
  cout<<"\nnumber="<<number<<endl;
   while(!bfile.eof())
  {
  	bfile.getline(buf,100,'$');
  	sscanf(buf,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|",bus.busn,bus.driver,bus.depart,bus.from,bus.to,bus.route,temp);
  	if( strcmp(bus.busn,number)==0 )
  	{
  		found=1;
  		break;
	  }
  }
    
    if(found==0)
    {
    	cout<<"\nYou have entered wrong bus number\n";
        goto menu;	
	}
   
    cout<<"\nSeat Number: ";

    cin>>seat;
    
    if(seat>32)

    {

      cout<<"\nThere are only 32 seats available in this bus.";
      goto menu;
    }
    
    if(seat<1)
    {
    	cout<<"\n You have entered invalid seat number \n";
    	return;
    	// goto menu;
	}
       ifile.seekg(0,ios::beg);
       
       while(!ifile.eof())
       {
       	ifile.getline(buf,100,'$');
       	sscanf(buf,"%[^|]|%d|%[^|]|$",no,&rseat,name,temp);
       	if((rseat==seat) && ( strcmp(no,number)==0))
       	{
		   cout<<"\n\nseat is already reserved... try another seat...or another bus \n\n";   
		   goto menu;
		}
	   }
	   

        cout<<"Enter passnger's name: ";

        cin>>name;
        
        sprintf(buf,"%s|%d|%s|$",number,seat,name);
        ofile<<buf;
        cout<<"\nYOU HAVE SUCCESFULLY RESEREVED YOUR SEAT !\n";
        ofile.close();
        ifile.close();
        menu :
        	cout<<"";
      }

void a::show()
{
  int s[33],emptyseats=0,found=0;
  int rseat;
  for(int i=1;i<33;i++)
  s[i]=0;

  char number[5],buf[100],temp[100],name[20],bno[10];
  ifstream rfile;
  rfile.open("reservation.txt",ios::in);

  ifstream bfile;
  bfile.open("bus.txt",ios::in);

  cout<<"Enter bus no: ";

  cin>>number;
  
  a bus;
  
  while(!bfile.eof())
  {
  	bfile.getline(buf,100,'$');
  	sscanf(buf,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|",bus.busn,bus.driver,bus.depart,bus.from,bus.to,bus.route,temp);
  	if( strcmp(bus.busn,number)==0 )
  	{
  		found=1;
  		break;
	  }
  }
   if(found==0)
   {
   	cout<<"You have entered wrong bus number";
   	return;
   }
   while(!rfile.eof())
       {
       	rfile.getline(buf,100,'$');
       	sscanf(buf,"%[^|]|%d|%[^|]|$",bno,&rseat,name,temp);
       	if(strcmp(bno,number)==0)
       	{
		   s[rseat]=1;
		}
	   }

  vline('*');

  cout<<"\nBus no: \t"<<number

  <<"\nDriver: \t"<<bus.driver<<"\nDeparture time:"<<bus.depart

  <<"\nFrom: \t\t"<<bus.from<<"\nTo: \t\t"<<

  bus.to<<"\n Route:"<<bus.route<<"\n";

  vline('*');
  cout<<"\n";
  for(int i=1;i<33;i++)
   {
	  if(s[i]==0)
	  {
	   cout<<i<<"     empty\t\t\t";
       emptyseats--;
	  }
	  
	  if(s[i]==1)
	  cout<<i<<"  reserved\t\t\t";
	  
	  if(i%4==0)
	  cout<<"\n";
   }
   
   cout<<"\n There are "<< emptyseats<<" Empty seats\n";
}

void a::avail()
{
    int ani=0;
    a bus;
    char buf[100],temp[100];
    ifstream bfile;
    bfile.open("bus.txt",ios::in);

     while(!bfile.eof())
  {
  	bfile.getline(buf,100,'$');
  	sscanf(buf,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|",bus.busn,bus.driver,bus.depart,bus.from,bus.to,bus.route,temp);
  	if(strcmp(buf,"")==0)
  	break;
    cout<<"\n";
    vline('*');
    cout<<"\nBus no: \t"<<bus.busn<<"\nDriver: \t"<<bus.driver

    <<"\t\t\tDeparture Time: \t"

    <<bus.depart<<"\nFrom: \t\t"<<bus.from<<"\nTo: \t\t"

    <<bus.to<<"\nRoute : "<<bus.route <<"\n";

    vline('*');
    cout<<"\n";

    vline('_');
    
  }
  bfile.close();
}

void a::modify()
{
	char buf[100],temp[100],number[10];
	a bus;
	int flag=0,y,bani=1;
	ifstream ifile;
	ifile.open("bus.txt",ios::in);
	ofstream ofile;
	ofile.open("bus2.txt",ios::out);
	cout<<"Enter the bus number you need to modify : ";
	cin>>number;
	
	while(!ifile.eof())
	{
		ifile.getline(buf,100,'$');
		sscanf(buf,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|",bus.busn,bus.driver,bus.depart,bus.from,bus.to,bus.route,temp);
		if(strcmp(buf,"")==0)
		break;
		cout<<++bani;
		if(strcmp(bus.busn,number)==0)
		{
			flag=1;
		    cout<<"\n key found \n 1:modify bus driver name \n2:modify departure time \n3:modify from \n4:modify to \n5:route \n enter ur choice:";
		    cin>>y;
		    cout<<"\n";
		    switch(y)
		    {
		    	case 1:cout<<"Enter new driver name";
		    	       cin>>bus.driver;
		    	       break;
		    	case 2:cout<<"Enter new departure time";
				       cin>>bus.depart;
					   break;
				case 3:cout<<"Enter new from location";	 
				       cin>>bus.from;
					   break;
				case 4:cout<<"Enter new to location";	 
				       cin>>bus.to;
					   break;
				case 5:cout<<"Enter new route";	 
				       cin>>bus.route;
					   break;	              
			}
		}
		sprintf(buf,"%s|%s|%s|%s|%s|%s|$",bus.busn,bus.driver,bus.depart,bus.from,bus.to,bus.route);
        ofile<<buf;
	}
	if(flag==0)
    cout<<"\n You have entered wrong bus number\n";
     ofile.close();
    ifile.close();
    
    remove("bus.txt");

    rename("bus2.txt","bus.txt");
}

void a::delete1()
{
	char buf[100],temp[100],number[10];
	a bus;
	int flag=0,y;
	ifstream ifile;
	ifile.open("bus.txt",ios::in);
	
	ofstream ofile;
	ofile.open("bus2.txt",ios::out);
	cout<<"Enter the bus number you need to delete : ";
	cin>>number;
	
	while(!ifile.eof())
	{
		ifile.getline(buf,100,'$');
		sscanf(buf,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|",bus.busn,bus.driver,bus.depart,bus.from,bus.to,bus.route,temp);
		if(strcmp(buf,"")==0)
		{
			break;
		}
		if(strcmp(bus.busn,number)==0)
		{
			flag=1;
			cout<<"\n Bus Deleted \n";
		   
		}
		else
		{
		sprintf(buf,"%s|%s|%s|%s|%s|%s|$",bus.busn,bus.driver,bus.depart,bus.from,bus.to,bus.route);
        ofile<<buf;
	    }
	}
	if(flag==0)
    cout<<"\n bus number not found";
       ofile.close();
    ifile.close();
    
	remove("bus.txt");

    rename("bus2.txt","bus.txt");
 }

void a::reservations()
{
	ifstream ifile;
	int rseat,found=0;
    ifile.open("reservation.txt",ios::in);
    ifstream bfile;
    bfile.open("bus.txt",ios::in);
	char number[10],buf[100],temp[100],no[10],name[10];
	cout<<"\nEnter the bus number : ";
	cin>>number;
	a bus;
	
	  while(!bfile.eof())
  {
  	bfile.getline(buf,100,'$');
  	sscanf(buf,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|",bus.busn,bus.driver,bus.depart,bus.from,bus.to,bus.route,temp);
  	if( strcmp(bus.busn,number)==0 )
  	{
  		found=1;
  		break;
	  }
  }
  
  if(found==0)
  {
  	cout<<"\nYou have entered wrong bus number\n";
  	goto menu;
  }
	
	vline('*');
	cout<<"\n Seat number \t\t Name\n";
	
	 while(!ifile.eof())
       {
       	ifile.getline(buf,100,'$');
       	sscanf(buf,"%[^|]|%d|%[^|]|$",no,&rseat,name,temp);
       	if(strcmp(buf,"")==0)
       	{ 
       		break;
		   }
       	if(strcmp(no,number)==0)
       	cout<<rseat<< "\t\t\t"<<name<<"\n";
       }
       vline('*');
       menu : cout<<"";
}

int main()
{
	a bu;

system("cls");

int w;
menu :
while(1)

{
 //system("cls");
 cout<<"\n"; 
 vline('*');
  cout<<"\n\n\n";
  cout<<"\t\t\t\t\t\t\t\t\t\t BUS RESERVATION SYSTEM \n";
  cout<<"\t\t\t1.Admin\n\t\t\t"
  <<"2.Reservation\n\t\t\t"
  <<"3.Show\n\t\t\t"
  <<"4.Buses Available. \n\t\t\t"
  <<"5.Exit";
  cout<<"\n\n\n";
  vline('*');
  cout<<"\n\t\t\tEnter your choice:-> ";
  cin>>w;
  switch(w)
  {
    case 1:  while(1)
            {
	         int x; 
	         cout<<"\n";
	         vline('*');
	        cout<<"\n\n\n";
	        cout<<"\t\t\t\t\t\t ADMIN OPTIONS \n";
             cout<<"\t\t\t1.Insert a new bus info\n\t\t\t"
             <<"2.Modify bus info\n\t\t\t"
             <<"3.Delete bus info\n\t\t\t"
             <<"4.Info about reserved seats\n\t\t\t"
             <<"5.Exit";
             cout<<"\n\n\n";
	         vline('*');
            cout<<"\n\t\t\tEnter your choice:-> ";
            cin>>x;
            switch(x)
            {
            	case 1 : bu.install();
            	break;
               	case 2 : bu.modify();
            	break;
             	case 3: bu.delete1();
            	break;
              	case 4:bu.reservations();
            	break;
               	case 5 : goto menu;
           		break;
               	default :exit(0);
			}
		   }
      break;

    case 2:  bu.allotment();

      break;

    case 3:  bu.show();

      break;

    case 4:  bu.avail();

      break;
      

    case 5:  exit(0);
  }
}
return 0;
}
