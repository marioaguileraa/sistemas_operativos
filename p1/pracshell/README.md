# Sistemas Operativos - Práctica 1 - shell

## Ejercicios básicos con la `shell`

A continuación se presentan unos ejercicios básicos de manejo de la línea de
órdenes, que van incrementándose en dificultad, que deberán realizarse con los
datos contenidos en el repositorio proporcionado; concretamente desde dentro
del directorio `p1`.

La realización de estos ejercicios no se evalúa ni influye en la nota obtenida
en la práctica 1, sino que es una autoevaluación para el alumno y una forma de
tener una referencia de lo aprendido. La dificultad de las preguntas tampoco es
representativa de la dificultad de las preguntas que pueden aparecer en la
evaluación PL1.

Debajo de cada ejercicio propuesto, editando el presente documento, se deberá
indicar:

- El comando o comandos que el alumno ha empleado para conseguir lo propuesto
  en cada ejercicio. 
- (Opcional) El resultado por pantalla, si lo hay.

Se recomienda que si el alumno no tiene aún conocimientos suficientes para
hacerlo de otra forma, mantenga abiertas dos consolas; una donde realizar los
ejercicios y otra donde pueda editar este documento.

Las órdenes pueden ser simples o estar compuestas de varios comandos empleando
tuberías, o utilizar redirecciones.

Los primeros ejercicios se dan con sus respuestas, a modo de ejemplo sobre cómo
deben responderse el resto de ejercicios.

1. Abra una consola y, desde el directorio donde haya clonado el repositorio,
cambie el directorio de trabajo a `labssoo21-alumno/p1` (el nombre exacto
dependerá de cada alumno).
    
    
		cd labssoo21-alumno/p1
    
2. Crée un directorio que se llame `pruebas`. Cambie su directorio de trabajo a
este directorio. Muestre el nuevo directorio de trabajo.


		mkdir pruebas 
		cd pruebas 
		pwd 
		/home/nacho/labssoo21-alumno/p1/pruebas
    
3. Obtenga desde aquí, empleando una trayectoria relativa, el listado del
directorio `p1/pracshell` que está contenido en el arbol de directorios que ha
descargado el alumno.


		ls ../pracshell 
		test.tgz  
		README.md
    
4. Descomprima los contenidos del archivo `test.tgz` desde el directorio de
trabajo actual, empleando el comando `tar -xzf trayectoria_relativa`. Liste el
contenido del directorio actual.


		tar -xzf ../pracshell/test.tgz 
		ls 
		Chapter01.txt  Chapter05.txt Chapter09.txt  Chapter13.txt  Chapter17.txt 
		Chapter02.txt  Chapter06.txt Chapter10.txt  Chapter14.txt  Chapter18.txt 
		Chapter03.txt  Chapter07.txt Chapter11.txt  Chapter15.txt  Chapter19.txt 
		Chapter04.txt  Chapter08.txt Chapter12.txt  Chapter16.txt
    
5. Como puede observar, se trata de los 19 capítulos de un libro (en realidad,
un fragmento de cada uno), en formato texto plano. Liste los contenidos del
directorio en formato largo, mostrando la lista de archivos ordenada por tamaño
del archivo en bytes, de mayor a menor. (Consulte la página del manual para
encontrar la opción requerida).

    
5. Liste los contenidos del directorio en formato largo, mostrando la lista de
archivos ordenada por tamaño del archivo en bytes **de menor a mayor**.
(Consulte la página del manual para encontrar la opción requerida).


6. Liste los contenidos del directorio, mostrando la lista de archivos ordenada
por fecha de última modificación, mostrando **primero el más antiguo**.
(Consulte la página del manual para encontrar la opción requerida).


7. Cree tres directorios llamados `part1`, `part2` y `part3`. Copie, con un
solo comando y sin cambiar de directorio de trabajo, los capítulos del 1 al 7
en el directorio `part1`.

    
9. Cambie el directorio de trabajo a `part2` y copie en él, con un solo comando
y sin cambiar de directorio de trabajo, los capítulos del 9 al 14.


10. Sin cambiar de directorio de trabajo (es decir, permaneciendo en `part2`)
copie con un solo comando los capítulos del 15 al 19 en el directorio `part3`.


11. Vuelva a cambiar el directorio de trabajo al directorio `prueba` y liste
los contenidos del directorio en formato largo, haciendo que se visualice tras
el nombre de cada directorio el caracter `/`.


12. Sin cambiar de directorio de trabajo, cree un directorio llamado `backup`
en su directorio de conexión y mueva allí todos los archivos de texto del
directorio de trabajo.


13. Muestre por pantalla, con un solo comando y sin cambiar el directorio de
trabajo, los contenidos de los 3 primeros capítulos contenidos en el directorio
`part1`.


14. Sin cambiar de directorio de trabajo y con una única orden, genere un
archivo en el directorio de trabajo llamado `thehobbit.txt` que contenga el
texto de todos los capítulos almacenados en el directorio `part1`.

    
15. Sin cambiar de directorio de trabajo y con una única orden, añada al
archivo anterior los capítulos almacenados en los directorios `part2` y
`part3`. Bonus points si lo hace pasándole a `cat` una única trayectoria.

      
16. Sin cambiar de directorio y con una única orden, genere un archivo
`thehobbit.bak` con los contenidos de todos los capítulos contenidos en el
directorio `backup`creado anteriormente en el directorio de conexión. Compare
este archivo con el archivo `thehobbit.txt` empleando el comando `diff`, y
haciendo que si ambos son iguales este comando lo indique por pantalla.

   
17. Averigüe en cuantas lineas aparece la palabra "hobbit" en el archivo
`thehobbit.txt`.


18. Sin cambiar de directorio, averigüe cuantas veces aparece el nombre "Smaug"
en los capítulos contenidos en cada uno de los directorios `part1`, `part2`y
`part3`. No hace falta que sea con un único comando. A continuación, averigüe
con un único comando el total de veces que aparece este nombre entre los tres
directorios.


19. Sin cambiar de directorio y con una única orden, averigüe en qué capítulo
de los contenidos en los directorios `part1`, `part2`y `part3` aparece el
nombre "Balin". ¿Sería capaz de conseguir que la respuesta por pantalla fuese
únicamente la trayectoria relativa del archivo?


20. Borre el archivo `thehobbit.bak`. Borre los directorios `part1`, `part2` y
`part3` junto con sus contenidos, empleando la orden `rm` (consulte la página
del manual). Mueva todos los archivos almacenados en la carpeta `backup`que
creó en el directorio de conexión al directorio de trabajo. Borre, sin cambiar
el directorio de trabajo, el mencionado directorio `backup`.


21. Obtenga un archivo llamado "bigger.txt" que contenga la lista de los 8
capítulos de mayor tamaño del directorio en formato largo.

    
22. Obtenga un archivo llamado "smaller.txt" que contenga la lista de los 4
capítulos de menor tamaño del directorio en formato normal, ordenados por
número de capítulo. No utilice el modificador `-r` de `ls` para esta tarea.


23. El programa `uniq` sirve para eliminar lineas duplicadas (siempre que sean
consecutivas), y puede emplearse como filtro. Consulte la página del manual
para más información. Sabiendo esto, elabore un comando empleando filtros que
obtenga en cuántos de los 19 capítulos aparece la palabra "Bilbo".


