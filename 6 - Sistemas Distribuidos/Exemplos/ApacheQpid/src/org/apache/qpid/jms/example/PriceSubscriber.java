/*
 *  Learning Project.
 */
package org.apache.qpid.jms.example;

import javax.jms.Connection;
import javax.jms.ConnectionFactory;
import javax.jms.JMSException;
import javax.jms.Message;
import javax.jms.MessageConsumer;
import javax.jms.Session;
import javax.jms.Topic;
import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;

/**
 *
 * @author rodrigo
 */
public class PriceSubscriber {

    public PriceSubscriber() {
        this.runSubscriber();
    }

    public static void main(String[] args) {
        new PriceSubscriber();
    }

    private void runSubscriber() {
        try {
            Context context = new InitialContext();
            ConnectionFactory connectionFactory = (ConnectionFactory) context.lookup("myFactoryLookup");
            
            Topic priceTopic = (Topic) context.lookup("myTopicLookup");

            Connection connection = connectionFactory.createConnection("guest", "guest");
            connection.setClientID("Assinante1");
            connection.start();

            Session session = connection.createSession(true, Session.SESSION_TRANSACTED);

            MessageConsumer subscriber1 = session.createDurableSubscriber(priceTopic, "Assinante1");

            Message message = subscriber1.receive();
            session.commit();
            System.out.println("Subscriber 1 received : " + message);
            System.out.println(message.getStringProperty("instrument"));
            System.out.println(message.getIntProperty("price"));

            subscriber1.close();
            connection.close();
            context.close();
        } catch (NamingException | JMSException e) {
            System.out.println("ERRO:" + e);
        }
    }
}
