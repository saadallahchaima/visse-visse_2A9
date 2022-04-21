#include <Servo.h>
#include <SPI.h>
#include <Wire.h> 
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4); // set the LCD address to 0x27 for a 16 chars and 2 line display

const byte bonUID[4] = {134, 198, 137, 33};
#define PIN_LED 7 
#define Servo_PIN 4
#define Buzzer 6 
int x; 
#define pas  40 
const int pinRST = 9; // pin RST du module RC522
const int pinSDA = 10; // pin SDA du module RC522
MFRC522 rfid(pinSDA, pinRST);
char data;
char datar;
char  datam ;// variable contenant le caractère lu
Servo monServomoteur;
// Pin to which an 8 Ohm speaker is connected (use a 150 - 220 Ohm resistor)
#define speakerPin 3

// Tempo (beats per minute)
#define bpm 96

// Gap between notes. This is expressed as percentage of time between 2 beats.
#define noteGapPercentage 10

/*
 * 2D array containing the notes to be played
 * A note comprises of two values:
 *  * The first value determines the frequency of the note.
 *    This is expressed as the number of a key on an 88-key piano (1 - 88)
 *    A number outside this range can be used (e.g. 0) to create a gap 
 *  * The second value determines the duration:
 *    * 1 represents a whole note (spans 4 beats)
 *    * 2 represents a half note (spans 2 beats)
 *    * 4 represents a quarter note (spans 1 beat)
 *    * 8 represents an eighth note (spans 0.5 beat)
 *      etc.
 */
uint8_t notes[][2] = {
  {35,4}, {35,4}, {42,4}, {42,4}, {44,4}, {44,4}, {42,2},
  {40,4}, {40,4}, {39,4}, {39,4}, {37,4}, {37,4}, {35,2},
  {42,4}, {42,4}, {40,4}, {40,4}, {39,4}, {39,4}, {37,2},
  {42,4}, {42,4}, {40,4}, {40,4}, {39,4}, {39,4}, {37,2},
  {35,4}, {35,4}, {42,4}, {42,4}, {44,4}, {44,4}, {42,2},
  {40,4}, {40,4}, {39,4}, {39,4}, {37,4}, {37,4}, {35,2}
};

// Time between two beats in microseconds (equal to length of a quarter note)
#define beatDuration (60.0 / bpm) * 1000000L

// Time of the gap between two notes in microseconds
#define noteGap beatDuration * (noteGapPercentage / 100.0)

void setup() {
 monServomoteur.attach(Servo_PIN);
  digitalWrite(PIN_LED,LOW);
  pinMode(Buzzer,OUTPUT);
   digitalWrite(Buzzer,LOW);
  pinMode(PIN_LED,OUTPUT);
  Serial.begin(9600); //Permet d'initialiser le moniteur série à 9600 bauds 
   lcd.init();
  lcd.backlight();
  SPI.begin();
rfid.PCD_Init();
  lcd.setCursor(1,0);
              lcd.print("Hello Agent");
              delay(1000);
              
  lcd.clear();
   lcd.setCursor(1,0);
              lcd.print("Anything For");
              lcd.setCursor(0,1);
              lcd.print(" Today");
              pinMode(speakerPin, OUTPUT);

  x=0;

}




/*
 * Plays an individual note.
 * 
 * keyNumber - The key number (1 - 88)
 * noteType - The note type (1, 2, 4, 8, etc.)
 */
void playNote(uint8_t keyNumber, uint8_t noteType) {
  long halfPeriod = getPeriodForKey(keyNumber) / 2;
  long noteDuration = beatDuration * (4.0 / noteType);
  long elapsed = 0;

  // While we have a note to play
  while(halfPeriod > 0 && elapsed < (noteDuration - noteGap)) {
    // Set speakerPin high for half of the period
    digitalWrite(speakerPin, HIGH);
    wait(halfPeriod);

    // Set speakerPin low for half of the period
    digitalWrite(speakerPin, LOW);
    wait(halfPeriod);

    // Update the amount of time that has elapsed
    elapsed += halfPeriod * 2;
  }

  /*
   * Gap between notes. Calculated using 'elapsed' to minimise timing errors
   * and ensure that the correct gap occurs whenever getPeriodForKey() returns
   * zero. 
   */
  wait(noteDuration - elapsed);
}

/*
 * Returns the period for a key or zero for key numbers outside the range of 1 -
 * 88.
 * 
 * keyNumber - The key number (1 - 88)
 */
