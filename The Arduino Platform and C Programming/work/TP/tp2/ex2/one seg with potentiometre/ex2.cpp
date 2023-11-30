
int i=0;
int pot=A0;
 
void setup() {
for(int j=0; j<=11;j++){ 
pinMode(j,OUTPUT); 
  
}
// i=951;
  Serial.begin(9600);
}

void affiche(int i,int a,int b,int c ,int d); 
void loop() {
   
  int e1=analogRead(pot);
  e1=map(e1,0,1023,100,750);
  
  int   c = e1/ 100; // le quotient de la division par 100
   int  d = (e1/10)%10; // le quotient du reste de la division par 100 par 10
    int  u= e1% 10; // le reste de la division par 10
  Serial.print(c);
  Serial.print(d);
  Serial.print(u); 
  Serial.println("");
  
 
  
  affiche(c,0,1,2,3); 
 affiche(d,4,5,6,7); 
 affiche(u,8,9,10,11); 
  delay(500); 
 

  





}

void affiche(int i,int a,int b,int c ,int d){ 

switch(i){ 
case 0 : 
digitalWrite(a,0); 
digitalWrite(b,0); 
digitalWrite(c,0); 
digitalWrite(d,0); 

break;

case 1 : 
digitalWrite(a,1); 
digitalWrite(b,0); 
digitalWrite(c,0); 
digitalWrite(d,0); 


break; 
case 2 : 
digitalWrite(a,0); 
digitalWrite(b,1); 
digitalWrite(c,0); 
digitalWrite(d,0); 


break; 
case 3: 
digitalWrite(a,1); 
digitalWrite(b,1); 
digitalWrite(c,0); 
digitalWrite(d,0); 


break; 
case 4 : 
digitalWrite(a,0); 
digitalWrite(b,0); 
digitalWrite(c,1); 
digitalWrite(d,0); 


break; 

case 5 : 
digitalWrite(a,1); 
digitalWrite(b,0); 
digitalWrite(c,1); 
digitalWrite(d,0); 


break; 
case 6 : 
digitalWrite(a,0); 
digitalWrite(b,1); 
digitalWrite(c,1); 
digitalWrite(d,0); 


break; 
case 7 : 
digitalWrite(a,1); 
digitalWrite(b,1); 
digitalWrite(c,1); 
digitalWrite(d,0); 


break; 


case 8 : 
digitalWrite(a,0); 
digitalWrite(b,0); 
digitalWrite(c,0); 
digitalWrite(d,1); 


break; 
case 9 : 
digitalWrite(a,1); 
digitalWrite(b,0); 
digitalWrite(c,0); 
digitalWrite(d,1); 


break; 



}}