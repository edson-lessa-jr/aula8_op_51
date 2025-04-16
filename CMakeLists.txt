cmake_minimum_required(VERSION 3.30)
project(aula8_op_51 C)

set(CMAKE_C_STANDARD 11)

add_executable(aula8_op_51 main.c
        01-busca-interpolacao/busca_interpolacao.c
        01-busca-interpolacao/busca_interpolacao.h
        02-tabela-hash-encadeada/hash_encadeada.c
        02-tabela-hash-encadeada/hash_encadeada.h
        03-tabela-hash-aberta/hash_aberta.c
        03-tabela-hash-aberta/hash_aberta.h)
