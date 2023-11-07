# Trabalho 2 - OAC - Simulador

Neste trabalho foi desenvolvido um simulador de processadores RISC-V 32 bits, em C. Um simulador é um programa que consegue receber um arquivo binário, com as instruções e os dados de um programa compilado para a ISA simulada e ter no final o mesmo resultado que um processador implementado em Hardware teria.

Para o desenvolvimento do mesmo, foi criado um código em C, compilado com o compilador gcc, na plataforma macOS, versão Sonoma 14.0, que utiliza um processador intel x64. Todo o código é compilado com makefiles, e pode ser compilado, rodado, e deletar todos os binários ao rodar o script `./run.sh`.

As instruções do RISC-V implementadas foram:

| Instrução | o que ela faz |
| --------- | ------------- |
| `jalr x0, a(x1)` | guarda o valor do `pc` em `x0` e mudar o valor do `pc` para a + `x1`  |
| `lb x0, a(x1)`| guarda em `x0` o valor do byte que está em `x1 + a` |
| `lh x0, a(x1)`| guarda em `x0` o valor do half que está em `x1 + a` |
| `lw x0, a(x1)`| guarda em `x0` o valor da palavra que está em `x1 + a` |
| `lbu x0, a(x1)`| guarda em `x0` o valor do byte, sem extensão de sinal que está em `x1 + a` |
| `lhu x0, a(x1)`| guarda em `x0` o valor do half, sem extensão de sinal que está em `x1 + a` |
| `addi x0, x1, a`| adiciona o valor de `x1` e `a` e coloca em `x0` |
| `slti x0, x1, a`| se `x1` for menor que `a`, `x0 = 1`, se não `x0 = 0` |
| `sltiu x0, x1, a`| se `x1` for menor que `a`, desconsiderando sinais, `x0 = 1`, se não `x0 = 0` |
| `xori x0, x1, a`| faz um xor bitwise entre `x1` e `a` e guarda em `x0` |
| `ori x0, x1, a`| faz um or bitwise entre `x1` e `a` e guarda em `x0` |
| `andi x0, x1, a`| faz um and bitwise entre `x1` e `a` e guarda em `x0` |
| `slli x0, x1, a`| move o valor de `x1` para a esquerda `a` vezes e guarda em `x0` |
| `srai x0, x1, a`| move o valor de `x1` para a direita `a` vezes, se o valor de `x1` for negativo, completa os espaços vazios com 1 e guarda em `x0` |
| `srli x0, x1, a`| move o valor de `x1` para a direita `a` vezes e guarda em `x0` |
| `add x0, x1, x2`| adiciona o valor de `x1` e `x2` e coloca em `x0` |
| `slt x0, x1, x2`| se `x1` for menor que `x2`, `x0 = 1`, se não `x0 = 0` |
| `sltu x0, x1, x2`| se `x1` for menor que `x2`, desconsiderando sinais, `x0 = 1`, se não `x0 = 0` |
| `xor x0, x1, x2`| faz um xor bitwise entre `x1` e `x2` e guarda em `x0` |
| `or x0, x1, x2`| faz um or bitwise entre `x1` e `x2` e guarda em `x0` |
| `and x0, x1, x2`| faz um and bitwise entre `x1` e `x2` e guarda em `x0` |
| `sll x0, x1, x2`| move o valor de `x1` para a esquerda `x2` vezes e guarda em `x0` |
| `sra x0, x1, x2`| move o valor de `x1` para a direita `x2` vezes, se o valor de `x1` for negativo, completa os espaços vazios com 1 e guarda em `x0` |
| `srl x0, x1, x2`| move o valor de `x1` para a direita `x2` vezes e guarda em `x0` |
| `sb x0, a(x1)`| guarda o valor de x0 (como um byte) no endereço de `a + x1` |
| `sh x0, a(x1)`| guarda o valor de x0 (como um half) no endereço de `a + x1` |
| `sw x0, a(x1)`| guarda o valor de x0 (como uma palavra) no endereço de `a + x1` |
| `beq x0, x1, a`| se o valor de `x0` e de `x1` forem iguais, adiciona `a` ao `pc` |
| `bne x0, x1, a`| se o valor de `x0` e de `x1` forem diferentes, adiciona `a` ao `pc` |
| `bge x0, x1, a`| se o valor de `x0` for maior ou igual a `x1`, adiciona `a` ao `pc` |
| `blt x0, x1, a`| se o valor de `x0` for menor que `x1`, adiciona `a` ao `pc` |
| `bgeu x0, x1, a`| se o valor de `x0` for maior ou igual a `x1` (desconsidera o sinal), adiciona `a` ao `pc` |
| `bltu x0, x1, a`| se o valor de `x0` for menor que `x1` (desconsidera o sinal), adiciona `a` ao `pc` |
| `lui x0, a`| atribui a `x0`, o valor do imediato grande `a` |
| `auipc x0, a`| atribui a `x0`, o valor do imediato grande `a` somado ao `pc` |
| `jal x0, a`| atribui a `x0`o valor atual do `pc` e muda o valor do `pc` para `pc + a` |

Além dessas instruções também foram implementadas três chamadas de sistema, `print_int`, `print_string` e `exit_program`. `print_int` imprime o valor guardado no registrador a0, e é acessado quando o registrador a7 é igual a 1; `print_string` é acessado quando o registrador a7 é igual a 4, e imprime a string que começa o endereço em a0, terminando assim que encontrar `\0`; `exit_program` é execitado quando o a7 é igual a 10, e sai do programa, retornando 0.

Para testar este simulador, foi utilizado o código assembly presente no arquivo `tester.asm` que foi compilado utilizando o RARS, com a configuração de memória `compact, text at 0`. O código foi exportado para o arquivo `instructions` e os dados foram exportados para o arquivo `data`. Ambos foram exportados como arquivos binários. O código lê esse código, e roda ele todo, imprimindo que todos os testes estão corretos, desde o Teste1, ao Teste22, assim como era esperado.
