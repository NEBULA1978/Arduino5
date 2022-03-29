#define LED_1_PIN 9
#define LED_2_PIN 10
#define LED_3_PIN 11
#define LED_4_PIN 12

#define POTENTIOMETER_PIN A0

#define BUTTON_PIN 5

unsigned long previousTimeLed1 = millis();
long timeIntervalLed1 = 1000;
int ledState1 = LOW;

unsigned long previousTimeSerialPrintPotentiometer = millis();
long timeIntervalSerialPrint = 2000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
  pinMode(LED_3_PIN, OUTPUT);
  pinMode(LED_4_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime = millis();

  // task 1
  if(currentTime - previousTimeLed1 > timeIntervalLed1) {
    previousTimeLed1 = currentTime;

    if (ledState1 == HIGH) {
      ledState1 = LOW;
    }
    else {
      ledState1 = HIGH;
    }

    digitalWrite(LED_1_PIN, ledState1);
  }

  // task 2
  if (Serial.available()) {
    int userInput = Serial.parseInt();
    if (userInput >= 0 && userInput < 256) {
      analogWrite(LED_2_PIN, userInput);
    }
  }

  // task 3
  if (digitalRead(BUTTON_PIN) == HIGH) {
     digitalWrite(LED_3_PIN, HIGH);
  }
  else {
    digitalWrite(LED_3_PIN, LOW);
  }

  // task 4
  int potentiometerValue = analogRead(POTENTIOMETER_PIN);
  if (potentiometerValue > 512) {
    digitalWrite(LED_4_PIN, HIGH);
  }
  else {
    digitalWrite(LED_4_PIN, LOW);
  }

  // task 5
  if (currentTime - previousTimeSerialPrintPotentiometer > timeIntervalSerialPrint) {
    previousTimeSerialPrintPotentiometer = currentTime;
    Serial.print("Value : ");
    Serial.println(potentiometerValue);
  }
}

/*dfdfff
ódigo de configuración
#define LED_1_PIN 9
#define LED_2_PIN 10
#define LED_3_PIN 11
#define LED_4_PIN 12

#define POTENTIOMETER_PIN A0

#define BUTTON_PIN 5

unsigned long previousTimeLed1 = millis();
long timeIntervalLed1 = 1000;
int ledState1 = LOW;

unsigned long previousTimeSerialPrintPotentiometer = millis();
long timeIntervalSerialPrint = 2000;
Para mayor claridad, hemos usado algunas #define para usar nombres en lugar de números para todos los pines de hardware. También hemos declarado algunas variables para llevar la cuenta del tiempo.

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
  pinMode(LED_3_PIN, OUTPUT);
  pinMode(LED_4_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}
Como sabéis, la función setup() se llama primero en Arduino. Aquí sólo inicializamos la comunicación en serie y establecemos el modo correcto para los pines digitales (los pines analógicos no requieren una configuración, ya que se establecen automáticamente como pines de entrada).

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime = millis();
Y… ¡saltamos justo en la función loop()! Esta función será llamada una y otra vez, durante todo el tiempo que dure tu programa.

Lo primero que hacemos aquí es obtener el tiempo actual con millis(). Esto es muy importante. Para la mayoría de las subtareas del programa, usaremos algunas técnicas de seguimiento del tiempo para desencadenar una acción, y así evitaremos usar la función delay().

Tarea 1: Parpadear el LED 1 cada segundo
// task 1
if(currentTime - previousTimeLed1 > timeIntervalLed1) {
previousTimeLed1 = currentTime;
if (ledState1 == HIGH) {
ledState1 = LOW;
}
else {
ledState1 = HIGH;
}
digitalWrite(LED_1_PIN, ledState1);
}
Aquí calculamos la duración entre la hora actual y la última vez que disparamos el LED 1. Si la duración es mayor que el intervalo que hemos establecido previamente (1 segundo aquí), ¡podemos realmente hacer la acción!

Observa que cuando entramos en el bloque if, fijamos la hora anterior como la hora actual. De esta manera, le decimos al programa : “no vuelvas aquí antes de que haya pasado el siguiente intervalo de tiempo”.

El uso de esta estructura de código es bastante común en Arduino. Si no estás familiarizado con esyo, tómate el tiempo de escribir el código y prueba algunos ejemplos por ti mismo. Una vez que entiendas como funciona, lo usarás en todos tus programas de Arduino.

Tarea 2: Leer la entrada de usuario del Serial (número entre 0 y 255) y escribir los datos en el LED 2
// task 2
if (Serial.available()) {
  int userInput = Serial.parseInt();
  if (userInput >= 0 && userInput < 256) {
    analogWrite(LED_2_PIN, userInput);
  }
}
 

Necesitamos “escuchar” el Serial para poder obtener la entrada del usuario. En lugar de bloquear, bueno, sólo llamamos al método Serial.available() cada vez que estamos en la función principal loop().

Como todos los demás bloques de código son bastante pequeños y rápidos, podemos esperar que el Serial sea monitoreado con bastante frecuencia. De esta manera, estamos seguros de que no nos perdemos ningún dato, mientras realizamos cualquier otra acción en el lateral.

Tarea 3: Encender el LED 3 si se presiona el botón

 

// task 3
if (digitalRead(BUTTON_PIN) == HIGH) {
   digitalWrite(LED_3_PIN, HIGH);
}
else {
  digitalWrite(LED_3_PIN, LOW);
}
Este es bastante sencillo. Sólo monitoreamos el botón cada vez que ejecutamos la función loop() (Este código podría ser mejorado con una función debounce).

Tarea 4: Encender el LED 4 si el valor del potenciómetro es mayor de 512
// task 4
int potentiometerValue = analogRead(POTENTIOMETER_PIN);
if (potentiometerValue > 512) {
  digitalWrite(LED_4_PIN, HIGH);
}
else {
  digitalWrite(LED_4_PIN, LOW);
}
Igual que para el botón, sólo leemos el valor y actualizamos un LED dependiendo de ese valor. Obsérvese que usamos analogRead() para el potenciómetro, y el valor que obtenemos está entre 0 y 1024 (el convertidor analógico de Arduino tiene una resolución de 10 bits, y 2^10 = 1024).

Tarea 5: Imprimir el valor del potenciómetro vía Serial cada 2 segundos
// task 5
if (currentTime - previousTimeSerialPrintPotentiometer > timeIntervalSerialPrint) {
  previousTimeSerialPrintPotentiometer = currentTime;
  Serial.print("Value : ");
  Serial.println(potentiometerValue);
}
Al igual que en la tarea 1, calculamos la diferencia de tiempo (duración) para comprobar si podemos ejecutar la acción o no. Esta es una buena alternativa a la función delay().

Y aquí, en lugar de disparar un LED, sólo enviamos un valor con comunicación en serie.

Bueno, parece que todo el código está corriendo muy rápido, y si construyes este circuito y ejecutas este programa, tendrás una verdadera sensación multitarea.

La multitarea finalmente no es tan difícil
*/
