# Aula 8 – Técnicas Avançadas de Busca (Disciplina: Estrutura de Dados)

Este projeto contém exemplos práticos em linguagem C que demonstram três importantes técnicas de busca e estruturas associadas:

- **Busca por Interpolação**
- **Tabela Hash com Encadeamento**
- **Tabela Hash com Endereçamento Aberto (Sondagem Linear)**

---

## 📁 Estrutura do Projeto

```
├── main.c
├── 01-busca-interpolacao/
│   ├── busca_interpolacao.h
│   └── busca_interpolacao.c
├── 02-tabela-hash-encadeada/
│   ├── hash_encadeada.h
│   └── hash_encadeada.c
├── 03-tabela-hash-aberta/
│   ├── hash_aberta.h
│   └── hash_aberta.c
└── README.md
```

---

## 🚀 Compilação

Para compilar todos os arquivos com `gcc`, execute no terminal:

```bash
gcc main.c \
  01-busca-interpolacao/busca_interpolacao.c \
  02-tabela-hash-encadeada/hash_encadeada.c \
  03-tabela-hash-aberta/hash_aberta.c \
  -o aula8
```

---

## ▶️ Execução

Depois de compilado, execute o programa com:

```bash
./aula8
```

Você verá o menu com as opções:

```
========== AULA 8 – TECNICAS AVANCADAS DE BUSCA ==========
1. Busca por Interpolacao
2. Tabela Hash com Encadeamento
3. Tabela Hash com Enderecamento Aberto
0. Sair
```

Escolha a técnica que deseja explorar e siga as instruções do terminal.

---

## 🧪 Exemplos Incluídos

### 🔹 1. Busca por Interpolação
- Vetor ordenado com busca adaptativa por fórmula de interpolação.
- Exemplo ideal para vetores com distribuição uniforme.

### 🔹 2. Tabela Hash com Encadeamento
- Estrutura de vetor com listas ligadas para tratar colisões.
- Útil para aprender o uso de ponteiros e listas dinâmicas.

### 🔹 3. Tabela Hash com Endereçamento Aberto
- Vetor fixo com tratamento de colisão via sondagem linear.
- Didático para mostrar problemas de colisão e espaço limitado.

---

## 👨‍🏫 Projeto desenvolvido por

**Edson Orivaldo Lessa Junior**  
Universidade Unicesumar  
Disciplina: Estrutura de Dados  
Repositório oficial dos códigos da aula:  
[https://github.com/edson-lessa-jr/aula8_op_51](https://github.com/edson-lessa-jr/aula8_op_51)

---