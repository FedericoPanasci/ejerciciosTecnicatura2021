Algoritmo utilizarPara
	definir nro, max, i, cantidadnros Como Entero;
	
	escribir "ingrese cuantos numeros quiere procesar";
	leer cantidadnros
	
	mostrar "ingrese un numero"
	leer nro
	max = nro
	
	para i = 2 hasta cantidadnros con paso 1 hacer
		Mostrar "ingrese otro numero"
		leer nro
		si nro > max entonces
			max = nro
		FinSi
	FinPara
	Mostrar  "su numero mas alto es ", max
FinAlgoritmo
