int led = 0;
const int pinEntradaAnalogica = A0;
int bits = 0;
 
void setup(){

  pinMode(3, OUTPUT);
  pinMode(A0, INPUT);
  
  Serial.begin(9600);

}

void loop(){
  
    float tempo_respiracao = map(bits, 0, 1023, 500, 4000);
	bits = analogRead (A0)/4;
    analogWrite(led, bits);
  	Serial.println(bits);
  	

  if (bits == 0){
 
   digitalWrite(3, 0);
    
  } 
  
  else {
  
    for (int percentual = 0; percentual <= 100; percentual++) {
      Serial.print("Percentual: ");
      Serial.print(percentual);
      Serial.println("%");
      analogWrite(3, map(percentual, 0, 100, 0, 255)); // Define a intensidade do LED
      delay(tempo_respiracao / 200); // Divide o tempo total de respiração por 200 para obter o tempo de cada incremento
    }
    
    for (int percentual = 100; percentual >= 0; percentual--) {
      Serial.print("Percentual: ");
      Serial.print(percentual);
      Serial.println("%");
      analogWrite(3, map(percentual, 0, 100, 0, 255)); // Define a intensidade do LED
      delay(tempo_respiracao / 100); // Divide o tempo total de respiração por 200 para obter o tempo de cada decremento
    }
  
  }  
  
}