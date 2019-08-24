Proceso  p1_solo_condicional
	Hacer
		Escribir 'Ingrese un codigo de 4 cifras'
		Leer cod		
	Hasta Que cod < 10000 Y cod > 999
	// Obtenemos el valor de cada digito
	digito_1 <- trunc(cod/1000)
	digito_2 <- trunc((cod-(digito_1*1000))/100)
	digito_3 <- trunc((cod-(digito_1*1000)-(digito_2*100))/10)
	digito_4 <- trunc((cod-(digito_1*1000)-(digito_2*100)-digito_3*10)/1)
	
	// variables respuesta
	dep <- ''
	hora <- 0
	paradas <- ''
	
	// Determinamos el departamento
	si digito_1 es 1
		dep <- 'Piura'
	FinSi
	si digito_1 es 2
		dep <- 'Ica'
	FinSi	
	si digito_1 es 3
		dep <- 'Piura'
	FinSi
	
	// Calculamos la hora
	hora <- digito_2 * 10 + digito_3
	
	//Determinamos si existe alguna parada
	si digito_4 es 1
		paradas <- 'Si'
	FinSi
	si digito_4 es 2
		paradas <- 'No'
	FinSi
	
	Escribir 'Departamento de destino: ', dep
	Escribir 'Hora de salida: ', hora
	Escribir 'Realizan paradas:', paradas
FinProceso

