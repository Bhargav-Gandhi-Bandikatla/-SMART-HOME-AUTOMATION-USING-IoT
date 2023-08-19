#include "WiFi.h"
#include "ThingSpeak.h"
WiFiClient client;

int ldr=22,l1=23,hs1=36,hs2=39,motor=34,l2=35,l3=32,fan=33,geezer=1,tv=27,ac=14;
int s1=12,s2=13,s3=15,s4=2,s5=0,s6=4,s7=16,s8=17;

void setup() 

{
  pinMode(ldr,INPUT);
  pinMode(l1,OUTPUT);
  pinMode(hs1,INPUT);
  pinMode(hs2,OUTPUT);
  pinMode(motor,OUTPUT);
  pinMode(l2,OUTPUT);
  pinMode(l3,OUTPUT);
  pinMode(fan,OUTPUT);
  pinMode(geezer,OUTPUT);
  pinMode(tv,OUTPUT);
  pinMode(ac,OUTPUT);
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);
  pinMode(s4,OUTPUT);
  pinMode(s5,OUTPUT);
  pinMode(s6,OUTPUT);
  pinMode(s7,OUTPUT);
  pinMode(s8,OUTPUT);

  Serial.begin(9600);

  connect_wifi();
  Serial.println("connecting to thingspeak cloud");
  ThingSpeak.begin(client);
  delay(300);
  Serial.println("thingspeak cloud Connected");
  delay(500);
}

void loop() 
{
  
 int val_l1=digitalRead(ldr);

 if(val_l1==1 || s1=1)
 {
   Serial.println("light is not available ");
   digitalWrite(l1,1);
 }
 else
 {
  Serial.println("light is available ");
   digitalWrite(l1,0);
 }
 delay(1000);

//***************

//fan

  int fan_status=ThingSpeak.readFloatField(1593454,1,"W231GVSSJ7PV41T8");
  int sta1=ThingSpeak.getLastReadStatus();

  if(sta1==200 || s2=1)
  {
    Serial.print("fan Status from Cloud:");
    Serial.println(fan_status);
    delay(1000); 
   
    if(fan_status==1)
    {
      digitalWrite(fan,HIGH);
    }
    else
      digitalWrite(fan,LOW);
  }
  else
  {
    Serial.println("Error in Reading Data from Cloud");
    delay(500);
  } 

//*****************

//light 2 

  int l2_status=ThingSpeak.readFloatField(1593454,2,"W231GVSSJ7PV41T8");
  int sta2=ThingSpeak.getLastReadStatus();

  if(sta2==200)
  {
    Serial.print("Light 2 Status from Cloud:");
    Serial.println(l2_status);
    delay(1000); 
   
    if(l2_status==1 || s3=1)
    {
      digitalWrite(l2,HIGH);
    }
    else
      digitalWrite(l2,LOW);
  }
  else
  {
    Serial.println("Error in Reading Data from Cloud");
    delay(500);
  }


//*****************
  
//light 3

  int l3_status=ThingSpeak.readFloatField(1593454,3,"W231GVSSJ7PV41T8");
  int sta3=ThingSpeak.getLastReadStatus();

  if(sta3==200)
  {
    Serial.print("Light 3 Status from Cloud:");
    Serial.println(l3_status);
    delay(1000); 
   
    if(l3_status==1 || s4=1)
    {
      digitalWrite(l3,HIGH);
    }
    else
      digitalWrite(l3,LOW);
  }
  else
  {
    Serial.println("Error in Reading Data from Cloud");
    delay(500);
  } 

//******************

//geezer

  int geezer_status=ThingSpeak.readFloatField(1593454,4,"W231GVSSJ7PV41T8");
  int sta4=ThingSpeak.getLastReadStatus();

  if(sta4==200)
  {
    Serial.print("Light Status from Cloud:");
    Serial.println(geezer_status);
    delay(1000); 
   
    if(geezer_status==1 || s5=1)
    {
      digitalWrite(geezer,HIGH);
    }
    else
      digitalWrite(geezer,LOW);
  }
  else
  {
    Serial.println("Error in Reading Data from Cloud");
    delay(500);
  } 

//***************

//tv

  int tv_status=ThingSpeak.readFloatField(1593454,5,"W231GVSSJ7PV41T8");
  int sta5=ThingSpeak.getLastReadStatus();

  if(sta5==200)
  {
    Serial.print("tv Status from Cloud:");
    Serial.println(tv_status);
    delay(1000); 
   
    if(tv_status==1 || s6=1)
    {
      digitalWrite(tv,HIGH);
    }
    else
      digitalWrite(tv,LOW);
  }
  else
  {
    Serial.println("Error in Reading Data from Cloud");
    delay(500);
  } 

//*******************


//ac

  int ac_status=ThingSpeak.readFloatField(1593454,6,"W231GVSSJ7PV41T8");
  int sta6=ThingSpeak.getLastReadStatus();

  if(sta6==200)
  {
    Serial.print("ac Status from Cloud:");
    Serial.println(ac_status);
    delay(1000); 
   
    if(ac_status==1 || s7=1)
    {
      digitalWrite(ac,HIGH);
    }
    else
      digitalWrite(ac,LOW);
  }
  else
  {
    Serial.println("Error in Reading Data from Cloud");
    delay(500);
  } 

//*******************

//motor

  int val1=map(analogRead(hs1),0,4095,100,0);
  Serial.print("value:");
  Serial.println(val1);
  delay(1000);

  if(val1<20 || s8=1)
  {
    Serial.println("Motor ON");
    digitalWrite(motor,HIGH);
  }
  int val2=map(analogRead(hs2),0,4095,100,0);
  Serial.print("value:");
  Serial.println(val2);
  delay(1000);
  if(val2=80)
  {
    Serial.println("Motor OFF");
    digitalWrite(motor,LOW);
  }
}
void connect_wifi()
{
  Serial.println("Connecting to WiFi Network");
  delay(1000);
  WiFi.disconnect();
  delay(300);
  WiFi.begin("QWERTY","12345678");
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println("WiFi Connected");
  Serial.print("IP Address:");
  Serial.println(WiFi.localIP());
  delay(500);
}