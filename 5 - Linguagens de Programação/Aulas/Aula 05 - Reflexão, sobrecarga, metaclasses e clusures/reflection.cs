using System;

public class Reflection {

    static void Main(string[] args) {
        int inteiro = 10;
        string texto = "Aula de LP";
        double Flutuante = 10.5;
        System.Type Tipo = null;
        Tipo = inteiro.GetType();
        Console.WriteLine(Tipo.Name);
        Console.WriteLine(texto.GetType().Name);
        Console.WriteLine(Flutuante.GetType().Name);
    }
}