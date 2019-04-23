#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(5, 4);

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
int fingerprintID = 0;
String IDname;

void setup(){
  //Fingerprint sensor module setup
  Serial.begin(9600);
  // set the data rate for the sensor serial port
  finger.begin(57600);
  
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } 
  else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }
}

void loop(){
  fingerprintID = getFingerprintIDez();
  delay(50);
  if(fingerprintID == 1){
    Serial.println("Hallo Iwan Cilibur, Scan Kembali Jari Telunjukmu!!!"); 
    delay(2000);         
  }  
  else if(fingerprintID == 2){
    Serial.println();Serial.println();
    Serial.println("Hallo Iwan Cilibur :)"); 
    Serial.println("Kamu Di Terima!!! Selamat Yaaa Kamu berhasil membuka Pintu HATI ^_^");   
    Serial.println("Assiyapppp :D :D :D");   
    delay(8000);
  }else{
    Serial.println("Tempelkan Jari Telunjukmu Untuk membuka HATI...");
    delay(100);
  }
}

// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;
  
  // found a match!
  Serial.print("Found ID #"); 
  Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); 
  Serial.println(finger.confidence);
  return finger.fingerID; 

  if(p==FINGERPRINT_OK){
    Serial.println("Siapa kamu");
  }
}
