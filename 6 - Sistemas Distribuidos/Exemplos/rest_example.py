"""
Building a Basic RestFul API in Python
Fonte: https://www.codementor.io/sagaragarwal94/building-a-basic-restful-api-in-python-58k02xsiq

No Linux e Python 3.5
--> Criar e acessar uma pasta para o projeto (ex: python_rest)
$ apt-get install sqlite3
$ wget http://www.sqlitetutorial.net/wp-content/uploads/2018/03/chinook.zip
$ unzip chinook.zip 
$ rm chinook.zip

--> Criar um ambiente virtual para o Python
$ sudo pip3 install virtualenv
$ virtualenv --python=python3.5 restenv

--> Ativar o ambiente e instalar as bibliotecas
$ source venv/bin/activate
$ pip install flask flask-jsonpify flask-sqlalchemy flask-restful
$ pip freeze

--> Executar o código fonte
$ python3.5 rest_example.py

--> Testar no navegador
http://127.0.0.1:5002/employees 
http://127.0.0.1:5002/tracks
http://127.0.0.1:5002/employees/8

--> Finalizar a aplicação e desativar o ambiente
$ deactivate

"""

from flask import Flask, request
from flask_restful import Resource, Api
from sqlalchemy import create_engine
from json import dumps
from flask_jsonpify import jsonpify

db_connect = create_engine('sqlite:///chinook.db')
app = Flask(__name__)
api = Api(app)

class Employees(Resource):
    def get(self):
        conn = db_connect.connect() # connect to database
        query = conn.execute("select * from employees") # This line performs query and returns json result
        return {'employees': [i[0] for i in query.cursor.fetchall()]} # Fetches first column that is Employee ID

class Tracks(Resource):
    def get(self):
        conn = db_connect.connect()
        query = conn.execute("select trackid, name, composer, unitprice from tracks;")
        result = {'data': [dict(zip(tuple (query.keys()) ,i)) for i in query.cursor]}
        return jsonpify(result)

class Employees_Name(Resource):
    def get(self, employee_id):
        conn = db_connect.connect()
        query = conn.execute("select * from employees where EmployeeId =%d "  %int(employee_id))
        result = {'data': [dict(zip(tuple (query.keys()) ,i)) for i in query.cursor]}
        return jsonpify(result)

api.add_resource(Employees, '/employees') # Route_1
api.add_resource(Tracks, '/tracks') # Route_2
api.add_resource(Employees_Name, '/employees/<employee_id>') # Route_3

if __name__ == '__main__':
     app.run(port='5002')