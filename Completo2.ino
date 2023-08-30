#define STEP 10      // pin STEP de A4988 Rotar
#define DIR 11     // pin DIR de A4988 Rotar
#define FCcero 9   //Pin en cero para marcar final de carrera Rotar
#define FCpi 8  //Pin 180 para marcar el final de carrera Rotar
#define reset 12 //Rotar

#define STEPD 4      // pin STEP de A4988 desplazar
#define DIRD 5     // pin DIR de A4988 Desplazar
#define FCceroD 9   //Pin en cero para marcar final de carrera Desplazar
#define FCpiD 8  //Pin 180 para marcar el final de carrera Desplazar
#define resetD 6  //Desplazar

 //Recordar que acá van los valores de 25, 42, 50, 58, 75 o 100  
int restaN;
int posicion;
int iselect;
int select;
int resta;

int restaND;
int posicionD;
int iselectD;
int selectD;
int restaD;
void setup() 
{
  pinMode(STEP, OUTPUT);  // pin 4 como salida
  pinMode(DIR, OUTPUT);   // pin 5 como salida
  pinMode(FCcero, INPUT);  //pin Final de carrera en cero grados
  pinMode(FCpi, INPUT);  //pin Final de carrera en 180 grados
  pinMode(reset, OUTPUT); //pin para encender y apagar el motor

  pinMode(STEPD, OUTPUT);  // Desplazar
  pinMode(DIRD, OUTPUT);   // Desplazar como salida
  pinMode(FCceroD, INPUT);  //pin Final de carrera en cero grados Despazar
  pinMode(FCpiD, INPUT);  //pin Final de carrera en 180 grados
  pinMode(resetD, OUTPUT); //pin para encender y apagar el motor
  
  Serial.begin(9600);

}

