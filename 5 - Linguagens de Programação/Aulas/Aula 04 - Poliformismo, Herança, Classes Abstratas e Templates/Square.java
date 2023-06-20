public class Square implements Shape {
    
    private int side;
    
    public int getSide() {
        return side;
    }
    
    public void setSide(int side) {
        this.side = side;
    }

    @Override
    public int getArea() {
        return side * side;
    }

    @Override
    public int getPerimeter() {
        return side * 4;
    }

    @Override
    public String getName() {
        return "Quadrado";
    }
}
