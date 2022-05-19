import "./Produto.css";
import Bee from "../../../assets/images/background_home_pequeno.png";

function Produto() {
    return(
        <section className="blogs" id="blogs">
            <h1 className="heading"> Produtos <span>Disponíveis</span> </h1>
        
            <div className="box-container">
                <div className="box">
                    <div className="image">
                        <img src={Bee} />
                    </div>
                    <div className="content">
                        <a href="#" className="title">Brigadeiro</a>
                        <span>Localização: Em frente ao Bloco X</span>
                        <p>Brigadeiro muito gostoso</p>
                        <a href="#" className="btn">tenho interesse</a>
                    </div>
                </div>

                <div className="box">
                    <div className="image">
                        <img src={Bee} />
                    </div>
                    <div className="content">
                        <a href="#" className="title">Brownie</a>
                        <span>Localização: Em frente ao Bloco X</span>
                        <p>Brownie muito gostoso</p>
                        <a href="#" className="btn">tenho interesse</a>
                    </div>
                </div>

                <div className="box">
                    <div className="image">
                        <img src={Bee} />
                    </div>
                    <div className="content">
                        <a href="#" className="title">Bolo</a>
                        <span>Localização: Em frente ao Bloco X</span>
                        <p>Bolo muito gostoso</p>
                        <a href="#" className="btn">tenho interesse</a>
                    </div>
                </div>


            </div>

        </section>
    );
}

export default Produto;