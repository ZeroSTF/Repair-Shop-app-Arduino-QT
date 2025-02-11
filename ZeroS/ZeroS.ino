#include <SPI.h>
#include <MFRC522.h>
 #include <Servo.h>

#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

// Constants
 
Servo monServomoteur;
char data;

void setup() {
  Serial.begin(9600);   // Initialize serial communications with the PC
  while (!Serial);    // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init();   // Init MFRC522
  delay(4);       // Optional delay. Some board do need more time after init to be ready, see Readme
  mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));

  monServomoteur.attach(6);
  monServomoteur.write(20);
  delay(2000);

}

void loop() {
  if (Serial.available())
{
 data=Serial.read();
 if (data=='1')
 {
    monServomoteur.write(120);
   delay(5000);
   monServomoteur.write(20);
 }
}
  
  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    Serial.write('0');
    delay(500);
    return;
  }

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
  delay(500);
    return;
  }
 else 
 {
  Serial.write('1');
  delay(500);
 }


/*monServomoteur.write(120);
   delay(5000);
   monServomoteur.write(20);*/
 
}
