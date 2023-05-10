function v = filtra_matriz(m, n)
% Esta funcao recebe uma matriz e retorna outra matriz so queos numeros
% n encontrados
% inputs: m - matriz recebida
         %n - tipo de implementacao (1,2)
% outputs: v - matriz com os intervalos n
if n==1
    v=[];
    for coluna = 1:size(m,2)
        for linha=1:size(m,1)
            value = m(linha, coluna);
            if mod(value, 2) == 0
                v = [v value];
            end
        end
    end
end
if n==2
    posicoes = mod(m,2)==0;
    v= m(posicoes)';

end
end

