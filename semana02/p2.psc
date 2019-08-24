Proceso p2
	// Leer y validar
	Repetir
		Escribir 'Ingrese el tipo de uva:'
		Leer tipo
	Hasta Que tipo Es 'A' O tipo Es 'B'
	Repetir
		Escribir 'Ingrese el tamanio de uva:'
		Leer tam
	Hasta Que tam Es 1 O tam Es 2
	Repetir
		Escribir 'Precio de la uva:'
		Leer precio
	Hasta Que precio > 0
	Repetir
		Escribir 'Kilos de producción:'
		Leer kg
	Hasta Que kg > 0
	// variable respuesta, por defecto el total es precio uni * kg
	total <- (precio * kg)
	// Soulcion
	Si tipo Es 'A'
		Si tam Es 1
			total <- total * 1.2
		SiNo 
			// Como ya validamos que solo acepte 1 o 2 la instruccion SiNo 
			// siempre se ejecutara cuando el tamanio es 2
			total <- total * 1.3
		FinSi
	SiNo
		// Como ya validamos que solo acepte A o B la instruccion SiNo 
		// este bloque siempre se ejecutara cuando el tipo es B
		Si tam Es 1
			total <- total * 0.75
		SiNo
			total <- total * 0.65
		FinSi
	FinSi
	// Mostrar resultado
	Escribir 'Monto a recibir: ', total 
FinProceso

	