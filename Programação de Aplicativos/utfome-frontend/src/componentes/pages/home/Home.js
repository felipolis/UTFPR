import './Home.css';
import bee from '../../../assets/images/bee_grande.png';
import logo from '../../../assets/images/Logo-marrom.png';


function Home(){
    return (
        <section className="home" id="home">
            <div className='logos'>
                <img src={bee} className="bee" alt=''/>
                <img src={logo} className="logo"/>
            </div>
            <div className='btn botao-entrar'>Bee  Happy</div>
        </section>
    );

}
export default Home;