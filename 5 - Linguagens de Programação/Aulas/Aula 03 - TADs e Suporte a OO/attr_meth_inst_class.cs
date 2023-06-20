using System;

public class Shape {

    public string Name {get; set; }
    private static int count = 0;

    public Shape(string name="sem nome") {
        Name = name;
        count++;
    }

    public virtual void display() {
        Console.WriteLine("Shape: {0}", Name);
    }

    public static int GetInstanceCount() {
        return count;
    }

    static void Main(string[] args) {
        Shape[] vec = new Shape[10];
        for (int i=0; i<vec.Length; i++) {
            vec[i] = new Shape("Retângulo - " + (i+1));
            vec[i].display();
        }
        Console.WriteLine("Count: {0}", Shape.GetInstanceCount());
    }
}