void initialize()
{
    int i;
    for(i=8;i<16;i++)
     digitalWrite(i,HIGH); 
}


void blink(int i,int j)
{
   digitalWrite(j,LOW);
   digitalWrite(i,HIGH);
   delay(1);
   digitalWrite(i,LOW);
   digitalWrite(j,HIGH);
   delay(1);  
}

void snakeblink(int k){
  if(k<=7)
    blink(k,8);
  else
   if(k>7&&k<=39)
    blink(k%8,8+(k/8));
  else
   blink((k+8)%8,8+((k+8)/8));
}

void gridblink(int g[])
{
    for(int i =0; i<5; i++){
      snakeblink(g[i]);
      }
    initialize();
    delay(45);
}

class snake
{
	public:
  
        struct NODE
	{
		int item;
		NODE* next;
	}*x;

	NODE* head;
	NODE* tail;
        int offset;
	
	
	
	snake()
	{
		x = new NODE;
                NODE *y = new NODE;
                NODE *z = new NODE;
		x->item = 2;
		x->next = y;
                y->item = 1;
		y->next = z;
                z->item = 0;
		z->next = NULL;
		head = x;
		tail = z;
                offset = 1;
	}
	~snake()
	{
		head = NULL;
		tail = NULL;
		delete x;
		x = NULL;
	}
	
	void add(int data)
	{				
		if(x->item==0)
		{
			x->item = data;
		}
		else
		{
			NODE* temp;
			temp = new NODE;
			temp->item = data;
			temp->next = head;
			head = temp;			
		}		
	}
	void del()
	{
		if(is_empty()==0)
		{		
			tail->item = NULL;
			NODE* temp = head;		
			while(temp->next->item!=0)
				temp = temp->next;
                        //delete(tail);
			tail = temp;	
		}		
	}
	
	int is_empty()
	{
		if(head==tail&&head->item==0)
		{		
			return 1;
		}		
		else
			return 0;
	}
	void display()
	{
		NODE* temp = head;		
		while(temp!=tail)
		{
			snakeblink(temp->item);		
			temp = temp->next;
		}
		snakeblink(temp->item);
                 initialize();
                delay(15);
	}	
};


void setup()
{
  for(int i=0;i<16;i++)
  pinMode(i,OUTPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
}


   snake p;

void loop()
{
   initialize(); 
   p.display();
   int flag = 0;
    if(digitalRead(A3)==HIGH){
     int x = (p.head->item + 8)%56;  
     p.add(x); 
     p.display();
     flag = 1;
   }
    if(digitalRead(A5)==HIGH){
     int y = p.head->item;
     int x;
     switch (y){
      case 7:  x = 0;  break;
      case 15: x = 8;  break;
      case 23: x = 16; break;
      case 31: x = 24; break;
      case 39: x = 32; break;
      case 47: x = 40; break;
      case 55: x = 48; break;
      default: x = (p.head->item + 1)%56;  break;
     }  
     p.add(x); flag = 1;
     p.display();     
   }
   if(digitalRead(A4)==HIGH){
     int y = p.head->item;
     int x;
     switch (y){
      case 0:  x = 7;  break;
      case 8:  x = 15;  break;
      case 16: x = 23; break;
      case 24: x = 31; break;
      case 32: x = 39; break;
      case 40: x = 47; break;
      case 48: x = 55; break;
      default: x = (p.head->item - 1)%56;  break;
     }      
     p.add(x); 
     p.display();
     flag = 1;
   }
   if(digitalRead(A2)==HIGH){
     int y = p.head->item;
     int x;
     switch (y){
      case 0: x = 48;  break;
      case 1: x = 49;  break;
      case 2: x = 50; break;
      case 3: x = 51; break;
      case 4: x = 52; break;
      case 5: x = 53; break;
      case 6: x = 54; break;
      case 7: x = 55; break;
      default: x = (p.head->item - 8)%56;  break;
     }
     p.add(x); 
     p.display();
     flag = 1;
   }
   
 if(flag == 1){
   p.del();}

  
}
   
