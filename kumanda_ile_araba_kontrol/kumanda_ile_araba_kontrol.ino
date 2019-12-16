#include <IRremote.h>
 
int RECV_PIN = 11;
int sagileri = 7;
int saggeri  = 8;
int solileri = 9;
int solgeri  = 10;


int itsONled[] = {0,0,0,0,0};

#define code1 33150

#define code2 4590

#define code3 16830

#define code4 2550


IRrecv irrecv(RECV_PIN);
 
decode_results results;
 
void setup()
{
Serial.begin(9600);
irrecv.enableIRIn();
pinMode(sagileri, OUTPUT);
pinMode(saggeri,  OUTPUT);
pinMode(solileri, OUTPUT);
pinMode(solgeri,  OUTPUT);
}
 
void loop() {
if (irrecv.decode(&results)) {
unsigned int value = results.value;
switch(value) {
case code1:
if(itsONled[1] == 1) {
digitalWrite(sagileri, LOW);
digitalWrite(solileri, LOW);
digitalWrite(saggeri, LOW);
digitalWrite(solgeri, LOW);
itsONled[1] = 0;
} else {
digitalWrite(sagileri, HIGH);
digitalWrite(solileri, HIGH);
digitalWrite(saggeri, LOW);
digitalWrite(solgeri, LOW);
itsONled[1] = 1;
}
break;
case code2:
if(itsONled[2] == 1) {
digitalWrite(sagileri, LOW);
digitalWrite(solileri, LOW);
digitalWrite(saggeri, LOW);
digitalWrite(solgeri, LOW);
itsONled[2] = 0;
} else {
digitalWrite(sagileri, LOW);
digitalWrite(solileri, LOW);
digitalWrite(saggeri, HIGH);
digitalWrite(solgeri, HIGH);
itsONled[2] = 1;
}
break;
case code3:
if(itsONled[3] == 1) {
digitalWrite(sagileri, LOW);
digitalWrite(solileri, LOW);
digitalWrite(saggeri, LOW);
digitalWrite(solgeri, LOW);
itsONled[3] = 0;
} else {
digitalWrite(sagileri, LOW);
digitalWrite(solileri, HIGH);
digitalWrite(saggeri,  HIGH);
digitalWrite(solgeri,  LOW);
itsONled[3] = 1;
}
break;
case code4:
if(itsONled[4] == 1) {
digitalWrite(sagileri, LOW);
digitalWrite(solileri, LOW);
digitalWrite(saggeri, LOW);
digitalWrite(solgeri, LOW);
itsONled[4] = 0;
} else {
digitalWrite(sagileri,HIGH);
digitalWrite(solileri, LOW);
digitalWrite(saggeri,  LOW);
digitalWrite(solgeri, HIGH);
itsONled[4] = 1;
}
break;


}
Serial.println(value);
irrecv.resume();

}


}
