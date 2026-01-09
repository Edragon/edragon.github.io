
# atmega-serial-dat

使用ARV MEGA88单片机，串口中断接收卡号例程序


void Init_Uart (void)     // 初始化波特率， 7.3728M晶振， 9600 8 N 1
{
 UCSR0B = 0x00; 
 UCSR0A = 0x00;
 UCSR0C = 0x06;
 UBRR0L = 0x26; 
 UBRR0H = 0x00; 
 UCSR0B = 0x90;
}

 

#pragma vector = USART_RX_vect           //串口中断 接收卡号。 
__interrupt void Usart_Rxc(void)
{
 char Rx_Char;
 Rx_Char = UDR0; 
 if(Rx_Char == 0X02)    Rx_Length = 0;   //收到数据头，接收计数从0开始
 Rx[Rx_Length] = Rx_Char;  
 Rx_Length ++; 
 if (Rx_Char == 0X03 )              //收到数据尾
       {       
         Comm_Start = 1;              //数据接收完成标志位  
         cbi(UCSR0B,RXEN0);         //暂时关闭串口         
       }
}

 

void main (void)
{
  while(1)
       {
            if (Comm_Start == 1)             //主程序判断 如果收到完整卡号
                {  
                   Comm_Start = 0;   
                   sbi(UCSR0B,RXEN0);       //打开串口接收                   
                   LED_ON;   
              }
       }
}

 