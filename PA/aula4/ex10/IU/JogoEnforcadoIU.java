package pt.isec.a2021130221.ex10.IU;

import pt.isec.a2021130221.ex10.modelo.JogoEnforcadoModelo;

import java.util.Scanner;

public class JogoEnforcadoIU {
    private JogoEnforcadoModelo jogo;
    private Scanner sc;

    public JogoEnforcadoIU(JogoEnforcadoModelo jogo) {
        this.jogo = jogo;
        this.sc = new Scanner(System.in);
    }

    public void jogar() {
        jogo.iniciaNovoJogo();

        while (!jogo.terminou()) {
            System.out.println("Situação atual: " + jogo.getSituacaoAtual());
            System.out.println("Nr. tentativas: " + jogo.getNumeroTentativas());
            System.out.println(desenhoEnforcado(jogo.getNumeroErros()));
            //System.out.println("Erros: " + jogo.getNumeroErros() + "(máx.: " + JogoEnforcadoModelo.MAX_ERRORS + ")");
            System.out.println("Caracteres já tentados: " + jogo.getTentativas());

            System.out.println("Tentativa: ");
            String tentativa = sc.nextLine().trim();

            jogo.tenta(tentativa.charAt(0));
        }
        if (jogo.ganhou()){
            System.out.println("Parabéns! Acertou na palavra " + jogo.getSituacaoAtual() + " em " + jogo.getNumeroTentativas() + " tentativas");
        } else {
            System.out.println("Situação atual: " + jogo.getSituacaoAtual());
            System.out.println("Nr. tentativas: " + jogo.getNumeroTentativas());
            System.out.println(desenhoEnforcado(jogo.getNumeroErros()));
            //System.out.println("Erros: " + jogo.getNumeroErros() + "(máx.: " + JogoEnforcadoModelo.MAX_ERRORS + ")");
            System.out.println("Caracteres já tentados: " + jogo.getTentativas());
            System.out.println("Não ganhou! Não acertou a palavra " + jogo.getPalavra());
        }
    }
    private String desenhoEnforcado(int error){
        StringBuilder sb = new StringBuilder();
        sb.append("+----------+\n");
        sb.append("|          |\n");
        sb.append(error >= 1? "|          o\n" : "|\n"); //Error 0-7
        if (error == 2) {                                //Error 2
            sb.append("|          +\n");
        }
        else if (error == 3) {                          //Error 3
            sb.append("|          +--+\n");
        }
        else if (error >= 4) {                          //Error 4-7
            sb.append("|       +--+--+\n");
        } else {
            sb.append("|\n");
        }
        sb.append(error >= 5 ? "|          |\n" : "|\n");   //Error 5-7
        sb.append(error >= 5 ? "|          |\n" : "|\n");
        if (error == 6){                                    //Error 6
            sb.append("|           \\\n");
            sb.append("|            \\\n");
        } else if (error == 7){                             //Error 7
            sb.append("|         / \\\n");
            sb.append("|        /   \\\n");
        } else {
            sb.append("|\n");
            sb.append("|\n");
        }
        sb.append("|\n");
        sb.append("===");
        return sb.toString();
    }
}
