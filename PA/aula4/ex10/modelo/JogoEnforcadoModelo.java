package pt.isec.a2021130221.ex10.modelo;

import java.util.Random;

public class JogoEnforcadoModelo {
    public static final int MAX_ERRORS = 7; //Variavel para o máximo de erros
    private String palavra;         //Variavel para a palavra a adivinhar
    private int numeroTentativas;   //Variavel para o numero de tentativas
    private int numeroErros;        //Variavel para o numero de erros
    private String situacaoAtual;   //situacao atual
    StringBuilder tentativas;
    public JogoEnforcadoModelo() {this.tentativas = new StringBuilder();} //Numero de letras que existem
    public void iniciaNovoJogo() {
        Random rnd = new Random();
        int r = rnd.nextInt(JogoEnforcadoDicionario.getNumeroPalavras());
        this.palavra = JogoEnforcadoDicionario.getPalavra(r);
        this.numeroTentativas = 0;
        this.numeroErros = 0;
        this.situacaoAtual = "_".repeat(this.palavra.length());
    }
    public boolean terminou() {
        return this.situacaoAtual.equals(this.palavra) || this.numeroErros == MAX_ERRORS ;
    }
    public String getSituacaoAtual() {
        return situacaoAtual;
    }
    public int getNumeroTentativas() {
        return numeroTentativas;
    }
    public int getNumeroErros() {
        return numeroErros;
    }
    public String getPalavra(){
        return palavra;
    }
    public String getTentativas() {
       return this.tentativas.toString();
    }
    public void tenta(char letra) {
        letra = Character.toUpperCase(letra);
        String caracteres = String.valueOf(tentativas);
        numeroTentativas++;
        if(caracteres.indexOf(letra) != -1){
            return;
        }
        if (this.palavra.indexOf(letra) != -1) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < this.palavra.length(); i++) {
                if (this.palavra.charAt(i) == letra){
                    sb.append(letra);
                } else {
                    sb.append(this.situacaoAtual.charAt(i));
                }
            }
            this.situacaoAtual = sb.toString();
        }else{
            numeroErros++;
        }
        this.tentativas.append(letra);
    }

    public boolean ganhou() {
        return this.situacaoAtual.equals(palavra);
    }
}
