package pt.isec.pa.aula1;

import pt.isec.util.ParInteiros;

public class SomaParInteiros {
	public static void main(String args[]) {
		int i1,i2;
		
		System.out.println();
		
		if(args.length != 2){
			System.out.println("Devem serindicados 2 parametros inteiros!");
			return;
		}
		
		i1 = Integer.parseInt(args[0]);
		i2 = Integer.parseInt(args[1]);
		
		ParInteiros p =new ParInteiros(i1,i2);
		System.out.println(p);
		
		System.out.println(i1+"+"+i2+"="+p.getSoma());
		
	}
}