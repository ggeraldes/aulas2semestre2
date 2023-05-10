function f3ex4()

% limpar
clear all;
close all;

% inicializar entrada
% a)
p = [0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1
     0 0 0 0 1 1 1 1 0 0 0 0 1 1 1 1
     0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1 
     0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1];

% b)
nr_exemplos = size(p,2);
t = [1 0 0 1 0 1 1 0 0 1 1 0 1 0 0 1];

% c)
disp('Percetron: ')
net = perceptron;
net.divideFcn='';

net = train(net, p, t); % treina a rede com as entradas e saídas

y = net(p); % faz a previsão com a rede treinada

disp(y);
accuracy=sum(y==t)/nr_exemplos;
disp([' Accuracy = ' num2str(accuracy)]);

% d)
disp('Rede Neuronal:')
net = feedforwardnet;
net.divideFcn='';
net = train(net, p, t);
y=net(p);
y=y>=0.5;
disp(y)
accuracy = sum (y==t)/nr_exemplos;
disp(['Accuracy = ' num2sstr(accuracy)]);

end
