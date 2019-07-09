# Tutorial VIM

## Editando um arquivo

- `vim nome_do_arquivo`

## Saíndo do Vim

Para sair (**q**uit):

- `Esc + :q`
- `ZZ`

## Salvando o arquivo

Para salvar (**w**rite):

- `Esc + :w`

Note que é possível concatenar comandos, logo, para salvar e sair, basta
utilizar o seguinte comando:

- `Esc + :wq`

## Modos principais do Vim

Existem 12 modos, mas na maioria das vezes, você usará apenas 4 modos.

### Modo de Inserção

Neste modo é feita a inserção de texto, para entrar neste modo basta pressionar
a tecla `i` de insert.

### Modo Normal

Quando se inicia o Vim já estamos neste modo; caso esteja em outro modo basta
pressionar ESC para retornar ao modo Normal.

Neste modo é realizado a maioria dos comandos, como `d`elete, `y`ank (copiar) e
`p`aste. Também é possível executar um comando múltiplas vezes, por exemplo:

- `5dd`

O comando `dd` apaga toda uma linha, e com o `5` de prefixo, apaga 5 linhas
completas.

### Modo de Comando

Para acessar o modo de comando é necessário estar no modo normal e digitar `:`
(dois pontos).

Neste modo podemos realizar algumas configurações no editor (ex: set number,
para ativar a numeração das linhas) e executar alguns comandos, como :w, :wq!,
:set number, :set tabstop=4, etc.

### Modo Visual

Permite a seleção de texto, seja na horizontal ou vertical.

Para acessar o modo visual é necessário estar no modo normal e utilizar um dos seguintes caracteres:

- `v` - seleção de caracteres
- `Shift + v` - (maiúsculo) seleção de linhas inteiras
- `Ctrl + v` - seleção de blocos (vertical + horizontal)

## Navegação

Apesar de ser permitido o uso das "setinhas" no VIM, elas não são recomendadas.
Para tirar o máximo do VIM, se acostumar com seus comandos de movimentação é
essencial.

Comando | Direção
--------|--------
h | Esquerda
j | Baixo
k | Cima
l | Direita

## Arquivo de configuração

Para evitar a necessidade de reconfigurar seu VIM toda vez que abrir um
arquivo, é possível armazenar as configurações em um arquivo nomeado `.vimrc`,
que deve ficar no `home` (`/home/nome_de_usuario/.vimrc` ou apenas `~/.vimrc`).

Exemplo de arquivo `.vimrc`:

```vim
syntax on

" Numeração nas linhas
set number

" Indentação de espaços com tamanho 4
set autoindent
set expandtab
set tabstop=4
set shiftwidth=4
```

## FAQ

### O que é o buffer?

Uma região de memória que será armazenada temporariamente. No caso do VIM, tudo
que for copiado ou deletado será armazenado no buffer até o fechamento do
programa.

### Como colar texto para dentro do editor?

No modo de inserção, use

- `Ctrl + Shift + v`

Lembre-se que o comando `p` só cola o que está no buffer! Logo, o que foi
copiado fora do VIM não afetará o que foi copiado com `y` ou deletado com `d`.

### Como copiar o texto para fora do editor?

Infelizmente isso não é trivial no VIM, então será necesário utilizar outro
editor somente para abrir o arquivo e copiar.

### Meu VIM simplismente congelou! O que eu faço?

Você provavelmente tentou salvar o arquivo com `Ctrl + s`. Na maioria dos
terminais, este comando serve para congelar o terminal mesmo. Para descongelar,
use `Ctrl + q`

## Referências

- https://www.youtube.com/watch?v=ggSyF1SVFr4
- https://pt.wikibooks.org/wiki/Vim/
