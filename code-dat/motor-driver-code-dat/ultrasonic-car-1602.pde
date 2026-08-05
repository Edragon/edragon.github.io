#include <IRremote.h>  
#include <Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//***********************定義馬達腳位*************************
int MotorRight1=6;
int MotorRight2=9;
int MotorLeft1=10;
int MotorLeft2=11;
int counter=0;
const int irReceiverPin = 3; //紅外線接收器 OUTPUT 訊號接在 pin 2

//***********************設定所偵測到的IRcode*************************
long IRfront= 0x00FF629D;        //前進碼
long IRback=0x00FFA857;         //後退
long IRturnright=0x00FF22DD;    //右轉
long IRturnleft= 0x00FFC23D;     //左轉
long IRstop=0x00FF02FD;         //停止
long IRAutorun=0x00FF6897;      //超音波自走模式
long IRturnsmallleft= 0x00FFB04F; 
IRrecv irrecv(irReceiverPin);  // 定義 IRrecv 物件來接收紅外線訊號
decode_results results;     
//*************************定義超音波腳位******************************
int inputPin =A0 ; // 定義超音波信號接收腳位rx
int outputPin =A1; // 定義超音波信號發射腳位'tx
int Fspeedd = 0; // 前方距離
int Rspeedd = 0; // 右方距離
int Lspeedd = 0; // 左方距離
int directionn = 0; // 前=8 後=2 左=4 右=6 
Servo myservo; // 設 myservo
int delay_time = 250; // 伺服馬達轉向後的穩定時間
int Fgo = 8; // 前進
int Rgo = 6; // 右轉
int Lgo = 4; // 左轉
int Bgo = 2; // 倒車
//********************************************************************(SETUP)
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
void setup()
{  
  Serial.begin(9600);
  pinMode(MotorRight1, OUTPUT);  // 腳位 8 (PWM)
  pinMode(MotorRight2, OUTPUT);  // 腳位 9 (PWM)
  pinMode(MotorLeft1,  OUTPUT);  // 腳位 10 (PWM) 
  pinMode(MotorLeft2,  OUTPUT);  // 腳位 11 (PWM)
  irrecv.enableIRIn();     // 啟動紅外線解碼
  digitalWrite(3,HIGH);
  pinMode(inputPin, INPUT); // 定義超音波輸入腳位
  pinMode(outputPin, OUTPUT); // 定義超音波輸出腳位 
  myservo.attach(5); // 定義伺服馬達輸出第5腳位(PWM)
  lcd.init();   // initialize the lcd 
  lcd.init();
 // Print a message to the LCD.
  lcd.backlight();



 }
