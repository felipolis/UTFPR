/*
 *  Learning Project.
 */
package org.apache.qpid.jms.example;

import javax.jms.Connection;
import javax.jms.ConnectionFactory;
import javax.jms.JMSException;
import javax.jms.Message;
import javax.jms.MessageProducer;
import javax.jms.Session;
import javax.jms.Topic;
import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;

/**
 *
 * @author rodrigo
 */
public class PricePublish {

    public PricePublish() {
        this.runPublisher();
    }

    public static void main(String[] args) {
        new PricePublish();
    }

    private void runPublisher() {
        try {
            Context context = new InitialContext();
            ConnectionFactory connectionFactory = (ConnectionFactory) context.lookup("myFactoryLookup");
            
            Topic priceTopic = (Topic) context.lookup("myTopicLookup");

            Connection connection = connectionFactory.createConnection("guest", "guest");
            connection.start();

            Session session = connection.createSession(true, Session.SESSION_TRANSACTED);
            
            MessageProducer messageProducer = session.createProducer(priceTopic);

            Message message = session.createMessage();
            message.setStringProperty("instrument", "IBM");
            message.setIntProperty("price", 100);
            messageProducer.send(message);
            session.commit();
            System.out.println("publicado");

            connection.close();
            context.close();
        } catch (NamingException | JMSException e) {
            System.out.println("ERRO:" + e);
        }
    }
}
