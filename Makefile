gerar-senha: main.c
	gcc main.c -o gerar-senha

install: gerar-senha
	mv gerar-senha /usr/local/bin
	chmod 755 /usr/local/bin/gerar-senha
	cp gerar-senha.1 /usr/local/share/man/man1
	chmod 644 /usr/local/share/man/man1/gerar-senha.1

uninstall:
	rm -f /usr/local/bin/gerar-senha
	rm -f /usr/local/share/man/man1/gerar-senha.1