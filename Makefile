interface:
	gcc main.c -o UI `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0` -lm

compile:
	gcc src/Atributos.c src/BlocoConteudo.c src/EntradaDiretorio.c src/INode.c src/SistemaArquivo.c Leitura.c main.c -lm -o exefile
run:
	./exefile