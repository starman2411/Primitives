# Primitives
Готовые классы для быстрого создания фигур тетрамино и удобной работы с ними.




    * `N_matrix()`  - конструктор без параметров

    *`N_matrix(long int m,long int n)`  -стандартный конструктор принимает высоту и ширину

    *`N_matrix(const N_matrix& a)`      -конструктор копирования

    *`N_matrix& rotate_matrix(int k)`       -поворот матрицы на угол k*Пи/2 (где k=1,2,3,4) (при k не из диапазона 1-4 матрица не изменется)

    *`N_matrix& operator =(const N_matrix& a)`   -оператор присваивания

    *`long int get_height()const`  -получить высоты
        
    *`long int get_width()const`  -получить ширину
    
    *`void set_value(int i,int j,float a)   -задать значение по индексам
 
    *`float get_value(int i,int j) const`   -получить значение по индексам
    
    *`void set_from_array(float* a)`      -задать матрицу через массив



 


