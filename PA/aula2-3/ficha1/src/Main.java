

//ex2
/*
public class Main {

    public static final int NUMERO_PENSADO_IGUAL = 1;
    public static final int NUMERO_PENSADO_MAIOR = 2;
    public static final int NUMERO_PENSADO_MENOR = 3;
    public static int obtemResposta(int palpite) {
        Scanner sc = new Scanner(System.in);
        int resposta;

        do{
            System.out.printf("O número em que pensou é: %d?\n",palpite);
            System.out.println("\n" + NUMERO_PENSADO_IGUAL +" - SIM");
            System.out.println(NUMERO_PENSADO_MAIOR + " - PENSEI NUM NÚMERO MAIOR");
            System.out.println(NUMERO_PENSADO_MENOR + " -PENSEI NUM NÚMERO MENOR");
            System.out.print("\nResposta: ");

            resposta = sc.nextInt();

        }while(resposta<1 || resposta>3);

        return resposta;
    }

    public static void main(String[] args){

        int min=1, max=100, palpite;
        int resposta, numTentativas=0;

        System.out.println("Pense num número...");

        do{
            numTentativas++;
            palpite =(min+max)/2;
            resposta = obtemResposta(palpite);

            if(resposta==NUMERO_PENSADO_MAIOR)
                min = palpite + 1;
            else if (resposta == NUMERO_PENSADO_MENOR)
                max=palpite-1;

        }while (resposta != NUMERO_PENSADO_IGUAL && min <= max);

        if(resposta != NUMERO_PENSADO_IGUAL)
            System.out.println("\nMentiu-me!");
        else
            System.out.printf("\nAcertei no número %d em %d tentativas\n", palpite, numTentativas);

    }
}

 */


//ex4
/*
public class Main {


    public static void main(String[] args) {

        Tabela tab = new Tabela();
        tab.geraNums();
        tab.listar();
        tab.mostraQtDuplicados();

    }
}
 */


//ex7
/*
public class Main {

    public static void main(String[] args) throws Exception {

        Matrix m1 = new Matrix(4,3);

        for(int i=0;i<4;i++)
            for(int j=0;j<3;j++)
                m1.set(i, j, (float) Math.random()*100);

        Matrix m2 = new Matrix(m1);
        Matrix m3 = (Matrix) m1.clone();

        m1.set(1, 1, 1000);
        m2.set(1, 1, 2000);
        m3.set(1, 1, 3000);

        Matrix m4 = Matrix.add(m1, m2);

        System.out.println("M1:");
        m1.show();
        System.out.println("\nM2:");
        m2.show();
        System.out.println("\nM3:");
        m3.show();
        System.out.println("\nM4 (M1+M2):");
        m4.show();

        m4.add(m3);

        System.out.println("\nM4 += M3:");
        m4.show();

        /*Matrix m5 = m4.getTransposed_v2();
        Matrix m6 = Matrix.getTransposed(m4);
        m4.transpose();

        System.out.println("\nTranspose M4");
        m4.show();
        System.out.println("\nTranspose M4 (v2)");
        m5.show();
        System.out.println("\nTranspose M4 (static)");
        m6.show();

        System.out.println("\nM1 = "+m1);
    }
}
*/


//ex9
/*
public class Main {

        public static void main(String[] args) {
            int depth = 8;
            PascalTriangle triangle = new PascalTriangle(depth);
            triangle.showTriangle();
        }
}
*/

//ex10
public class Main {

    public static void main(String[] args) {
        
    }
}
