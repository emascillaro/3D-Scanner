int IR_read = A0; // analog pin used to read IR sensor
int counter = 0;
void setup() {
  // setup serial output and pin input 
  Serial.begin(9600);
  pinMode(IR_read, INPUT);

}

void loop() {
  counter += 1;
  // print sensor reading every second
  Serial.print(analogRead(IR_read));
  if(counter%5 == 0){
    Serial.println();
  }
  delay(1000);

}
