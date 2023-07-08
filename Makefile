interface:
	gcc main.c -o UI `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0` -lm

compile:
	gcc main.c src/Atributos.c src/BlocoIndireto.c src/Conteudo.c src/DiretorioRais.c src/EnderecoBloco.c src/EntradaDiretorio.c src/INodes.c src/SistemaArquivo.c -lm -o exefile
roda:
	gcc main.c src/Atributos.c src/BlocoConteudo.c src/EntradaDiretorio.c -lm -o exefile
run:
	./exefile