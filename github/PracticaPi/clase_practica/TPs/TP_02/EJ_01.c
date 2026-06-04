a)
int letra, flag;					int letra, flag;
	flag = 0;					        flag = 0;
if ( letra == (int)’x’)				if ( letra == ‘x’)
		flag=1;						flag=1;

/* Da lo mismo, porque el ascii de la x ya es un entero */

b)
float x;						float x;
int y;						    int y;
y = 5;						    y = 5;
x = y / 3.0;					x = (float) (y / 3);
						
/* 
Da distinto, porque en el segundo primero hace la
division entera y luego lo convierte a float 
*/

c)
float x;						int x;
int y;						    int y;
y = 5;						    y = 5;
x = y / 3.0;					x = (float) y / 3;

/*
Aca da lo mismo ya que en el segundo caso primero se 
convierte a float y luego se hace la division
*/

d)
int x;						int x;
float y;						float y;
y = 5.5;					y = 5.5;
x = y / 3;					x = (int) y / 3.0;

/*
No dan lo mismo, el primero divide 5.5/3.0 aunque luego
trunque el resultado a int y el segundo divide 5.0/3.0
y dan lo mismo, porque truncan el resultado a int. si en 
vez de un int fuera un double o float, darian diferente
*/

