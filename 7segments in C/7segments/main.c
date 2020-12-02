/*
 * Odometer.c
 *
 * Created: 26/02/2016 9:05:18 a. m.
 * Author : MariaPaola
 */ 
/////////////////////////////////////////////////// Inclusión de headers /////////////////////////////////////
#include <avr/io.h>
/////////////////////////////////////////////////// Definición de funciones //////////////////////////////////
void velocity(int frequency);
void Seven_segments(int num);
/////////////////////////////////////////////////// Definición de MEF ////////////////////////////////////////
typedef enum STATE state_m;
enum STATE{Dig0,Dig1,Dig2,Dig3};
/////////////////////////////////////////////////// MAIN ///////////////////////////////////////////////////////
int main(void)
{
	state_m state;
	state = Dig0;
	//int vel_counter=0, frequency_num=0, encoder_flag=0, button_counter=0, boolean=0;	//contadores y banderas
	PORTA.DIRSET= 0xFE;		//7 Segmentos
	PORTA.OUTCLR= 0x7E;		//numero 0 inicialmetne en el 7 segmentos
	
	PORTC.DIRCLR= 0x01;		//Encoder
	
	TCCR0 |= (1<<CS00);         //Sin presc 
	TCNT0 =0x04;		//preescalización de 8
	
	while (1)
	{	
		Vrms=1024*(PORTA.IN &0x01)+512(PORTA.IN &0x01)+64*(PORTA.IN &0x01)+32*(PORTA.IN &0x01)+16*(PORTA.IN &0x01)+8*(PORTA.IN &0x01)+4*(PORTA.IN &0x01)+2*(PORTA.IN &0x01)+1*(PORTA.IN &0x01);
		switch(state)	
		{
			case Dig0:
			 if ()
			 {
				 Digi0=Vrms%10;
				 num=Digi0;
				 Seven_segments(num);
			 }
			break;
			
			case Dig1:
			if ()
			{
				Digi1=Digi0%10;
				num=Digi1;
				Seven_segments(num);
			}
			break;
			
			case Dig2:
			if ()
			{
				Digi2=Digi1%10;
				num=Digi2;
				Seven_segments(num);
			}
			break;
			
			case Dig3:
			if ()
			{
				Digi3=Digi2%10;
				num=Digi3;
				Seven_segments(num);
			}
			break;
			
			 
		}	
				
		//if((PORTA.IN &0x01)==0)					//reviso pulsador
		//{
			//boolean=1;
		//}
		//if((PORTA.IN &0x01)==1 && boolean==1)
		//{
			//button_counter=button_counter+1;
			//boolean=0;
		//}
		//switch(state)							////////**///////// SWITCH ////////**/////////
		//{
			//case RUN:                         /////////////////////// Case RUN ////////////////////        
			//if((TCC0.INTFLAGS & 0x01)==0)		//mientras la bandera esté abajo, se cuentan los pulsos en 1 seg
			//{	
				//if((PORTC.IN &0x01) == 0)
				//{
					//encoder_flag=1;
				//if(encoder_flag==1 && (PORTC.IN & 0x01) == 1)
				//{ 
					//vel_counter++;
					//encoder_flag=0; 
				//}
				//}
			//}	
			//else if((TCC0.INTFLAGS & 0x01)!=0)	//Cuando suba la bandera del timer, manda la frecuencia a la función velocidad
			//{
				//TCC0.INTFLAGS|=0x01;				//Bajo la bandera
				//frequency_num=(vel_counter);				//guardo el valor en otra variable
				//vel_counter=0;						//reinicio el contador
				//velocity(frequency_num);				//llamo a la función de velocidad
			//}
					//if(button_counter%2==0)		//Si el número del pulsador es 0 o 2, el estado será run
					//{
						//state=RUN;
						//button_counter=0;
					//}							//Si el numero del pulsador es 1, el estado será stop
					//else
					//{state=STOP;}
					//
			//break;
			//
			//case STOP:							///////////////////////////////////// Case STOP ////////////////////
			//velocity(frequency_num);			//llamo a la función velocidad con el último valor que obtuvo
			//if(button_counter%2==0)				//Si el numero del pulsador es 0 o 2, el estado vuelve a run
			//{
				//state=RUN;
				//button_counter=0;
			//}									//Si el numero del pulsador es 1, el estado se queda en STOP
			//else
			//{state=STOP;}
//
			//break;
		//}
	}
}

////////////////////////////////////////////////////FUNCIONES////////////////////////////////////////////////////////
void velocity(int frequency)
{
	int linear_vel=0;
	linear_vel=((frequency)(2*3.1416)(0.0135)*(3.6)); //(frecuencia*2pi*radio) vel lineal en m/s, *(3.6) en km/h
	Seven_segments(linear_vel);
}
void Seven_segments(int num)
{
	PORTA.OUTSET= 0xFE;
	if(num==0)
	{PORTA.OUTCLR= 0x7E;}
	if(num==1 || (num>9 && num<20))
	{PORTA.OUTCLR= 0x0C;}
	if(num==2 || (num>19 && num<30))
	{PORTA.OUTCLR= 0xB6;}
	if(num==3 || (num>29 && num<40))
	{PORTA.OUTCLR= 0x9E;}
	if(num==4 || (num>39 && num<50))
	{PORTA.OUTCLR= 0xCC;}
	if(num==5 || (num>49 && num<60))
	{PORTA.OUTCLR= 0xDA;}
	if(num==6 || (num>59 && num<70))
	{PORTA.OUTCLR= 0xFA;}
	if(num==7 || (num>69 && num<80))
	{PORTA.OUTCLR= 0x0E;}
	if(num==8 || (num>79 && num<90))
	{PORTA.OUTCLR= 0xFE;}
	if(num==9 || (num>89 && num<100))
	{PORTA.OUTCLR= 0xDE;}
}