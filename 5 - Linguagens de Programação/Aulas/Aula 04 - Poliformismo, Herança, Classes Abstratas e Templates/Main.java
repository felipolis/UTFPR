public class Main {
    public static void main(String[] args) {
        Square quadrado = new Square();
        quadrado.setSide(15);
        System.out.println(quadrado.getName());
        System.out.println(quadrado.getArea());
        System.out.println(quadrado.getPerimeter());
    }
}
