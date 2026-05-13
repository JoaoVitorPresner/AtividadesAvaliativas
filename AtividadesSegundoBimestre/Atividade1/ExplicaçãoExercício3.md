-EXPLICAÇÃO:
Esse código resolve o problema das Torres de Hanoi utilizando recursão, mostrando passo a passo os movimentos necessários para mover todos os discos da torre de origem até a torre de destino e contabilizando o total de movimentos realizados. 
Esse código utiliza a fórmula (dois elevado a N menos um).

#Exemplo de entrada
Digite a quantidade de discos: 3

#Exemplo de saída
Movimentos realizados:

Mover disco 1 de A para C
Mover disco 2 de A para B
Mover disco 1 de C para B
Mover disco 3 de A para C
Mover disco 1 de B para A
Mover disco 2 de B para C
Mover disco 1 de A para C

Total de movimentos: 7

A saída dá 7 movimentos quando usamos 3 discos porque a Torre de Hanoi segue esta fórmula:

2
n (2 elevado a N menos 1)
−1

Onde:

n = quantidade de discos.

Então, para 3 discos:

2³ - 1
8 - 1
7

Ou seja, são necessários exatamente 7 movimentos para mover todos os discos corretamente.
