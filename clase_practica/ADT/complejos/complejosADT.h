typedef struct complexCDT * complexADT;

complexADT newComplex (double re, double im); //crea el complejo con parte imaginaria y real

double realPart(complexADT z);
double imPart(complexADT z);

complexADT addComplex(const complexADT a, const complexADT b); //Devuelve un nuevo complejo sin modificar

void freeComplex(complexADT z); //Libera el complejo
