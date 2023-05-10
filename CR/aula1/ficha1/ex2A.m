function m = ex2A(a,b,x) %funcao ex2A aka gera_matriz
% Esta funcao vai gerar uma matriz de valores inteiros alocados
% inputs: a - numero de linhas da matriz de saida m
         %b - numero de colunas
         %x - limite maximo dos aleatorios gerados
% outputs: m - matriz a*b inicializada com numeros x
m = randi(x,a,b);
end