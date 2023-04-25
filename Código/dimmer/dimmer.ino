
const int Zero = 2; // Detector de cruce por cero en el pin 2 const 
const int Triac = 3; // Salida del pulso para el triac en el pin 3
boolean state = LOW;

/* Se definen variables para el estado del potenciómetro
y para el cruce por cero */

int Pot = 0;
int Zero_state = 0;
int last_state = 0;

void setup()
{

    // Se define como entrada el pin 2 que detecta el cruce por cero

    pinMode(Zero, INPUT);
    pinMode(Triac, OUTPUT);

    // Se define como salida el pin 3 que mandará el pulso al TRIAC pinMode (Triac, OUTPUT);
}

void loop()
{

    // Se lee la señal del saliente del Optoacoplador

    Zero_state = digitalRead(Zero);

    /* A continuación, mediante la condicionante, se detecta el momento
    en el que existe un cruce por cero y se almacena en la variable "state" */

    if (Zero_state != last_state)
    {
        if (Zero_state == HIGH)
        {
            state = true;
        }
    }
    last_state = Zero_state;

    /* Se lee la señal del potenciómetro que Arduino lo interpreta con valores de 0 a 1023 
    y se hace un mapeo, de tal manera que el 0 equivale a 10000 us y el 1023 equivale a 1000 us.
    Estos valores son de acuerdo a la frecuencia que se trabaja y determinan el retraso de disparo del TRIAC.
    Los valores máximos y mínimos se determinaron haciendo pruebas ya que no es necesario ser muy estrictos. 
    */


//Inicialmente era 10K a 1K, pero entonces lo pasamos a estos valores
    Pot = map(analogRead(A0), 0, 1023, 7600, 10); 
    
    /* A continuación se envía el pulso al TRIAC, el pulso tiene una duración de 10 us. */
    
    if (state == true)
    {
        delayMicroseconds(Pot);
        digitalWrite(Triac, HIGH);
        delayMicroseconds(10);
        digitalWrite(Triac, LOW);
        state = false;
    }
}
