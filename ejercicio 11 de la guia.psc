Algoritmo ejercicio_11
	
	Definir edad Como entero;
	Definir leyenda como cadena;
	
	Mostrar "ingrese una edad";
	Leer edad;
	
	si edad <= 12 Entonces
		leyenda = "menor"
	SiNo
		si edad <= 18 Entonces
		leyenda = "cadete"	
		SiNo
			si edad <= 26 Entonces
			leyenda = "juvenil"	
			SiNo
				leyenda = "mayor"	
			FinSi
		FinSi
	FinSi
	
	Mostrar leyenda
	
FinAlgoritmo

