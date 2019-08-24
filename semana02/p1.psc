Proceso  p1
	// realizamos la lectura del codigo
	Hacer
		Escribir 'Ingrese un codigo de 4 cifras'
		Leer cod
	Hasta Que cod < 10000 Y cod > 999
	
	//definimos las variables de respuesta
	dep <- ''
	hora <- 0
	paradas <- ''
	
	aux <- cod
	
	Para  i <- 1 hasta 4 Hacer
		// obtenemos el digito hacia la izquierda
		// para esta repeticion
		divisor <- 10^(4-i)
        digito <- trunc (divisor / divisor)
        aux <- aux - digito*pot
		
		// primer digito		
		Si i es 1
			si digito es 1
				dep <- 'Piura'
			FinSi
			si digito es 2
				dep <- 'Ica'
			FinSi	
			si digito es 3
				dep <- 'Piura'
			FinSi	
		FinSi
		// segundo y tercer digito
		Si i es 2 O i  es 3
			hora <- hora * 10
			hora <- hora + digito
		FinSi
		// ultimo digito
		si i es 4
			si digito es 1
				paradas <- 'Si'
			FinSi
			si digito es 2
				paradas <- 'No'
			FinSi
		FinSi
	FinPara
	
	Escribir 'Departamento de destino: ', dep
	Escribir 'Hora de salida: ', hora
	Escribir 'Realizan paradas:', paradas
	
	
FinProceso

