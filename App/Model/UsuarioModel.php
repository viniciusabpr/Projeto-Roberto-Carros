<?php

class UsuarioModel
{

    public $id_usuario, $nome, $email, $telefone, $idade;

    public function save()
    {

        include 'DAO/UsuarioBD.php';

        $BD = new UsuarioBD();

        $BD->insert($this);
    }
}