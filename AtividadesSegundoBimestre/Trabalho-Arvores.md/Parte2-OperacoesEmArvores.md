## Parte 2 – Operações em Árvores

### Rotação Simples à Direita

#### Objetivo

Corrigir desequilíbrios causados por excesso de nós à esquerda.

#### Quando é utilizada

Caso LL (Left-Left).

#### Exemplo Antes

```text
      30
     /
   20
  /
10
```

#### Exemplo Depois

```text
      20
     /  \
   10    30
```


### Rotação Simples à Esquerda

#### Objetivo

Corrigir desequilíbrios causados por excesso de nós à direita.

#### Quando é utilizada

Caso RR (Right-Right).

#### Exemplo Antes

```text
10
  \
   20
     \
      30
```

#### Exemplo Depois

```text
      20
     /  \
   10    30
```

---

### Rotação Dupla Esquerda-Direita (LR)

#### Objetivo

Corrigir um desequilíbrio onde a inserção ocorre à direita da subárvore esquerda.

#### Exemplo Antes

```text
      30
     /
   10
     \
      20
```

#### Exemplo Depois

```text
      20
     /  \
   10    30
```


### Rotação Dupla Direita-Esquerda (RL)

#### Objetivo

Corrigir um desequilíbrio onde a inserção ocorre à esquerda da subárvore direita.

#### Exemplo Antes

```text
10
  \
   30
   /
 20
```

#### Exemplo Depois

```text
      20
     /  \
   10    30
```


### Inversão (Espelhamento)

#### Conceito

A operação de espelhamento troca todos os filhos esquerdos pelos filhos direitos de cada nó da árvore.

#### Aplicação

* Processamento de imagens;
* Estudos de simetria;
* Algoritmos de manipulação de árvores.

#### Exemplo Antes

```text
      A
     / \
    B   C
```

#### Exemplo Depois

```text
      A
     / \
    C   B
```
