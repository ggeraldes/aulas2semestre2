package pt.isec.a2021130221.ex10;

import pt.isec.a2021130221.ex10.IU.JogoEnforcadoIU;
import pt.isec.a2021130221.ex10.modelo.JogoEnforcadoModelo;

public class JogoEnforcado {
    public static void main(String args[]) {
        JogoEnforcadoModelo jogo = new JogoEnforcadoModelo();
        JogoEnforcadoIU jogoIU = new JogoEnforcadoIU(jogo);
        jogoIU.jogar();
    }
}
