Proceso  p3
	// Obtenemos y validamos
	Repetir
		Escribir 'Marca (B: Best; M: Monark; O: Oxford): '
		Leer marca
	Hasta Que marca Es 'B' O marca Es 'M' O marca Es 'O'
	Repetir
		Escribir 'Categoría (P: Paseo; M: Montañera): '
		Leer categoria
	Hasta Que categoria Es 'P' O categoria Es 'M'
	
	precio <- 0
	
	Si marca Es 'B'
		Si categoria Es 'P'
			precio <- 1300
			// en esta linea pudimos haber puesto SiNo
		FinSi
		Si categoria Es 'M'
			precio <- 1000
		FinSi
	FinSi
	Si marca Es 'M'
		Si categoria Es 'P'
			precio <- 1350
		SiNo // En este caso usamos SiNo, se pudo hacer de la forma anterior tambien
			precio <- 2500
		FinSi
	FinSi
	Si marca Es 'O'
		Si categoria Es 'P'
			precio <- 900
		FinSi
		Si categoria Es 'M'
			precio <- 3200
		FinSi
	FinSi
	
	Escribir 'Monto a pagar: ', precio
	
FinProceso

