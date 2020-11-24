/*
 * LABORATORIO 1
 * JERSON BAEZ
 */
#include<LiquidCrystal.h>
#include <Keypad.h>
const byte Fila = 4;
const byte Col = 4;
const byte filaPins[Fila] = { 13, 12, 11, 10 };
const byte columnaPins[Col] = { 9, 8, 7, 6 };

char keys[Fila][Col] = {
  {'7','8','9','a'},
  {'4','5','6','b'},
  {'1','2','3','c'},
  {'*','0','#','j'}
};

Keypad tecladoMatr= Keypad(makeKeymap(keys),filaPins,columnaPins,Fila,Col);

LiquidCrystal lcd(A0,A1,A2,A3,A4,A5); //RS,E,D4,D5,D6,D7
const  String clave1 = "jb961101" ;
const String clave2 = "ca900813";
const String clave3 = "aj881112";
const String clave4 = "ja890109";

const String uno;
const String dos;
const String tres;
const String cuatro;
const int btn=5;

String input_password;

void setup() {
   pinMode(btn,INPUT);
   Serial.begin(9600);
   input_password.reserve (32);
   Serial.println("Laboratorio 1");
   Serial.println("Ingrese la clave: ");
   lcd.begin(16,2);
   lcd.clear();
   lcd.setCursor(2,0);
   lcd.print("Laboratorio 1");

}

void loop() {
  lcd.autoscroll();
  lcd.print(" ");
  delay(300);
  char tecla=tecladoMatr.getKey();
  if(tecla){
    Serial.print(tecla);
    if(tecla=='*'){
      input_password=" ";
    }else 
    if(tecla=='#'){
      if(clave1==input_password || clave2==input_password || clave3==input_password || clave4==input_password){
        if(clave1==input_password){
        uno=clave1;
        Serial.println(" ");
        Serial.println("La clave es correcta");
        lcd.setCursor(1,1);
        lcd.print("Bienvenido Jerson Baez");
        delay(300);
          }else{
            if(clave2==input_password){
              dos=clave2;
              Serial.println(" ");
              Serial.println("La clave es correcta");
              lcd.setCursor(1,1);
              lcd.print("Bienvenido Carlos Arias");
              delay(300);
                }else{
                  if(clave3==input_password){
                    tres=clave3;
                    Serial.println(" ");
                    Serial.println("La clave es correcta");
                    lcd.setCursor(1,1);
                    lcd.print("Bienvenido Andres Juarez");
                    delay(300);
                      }else{
                        if(clave4==input_password){
                          cuatro=clave4;
                          Serial.println(" ");
                          Serial.println("La clave es correcta");
                          lcd.setCursor(1,1);
                          lcd.print("Bienvenido Javier Andrada");
                          delay(300);
                            }
                        }
                      }
                    }
                  }else{
                      Serial.println(" ");
                      Serial.println("Clave incorrecta intente nuevamente");
                      }     
                  input_password="";
                }else{
                  input_password+=tecla;
                }
              }
if(digitalRead(btn)==HIGH){
    delay(300);
    Serial.println(" ");
    Serial.println("Registro de Asistencia:");
    if(uno==clave1){
      Serial.println(" ");
      Serial.println("Jerson Baez ha iniciado sesion"); 
    }else{
      Serial.println(" ");
      Serial.println("Jerson Baez no ha iniciado sesion");
    }
     if(dos==clave2){
      Serial.println("Carlos Arias ha iniciado sesion"); 
    }else{
      Serial.println("Carlos Arias no ha iniciado sesion");
    }
     if(tres==clave3){
      Serial.println("Andres Juarez ha iniciado sesion"); 
    }else{
      Serial.println(" ");
      Serial.println("Andres Juarez no ha iniciado sesion");
    }
     if(cuatro==clave4){
      Serial.println("Javier Andrada ha iniciado sesion"); 
    }else{
      Serial.println("Javier Andrada no ha iniciado sesion");
    }
} 
}
