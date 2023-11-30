int a=1,b=2,c=3,d=4,e=5,f=6,g=7;



void setup()
{
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);

}



void seg_7(int a , int b , int c, int d , int e ,int f, int g,int i){ 
  switch(i){
  
  case 0: 
    digitalWrite(a,1);
     digitalWrite(b,1);
     digitalWrite(c,1);
     digitalWrite(d,1);
     digitalWrite(e,1);
     digitalWrite(f,1);
     digitalWrite(g,0);
    
    break; 
    
     case 1: 
   
      digitalWrite(a,0);
     digitalWrite(b,1);
     digitalWrite(c,1);
     digitalWrite(d,0);
     digitalWrite(e,0);
     digitalWrite(f,0);
     digitalWrite(g,0);
    
    
    break; 
    
     case 2: 
     digitalWrite(a,1);
     digitalWrite(b,1);
     digitalWrite(c,0);
     digitalWrite(d,1);
     digitalWrite(e,1);
     digitalWrite(f,0);
     digitalWrite(g,1);
    
    break;
      case 3: 
     digitalWrite(a,1);
     digitalWrite(b,1);
     digitalWrite(c,1);
     digitalWrite(d,1);
     digitalWrite(e,0);
     digitalWrite(f,0);
     digitalWrite(g,1);
    
    break; 
    
     case 4: 
    digitalWrite(a,0);
     digitalWrite(b,0);
     digitalWrite(c,1);
     digitalWrite(d,0);
     digitalWrite(e,0);
     digitalWrite(f,1);
     digitalWrite(g,1);
    
    break; 
    
     case 5: 
     digitalWrite(a,1);
     digitalWrite(b,0);
     digitalWrite(c,1);
     digitalWrite(d,1);
     digitalWrite(e,0);
     digitalWrite(f,1);
     digitalWrite(g,1);
    
    break; 
  case 6: 
     digitalWrite(a,1);
     digitalWrite(b,0);
     digitalWrite(c,1);
     digitalWrite(d,1);
     digitalWrite(e,1);
     digitalWrite(f,1);
     digitalWrite(g,1);
    
    break; 
    
    case 7: 
     digitalWrite(a,1);
     digitalWrite(b,1);
     digitalWrite(c,1);
     digitalWrite(d,0);
     digitalWrite(e,0);
     digitalWrite(f,0);
     digitalWrite(g,0);
    
    break; 
   case 8: 
     digitalWrite(a,1);
     digitalWrite(b,1);
     digitalWrite(c,1);
     digitalWrite(d,1);
     digitalWrite(e,1);
     digitalWrite(f,1);
     digitalWrite(g,1);
    
    break; 
    
      case 9: 
     digitalWrite(a,1);
     digitalWrite(b,1);
     digitalWrite(c,1);
     digitalWrite(d,1);
     digitalWrite(e,0);
     digitalWrite(f,1);
     digitalWrite(g,1);
    
    break; 
     default :
       digitalWrite(a,1);
     digitalWrite(b,0);
     digitalWrite(c,0);
     digitalWrite(d,0);
     digitalWrite(e,1);
     digitalWrite(f,1);
     digitalWrite(g,1);
    break;
  
  }

}

void loop()
{
  for(int i=0;i<=10;i++){
   seg_7(a ,b ,c,d ,e ,f,g,i);
    delay(500); 
    
  
  }
}