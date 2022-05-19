import Footer from '../../layout/footer/Footer';
import Header from '../../layout/header/Header';
import './Contact.css';

function Contact(){
    return (
        <>
            <Header />
            <section className="contact" id="contact">

                <h1 className="heading"> <span>contate</span> nos </h1>

                <div className="row">

                    <iframe title="map" className="map" src="https://www.google.com/maps/embed?pb=!1m18!1m12!1m3!1d3643.1649489867455!2d-52.38915795000186!3d-24.060495186021026!2m3!1f0!2f0!3f0!3m2!1i1024!2i768!4f13.1!3m3!1m2!1s0x94ed756613064859%3A0xc12ba615c30491ed!2sUTFPR%20Universidade%20Tecnol%C3%B3gica%20Federal%20Do%20Paran%C3%A1!5e0!3m2!1spt-BR!2sbr!4v1649035605632!5m2!1spt-BR!2sbr" allowfullscreen="" loading="lazy"></iframe>


                    <form action="">
                        <h3>entre em contato</h3>
                        <div className="inputBox">
                            <span className="fas fa-user"></span>
                            <input type="text" placeholder="nome"/>
                        </div>
                        <div className="inputBox">
                            <span className="fas fa-envelope"></span>
                            <input type="email" placeholder="email"/>
                        </div>
                        <div className="inputBox">
                            <span className="fas fa-phone"></span>
                            <input type="number" placeholder="telefone"/>
                        </div>
                        {/* area da mensagem */}
                        <div className="inputBox">
                            <span className="fas fa-pencil-alt"></span>
                            <textarea name="" id="" cols="30" rows="10" placeholder="mensagem"></textarea>
                        </div>
                        <input type="submit" value="enviar" className="btn"/>
                    </form>

                </div>

            </section>
            <Footer />
        </>
    );
}

export default Contact;