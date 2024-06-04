<?php
/*
namespace DAO;

class UsuarioBD
{

    private $conexao;

    /*sempre que for criado um novo usuario, ele faz conexao com o BD
    com o DSN e armazena em conexao*/

  /*  public function __construct()
    {
        /* data source name, faz a conexão com o BD*/
        $dsn = "mysql:host=localhost:3307;dbname=roberto_carros";

        /*PHP data object*/
/*        $this->conexao = new PDO($dsn, 'root', 'admin');
    }

    public function insert(PessoaModel $model)
    {

        /*preparador, separa os dados, preenche os "?" e executa, ou seja, manda para o BD*/
/*        $sql = "INSERT INTO usuario (nome, email, idade, telefone) VALUES (?, ?, ?, ?)";

        $stmt = $this->conexao->prepare($sql);
        $stmt->bindValue(1, $model->nome);
        $stmt->bindValue(2, $model->email);
        $stmt->bindValue(3, $model->idade);
        $stmt->bindValue(4, $model->telefone);
        $stmt->execute();

    }

    public function update(UsuarioModel $model)
    {

    }

}
*/