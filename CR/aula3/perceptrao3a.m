function perceptrao3a( )
%Funcao percepcao3a: cria, treina e testa um perceptrao
%usando as funcoes da NNTool

% limpar
clear all;
close all;

% inicializar entrada
p = [0 0 1 1; 0 1 0 1];

%informacao sobre operador logico 
fprintf('Introduza operador logico desejado:\n');
fprintf('1 - AND\n');
fprintf('2 - OR\n');
fprintf('3 - NAND\n');
fprintf('4 - XOR\n');
tmp =  input('                        operador? (default 1) = ');

% inicializar targets
if isempty(tmp)
    t = [0 0 0 1];
    op='AND';
else
    switch tmp
        case 1
            t = [0 0 0 1];
            op='AND';
        case 2
            t = [0 1 1 1];
            op='OR';
        case 3
            t = [1 1 1 0];
            op='NAND';
        case 4
            t = [0 1 1 0];
            op='XOR';
       otherwise
            t = [0 0 0 1];
            op='AND';
    end
end

net = perceptron;

net.trainParam.epochs = 100; % número de épocas de treinamento
net = train(net, p, t); % treina a rede com as entradas e saídas

y = net(p); % faz a previsão com a rede treinada

% Mostrar resultado
fprintf('Saida do perceptrao para %s:', op);
disp(y);
fprintf('Saida desejada para %s:', op);
disp(t);

% visualizar a arquitetura da rede criada
view(net)

%Plot 
w = net.iw{1,1};
b = net.b{1};
plotpv(p, t)
plotpc(w, b)

end

