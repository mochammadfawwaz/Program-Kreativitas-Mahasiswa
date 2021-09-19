const int ph_Pin = A0;
float Po = 0;
float pH_step;
int nilai_analog_PH;
double TeganganPH;

// kalibrasi
float PH4 = 0.85;
float PH7 = 1.78;
float PH9 = 2.67;

void setup() {
  // put your setup code here, to run once:
  pinMode(ph_Pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  nilai_analog_PH = analogRead(ph_Pin);
  Serial.print("Nilai ADC pH: ");
  Serial.println(nilai_analog_PH);
  TeganganPH = 5 / 1024.0 * nilai_analog_PH;
  Serial.print("Tegangan: ");
  Serial.println(TeganganPH, 3);

  pH_step = (PH9 - PH7 ) / 3;
  Po = 7.00 + ((PH7 - TeganganPH) / pH_step) + 5;
  Serial.print("Nilai PH cairan: ");
  Serial.println(Po,2);
  delay(500);
  
}
