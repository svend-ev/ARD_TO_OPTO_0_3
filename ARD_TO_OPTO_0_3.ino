/*
  Snak med Robin om globale og lokale variable, 
  Globale variable fungerer i alle metoder og funktioner i hele programmet.
  (pladskrævende) 
  Vokale variable fungerer kun i den enkelte metode og funktion.
  
  Mulighed for at aflæse den enkelte pinn:
 
  in void setup();    :
  pinMode(7, OUTPUT)
  in void loop();     :
  digitalWrite(7, HIGH);
  boolean pin7State = digitalRead(7);

  HW
  Pover 
  Sort == GND
  Rød  == 5v
  
  Data
  Grå    ==  D2
  Lilla  ==  D3
  Blå    ==  D4
  Grøn   ==  D5

moget endret
*/



#include <SoftwareSerial.h>
char input= 0;
int x;

void setup() {
  DDRD =B11111110;
  Serial.begin(9600);
  delay(1000);
  Serial.println("\n\tRelay shield sample code");
  Serial.println("\tPress 1-4 to control the state of the relay");
  Serial.println("\tThis sample will cycle each of the relays once, ");
  Serial.println("\tPress 0 to control the state of the all the relays."); 
  Serial.println("\tAfter start of 'relay shield program' all relays is on.");
  Serial.println ("\tthen wait for your input");


  PORTD=B00000100; //address for Relay 1 (Digital pin 2)
  delay(250);
  PORTD=B00001100; //address for Relay 2 (Digital pin 3)
  delay(250);
  PORTD=B00011100; //address for Relay 3 (Digital pin 4)
  delay(250);
  PORTD=B00111100; //address for Relay 4 (Digital pin 5)
  delay(250);
  PORTD=B00000000; //Set all relays to off position.
  delay(250);
  

  Serial.println("\n\twaiting for input:");
}

void loop() 
{

  if (Serial.available() > 0) 
  {
    input= Serial.read();
    // Serial.print("\n\tread:  "); Serial.print (input);Serial.print ("  from 'Serial Monitor'");
    if(input =='1')
    {
      skift();
      // x=(bitRead(PORTD,2));
      // x=!x;
      // bitWrite(PORTD,2,x);
      // udskriv (input, x );
    }  

    else if (input =='2')
    {
      skift();
      // x=(bitRead(PORTD,3));
      // x=!x;
      // bitWrite(PORTD,3,x);
      // udskriv ();      
    } 

    else if (input =='3')
    {
      skift();
      // x=(bitRead(PORTD,4));
      // x=!x;
      // bitWrite(PORTD,4,x);
      // udskriv ();      
    }

    else if (input =='4')
    {
      skift();
      // x=(bitRead(PORTD,5));
      // x=!x;
      // bitWrite(PORTD,5,x);
      // udskriv ();
    }
    
    else if (input =='0')
    {
      // for (int i = 2; i  <= 5; i++)
      // {
      x=(bitRead(PORTD,2));
      x=!x;
      bitWrite(PORTD,2,x);
      x=(bitRead(PORTD,3));
      x=!x;
      bitWrite(PORTD,3,x);
      x=(bitRead(PORTD,4));
      x=!x;
      bitWrite(PORTD,4,x);
      x=(bitRead(PORTD,5));
      x=!x;
      bitWrite(PORTD,5,x);
      // }
      udskriv1 ();
    }  

    else
    {
      Serial.print("\n\t");
      Serial.print(input);
      Serial.println("\tIs an invalid entry, please press 1,2,3, or 4");
    }
  }
}

int udskriv()
{
  if (x == 1)
  {
    Serial.print ("\n\tRelay:  ");
    Serial.print (input);
    Serial.print (" slukkes \n\tLED nr: ");  
    // Serial.print (input); 
    // Serial.print ("  bliver slukket\n");
  } 
  else
  {
    Serial.print ("\n\tRelay:  ");
    Serial.print (input);
    Serial.print (" taendes \n\tLED nr: ");
    // Serial.print (input); 
    // Serial.print ("  bliver taendt\n");
  }
}

int udskriv1 ()
{
  if (x == 1)
 {
    Serial.print ("\n\t");
    Serial.print (input);
    Serial.print ("\n\tRelay : 1, 2, 3, 4 afbrydes\n");
    // Serial.print ("\tLED nr: 1, 2, 3, 4 slukkes\n");
 }
else
 {
    Serial.print ("\n\t");
    Serial.print (input);
    Serial.print ("\n\tRelay : 1, 2, 3, 4 taendes\n");
    // Serial.print ("\tLED nr: 1, 2, 3, 4 taendes\n");
 }
}

int skift()
{
      x=(bitRead(PORTD,(input+1)));
      // Serial.print("\n\tX er sat til: " );   //   remmes senere
      // Serial.print( x );                  //   remmes senere
      // Serial.print("\n");                //   remmes senere
      // Serial.print("\tinput er sat til: " );   //   remmes senere
      // Serial.print( input );                  //   remmes senere
      // Serial.print("\n");                    //   remmes senere
      x=!x;
      // Serial.print("\tX saettes til: " );   //   remmes senere
      // Serial.print( x );                      //   remmes senere
      // Serial.print("\n");                    //   remmes senere
      bitWrite(PORTD,(input+1),x);
      udskriv ();
}

// int blink1 ()
// {
//  void loop ()
//  {  
//    digitalWrite ( 13, HIGH);      // set the LED on.
//    delay(500);                  // wait for a ½ second.
//    digitalWrite (13, LOW);        // set the LED off.
//    delay (500);                  // wait for a ½ second.
//  }
// }