long getPeriodForKey(uint8_t keyNumber) {
  // If the key is between 1 and 88
  if(keyNumber >= 1 && keyNumber <= 88) {
    // Return the period (one second divided by the frequency of the key)
    return 1000000L / (pow(2.0, (keyNumber - 49.0) / 12.0) * 440.0);
  }

  // Otherwise return zero
  return 0;
}

/*
 * Delay for a number of microseconds. This is necessary because
 * delayMicroseconds() has an upper limit.
 * 
 * us - The delay in microseconds
 */
void wait(long us) {
  // First delay for the number of whole milliseconds using delay()
  delay(us / 1000);
  // Then delay for the remainder of microseconds using delayMicroseconds()
  delayMicroseconds(us % 1000);
}





void loop() {
  
      int refus = 0; // quand cette variable n'est pas nulle, c'est que le code est refusé
if (rfid.PICC_IsNewCardPresent()) // on a dédecté un tag
{
 
if (rfid.PICC_ReadCardSerial()) // on a lu avec succès son contenu
{
for (byte i = 0; i < rfid.uid.size; i++) // comparaison avec le bon UID
{
if (rfid.uid.uidByte[i] != bonUID[i]) {
refus++;
}
}
if (Serial.available()){
  //Si un message a été reçu  faire ceci
    data=Serial.read();  
     if(data=='1' ) //si le caractère lu est égale à 1
    {
      lcd.clear();
if (refus == 0) // UID accepté
{
  
   Serial.write('2');
      
       
      lcd.clear();
      delay(7000);
      digitalWrite(Buzzer,HIGH);
      
       lcd.print("Access Succeed");
       lcd.setCursor(0,1);
       
       lcd.print("**************");
       lcd.setCursor(2,1);
             delay(250);
      digitalWrite(Buzzer,LOW);
      digitalWrite(PIN_LED,HIGH);
      delay(3000);
      lcd.clear();
     lcd.print("Animation **** ");
               lcd.setCursor(1,1);
              lcd.print("**** Succeed");
              lcd.setCursor(2,1);
               delay(3000);
  digitalWrite(PIN_LED,LOW);
 delay(2000);
 delay(2000);
lcd.clear();
while (1)
  {
    datam=Serial.read();
   if(datam=='7') //si le caractère reçu est égale à 2
     {
      lcd.clear();
      lcd.setCursor(4,0);
      lcd.print("Moteur");
              lcd.setCursor(2,1);
              lcd.print("**************");
              delay(2000);
              
        for (int position = 180; position >= 0; position--) {
    monServomoteur.write(position);
    delay(150);
  }
        
     }  
     else if(datam=='8')
     {lcd.clear();
      lcd.setCursor(4,0);
      lcd.print("Moteur");
              lcd.setCursor(2,1);
              lcd.print("**************");
        for (int position = 180; position >= 0; position--) {
    monServomoteur.write(position);
    delay(150);
  } 
     }
     
      else if(datam=='4')
     {
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("ID : 7777");
              lcd.setCursor(2,1);
              lcd.print("Ash Elarbi");
              delay(500);
       
     }
        else if(datam=='5')
     {
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("ID : 1478");
              lcd.setCursor(2,1);
              lcd.print("Ash Ler");
       delay(500);
     }
     else if(datam=='3')
     {
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("ID : 2569");
              lcd.setCursor(2,1);
              lcd.print("Ff Sada");
       delay(500);
     }
      else if(datam=='6')
     {
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Theme Set");
              lcd.setCursor(2,1);
              lcd.print("Successfully**");
       delay(500);
     }
      else if(datam=='2')
     {
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Good Bye");
              lcd.setCursor(0,1);
              lcd.print("************");
       delay(500);
     }
     else if(datam=='9')
     {
        lcd.clear();
      lcd.setCursor(5,0);
      lcd.print("Piano");
              lcd.setCursor(0,1);
              lcd.print("***************");
      for(int i = 0; i < (sizeof(notes) / sizeof(*notes)); i++) {
    // pass the key number and note type
    playNote(notes[i][0], notes[i][1]);
    
     } 
  }
  }
}
    }
    else {   // UID refusé
 
Serial.write('0');
              delay(2000);
              for(int i=0 ;i <17 ; i++)
              {
                digitalWrite(Buzzer,HIGH);
              digitalWrite(PIN_LED,HIGH);
              delay(200);
              lcd.clear();
               lcd.setCursor(1,0);
               lcd.print("Access  Denied");
           lcd.setCursor(2,1);
              lcd.print("*************");
        digitalWrite(PIN_LED,LOW);
        delay(200);
              }
         digitalWrite(Buzzer,LOW);
   
}  
 }  
   
}
}


}
