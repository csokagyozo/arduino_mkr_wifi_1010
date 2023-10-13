const int led1Pin = 12;  
const int pir1Pin = 9;

int led1State = LOW;
int pir1State = LOW;

unsigned long previousMillis = 0;  
const long interval = 1000;  

void setup() {
  pinMode(led1Pin, OUTPUT);
  pinMode(pir1Pin, INPUT);
}

void loop() {

  unsigned long currentMillis = millis(); // fetching the current time in milliseconds
  if (currentMillis - previousMillis >= interval) { // checking if we have waited for 1s
    previousMillis = currentMillis; // store time of current run

    pir1State = digitalRead(pir1Pin);

    if (pir1State == HIGH) {
      led1State = HIGH;
    }
    else
    {
      led1State = LOW;
    }
  
    digitalWrite(led1Pin, led1State);
  }
}