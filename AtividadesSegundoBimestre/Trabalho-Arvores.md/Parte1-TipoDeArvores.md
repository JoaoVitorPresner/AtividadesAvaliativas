#Tipos de Árvores

## AVL

### Conceito

A árvore AVL é uma Árvore Binária de Busca (BST) auto balanceada criada por Adelson-Velsky e Landis. Ela mantém a diferença de altura entre as subárvores esquerda e direita de cada nó em no máximo 1.

### Características

* Estrutura binária de busca.
* Balanceamento automático.
* Utiliza rotações para corrigir desequilíbrios.
* Mantém altura próxima do ideal.

### Vantagens

* Busca muito eficiente.
* Desempenho previsível.
* Menor altura da árvore.

### Desvantagens

* Inserções e remoções mais complexas.
* Maior número de rotações.
* Implementação mais trabalhosa.

### Exemplo Ilustrado

```text
      30
     /  \
   20    40
  /
10
```

Após o balanceamento:

```text
      20
     /  \
   10    30
           \
            40
```

---

## Rubro-Negra

### Conceito

A árvore Rubro-Negra é uma árvore binária de busca balanceada que utiliza nós vermelhos e pretos para controlar seu balanceamento.

### Regras de Coloração

1. Todo nó é vermelho ou preto.
2. A raiz sempre é preta.
3. Folhas nulas são pretas.
4. Um nó vermelho não pode ter filho vermelho.
5. Todos os caminhos da raiz até as folhas devem possuir a mesma quantidade de nós pretos.

### Vantagens

* Menos rotações que AVL.
* Inserções e remoções rápidas.
* Muito utilizada em sistemas reais.

### Desvantagens

* Implementação complexa.
* Balanceamento menos rigoroso que AVL.

### Exemplo Ilustrado

```text
         20(P)
        /     \
    10(V)    30(V)
```

Legenda:

* P = Preto
* V = Vermelho

---

## N-ária

### Conceito

A árvore N-ária é uma estrutura em que cada nó pode possuir vários filhos, diferentemente das árvores binárias que permitem apenas dois.

### Diferenças em Relação às Árvores Binárias

| Característica   | Árvore Binária | Árvore N-ária |
| ---------------- | -------------- | ------------- |
| Número de filhos | Até 2          | Vários        |
| Estrutura        | Mais simples   | Mais flexível |
| Uso comum        | Busca de dados | Hierarquias   |

### Vantagens

* Representa hierarquias naturalmente.
* Suporta muitos filhos por nó.
* Menor profundidade em alguns casos.

### Desvantagens

* Implementação mais complexa.
* Pode consumir mais memória.

### Exemplo Ilustrado

```text
           A
      /    |    \
     B     C     D
   / | \
  E  F  G
```

### Aplicações Práticas

* Sistema de arquivos.
* Menus de programas.
* Estruturas XML e HTML.
* Organogramas empresariais.
* Taxonomias e classificações.
