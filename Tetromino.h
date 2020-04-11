#ifndef TETROMINO_H_INCLUDED
#define TETROMINO_H_INCLUDED
#include "Square.h"
#include <vector>
#include "N_matrix.h"
template<typename T>
class Tetromino{
private:
    N_matrix frame;
    GVector pos;
    vector<T*> figures;
    float size_of_figures;
    float border;

public:
    Tetromino(GVector &p, N_matrix &a, float size_of_figures, float border,  Color outline_color={230,230,0},string texture_file="texture.png"){
        this->size_of_figures=size_of_figures;
        this->border=border;
        frame=a;
        pos=p;

        for (int i = 0; i < frame.get_height(); i++)
            for (int j = 0; j < frame.get_width(); j++){
                if ((frame.get_value(i,j))==1){
                    GVector t(j*(size_of_figures+border),i*(size_of_figures+border));
                    T *a= new T((t+pos),size_of_figures,border, outline_color,texture_file);
                    figures.push_back(a);}
            }
        }

    vector<T*> get_figures(){
        return(figures);
    }
    void rotate_tetramino(int k){
    frame=frame.rotate_matrix(k);
    unsigned int l=0;
        for (int i = 0; i < frame.get_height(); i++)
            for (int j = 0; j < frame.get_width(); j++){
                if ((frame.get_value(i,j))==1){
                    GVector t(j*(size_of_figures+border),i*(size_of_figures+border));
                    figures[l]->change_position(pos+t);
                    l++;}
            }


    }

    N_matrix& get_matrix(){
    return(frame);
    }
    void set_position(GVector& new_pos){
    pos=new_pos;
    unsigned int k=0;
        for (int i = 0; i < frame.get_height(); i++)
            for (int j = 0; j < frame.get_width(); j++){
                if ((frame.get_value(i,j))==1){
                    GVector t(j*(size_of_figures+border),i*(size_of_figures+border));
                    figures[k]->change_position(pos+t);
                ++k;
            }
    }
    };
    void move_tetramino(GVector& delta){
    pos=pos+delta;
        for (unsigned int i = 0; i < figures.size(); i++){
            figures[i]->move_figure(delta);
        }

    }
    GVector& get_position(){
    return(pos);
    }
    float get_sizeoffigures(){
    return(size_of_figures);
    }
};



#endif // TETROMINO_H_INCLUDED
