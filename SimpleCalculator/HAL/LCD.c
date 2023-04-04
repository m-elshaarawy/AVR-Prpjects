

#include "LCD.h"

#if  LCD_MODE==_8_BIT

static void LCD_WriteCommand(U8 command){
		DIO_WritePin(RS,LOW);
		DIO_WritePort(LCD_PORT,command);
		DIO_WritePin(EN,HIGH);
		_delay_ms(1);
		DIO_WritePin(EN,LOW);
		_delay_ms(1);
}

static void LCD_WriteData(U8 data){
	DIO_WritePin(RS,HIGH);
	DIO_WritePort(LCD_PORT,data);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

void LCD_Init(void){
	
	_delay_ms(50);
LCD_WriteCommand(0x38); // 2line 5*7
LCD_WriteCommand(0x0c);// cursor ,ox0f,0x0e;
LCD_WriteCommand(0x01);// clear screen
_delay_ms(1);
LCD_WriteCommand(0x06);// increase DDRAM address , no shift
	
	
}

#elif LCD_MODE==_4_BIT

static void LCD_WriteCommand(U8 command){
	//U8 comh=0,coml=0;
	DIO_WritePin(RS,LOW);
	// comh=command&0xf0;
	//PORTA=PORTA&0x0f;
	//PORTA&=comh;
	// no use  DIO_WritePort(LCD_PORT,command);
	DIO_WritePin(D7,READ_BIT(command,7));
	DIO_WritePin(D6,READ_BIT(command,6));
	DIO_WritePin(D5,READ_BIT(command,5));
	DIO_WritePin(D4,READ_BIT(command,4));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	//coml=command<<4;
	//coml=command&0xf0;
	//PORTA=PORTA&0x0f;
	//PORTA&=coml;
	DIO_WritePin(D7,READ_BIT(command,3));
	DIO_WritePin(D6,READ_BIT(command,2));
	DIO_WritePin(D5,READ_BIT(command,1));
	DIO_WritePin(D4,READ_BIT(command,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

static void LCD_WriteData(U8 data){
	DIO_WritePin(RS,HIGH);
	//DIO_WritePort(LCD_PORT,data);
DIO_WritePin(D7,READ_BIT(data,7));
DIO_WritePin(D6,READ_BIT(data,6));
DIO_WritePin(D5,READ_BIT(data,5));
DIO_WritePin(D4,READ_BIT(data,4));
DIO_WritePin(EN,HIGH);
_delay_ms(1);
DIO_WritePin(EN,LOW);
_delay_ms(1);
DIO_WritePin(D7,READ_BIT(data,3));
DIO_WritePin(D6,READ_BIT(data,2));
DIO_WritePin(D5,READ_BIT(data,1));
DIO_WritePin(D4,READ_BIT(data,0));
DIO_WritePin(EN,HIGH);
_delay_ms(1);
DIO_WritePin(EN,LOW);
_delay_ms(1);
}

void LCD_Init(void){
	
	_delay_ms(50);
	LCD_WriteCommand(0x02);
	LCD_WriteCommand(0x28); // 2line 5*7
	LCD_WriteCommand(0x0c);// cursor ,ox0f,0x0e;
	LCD_WriteCommand(0x01);// clear screen
	_delay_ms(1);
	LCD_WriteCommand(0x06);// increase DDRAM address , no shift
	
	
}

#endif

/***********************************************************************************/

void LCD_WriteChar(U8 ch){
	
	LCD_WriteData(ch);
}
void LCD_Clear(void){
	LCD_WriteCommand(0x01);
	_delay_ms(1);
}
	

void LCD_WriteString(U8*str){
	U8 i;
	for (i=0;str[i];i++)
	{
		LCD_WriteChar(str[i]);
	}
}

void LCD_WriteNumber(S32 num){
	U8 r, n=1,i=0;
	U8 str[20];
	if (num<0)
	{
		num=num*-1;
		LCD_WriteChar('-');
	}
	
	while(n)
	{	
	    r=num%10;
		num=num/10;
		str[i]=(r+'0');
		n=num;
		i++;
	}
	for (S8 j=i-1;j>=0;j--)
	{

		LCD_WriteChar(str[j]);

	}
	
}

void LCD_WriteNumber_4D(U16 num){

LCD_WriteChar((num/1000)+'0');
LCD_WriteChar(((num %1000)/100)+'0');
LCD_WriteChar(((num %100)/10)+'0');
LCD_WriteChar(((num %10))+'0');
}

void LCD_WriteBinary(U8 num){
 S8 i,flag=0;
	

	  for (i=7;i>=0;i--)
	  {
       if ((num>>i)&1)
       {
		   LCD_WriteChar('1');
		   flag=1;
       }/*else{
		   LCD_WriteChar('0');
	   }*/
	   else if (flag==1)
		 {
			 LCD_WriteChar('0');
		 }
		   
	   
	  }
	 


	  
}

void LCD_WriteHex(U8 num){
	/*U8 str[3];
	U8 r,i=0,n=1;
	while (n)
	{
		r=num%16;
		if (r<10)
		{
			str[i]=r+'0';
			i++;
		} 
		else
		{
			str[i]=r+'7';
			i++;
		}
		num=num/16;
		n=num;
	}
	for (S8 j=i-1;j>=0;j--)
	{

		LCD_WriteChar(str[j]);

	}*/
	U8 Hnibble=num>>4;
	U8 Lnibble=num&0x0f;
	if (Hnibble<10)
	{
		LCD_WriteChar(Hnibble+'0');
	}else{
		LCD_WriteChar(Hnibble+'7');
	}
		if (Lnibble<10)
		{
			LCD_WriteChar(Lnibble+'0');
			}else{
			LCD_WriteChar(Lnibble+'7');
		}
	
}

void LCD_GoTo(U8 line , U8 cell){
	
	if (line==0)
	{
		LCD_WriteCommand(0x80+cell);
	}else if (line==1)
	{
		LCD_WriteCommand(0x80+0x40+cell);
	}
	
}

void LCD_GoToClear(U8 line ,U8 cell,U8 NumOfCells){
	
	U8 i;
	  LCD_GoTo(line,cell);
	for (i=0;i<NumOfCells;i++)
	{
		LCD_WriteChar(' ');
	}
	
}

void LCD_GoToWriteString(U8 line ,U8 cell,U8* str){

LCD_GoTo(line,cell);
LCD_WriteString(str);
}

void LCD_Create_Character(U8* pattern,U8 location){
	U8 i=0;
LCD_WriteCommand(0x40+(location*8)); //send the address of CGRAM 
for(i=0;i<8;i++){
	LCD_WriteData(pattern[i]);
   }
   LCD_WriteCommand(0x80); // return to DDRAM
 }

	


