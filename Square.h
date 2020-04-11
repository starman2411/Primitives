#ifndef SQUARE_H_INCLUDED
#define SQUARE_H_INCLUDED
#include <SFML/Graphics.hpp>
using namespace sf;
class Square{
private:
    RectangleShape rect;
    GVector position;
    Texture texture;

public:


    Square(GVector &p, float this_size, float OutlineThickness=0, Color outline_color={230,230,0},string texture_file="texture.png"){
    position=p;
    string s=texture_file;
    rect.setSize(Vector2f(this_size, this_size));
    rect.setPosition(position.getX(), position.getY());
    rect.setOutlineThickness(OutlineThickness);
    rect.setOutlineColor(outline_color);
    texture.loadFromFile(s);
    rect.setTexture(&texture);
    rect.setTextureRect(sf::IntRect(10, 10, 100, 100));
    }



    void change_position(GVector& pos){
        position=pos;
        rect.setPosition(pos.getX(), pos.getY());
    }
    void move_figure(GVector& delta){
        position=position+delta;
        rect.setPosition(position.getX(),position.getY());
    }
    RectangleShape& get_figure(){
        return(rect);
    }
    GVector& get_position(){
        return(position);
    }

};


#endif // SQUARE_H_INCLUDED
