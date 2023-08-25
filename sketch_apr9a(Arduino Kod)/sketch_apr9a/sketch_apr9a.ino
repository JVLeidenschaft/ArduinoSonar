#include <Servo.h>. //servo motor kutuphanesini dahil ediyoruz

const int trigPin = 10; //sensor trig pinini arduino ustunde 10 olarak tanimladik
const int echoPin = 11; //sensor echo pinini arduino ustunda 11 olarak tanimladik
long duration; //sure degiskenini tanimladik
int distance; //mesafe degiskenini tanimladik
Servo myServo; //servo motor degiskenini tanimladik


void setup() {
  
  pinMode(trigPin, OUTPUT); //trig pinini cikis olarak tanımladik
  pinMode(echoPin, INPUT);  //echo pinini giris olarak tanimladik
  Serial.begin(9600); //serial haberlesmeyi baslattik
  myServo.attach(12); //servo motorun 12. pinde bagli oldugunu gosterdik
}

void loop() { //tekrar

  for(int i=15;i<=165;i++){  // 15 dereceden baslayarak 165 dereceye kadar servo motoru 1 derece olacak sekilde hareket ettiriyoruz
  myServo.write(i); //aci degerini servo motora gonderdik
  delay(30); //servo motorun hareket etmesi icin 30 ms bekliyoruz
  distance = calculateDistance(); //mesafeyi hesapliyoruz calculateDistane() fonksiyonuna giderek
  Serial.print(i); //aciyi yazdiriyoruz
  Serial.print(","); 
  Serial.print(distance); //mesafeyi yazdiriyoruz
  Serial.print(".");
  }

  for(int i=165;i>15;i--){  //yukarida yaptirdigimiz 15 den 165 dereceye olan olayin tam tersini yaptiriyoruz
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  }
}

int calculateDistance(){ //sensore mesafeyi hesaplatiyoruz
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance= duration*0.034/2;
  return distance;

}

