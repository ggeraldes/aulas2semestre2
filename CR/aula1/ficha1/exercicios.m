%fechar todas as janelas, limpar variaveis, e limpar ecra
close all; clear; clc;

% 1.
    % a)
        %vetor de 0 a 100 de 2 em 2
        m_a = 0:2:100;
    
    % b)
        % m_b = transposta de ma
        m_b = m_a';
    
    % c)
        % m_c = matriz 3*3 linhas separadas por ";"
        m_c=[1,2,3;4,5,6;7,8,9];
    
    % d)
        % alterar o valor de m_d(1,3)
        m_d=m_c;
        m_d(1,3)=33;
    
    % e)
        % matriz 3*3 ó com uns. m_e=ones(3,3)*33 para ser só com 33
        m_e=ones(3,3);
    
    % f)
        m_f=randn(8,8);
        m_f2=rand(8,8);
    
    % g)
        %remove a segunda coluna
        m_g=m_f2;
        m_g(:,2)=[];
    
    % h)
        % Definindo o vetor de ângulos
        x = 0:pi/100:2*pi;
        % Calculando os valores da função seno para cada ângulo
        y = sin(x);
        % Plotando o gráfico
        plot(x,y);
    
    % i)
        hold on;
        coss=cos(x);
        plot(x,coss, 'g');
    
    % j)
        % a)
            legend("sen","cos");
    
        % b)
            title("SENO E COSSSENO");

% 2.
    % a)
        a=5; b=6; c=10;
        m2A = ex2A(a,b,c);

    % b)
        m2B = filtra_matriz(m_d, 1);
    
    % c)
        m2C = maior_num(1);
        



