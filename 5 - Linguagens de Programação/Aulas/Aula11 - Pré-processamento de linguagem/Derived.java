class Derived extends Base {

    public void display(int x)
    {
        System.out.println("Derived display(int )");
    }

    public static void main(String args[])
    {
        Derived obj = new Derived();

        obj.display(4);
    }
}