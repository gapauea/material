# VIM Comandos Básicos

Comando (modo normal) | Descrição
--------|-----------
i | Entra no modo de inserção
Esc | Entra no modo normal
x | Deleta um caractere
u | Desfaz a última alteração (equiavlente a ctrl + z em outros editores)
Ctrl + r | Refaz a última alteração
yy | Insere uma linha no buffer (copia a linha)
dd | Deleta uma linha e a insere no buffer
p | Cola o conteúdo do buffer
o | Insere uma nova linha em baixo do cursor
O | Insere uma linha acima do cursor
gg | Salta para o início do arquivo
G | Salta para o final do arquivo
/exemplo | Pesquisa a palavra "exemplo" no texto. A próxima ocorrência pode ser consultada com a letra `n` e a anterior com `N`
Ctrl + Shift + v | Cola o conteúdo do buffer externo (o que foi copiado fora do VIM)
Ctrl + s | Ao invés de salvar as alterações, trava o terminal
Ctrl + q | Destrava o terminal do comando acima :)

---

Comando | Descrição
-|-
:w | Salva as alterações
:wq | Salva as alterações e fecha o arquivo
:q! | Fecha o arquivo sem salvar alterações
:set number | Ativa numeração nas linhas
:set expandtab | Troca tabs por espaços
:set shiftwidth=4 | Indentação de 4 espaços
:set tabstop=4 | Tab de tamanho 4
:set autoindent | Indentação automática
:set cindent | Indentação melhorada para C/C++

