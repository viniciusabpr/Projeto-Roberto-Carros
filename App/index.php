<?php
    include 'Controller/UsuarioController.php';

    $url = parse_url($_SERVER['REQUEST_URI'], PHP_URL_PATH);

    switch ($url)
    {
        case '/':
            echo "Página inicial";
        break;

        case '/login':
            echo "Página de login";
        break;

        case '/cadastro':
            echo "Página para cadastrar usuário";
        break;

        case '/cadastrar-veiculo':
            echo "Página para cadastrar os veículos";
        break;

        default:
            echo 'Erro 404 - página não encontrada';
        break;
    }