package com.sample;
import com.sample.Paciente;
import com.sample.Sintoma;

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
        	
        	
        	Paciente P1 = new Paciente ("001","Ana Melo",12,"");
        	Paciente P2= new Paciente ("002","Rui Costa",13,"");
        	Paciente P3= new Paciente ("003","Joana Martins",85,"");
        	Paciente P4= new Paciente ("004","Pedro Torres",53,"");
        	Paciente P5= new Paciente ("005","Ana Gomes",93,"");

        	Sintoma S1= new Sintoma ("001", "febre");
        	Sintoma S2= new Sintoma ("001", "manchas");
        	Sintoma S3= new Sintoma ("002", "febre");
        	Sintoma S4= new Sintoma ("003", "febre");
        	Sintoma S5= new Sintoma ("003", "dores");
        	Sintoma S6= new Sintoma ("004", "febre");
        	Sintoma S7= new Sintoma ("004", "dores");
        	Sintoma S8= new Sintoma ("004", "manchas");
        	kSession.insert(P1);
        	kSession.insert(P2);
        	kSession.insert(P3);
        	kSession.insert(P4);
        	kSession.insert(P5);
        	kSession.insert(S1);
        	kSession.insert(S2);
        	kSession.insert(S3);
        	kSession.insert(S4);
        	kSession.insert(S5);
        	kSession.insert(S6);
        	kSession.insert(S7);
        	kSession.insert(S8);
        	 
            // go !
            Message message = new Message();
            message.setMessage("Hello World");
            message.setStatus(Message.HELLO);
            /*kSession.insert(message);
            kSession.fireAllRules();*/
            
        } catch (Throwable t) {
            t.printStackTrace();
        }
    }

    public static class Message {

        public static final int HELLO = 0;
        public static final int GOODBYE = 1;

        private String message;

        private int status;

        public String getMessage() {
            return this.message;
        }

        public void setMessage(String message) {
            this.message = message;
        }

        public int getStatus() {
            return this.status;
        }

        public void setStatus(int status) {
            this.status = status;
        }

    }

}
