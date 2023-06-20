import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;

public class BuiltinAnnotations {

    public static void main(String[] args) throws FileNotFoundException {
		genericsTest();
	}

	@Deprecated
	public static void oldMethod() {
		System.out.println("Método muito velho... Não o use!");
	}

	// @SuppressWarnings({ "unchecked" })
	public static void genericsTest() throws FileNotFoundException {
		List l = new ArrayList();
		l.add("abc");
		oldMethod();
	}

}