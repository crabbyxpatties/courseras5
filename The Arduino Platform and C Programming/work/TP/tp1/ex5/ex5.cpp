
// ecrie une programme a l'aide de potentiometer  pour contorle  lluminosité d'une led :
int led=11;
int  analogpin=A0;
void setup(){
pinMode(11,OUTPUT);

}

void loop(){
int x=analogRead(analogpin);
x=map(x,0,1023,0,255);
analogWrite(led,x);


}