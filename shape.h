


template <typename T, typename S>
class Shape{
    protected:
        T _position;
        S _size;
    
    public:
        Shape(T position, S size):
            _position(position),
            _size(size)
        {}
        Shape(T x, T y, S size):
            _position(x,y),
            _size(size)
        {}

        Shape():
            _position(0,0),
            _size(0)
        {}

        virtual std::string getName() = 0;
        virtual void draw() = 0;

        T get_position() const{
            return _position;
        }

        T get_size() const{
            return _size;
        }

        T setPosition(const Point &v){
            _position.x = v.get_x();
            _position.y = v.get_y();
        }

        T setPosition(T x, T y){
            _position.x = x;
            _position.y = y;
        }
};