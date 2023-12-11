# gerar-senha
gerar-senha é um gerador de senhas de linha de comando simples escrito em C.
Por padrão, ao executar o programa é impressa na saída padrão uma senha
aleatória de 16 caracteres, que pode incluir letras maiúsculas, minúsculas,
números e símbolos.

## Instalar
```sh
# clonar o repositório
git clone https://github.com/lucasms07/gerar-senha.git

# entrar na pasta do projeto
cd gerar-senha/

# compilar e instalar
sudo make install
```

## Usar
```sh
# gerar senha usando configurações padrão
gerar-senha

# gerar 5 senhas de 32 caracteres
gerar-senha -q 5 -t 32

# gerar uma senha sem letras maiúsculas
gerar-senha -M

# gerar uma senha apenas com letras maiúsculas
gerar-senha -m -n -s
```

## Desinstalar
```sh
# remover tudo
sudo make clean uninstall
```

## Licença
Este software está sob a licença [Unlicense](./UNLICENSE).