1. AVL

-Conceito

A árvore AVL é uma Árvore Binária de Busca (BST) auto balanceada, criada por Adelson-Velsky e Landis. Ela mantém a diferença de altura entre as subárvores esquerda e direita de cada nó em no máximo 1.

-Características

Árvore binária.

Possui balanceamento automático.

Utiliza rotações para corrigir desequilíbrios.

Mantém operações eficientes.

-Vantagens

Busca muito rápida.

Altura sempre próxima do ideal.

Desempenho previsível.

-Desvantagens

Inserção mais complexa.

Maior quantidade de rotações.

Consome mais processamento para manter o balanceamento.

Exemplo
      
      30
     /  \
   20    40
   /
 10

Após inserções que causem desequilíbrio, rotações são realizadas para manter a árvore balanceada.

2. Rubro-Negra

-Conceito

É uma árvore binária de busca balanceada que utiliza cores (vermelho e preto) para controlar o balanceamento.

-Regras de Coloração

Todo nó é vermelho ou preto.

A raiz sempre é preta.

Folhas nulas são pretas.

Um nó vermelho não pode ter filho vermelho.

Todos os caminhos da raiz até uma folha possuem a mesma quantidade de nós pretos.

-Vantagens

Menos rotações que AVL.

Inserções e remoções eficientes.

Muito utilizada em bibliotecas de sistemas.

-Desvantagens

Implementação mais complexa.

Balanceamento menos rigoroso que AVL.

Exemplo
        20(P)
       /     \
   10(V)    30(V)

P = Preto
V = Vermelho

3. N-ária

-Conceito

Árvore onde cada nó pode possuir vários filhos, não ficando limitada a apenas dois.

-Diferenças para Árvores Binárias
Árvore Binária	                  

Até 2 filhos	                 

Estrutura mais simples	      

Usada em buscas	               

 Árvore N-ária

 Vários filhos

 Estrutura mais flexível

 Usada em hierarquias



-Vantagens

Representa hierarquias naturalmente.

Menor profundidade em alguns casos.

Organização mais intuitiva.

-Desvantagens

Implementação mais complexa.

Pode exigir mais memória.

-Exemplo
                         A
                    /    |    \
                   B     C     D
                 / | \
                E  F  G

Aplicações Práticas
Sistema de arquivos.
Menus de programas.
Organogramas.
Estruturas XML e HTML.