void loop() 
{
  if (Serial.available()>0){      
     iselect = Serial.parseInt();
  }
    
  Serial.print("Esto fue lo ingresado por usuario");
  Serial.println(iselect);

  digitalWrite(reset, LOW);
  digitalWrite(resetD, LOW);
  

  
  switch (iselect){
    case 1:
    select=0;
    selectD=0;
    break;
    
    case 2:
    select=25;
    selectD=3300;
    break;

    case 3:
    select=42;
    selectD=0;
    break;

    case 4:
    select=50;
    selectD=6346;
    break;

    case 5:
    select=58;
    selectD=0;
    break;

    case 6:
    select=75;
    selectD=3300;
    break;

    case 7:
    select=100;
    selectD=0;
    break;
    
  }

 int fcCero=digitalRead(FCcero);
 if (fcCero!=LOW){
      posicion=0;
 }
        
int fcPi=digitalRead(FCpi);
if (fcPi!= LOW){
 posicion=100;
}

int fcCeroD=digitalRead(FCceroD);
 if (fcCeroD!=LOW){
      posicionD=0;
 }
        
int fcPiD=digitalRead(FCpiD);
if (fcPiD!= LOW){
 posicionD=6346;
}

Serial.print("Final de carrera 1=  ");
 Serial.println(fcCero);
Serial.print("Final de carrera 2=  ");
Serial.println(fcPi);

Serial.print("Final de carrera 0=  ");
 Serial.println(fcCeroD);
Serial.print("Final de carrera 6346=  ");
Serial.println(fcPiD);


 if (fcPi!=LOW || fcCero!=LOW){
  resta=0;
 
 }else{
    resta=(select-posicion)*5.2*4;
 }
 
 if (fcPiD!=LOW || fcCeroD!=LOW){
  restaD=0;
 
 }else{
    restaD=(selectD-posicionD)*4;
    
 }
  
  
  if (resta ==0){
    digitalWrite(reset, LOW);  
  }else{
    digitalWrite(reset, HIGH); 
  }

  if (restaD ==0){
    digitalWrite(resetD, LOW);  
  }else{
    digitalWrite(resetD, HIGH); 
  }
  
  Serial.print("Esta es la resta");
  Serial.println(resta);

 Serial.print("Este es la posicion actual");
 Serial.println(posicion);
 Serial.print("Esta es la resta desplazamiento");
 Serial.println(restaD);

 Serial.print("Este es la posicion actual desplazamiento");
 Serial.println(posicionD);
 
 delay(3000);

  switch (select){
    case 0: 
      if (resta>0){
        digitalWrite(DIR, LOW);    // gira hacia 180, solo gira 45 grados
        for(int i = 0; i < resta; i++){     // 
          digitalWrite(STEP, HIGH);       // nivel alto
          delay(10);          // por 10 mseg
          digitalWrite(STEP, LOW);        // nivel bajo
          delay(10);
        } 
        posicion=0;
      }
      else if (resta<0){
        digitalWrite(DIR, HIGH);     // gira hacia cero, hasta llegar a 45 grados
        restaN=-resta;
        for(int i = 0; i < restaN; i++){
          digitalWrite(STEP, HIGH); 
          delay(10);
          digitalWrite(STEP, LOW);
          delay(10);
        }
        posicion=0;
      }
      break;
    case 25: 
      if (resta>0){
        digitalWrite(DIR, LOW);    // gira hacia 180, solo gira 45 grados
        for(int i = 0; i < resta; i++){     // 
          digitalWrite(STEP, HIGH);       // nivel alto
          delay(10);          // por 10 mseg
          digitalWrite(STEP, LOW);        // nivel bajo
          delay(10);
        } 
        posicion=25;
      }
      else if (resta<0){
        digitalWrite(DIR, HIGH);     // gira hacia cero, hasta llegar a 45 grados
        restaN=-resta;
        for(int i = 0; i < restaN; i++){
          digitalWrite(STEP, HIGH); 
          delay(10);
          digitalWrite(STEP, LOW);
          delay(10);
        }
        posicion=25;
      }
      break;
    case 42:
      if (resta>0){
          digitalWrite(DIR, LOW);    // gira hacia 180, solo gira 45 grados
          for(int i = 0; i < resta; i++){     // 200 pasos para motor de 0.9 grados de angulo de paso
            digitalWrite(STEP, HIGH);       // nivel alto
            delay(10);          // por 10 mseg
            digitalWrite(STEP, LOW);        // nivel bajo
            delay(10);
          } 
          posicion=42;
        }
        else if (resta<0){
          digitalWrite(DIR, HIGH);     // gira hacia cero, hasta llegar a 45 grados
          restaN=-resta;
          for(int i = 0; i < restaN; i++){
            digitalWrite(STEP, HIGH); 
            delay(10);
            digitalWrite(STEP, LOW);
            delay(10);
          }
          posicion=42;
        }
        break;
     case 50:
      if (resta>0){
          digitalWrite(DIR, LOW);    // gira hacia 180, solo gira 45 grados
          for(int i = 0; i < resta; i++){     // 200 pasos para motor de 0.9 grados de angulo de paso
            digitalWrite(STEP, HIGH);       // nivel alto
            delay(10);          // por 10 mseg
            digitalWrite(STEP, LOW);        // nivel bajo
            delay(10);
          } 
          posicion=50;
        }
        else if (resta<0){
          digitalWrite(DIR, HIGH);     // gira hacia cero, hasta llegar a 45 grados
          restaN=-resta;
          for(int i = 0; i < restaN; i++){
            digitalWrite(STEP, HIGH); 
            delay(10);
            digitalWrite(STEP, LOW);
            delay(10);
          }
          posicion=50;
        }
        break;
     case 58:
      if (resta>0){
          digitalWrite(DIR, LOW);    // gira hacia 180, solo gira 45 grados
          for(int i = 0; i < resta; i++){     // 200 pasos para motor de 0.9 grados de angulo de paso
            digitalWrite(STEP, HIGH);       // nivel alto
            delay(10);          // por 10 mseg
            digitalWrite(STEP, LOW);        // nivel bajo
            delay(10);
          } 
          posicion=58;
        }
        else if (resta<0){
          digitalWrite(DIR, HIGH);     // gira hacia cero, hasta llegar a 45 grados
          restaN=-resta;
          for(int i = 0; i < restaN; i++){
            digitalWrite(STEP, HIGH); 
            delay(10);
            digitalWrite(STEP, LOW);
            delay(10);
          }
          posicion=58;
        }
        break;
     case 75:
      if (resta>0){
          digitalWrite(DIR, LOW);    // gira hacia 180, solo gira 45 grados
          for(int i = 0; i < resta; i++){     // 200 pasos para motor de 0.9 grados de angulo de paso
            digitalWrite(STEP, HIGH);       // nivel alto
            delay(10);          // por 10 mseg
            digitalWrite(STEP, LOW);        // nivel bajo
            delay(10);
          } 
          posicion=75;
        }
        else if (resta<0){
          digitalWrite(DIR, HIGH);     // gira hacia cero, hasta llegar a 45 grados
          restaN=-resta;
          for(int i = 0; i < restaN; i++){
            digitalWrite(STEP, HIGH); 
            delay(10);
            digitalWrite(STEP, LOW);
            delay(10);
          }
          posicion=75;
        }
        break;
     case 100:
      if (resta>0){
          digitalWrite(DIR, LOW);    // gira hacia 180, solo gira 45 grados
          for(int i = 0; i < resta; i++){     // 200 pasos para motor de 0.9 grados de angulo de paso
            digitalWrite(STEP, HIGH);       // nivel alto
            delay(10);          // por 10 mseg
            digitalWrite(STEP, LOW);        // nivel bajo
            delay(10);
          } 
          posicion=100;
        }
        else if (resta<0){
          digitalWrite(DIR, HIGH);     // gira hacia cero, hasta llegar a 45 grados
          restaN=-resta;
          for(int i = 0; i < restaN; i++){
            digitalWrite(STEP, HIGH); 
            delay(10);
            digitalWrite(STEP, LOW);
            delay(10);
          }
          posicion=100;
        }
        break;
  }
  
 delay(2000);
  
 switch (selectD){
    case 0: 
      if (restaD>0){
        digitalWrite(DIRD, LOW);    // gira hacia 180, solo gira 45 grados
        for(int i = 0; i < restaD; i++){     // 
          digitalWrite(STEPD, HIGH);       // nivel alto
          delay(1);          // por 1 mseg
          digitalWrite(STEPD, LOW);        // nivel bajo
          delay(1);
        } 
        posicionD=0;
      }
      else if (restaD<0){
        digitalWrite(DIRD, HIGH);     // gira hacia cero, hasta llegar a 45 grados
        restaND=-restaD;
        for(int i = 0; i < restaND; i++){
          digitalWrite(STEPD, HIGH); 
          delay(1);
          digitalWrite(STEPD, LOW);
          delay(1);
        }
        posicionD=0;
      }
      break;
    case 3300: 
      if (restaD>0){
        digitalWrite(DIRD, LOW);    // gira hacia 180, solo gira 45 grados
        for(int i = 0; i < restaD; i++){     // 
          digitalWrite(STEPD, HIGH);       // nivel alto
          delay(1);          // por 1 mseg
          digitalWrite(STEPD, LOW);        // nivel bajo
          delay(1);
        } 
        posicionD=3300;
      }
      else if (restaD<0){
        digitalWrite(DIRD, HIGH);     // gira hacia cero, hasta llegar a 45 grados
        restaND=-restaD;
        for(int i = 0; i < restaND; i++){
          digitalWrite(STEPD, HIGH); 
          delay(1);
          digitalWrite(STEPD, LOW);
          delay(1);
        }
        posicionD=3300;
      }
      break;
    case 6346:
      if (restaD>0){
          digitalWrite(DIRD, LOW);    // gira hacia 180, solo gira 45 grados
          for(int i = 0; i < restaD; i++){     // 200 pasos para motor de 0.9 grados de angulo de paso
            digitalWrite(STEPD, HIGH);       // nivel alto
            delay(1);          // por 1 mseg
            digitalWrite(STEPD, LOW);        // nivel bajo
            delay(1);
          } 
          posicionD=6346;
        }
        else if (restaD<0){
          digitalWrite(DIRD, HIGH);     // gira hacia cero, hasta llegar a 45 grados
          restaND=-restaD;
          for(int i = 0; i < restaND; i++){
            digitalWrite(STEPD, HIGH); 
            delay(1);
            digitalWrite(STEPD, LOW);
            delay(1);
          }
          posicionD=6346;
        }
        break;
  }

}
