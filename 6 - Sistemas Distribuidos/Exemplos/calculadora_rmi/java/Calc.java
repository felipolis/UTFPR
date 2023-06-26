/**
 * Implementacao do objeto remoto
 * autor: Rodrigo Campiolo
 * data: 22/11/2006
 */

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class Calc extends UnicastRemoteObject implements Calculadora {

    public Calc() throws RemoteException {
        super();
        System.out.println("Objeto remoto instanciado");
    } //Calc

    public int soma (int a, int b) throws RemoteException {
        System.out.println(a + "+" + b + "=" + (a+b));
        return  (a+b);
    } //soma

    public int subtrai (int a, int b) throws RemoteException {
        System.out.println(a + "-" + b + "=" + (a-b));
        return  (a-b);
    } //subtrai

    public int divide (int a, int b) throws RemoteException {
        System.out.println(a + "/" + b + "=" + (a/b));
        return  (a/b);
    } // divide

    public int multiplica (int a, int b) throws RemoteException {
        System.out.println(a + "*" + b + "=" + (a*b));
        return  (a*b);
    } //multiplica

} //Calc
