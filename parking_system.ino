//Aurdino Code
int lastS1 = HIGH;
int lastS2 = HIGH;
int lastS3 = HIGH;

void setup() {
  Serial.begin(9600);

  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
}

void loop() {

  int s1 = digitalRead(2);
  int s2 = digitalRead(3);
  int s3 = digitalRead(4);

  // ✅ SEND ONLY IF CHANGE DETECTED
  if (s1 != lastS1 || s2 != lastS2 || s3 != lastS3) {

    Serial.print("{\"slot1\":\"");
    Serial.print(s1 == LOW ? "Occupied" : "Empty");

    Serial.print("\",\"slot2\":\"");
    Serial.print(s2 == LOW ? "Occupied" : "Empty");

    Serial.print("\",\"slot3\":\"");
    Serial.print(s3 == LOW ? "Occupied" : "Empty");

    Serial.println("\"}");

    // update last values
    lastS1 = s1;
    lastS2 = s2;
    lastS3 = s3;
  }

  delay(100);  // small delay
}