typedef struct complejoCDT * complejoADT;

// crea un un nuevo complejo
complejoADT newCompl(double re, double im);

// obtiene la parte real
double getReal(complejoADT num);

// obtiene la parte imaginaria
double getIm(complejoADT num);

// suma dos numeros complejos
complejoADT suma(complejoADT num1, complejoADT num2);

// saca el modulo
double modulo(complejoADT num);

// libera complejos
void freeComplejo(complejoADT num);