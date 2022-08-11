template <typename T,typename V>    //Multiple temporary datatype can be created

class Pair {

    T x;
    V y;

    public :

    void setX(T x) {
        this->x = x;
    }

    T getX() {
        return x;
    }

    void setY(V y) {
        this->y = y;
    }

    V getY() {
        return y;
    }
};