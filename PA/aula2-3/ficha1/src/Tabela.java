public class Tabela {

    private static final int MAX = 100;
    private  static final int TAM = 20;
    private int [] tab;
    private int nInseridos = 0;
    private int nGerados = 0;

    public Tabela(){ tab = new int[TAM];}

    public int getnInseridos() {
        return nInseridos;
    }

    public int getnGerados() {
        return nGerados;
    }

    public boolean existe(int nr) {

        for (int i = 0; i < nInseridos; i++) {
            if (nr == tab[i])
                return true;
        }
        return false;
    }

    public boolean adiciona(int nr){

        if (nr < 0 || nr > MAX || nInseridos >= TAM)
            return false;

        if(existe(nr))
            return false;

        tab[nInseridos++]=nr;
        return true;


    }

    public void geraNums(){

        while(nInseridos < TAM){
            int nr =(int) (Math.random() * (MAX+1));
            nGerados++;
            adiciona(nr);
        }

    }

    public void listar(){

        System.out.print("[");

        for(int i=0;i < nInseridos;i++){
            if (i>0){
                System.out.print(", ");
            }
            System.out.print(tab[i]);
        }

        System.out.print("]");
    }

    public void mostraQtDuplicados(){

        if (nInseridos==0)
            System.out.println("Ainda não foram gerados valores");
        else
            System.out.printf("\npara além dos valores inseridos %d, foram gerados %d valores duplicados", nInseridos, nGerados-nInseridos);
    }



}
