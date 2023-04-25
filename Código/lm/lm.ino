float temperatura;
void setup() {
  Serial.begin(9600); // Inicia la comunicación serial a 9600 baudios
}

void loop() {
  
  int lectura = (analogRead(A0)+analogRead(A0)+analogRead(A0)+
                  analogRead(A0)+analogRead(A0)+analogRead(A0)+
                  analogRead(A0)+analogRead(A0)+analogRead(A0)+
                  analogRead(A0)
  ) / 10;

  if (lectura < 307){
  Serial.print("Temperatura: ");
    temperatura = (5.0 * lectura * 100) / 1024;

  }else{
    Serial.print("fallo ");
  }
  
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" C");
  Serial.print("Lecctura: ");
  Serial.println(lectura);
  delay(500); // Espera 1 segundo
}