#meu Make para executar o progecto
main: sequencia.o tarefa.o main.o
	gcc -g -o main sequencia.o tarefa.o main.o
sequencia.o: sequencia.c sequecia.h 
	gcc -c sequencia.c
tarefa.o: tarefa.c tarefa.h
	gcc -c tarefa.c
main.o: main.c sequecia.h tarefa.h
	gcc -c main.c
clean:
	rm -f *.o main