/*
 * Classe representa uma mensagem
 * @author Rodrigo
 */

public class Message {
    
    private final byte type;           // tipo da mensagem 
    private final String source;       // origem (apelido)
    private final String message;      // conteudo da mensagem

    
    /* Construtor 1 */
    public Message (byte typeMsg, String nick, String msg) {
        type = typeMsg;
        source = nick;
        message = msg;
    } // construtor 1

    
    /* Construtor 2 */
    public Message (byte[] msg) {
        int sizeApelido = (int) msg[1];
        
        type = msg[0];
        source = new String(msg, 2, sizeApelido);
        message = new String(msg,2+sizeApelido,msg.length-(sizeApelido+2));
    } // construtor 2

    
    /**
     * Transformar a mensagem em uma sequencia de bytes
     * byte 0 = tipo da mensagem
     * byte 1 = tamanho apelido
     * byte 2 a 2+tamanho apelido = apelido
     * byte 2+tamalho apelido a final = mensagem
     * @return formato da mensagem em array de bytes
     */
    public byte[] getBytes() {
        byte[] sourceBytes = source.getBytes();
        byte[] msgBytes = message.getBytes();
        int size = 1 + 1 + sourceBytes.length + msgBytes.length; // tamanho do vetor
        byte[] msg = new byte[size];
        
        msg[0] = type;
        msg[1] = (byte) source.length();
        System.arraycopy(sourceBytes, 0, msg, 2, sourceBytes.length);
        System.arraycopy(msgBytes, 0, msg, 2 + sourceBytes.length, msgBytes.length);
        
        return msg;
    } //getBytes

    
    /** metodos para obter o conteudo da mensagem */
    public byte getType() { return type; }
    public String getSource() { return source; }
    public String getMessage() { return message; }
    
    @Override
    public String toString() {
        return "[ " + this.type + ", " + this.source + ", " + this.message + " ]";
    }
    
} // class Mensagem
