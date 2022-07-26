#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;

static int r = 0;

class reserve

{

  char num[5], driver[20], arrival[5], departure[5], from[20], to[20], seat[8][4][10];

public:

  void getdetails();

  void reservation();

  void empty();

  void vacancy();

  void display();

  void seatstatus(int i);

}

bus[15];

void vline(char ch)

{

  for (int i=90;i>0;i--)

  cout<<ch;

}

void reserve::getdetails()

{
  vline('_');
  
  cout<<"\n\n\t********** ENTER FOLLOWING DETAILS FOR A NEW BUS **********\n";
  
  vline('_');
  cout<<"\n\n\tBus Number: \t\t";

  cin>>bus[r].num;

  cout<<"\n\tDriver's Name: \t\t";

  cin>>bus[r].driver;
  
  cout<<"\n\tFrom: \t\t\t";

  cin>>bus[r].from;

  cout<<"\n\tTo: \t\t\t";

  cin>>bus[r].to;

  cout<<"\n\tArrival Time: \t\t";

  cin>>bus[r].arrival;

  cout<<"\n\tDeparture Time: \t";

  cin>>bus[r].departure;

  bus[r].empty();

  r++;

}

void reserve::reservation()

{

  int seat;

  char number[5];

  top:

  vline('_');
  cout<<"\n\n\n\t************ MAKE A NEW RESERVATION ************\n";
  
  vline('_');
  cout<<"\n\n\tBus Number: ";

  cin>>number;

  int n;

  for(n=0;n<=r;n++)

  {

    if(strcmp(bus[n].num, number)==0)

    break;

  }

  while(n<=r)

  {

    cout<<"\n\tSeat Number: ";

    cin>>seat;

    if(seat>32)

    {

      cout<<"\n\tSorry! There are only 32 seats available in this bus.\n";

    }

    else

    {

    if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)

      {

        cout<<"\n\tEnter Passanger's Name: ";

        cin>>bus[n].seat[seat/4][(seat%4)-1];

        break;

      }

    else

      cout<<"\tThis seat is reserved already!\n";

      }

      }

    if(n>r)

    {

      cout<<"\tNo bus with this number is available on our system. \n\tPlease check and make a valid entry.\n";

      goto top;

    }

  }


void reserve::empty()

{

  for(int i=0; i<8;i++)

  {

    for(int j=0;j<4;j++)

    {

      strcpy(bus[r].seat[i][j], "Empty");

    }

  }

}

void reserve::vacancy()

{

  int n;

  char number[5];

  vline('_');
  cout<<"\n\n\t********** SEE VACANCY IN A BUS **********\n";
  
  vline('_');
  cout<<"\n\n\tEnter Bus Number: ";

  cin>>number;

  for(n=0;n<=r;n++)

  {

    if(strcmp(bus[n].num, number)==0)

    break;

  }

while(n<=r)

{

  cout<<"\n";
  
  vline('*');

  cout<<"\n\t\t\t\tBus No.: \t"<<bus[n].num

  <<"\nDriver: \t"<<bus[n].driver<<"\nArrival time: \t"

  <<bus[n].arrival<<"\t\tDeparture time: \t"<<bus[n].departure

  <<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t\t"<<

  bus[n].to<<"\n";

  vline('*');

  bus[0].seatstatus(n);

  int a=1;

  for (int i=0; i<8; i++)

  {

    for(int j=0;j<4;j++)

    {

      a++;

      if(strcmp(bus[n].seat[i][j],"Empty")!=0)

      cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";

    }

  }

  break;

  }

  if(n>r)

    cout<<"\tNo bus with this number is available on our system. \n\tPlease check and make a valid entry: ";

}

void reserve::seatstatus(int l)

{

  int s=0;r=0;

  for (int i =0; i<8;i++)

  {

    cout<<"\n";

    for (int j = 0;j<4; j++)

    {

      s++;

      if(strcmp(bus[l].seat[i][j], "Empty")==0)

        {

          cout.width(5);

          cout.fill(' ');

          cout<<s<<".";

          cout.width(10);

          cout.fill(' ');

          cout<<bus[l].seat[i][j];

          r++;

        }

        else

        {

        cout.width(5);

        cout.fill(' ');

        cout<<s<<".";

        cout.width(10);

        cout.fill(' ');

        cout<<bus[l].seat[i][j];

        }

      }

    }

  cout<<"\n\nThere are "<<r<<" seats empty in Bus Number "<<bus[l].num<<".";

  }

void reserve::display()

{


  for(int n=0;n<r;n++)

  {
    
    cout<<"\n\n";
    
    vline('*');

    cout<<"\n\t\t\t\tBus no: \t"<<bus[n].num
	<<"\n\nDriver: \t"<<bus[n].driver
	<<"\nArrival time: \t"
	<<bus[n].arrival<<"\t\tDeparture Time: "<<bus[n].departure
	<<"\nFrom: \t"<<bus[n].from<<"\t\t\tTo: \t"<<bus[n].to<<"\n";

    vline('*');
    
    cout<<"\n";

    vline('_');

  }

}

int main()

{


int choice;

while(1)

{

  cout<<"\n\n\n\n\n";

  cout<<"\t\t\t1. Enter details for a new bus \n"

  <<"\t\t\t2. Make a new reservation \n"

  <<"\t\t\t3. See vacancy and reservation status for a bus \n"

  <<"\t\t\t4. See the buses available \n"

  <<"\t\t\t5. Exit \n";

  cout<<"\n\t\t\tEnter your choice here:  ";

  cin>>choice;
  
  
  switch(choice)

  {

    case 1:  bus[r].getdetails();

      break;

    case 2:  bus[r].reservation();

      break;

    case 3:  bus[0].vacancy();

      break;

    case 4:  bus[0].display();

      break;

    case 5:  exit(0);

  }

}

return 0;

}
