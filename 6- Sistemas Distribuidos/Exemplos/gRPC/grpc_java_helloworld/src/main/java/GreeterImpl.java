
import io.grpc.stub.StreamObserver;

/**
 *
 * @author rodrigo
 */

public class GreeterImpl extends GreeterGrpc.GreeterImplBase {

    @Override
    public void sayHello(HelloRequest request, StreamObserver<HelloReply> responseObserver) {
        System.out.println("Recebido: " + request.getName());
        HelloReply response = HelloReply.newBuilder()
                .setMessage("Olá, recebi sua mensagem.")
                .build();
        
        responseObserver.onNext(response);
        responseObserver.onCompleted();
    }
    
    
}
