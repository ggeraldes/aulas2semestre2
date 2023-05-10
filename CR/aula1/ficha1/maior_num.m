function valorM = maior_num(t)
%MAIOR_NUM Summary of this function goes here
%   Detailed explanation goes here
switch t
    case 1
        maior = -inf;
        n=1;
        while(n~=0)
            n = input('Digite o numero: ');
            if(n>maior)
                maior=n;
            end
        end

      case 2
        v=[];
        n=1;
        while(n~=0)
            n = input('Digite o numero ');
            v=[v n];
        end
        maior = max(v);

        
end