//******************************************************************(Void)
void advance(int a) // 前進
{
        digitalWrite(MotorRight1,LOW);
        digitalWrite(MotorRight2,HIGH);
        digitalWrite(MotorLeft1,LOW);
        digitalWrite(MotorLeft2,HIGH);
        delay(a * 100); 
}
void right(int b) //右轉(單輪)
{
       digitalWrite(MotorLeft1,LOW);
       digitalWrite(MotorLeft2,HIGH);
       digitalWrite(MotorRight1,LOW);
       digitalWrite(MotorRight2,LOW);
       delay(b * 100);
}
void left(int c) //左轉(單輪)
{
      digitalWrite(MotorRight1,LOW);
      digitalWrite(MotorRight2,HIGH);
      digitalWrite(MotorLeft1,LOW);
      digitalWrite(MotorLeft2,LOW);
      delay(c * 100);
}
void turnR(int d) //右轉(雙輪)
{
      digitalWrite(MotorRight1,HIGH);
      digitalWrite(MotorRight2,LOW);
      digitalWrite(MotorLeft1,LOW);
      digitalWrite(MotorLeft2,HIGH);
      delay(d * 100);
}
void turnL(int e) //左轉(雙輪)
{
      digitalWrite(MotorRight1,LOW);
      digitalWrite(MotorRight2,HIGH);
      digitalWrite(MotorLeft1,HIGH);
      digitalWrite(MotorLeft2,LOW);
      delay(e * 100);
} 
void stopp(int f) //停止
{
     digitalWrite(MotorRight1,LOW);
     digitalWrite(MotorRight2,LOW);
     digitalWrite(MotorLeft1,LOW);
     digitalWrite(MotorLeft2,LOW);
     delay(f * 100);
}
void back(int g) //後退
{
        digitalWrite(MotorRight1,HIGH);
        digitalWrite(MotorRight2,LOW);
        digitalWrite(MotorLeft1,HIGH);
        digitalWrite(MotorLeft2,LOW);;
        delay(g * 100); 
}
void detection() //測量3個角度(前.左.右)
{ 
    int delay_time = 250; // 伺服馬達轉向後的穩定時間
    ask_pin_F(); // 讀取前方距離

    if(Fspeedd < 10) // 假如前方距離小於10公分
   {
      stopp(1); // 清除輸出資料 
      back(2); // 後退 0.2秒
      

   }
    if(Fspeedd < 25) // 假如前方距離小於25公分
   {
      stopp(1); // 清除輸出資料 
      ask_pin_L(); // 讀取左方距離
      delay(delay_time); // 等待伺服馬達穩定
      ask_pin_R(); // 讀取右方距離 
      delay(delay_time); // 等待伺服馬達穩定 

      if(Lspeedd > Rspeedd) //假如 左邊距離大於右邊距離
     {
        directionn = Lgo; //向左走
     }

      if(Lspeedd <= Rspeedd) //假如 左邊距離小於或等於右邊距離
      {
        directionn = Rgo; //向右走
      } 

      if (Lspeedd < 15 && Rspeedd < 15) //假如 左邊距離和右邊距離皆小於10公分
     {
        directionn = Bgo; //向後走 
      } 
    }
    else //加如前方大於25公分 
   {
      directionn = Fgo; //向前走 
   }
}   
//*********************************************************************************
void ask_pin_F() // 量出前方距離 
{
myservo.write(90);
digitalWrite(outputPin, LOW); // 讓超聲波發射低電壓2μs
delayMicroseconds(2);
digitalWrite(outputPin, HIGH); // 讓超聲波發射高電壓10μs，這裡至少是10μs
delayMicroseconds(10);
digitalWrite(outputPin, LOW); // 維持超聲波發射低電壓
float Fdistance = pulseIn(inputPin, HIGH); // 讀差相差時間
Fdistance= Fdistance/5.8/10; // 將時間轉為距離距离（單位：公分）

Fspeedd = Fdistance; // 將距離 讀入Fspeedd(前速)
} 
//********************************************************************************
void ask_pin_L() // 量出左邊距離 
{
myservo.write(177);
delay(delay_time);
digitalWrite(outputPin, LOW); // 讓超聲波發射低電壓2μs
delayMicroseconds(2);
digitalWrite(outputPin, HIGH); // 讓超聲波發射高電壓10μs，這裡至少是10μs
delayMicroseconds(10);
digitalWrite(outputPin, LOW); // 維持超聲波發射低電壓
float Ldistance = pulseIn(inputPin, HIGH); // 讀差相差時間
Ldistance= Ldistance/5.8/10; // 將時間轉為距離距离（單位：公分）

Lspeedd = Ldistance; // 將距離 讀入Lspeedd(左速)
} 
//******************************************************************************
void ask_pin_R() // 量出右邊距離 
{
myservo.write(5);
delay(delay_time);
digitalWrite(outputPin, LOW); // 讓超聲波發射低電壓2μs
delayMicroseconds(2);
digitalWrite(outputPin, HIGH); // 讓超聲波發射高電壓10μs，這裡至少是10μs
delayMicroseconds(10);
digitalWrite(outputPin, LOW); // 維持超聲波發射低電壓
float Rdistance = pulseIn(inputPin, HIGH); // 讀差相差時間
Rdistance= Rdistance/5.8/10; // 將時間轉為距離距离（單位：公分）

Rspeedd = Rdistance; // 將距離 讀入Rspeedd(右速)
} 
//******************************************************************************(LOOP)
void loop() 
{
     
//***************************************************************************正常遙控模式      
  if (irrecv.decode(&results)) 
    {         // 解碼成功，收到一組紅外線訊號
/***********************************************************************/
      if (results.value == IRfront)//前進
       {
       
        lcd.setCursor(0,0);
        lcd.print(" IR mode");
        lcd.setCursor(0,1);
        lcd.print("  advance ");
        advance(20);//前進
       }
/***********************************************************************/ 
      if (results.value ==  IRback)//後退
       {
        
        lcd.setCursor(0,0);
        lcd.print(" IR mode");
        lcd.setCursor(0,1);
        lcd.print("  back ");
        back(20);//後退
       }
/***********************************************************************/
      if (results.value == IRturnright)//右轉
      {
      
        lcd.setCursor(0,0);
        lcd.print(" IR mode");
        lcd.setCursor(0,1);
        lcd.print("  right ");
        right(10); // 右轉
         
      }
/***********************************************************************/
     if (results.value == IRturnleft)//左轉
     {
     
        lcd.setCursor(0,0);
        lcd.print(" IR mode");
        lcd.setCursor(0,1);
        lcd.print(" left ");
        left(10); // 左轉);
     }
/***********************************************************************/    
    if (results.value == IRstop)//停止
   {
       lcd.setCursor(0,0);
       lcd.print(" IR mode");
       lcd.setCursor(0,1);
       lcd.print(" stop ");
     digitalWrite(MotorRight1,LOW);
     digitalWrite(MotorRight2,LOW);
     digitalWrite(MotorLeft1,LOW);
     digitalWrite(MotorLeft2,LOW);
    
     
    }

//***********************************************************************超音波自走模式
 if (results.value ==IRAutorun )
      {
           while(IRAutorun)
        {
            myservo.write(90); //讓伺服馬達回歸 預備位置 準備下一次的測量
            detection(); //測量角度 並且判斷要往哪一方向移動
             if(directionn == 8) //假如directionn(方向) = 8(前進) 
            { 
              if (irrecv.decode(&results))
           {
             irrecv.resume(); 
             Serial.println(results.value,HEX);
             if(results.value ==IRstop)
             { 
               digitalWrite(MotorRight1,LOW); 
               digitalWrite(MotorRight2,LOW);
               digitalWrite(MotorLeft1,LOW);
               digitalWrite(MotorLeft2,LOW);
               break;
             }
           }
                results.value=0;
                
               
                lcd.setCursor(0,0);
                lcd.print(" aoto mode");
                lcd.setCursor(0,1);
                lcd.print(" Advance ");
                advance(1); // 正常前進 
            }
           if(directionn == 2) //假如directionn(方向) = 2(倒車) 
          {
            if (irrecv.decode(&results))
           {
             irrecv.resume(); 
             Serial.println(results.value,HEX);
             if(results.value ==IRstop)
             { 
               digitalWrite(MotorRight1,LOW); 
               digitalWrite(MotorRight2,LOW);
               digitalWrite(MotorLeft1,LOW);
               digitalWrite(MotorLeft2,LOW);
               break;
             }
           }
              results.value=0;
              
            
               lcd.setCursor(0,0);
                lcd.print(" aoto mode");
                lcd.setCursor(0,1);
                lcd.print(" Reverse ");
                back(8); // 倒退(車)
              turnL(3); //些微向左方移動(防止卡在死巷裡)
          }
            if(directionn == 6) //假如directionn(方向) = 6(右轉) 
          {
           if (irrecv.decode(&results))
           {
              irrecv.resume(); 
              Serial.println(results.value,HEX);
             if(results.value ==IRstop)
             { 
               digitalWrite(MotorRight1,LOW); 
               digitalWrite(MotorRight2,LOW);
               digitalWrite(MotorLeft1,LOW);
               digitalWrite(MotorLeft2,LOW);
               break;
             }
           }
             results.value=0;
               
            
               lcd.setCursor(0,0);
                lcd.print(" aoto mode");
                lcd.setCursor(0,1);
                lcd.print(" Right ");
                 back(1); 
               turnR(3); // 右轉
          }
            if(directionn == 4) //假如directionn(方向) = 4(左轉) 
          { 
             if (irrecv.decode(&results))
           {
             irrecv.resume(); 
             Serial.println(results.value,HEX);
             if(results.value ==IRstop)
             { 
               digitalWrite(MotorRight1,LOW); 
               digitalWrite(MotorRight2,LOW);
               digitalWrite(MotorLeft1,LOW);
               digitalWrite(MotorLeft2,LOW);
               break;
             }
           }
                results.value=0;
                
                 lcd.setCursor(0,0);
                lcd.print(" aoto mode");
                lcd.setCursor(0,1);
                lcd.print(" Left ");
                back(1); 
                turnL(3); // 左轉
            
           } 
            
             if (irrecv.decode(&results))
           {
             irrecv.resume(); 
             Serial.println(results.value,HEX);
             if(results.value ==IRstop)
             { 
               digitalWrite(MotorRight1,LOW); 
               digitalWrite(MotorRight2,LOW);
               digitalWrite(MotorLeft1,LOW);
               digitalWrite(MotorLeft2,LOW);
               break;
             }
           }
         }
               results.value=0;
       }
/***********************************************************************/    
     else
    {
           digitalWrite(MotorRight1,LOW);
           digitalWrite(MotorRight2,LOW);
           digitalWrite(MotorLeft1,LOW);
           digitalWrite(MotorLeft2,LOW);
     }
      

        irrecv.resume();    // 繼續收下一組紅外線訊號        
   }  
}
   
