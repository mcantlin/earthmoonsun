#include <LiquidCrystal.h>

#include <AccelStepper.h>
#include <MultiStepper.h>

const int X_STEP_PIN = 54;
const int X_DIR_PIN = 55;
const int X_EN_PIN = 38;

const int Y_STEP_PIN = 60;
const int Y_DIR_PIN = 61;
const int Y_EN_PIN = 56;

const int Z_STEP_PIN = 46;
const int Z_DIR_PIN = 48;
const int Z_EN_PIN = 62;

AccelStepper stepper1(AccelStepper::DRIVER, X_STEP_PIN, X_DIR_PIN); 
AccelStepper stepper2(AccelStepper::DRIVER, Y_STEP_PIN, Y_DIR_PIN); 
AccelStepper stepper3(AccelStepper::DRIVER, Z_STEP_PIN, Z_DIR_PIN);


int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int sDay=1;
int count=1;
long yr = 2017;
long steps;
String calendar="";


LiquidCrystal lcd(8,9,4,5,6,7);


void setup() {
  lcd.begin(16,2);  
  Serial.begin(9600);

  pinMode(X_EN_PIN, OUTPUT);
  pinMode(Y_EN_PIN, OUTPUT);
  pinMode(Z_EN_PIN, OUTPUT);
  
  digitalWrite(X_EN_PIN, LOW);
  digitalWrite(Y_EN_PIN, LOW);
  digitalWrite(Z_EN_PIN, LOW);

  stepper1.setMaxSpeed(5000);
  stepper2.setMaxSpeed(7000);
  stepper3.setMaxSpeed(7000);
  
  stepper1.setSpeed(70);// ==> ~5 second moon cycle ==> needs to be slightly faster
  stepper2.setSpeed(60);// ==> ~62 second year ==> needs to be slightly faster
  stepper3.setSpeed(3000);// ==> ~0.168 second day


  
 
}

void loop() {

  stepper1.runSpeed();
  stepper2.runSpeed();
  stepper3.runSpeed();

  Serial.println(stepper3.currentPosition());
  if (stepper3.currentPosition()%300==0) 
  { 

     date();
  }
  

  
 
}

//jan, march, may, july, august,october, december == 31
//april, june, september, november == 30
//feb == 28 (29 leap year)
void date()
{

   
     if (sDay<=days[count-1])
      {
        String zero="";
        String zero1="";
        String spacer = " / ";
        if (sDay < 10) zero = "0";
        if (count < 10) zero1 = "0";
        calendar = (zero +sDay + spacer + zero1 + count + spacer + yr);

        
        
       /* lcd.print(sDay);
        lcd.print(" / ");
        if (count < 10) lcd.print('0');
        lcd.print(count);
        lcd.print(" / ");
        lcd.print(yr);*/

        lcd.setCursor(0,0);
        lcd.print(calendar);
        sDay++;
        // for 11.8 rps needs to break for .085 seconds
      }
      if (sDay > days[count-1])
      {
        count++;
        sDay=1;
      }
      if (count > 12)
      {
        yr++;
        count=1;
      }
}





/*void printDate()
{
  lcd.setCursor(0,0);
  lcd.print(sDay);
  lcd.print(" / ");
  lcd.print(count);
  lcd.print(" / ");
  lcd.print(yr);

}*/


/*
 * 20 steps per day
 * 560 to 620 steps per month
 * 7300 to 7320 steps per year
  */
