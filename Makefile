interface:
	gcc src/Atributos.c src/BlocoConteudo.c src/EntradaDiretorio.c src/INode.c src/SistemaArquivo.c  src/gtk.c main.c -o UI `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0` -lm -rdynamic

run:
	./exefile
	
