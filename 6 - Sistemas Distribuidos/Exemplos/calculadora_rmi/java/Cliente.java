/**
 * Solicita o servico
 * autor: Rodrigo Campiolo
 * data:22/11/2006
 * modificado em: 03/05/2019
 */

import java.rmi.registry.Registry;
import java.rmi.registry.LocateRegistry;

 public class Cliente {
     public static void main(String args[]) {
         try {
            /* OPCIONAL: configurar e ativar o Security Manager */
            System.setProperty("java.security.policy", "policy.txt");
            System.setSecurityManager(new SecurityManager());

            System.out.println ("Cliente iniciado ...");

            /* obtem a referencia para o objeto remoto */
            Registry registry = LocateRegistry.getRegistry("localhost");
	        Calculadora c = (Calculadora)registry.lookup("ServicoCalculadora");

	        System.out.println("20+4=" + c.soma(20,4));
	        System.out.println("20-4=" + c.subtrai(20,4));
	        System.out.println("20*4=" + c.multiplica(20,4));
	        System.out.println("20/4=" + c.divide(20,4));
         } catch (Exception e) {
            System.out.println(e);
         } //catch
     } //main
 } //Cliente