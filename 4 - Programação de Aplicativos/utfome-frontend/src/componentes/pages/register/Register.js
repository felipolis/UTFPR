import React from 'react';
import './Register.css';
import logo from '../../../assets/images/Logo_grande.png';
import { useState, useContext } from 'react';
import { AuthContext } from '../../../contexts/auth';

const Register = () => {
    const { register } = useContext(AuthContext);

    const [name, setName] = useState('');
    const [lastName, setLastName] = useState('');
    const [email, setEmail] = useState('');
    const [password, setPassword] = useState('');

    const handleSubmit = (e) => {
        e.preventDefault();
        console.log("Submitted", { name, lastName, email, password });
        register(name, lastName, email, password);
    }

    return (
        <div className='container'>
            <div className='container-login'>
                <div className='wrap-register'>
                    <form 
                    className='login-form' 
                    onSubmit={handleSubmit}>
                        <span className='login-form-title'>
                            <img src={logo}></img>
                        </span>

                        <div className='wrap-input'>
                            <input 
                            className={name !== '' ? 'has-val input' : 'input'}
                            type="text"
                            value={name}
                            onChange={e => setName(e.target.value)} />
                            <span className='focus-input' data-placeholder="Nome"></span>
                        </div>

                        <div className='wrap-input'>
                            <input
                            className={lastName !== '' ? 'has-val input' : 'input'}
                            type="text"
                            value={lastName}
                            onChange={e => setLastName(e.target.value)} />
                            <span className='focus-input' data-placeholder="Sobrenome"></span>
                        </div>

                        <div className='wrap-input'>
                            <input 
                            className={email !== '' ? 'has-val input' : 'input'}
                            type="email"
                            value={email}
                            onChange={e => setEmail(e.target.value)} />
                            <span className='focus-input' data-placeholder="Email"></span>
                        </div>

                        <div className='wrap-input'>
                            <input 
                            className={password !== '' ? 'has-val input' : 'input'} 
                            type="password"
                            value={password}
                            onChange={e => setPassword(e.target.value)} />
                            <span className='focus-input' data-placeholder="Password"></span>
                        </div>

                        <div className='container-login-form-btn'>
                            <button className='login-form-btn'>
                                Registrar
                            </button>
                        </div>

                        <div className='text-center'>
                            <span className='txt1'>
                                Nao possui conta?
                            </span>

                            <a href='#' className='txt2'>
                                Criar conta
                            </a>
                        </div>
                    </form>
                </div>
            </div>
        </div>
    )
}

export default Register;