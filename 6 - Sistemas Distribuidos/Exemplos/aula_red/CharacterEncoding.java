/*
 *  Learning Project.
 */
package aula_red;

import java.io.UnsupportedEncodingException;

/**
 * JAVA supported encodings: https://docs.oracle.com/javase/8/docs/technotes/guides/intl/encoding.doc.html 
 *
 * @author http://blog.caelum.com.br/entendendo-unicode-e-os-character-encodings/
 * @author Modificado por Rodrigo
 */
public class CharacterEncoding {

    public static void main(String[] args) throws UnsupportedEncodingException {
        String[] codes = {"ISO-8859-1", "UTF-8", "UTF-16", "Windows-1252", "Cp850"};
        String letra = "ç";

        for (String encoding : codes) {
            byte[] b = letra.getBytes(encoding);
            System.out.printf("%12s\t%d\t", encoding, b.length);
            for (int k = 0; k < b.length; k++) {
                String hex = Integer.toHexString((b[k] + 256) % 256);
                if (hex.length() == 1) {
                    hex = "0" + hex;
                }
                System.out.print(hex);
            }
            System.out.println();
        }
    }

}
