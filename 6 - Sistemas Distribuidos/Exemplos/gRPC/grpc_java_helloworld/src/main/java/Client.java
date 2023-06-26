
import io.grpc.ManagedChannel;
import io.grpc.ManagedChannelBuilder;


/**
 *
 * @author rodrigo
 */
public class Client {
    public static void main(String[] args) {
        ManagedChannel channel = ManagedChannelBuilder
                .forAddress("localhost", 7777)
                .usePlaintext()
                .build();
        
        GreeterGrpc.GreeterBlockingStub stub = 
                GreeterGrpc.newBlockingStub(channel);
        
        HelloRequest request = HelloRequest
                .newBuilder()
                .setName("Luffy")
                .build();
        
        //chamada remota
        HelloReply reply = stub.sayHello(request);
        
        System.out.println("Resposta: " + reply.getMessage());
        channel.shutdown();
    }
}
