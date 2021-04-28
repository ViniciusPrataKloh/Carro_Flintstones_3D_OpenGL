# Carro_Flintstones_OpenGL

- Ao executar o programa:

       - Deverá ser acionada a tecla 'p', para que seja ligada a projeção "perspectiva";
       - Todas as luzes estarão desligadas, então suas respectivas teclas de acionamento devem ser utilizadas;
       - Caso desejado, a tecla 'a' remove os vetores de orientação, que se encontram na origem;
       - Há a possibilidade de alternação entre "solid" e "wireframe", utilizando a tecla "w". 


- Primitivas de desenho:

       - Cubos, Cilindros e Cones.


- Fontes de luz:

       - 2 fontes de luz pontuais;
       - 1 fonte de luz direcional;
       - 4 fontes de luz spots.

       obs: Todas as luzes iniciam apagadas;
       
       - Controle de luzes: 
            F1 - Ascende as luzes pontuais;
            F2 - Ascende a luz direcional;
            F3 - Ascende as luzes spots.

        obs2: Foram feitas matrizes para as definições das luzes spots.
                 As mesmas, possuem a intenção de uma iluminação colorida.


- Materiais:

      - Criei duas funções de materiais, onde material() tende a um objeto metálico, e material2() tende a um objeto plástico.
      - O programa inicia com as cores pré-definidas pelos glColors.



- Movimentação:

      - Deslocamento pelo eixo 'x' com o uso das teclas "LEFT" e "RIGHT";
      - Botão direito do mouse altera a proximidade da câmera;
      - Botão esquerdo do mouse altera o ângulo do observador.
