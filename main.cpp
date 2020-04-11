#include <SFML/Graphics.hpp>
#include "Line.h"
#include "Point.h"
#include "GVector.h"
#include "N_matrix.h"
#include <vector>
#include "Square.h"
#include "Tetromino.h"
using namespace std;
using namespace sf;

int main()
{
    sf::RenderWindow window(sf::VideoMode(720, 480), "SFML works!");

    N_matrix s(3,3);
    vector<Square*> h;
    float v[9]={1,1,1,1,0,0,1,0,0};


    s.set_from_array(v);    //можно заполнить из массива

    //s.set_value(0,0,1);
    //s.set_value(0,1,1);
    //s.set_value(1,1,1);        //можно заполнять матрицу так
    //s.set_value(0,2,1);
    //cout<<s<<endl;            //можно вывести матрицу

    GVector r(0,0);
    GVector q(300,100);
    GVector w(10,300);

    Tetromino<Square> tetr(r,s,50,3,Color(10,100,230),"texture1.jpg");

    tetr.rotate_tetramino(2);

    tetr.move_tetramino(q);

    tetr.set_position(w);



    h=tetr.get_figures();


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        for (unsigned int i=0;i<h.size();i++){
            window.draw((*h[i]).get_figure());}

        window.display();

    }


    return 0;
}
