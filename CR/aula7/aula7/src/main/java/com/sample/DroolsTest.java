package com.sample;

import java.util.Scanner;

import org.kie.api.KieServices;
import org.kie.api.runtime.KieContainer;
import org.kie.api.runtime.KieSession;

/**
 * This is a sample class to launch a rule.
 */
public class DroolsTest {

    public static final void main(String[] args) {
        try {
            // load up the knowledge base
	        KieServices ks = KieServices.Factory.get();
    	    KieContainer kContainer = ks.getKieClasspathContainer();
        	KieSession kSession = kContainer.newKieSession("ksession-rules");

            // go !
        	/**
            Divisao d1 = new Divisao("cozinha");
            Divisao d2 = new Divisao("escritorio");
            Divisao d3 = new Divisao("sala");
            
            kSession.insert(d1);
            kSession.insert(d2);
            kSession.insert(d3);
            
            Aspersor asp1 = new Aspersor(d1, false);
            Aspersor asp2 = new Aspersor(d2, false);
            
            kSession.insert(asp1);
            kSession.insert(asp2);
            
            Fogo f1 = new Fogo(d1);
            Fogo f2 = new Fogo(d2);
            Fogo f3 = new Fogo(d3);
            
            kSession.insert(f1);
            kSession.insert(f2);
            kSession.insert(f3);
            
            Aspersor asp3 = new Aspersor(d3, false);
            
            kSession.insert(asp3);
            */
        	Scanner ler = new Scanner(new FileInputStream("C:\Users\lipwo\Downloads\fogo.txt"));
            String linha = ler.netLine();
            while(ler.hasNextLine()) {
	            linha = ler.nextLine();
	            String [] temp = linha.split(";");
	            Divisao d = new DIvisao(temp[0]);
	            kSession.insert(d);
	            if (temp[1].equals("sim")) {
	                Aspersor a = new Aspersor(d, false);
	                kSession.insert(a);
	            }
	            if (temp[2].equals("sim")) {
	                Fogo f = new Fogo(d);
	                kSession.insert(f);
            }
        }
           
            kSession.fireAllRules();
        } catch (Throwable t) {
            t.printStackTrace();
        }
    }

    

}
