<?php
namespace Src\Traits;

/*Arquivo para separar os endereços das páginas em um array*/
trait TraitUrlParser
{
    /*Divide a URL em array*/
    public function parseurl()
    {
        return explode("/",rtrim($_GET['url']), FILTER_SANITIZE_URL);
    }
}